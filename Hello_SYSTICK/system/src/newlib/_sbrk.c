/*
 * This file is part of the µOS++ distribution.
 * It is covered by the µOS++ license, see the LICENSE file for details.
 */

// ----------------------------------------------------------------------------

#include <sys/types.h> // Include necessary system type definitions
#include <errno.h> // Include errno for error handling

// ----------------------------------------------------------------------------

caddr_t /* Returns a pointer to a newly allocated block of memory */
_sbrk(int incr); // Increase program data space by "incr" bytes

// ----------------------------------------------------------------------------

// The definitions used here should be kept in sync with the
// stack definitions in the linker script.

caddr_t
_sbrk(int incr)
{
  extern char _Heap_Begin; // Defined by the linker, points to the start of the heap
  extern char _Heap_Limit; // Defined by the linker, points to the end of the heap

  static char* current_heap_end; // Pointer to the current end of the heap
  char* current_block_address; // Pointer to the start of the new memory block

  if (current_heap_end == 0)
    {
      current_heap_end = &_Heap_Begin; // If current_heap_end is not set, initialize it to _Heap_Begin
    }

  current_block_address = current_heap_end; // Set the current_block_address to the current end of the heap

  // Align heap to word boundary (4-byte on Cortex-M0) to avoid hard faults
  incr = (incr + 3) & (~3); // align value to 4

  if (current_heap_end + incr > &_Heap_Limit)
    {
      // If the new heap end exceeds the heap limit, return an error
#if 0
      extern void abort (void);

      _write (1, "_sbrk: Heap and stack collision\n", 32);

      abort ();
#else
      // Heap has overflowed
      errno = ENOMEM;
      return (caddr_t) - 1;
#endif
    }

  current_heap_end += incr; // Update the current end of the heap

  return (caddr_t) current_block_address; // Return the pointer to the new memory block
}

// ----------------------------------------------------------------------------

