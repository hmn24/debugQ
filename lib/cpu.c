#define KXVER 3
#include "k.h"

/**
  * Read the cycle counter. AMD64 only in this version (note the non-portable
  * use of unsigned long long).
  *
  * @param x Ignored; required to allow us to bind to this from q.
  *
  * @return A long long wrapped in a K object.
  */
K q_read_cycles_of_this_cpu(K x)
{
  unsigned long a, d, reading;
  asm volatile("rdtsc" : "=a" (a), "=d" (d));
  reading = ((unsigned long long)a) | (((unsigned long long)d) << 32);
  return kj((J)reading);
}

