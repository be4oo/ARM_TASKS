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
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
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

#include "cortexm/ExceptionHandlers.h"
#include "cmsis_device.h"
#include "arm/semihosting.h"
#include "diag/Trace.h"
#include <string.h>

#if defined(OS_USE_SEMIHOSTING)
#include "diag/Semihosting.h"
#endif

#if defined(TRACE)
#include "diag/TraceStreamAlt.h"
#endif

#if defined(DEBUG)
#include "debug/Debug.h"
#endif

// ----------------------------------------------------------------------------

extern void
__attribute__((noreturn,weak))
_start (void);

// ----------------------------------------------------------------------------
// Default exception handlers. Override the ones here by defining your own
// handler routines in your application code.
// ----------------------------------------------------------------------------

#if defined(DEBUG)

void __attribute__ ((section(".after_vectors"),noreturn))
Reset_Handler (void)
{
  _start ();
}

#else

void __attribute__ ((section(".after_vectors"),naked))
Reset_Handler(void)
{
  asm volatile
  (
      " ldr     r0,=_start \n"
      " bx      r0"
      :
      :
      :
  );
}

#endif

void __attribute__ ((section(".after_vectors"),weak))
NMI_Handler (void)
{
#if defined(DEBUG)
  __DEBUG_BKPT();
#endif
  while (1)
    {
    }
}

#if defined(TRACE)

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

void
dumpExceptionStack (ExceptionStackFrame* frame,
                uint32_t cfsr, uint32_t mmfar, uint32_t bfar,
                                        uint32_t lr)
{
  trace_printf ("Stack frame:\n"
                " R0 =  %08X\n"
                " R1 =  %08X\n"
                " R2 =  %08X\n"
                " R3 =  %08X\n"
                " R12 =  %08X\n"
                " LR =  %08X\n"
                " PC =  %08X\n"
                " PSR = %08X\n"
                "FSR/FAR:\n"
                " CFSR =  %08X\n"
                " HFSR =  %08X\n"
                " DFSR =  %08X\n"
                " AFSR =  %08X\n"
                "MMFAR = %08X\n"
                "BFAR =  %08X\n"
                "Misc\n"
                " LR/EXC_RETURN= %08X\n",
                frame->r0, frame->r1, frame->r2, frame->r3, frame->r12,
                frame->lr, frame->pc, frame->psr, cfsr, SCB->HFSR,
                SCB->DFSR, SCB->AFSR, mmfar, bfar, lr);
}

#endif // defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)

#if defined(__ARM_ARCH_6M__)

void
dumpExceptionStack (ExceptionStackFrame* frame, uint32_t lr)
{
  trace_printf ("Stack frame:\n"
                " R0 =  %08X\n"
                " R1 =  %08X\n"
                " R2 =  %08X\n"
                " R3 =  %08X\n"
                " R12 =  %08X\n"
                " LR =  %08X\n"
                " PC =  %08
