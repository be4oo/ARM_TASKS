/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#if !defined(OS_USE_SEMIHOSTING)

#include "arm/semihosting.h"

int errno;
void *__dso_handle __attribute__ ((weak));

void __attribute__((weak))
__initialize_args(int* p_argc, char*** p_argv)
{
  // By the time we reach this, the data and bss should have been initialised.

  // The strings pointed to by the argv array shall be modifiable by the
  // program, and retain their last-stored values between program startup
  // and program termination. (static, no const)
  static char name[] = "";

  // The string pointed to by argv[0] represents the program name;
  // argv[0][0] shall be the null character if the program name is not
  // available from the host environment. argv[argc] shall be a null pointer.
  // (static, no const)
  static char* argv[2] =
    { name, NULL };

  *p_argc = 1;
  *p_argv = &argv[0];
  return;
}

#else // defined(OS_USE_SEMIHOSTING)

int errno;
void *__dso_handle __attribute__ ((weak));

void __attribute__((weak))
__initialize_args(int* p_argc, char*** p_argv)
{
  // Array of chars to receive the command line from the host
  static char args_buf[ARGS_BUF_ARRAY_SIZE];

  // Array of pointers to store the final argv pointers (pointing
  // in the above array).
  static char* argv_buf[ARGV_BUF_ARRAY_SIZE];

  int argc = 0;
  int isInArgument = 0;

  CommandLineBlock cmdBlock;
  cmdBlock.pCommandLine = args_buf;
  cmdBlock.size = sizeof(args_buf) - 1;

  int ret = call_host (SEMIHOSTING_SYS_GET_CMDLINE, &cmdBlock);
  if (ret == 0)
    {

      // In case the host send more than we can chew, limit the
      // string to our buffer.
      args_buf[ARGS_BUF_ARRAY_SIZE - 1] = '\0';

      // The command line is a null terminated string
      char* p = cmdBlock.pCommandLine;

      int delim = '\0';
      int ch;

      while ((ch = *p) != '\0')
	{
	  if (isInArgument == 0)
	    {
	      if (!isblank(ch))
		{
		  if (ch == '"' || ch == '\'')
		    {
