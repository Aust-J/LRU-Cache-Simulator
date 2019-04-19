 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUMOPS 10000

typedef struct { 
	int active;
	int wakeups;
	pthread_mutex_t lock;
	pthread_cond_t cv;

} SEM;

// contructor of semaphore
// parameter a is the initial value of the semaphore
SEM *sem_create(int a) {
	SEM *sem;
	sem = (SEM *)malloc(sizeof(SEM));
	assert(sem != NULL);

	// YOUR CODE HERE (initialize state and synchronization variables)
	pthread_mutex_init(&sem->lock, NULL);
	pthread_cond_init(&sem->cv, NULL);
	sem->active = a;
	sem->wakeups = 0;

	return(sem);
}

// wait operation on semaphore
void sem_wait(SEM *sem) {

	pthread_mutex_lock(&sem->lock);

	sem->active--;
	if(sem->active < 0){
		do{
			pthread_cond_wait(&sem->cv, &sem->lock);
		} while (sem->wakeups < 1);
			sem->wakeups--;
		}
	
	pthread_mutex_unlock(&sem->lock);

}

// signal operation on semaphore
void sem_signal(SEM *sem) {
	
	pthread_mutex_lock(&sem->lock);
	sem->active++;

	if(sem->active <= 0){
		sem->wakeups++;
		pthread_cond_signal(&sem->cv);
	}


	pthread_mutex_unlock(&sem->lock);
}

// repeatedly enter and exit critical section
void *agent(void *arg) {
	SEM *sem = (SEM *)arg;
	int i;
	for (i = 0; i < NUMOPS; i++) {
		sem_wait(sem);
		// beginning of critical section
		printf("in\n"); 
		int j; for (j = 0; j < 5000; j++);   // wait so others can enter critical section
		printf("out\n");
		// end of critical section
		sem_signal(sem);
	} 
	pthread_exit(NULL);
}

// test the semaphore
// note that the initial semaphore value can be provided on the command line
int main(int argc, char *argv[]) {
	int sem_init;
	pthread_t t1,t2,t3,t4;

	sem_init = 0;
	if (argc > 1) {
		// if input param 
		sem_init = atoi(argv[1]);
	}
	if (sem_init == 0) { 
		// default value
		sem_init = 2; 
	}

	SEM *sem = sem_create(sem_init);
	pthread_create(&t1, NULL, agent, (void *)sem);
	pthread_create(&t2, NULL, agent, (void *)sem);
	pthread_create(&t3, NULL, agent, (void *)sem);
	pthread_create(&t4, NULL, agent, (void *)sem);

	pthread_exit(NULL);
}
