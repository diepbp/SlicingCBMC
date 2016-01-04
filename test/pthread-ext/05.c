extern void __VERIFIER_error() __attribute__ ((__noreturn__));

//Simple test_and_set lock with exponential backoff
//
//From Algorithms for Scalable Synchronization on Shared-Memory Multiprocessors, 1991 (Fig. 1).
//Also available as pseudo-code here: http://www.cs.rochester.edu/research/synchronization/pseudocode/ss.html#tas

#include <pthread.h>

#define unlocked 0
#define locked 1
volatile int lock = 0;

#define assert(e) { if(!(e)) { ERROR: __VERIFIER_error();(void)0; } }

void __VERIFIER_atomic_TAS(
  volatile int *v,
  volatile int *o)
{
	// *o = *v;
	// *v = 1;
}

int c = 0;
void* thr1(void *arg){
	while(1){
	int cond;

	__VERIFIER_atomic_TAS(&lock,&cond);
	while(cond == 1){
		__VERIFIER_atomic_TAS(&lock,&cond);
	}
	assert(cond != lock);
	lock = 0; 
	}
  return 0;
}

int main(){
  pthread_t t;

	while(1) { 
		pthread_create(&t, 0, thr1, 0); 
	}
}

