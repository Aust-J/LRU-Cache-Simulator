#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lru_cache.h"

// test 4: replacement policy should be LRU
int main(int argc, char *argv[]) {
  int size = 3;
  CACHE *cache = cache_new(size);
  float y;
  cache_insert(cache, 0, 0.0);
  cache_insert(cache, 1, 1.0);
  cache_insert(cache, 2, 2.0);
  y = cache_lookup(cache, 0);
  y = cache_lookup(cache, 1);
  y = cache_lookup(cache, 2);
  cache_insert(cache, 3, 3.0);
  // the LRU policy should get rid of cached
  // value of element 0, as it is oldest
  float y1, y2;
  y1 = cache_lookup(cache, 0);
  y2 = cache_lookup(cache, 1);
  exit(y1 <= 0 && y2 >= 0 ? 0 : 1);
}
