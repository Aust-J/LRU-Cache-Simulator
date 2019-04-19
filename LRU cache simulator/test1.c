#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lru_cache.h"

// test 1: lookup should give negative value on non-cached elements
int main(int argc, char *argv[]) {
  int size = 3;
  int i = rand() % size;
   
	exit(cache_lookup(cache_new(size),i) < 0 ? 0 : 1);
}

