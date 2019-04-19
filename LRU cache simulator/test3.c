#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lru_cache.h"

// test 3: clearing an element should remove it from cache
int main(int argc, char *argv[]) {
  int size = 3;
  CACHE *cache = cache_new(size);
  int i = rand() % size;
  cache_clear(cache, i);
  float y = cache_lookup(cache, i);
  exit(y <= 0.0 ? 0 : 1);
}
