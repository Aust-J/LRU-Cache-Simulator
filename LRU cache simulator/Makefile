
# the include file in cache_sim.c must be set to select cache implementation

rand:	cache_sim_rand
	./cache_sim_rand

cache_sim_rand: cache_sim.c random_cache.c
	sed 's/\#include.*cache\.h/\#include \"random_cache\.h/' cache_sim.c > temp.c
	gcc -o cache_sim_rand temp.c random_cache.c

lru: 	cache_sim_lru
	./cache_sim_lru

cache_sim_lru: cache_sim.c lru_cache.c
	sed 's/\#include.*cache\.h/\#include \"lru_cache\.h/' cache_sim.c > temp.c
	gcc -o cache_sim_lru temp.c lru_cache.c

all_tests: test1 test2 test3 test4 test5
	./test1; echo $$?
	./test2; echo $$?
	./test3; echo $$?
	./test4; echo $$?
	./test5; echo $$?

test1:  test1.c lru_cache.h lru_cache.c
	gcc -o test1 test1.c lru_cache.c lru_cache.h

test2:  test2.c lru_cache.h lru_cache.c
	gcc -o test2 test2.c lru_cache.c lru_cache.h

test3:  test3.c lru_cache.h lru_cache.c
	gcc -o test3 test3.c lru_cache.c lru_cache.h

test4:  test4.c lru_cache.h lru_cache.c
	gcc -o test4 test4.c lru_cache.c lru_cache.h

test5:  test5.c lru_cache.h lru_cache.c
	gcc -o test5 test5.c lru_cache.c lru_cache.h

clean:
	rm -f cache_sim_lru cache_sim_rand temp.c test[1-5] *~ 

