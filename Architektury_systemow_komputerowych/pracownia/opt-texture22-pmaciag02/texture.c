/*
 * row-major vs. tiled texture queries
 *
 * Intel® Core™ i5-6600 CPU @ 3.30GHz
 *
 * $ ./texture -S 0xdeadc0de -t 65536 -v 0
 * Time elapsed: 1.707234 seconds.
 * $ ./texture -S 0xdeadc0de -t 65536 -v 1
 * Time elapsed: 1.031514 seconds.
 * $ ./texture -S 0xdeadc0de -t 65536 -v 2
 * Time elapsed: 0.935953 seconds.
 */
#include "texture.h"

static inline long index_0(long x, long y) {
  return y * N + x;
}

#define VARIANT 0
#include "texture_impl.h"

static inline long index_1(long x, long y) {
  /* TODO: Fill in this procedure! */
  return 0;
}

#define VARIANT 1
#include "texture_impl.h"
