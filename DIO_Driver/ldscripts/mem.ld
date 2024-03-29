/*
 * Memory Spaces Definitions.
 *
 * This linker script defines the memory spaces for a specific board. The memory
 * spaces include various flash and RAM segments, each with a specific origin
 * (starting address) and length.
 *
 * The values for FLASH.ORIGIN, FLASH.LENGTH, RAM.ORIGIN, and RAM.LENGTH need
 * to be modified for the specific board being used. The other memory segments
 * (CCMRAM, FLASHB1, EXTMEMB0, EXTMEMB1, EXTMEMB2, EXTMEMB3, and MEMORY_ARRAY)
 * are currently defined with a length of 0.
 *
 * The values defined in this linker script can be used in further linker scripts
 * using functions like 'ORIGIN(RAM)' or 'LENGTH(RAM)'.
 */

MEMORY
{
  /*
   * RAM segment with origin at 0x20000000 and length of 20K.
   */
  RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 20K

  /*
   * CCMRAM segment with origin at 0x00000000 and length of 0.
   */
  CCMRAM (xrw) : ORIGIN = 0x00000000, LENGTH = 0

  /*
   * FLASH segment with origin at 0x08001000 and length of 60K.
   */
  FLASH (rx) : ORIGIN = 0x08001000, LENGTH = 60K

  /*
   * FLASHB1 segment with origin at 0x00000000 and length of 0.
   */
  FLASHB1 (rx) : ORIGIN = 0x00000000, LENGTH = 0

  /*
   * EX
