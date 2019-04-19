#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lru_cache.h"

// test 2: lookup should correctly cache elements
int main(int argc, char *argv[]) {
  int size = 3;
  CACHE *cache = cache_new(size);
  float x = 5.5;
  int i = rand() % size;
  cache_insert(cache, i, x);
  float y = cache_lookup(cache, i);
  exit(fabsf(x-y) <= 0.01 ? 0 : 1);
}
