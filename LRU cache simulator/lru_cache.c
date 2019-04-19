#include <stdlib.h>
#include "lru_cache.h"

//
// Your implementations of cache_new, cache_lookup, cache_insert,
// and cache_clear go in this file.  You must use a least-recently-used
// cache replacement policy.
//

// return a new cache object
CACHE *cache_new(int size) {

	CACHE *cache = malloc(sizeof(CACHE));
	cache->size = size;
	cache->addr = malloc(size * sizeof(int));
	cache->data = malloc(size * sizeof(float));
	cache->free_index = 0;

	int i;
	for (i = 0; i < cache->size; i++) {
		cache->addr[i] = -1;
		cache->data[i] = 0.0;
	}
	return cache;

}

// return data element i if it is cached; else return -1
float cache_lookup(CACHE *cache, int i) {
	int j;
	for (j = 0; j < cache->size; j++) {
		if (cache->addr[j] != -1) {   
			return cache->data[j];
		}
	}
	return -1.0;       
}

// record in the cache that the ith data element has value x
// LRU replacement policy is used
void cache_insert(CACHE *cache, int i, float x) {

	if(cache_lookup(cache, i) == -1) { //item is not in cache
		if(cache->free_index < cache->size - 1){	// no eviction
			cache->addr[cache->free_index] = i;
			cache->data[cache->free_index] = x;
			cache->free_index++;

		} else { 			//eviction
			cache_clear(cache, i);
		}

	} else if(cache->free_index == 49) {		//item is in cache, cache is full
		cache_clear(cache, 0);		// eviction of oldest item
		cache->data[cache->free_index] = x; 
		cache->addr[cache->free_index] = i;
		cache->free_index++;
	} else {			// no eviction, newest item 
		cache_clear(cache, i);
		cache->data[cache->free_index] = x;
		cache->addr[cache->free_index] = i;
		cache->free_index++;
	}
}
// clear the ith element of the cache
void cache_clear(CACHE *cache, int i) {
	int j;

	for(j = 0; j < cache->size; j++){ 	//find element  
		if(cache->addr[j] == i){
			if(cache->addr[j+1] = -1){ //if it is last element, clear it out
				cache->addr[j] = -1;
				cache->data[j] = 0.0;
			} else {		  //otherwise, traverse to update cache using LRU
				for (j = j; j < cache->size - 1; j++){
					cache->addr[j] = cache->addr[j+1];
					cache->data[j] = cache->data[j+1];
				}

			}
			j = cache->size;	
		}	
	}
}
