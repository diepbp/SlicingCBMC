extern void __VERIFIER_error() __attribute__ ((__noreturn__));

//http://www.ibm.com/developerworks/java/library/j-jtp11234/
//Listing 5. Implementing a thread-safe PRNG with synchronization and atomic variables

#include <pthread.h>

#define assume(e) __VERIFIER_assume(e)
#define assert(e) { if(!(e)) { ERROR: __VERIFIER_error();(void)0; } }

int m = 0;

void __VERIFIER_atomic_acquire()
{
	assume(m==0);
	m = 1;
}

void __VERIFIER_atomic_release()
{
	assume(m==1);
	m = 0;
}

volatile int seed; 


volatile int state = 0;
void* thr1(void* arg)
{
	int myrand;
	int read, nexts, nextInt_return;
	__VERIFIER_atomic_acquire();
	switch(state)
	{
	case 0: 
		seed = 1;
		state = 1;
		__VERIFIER_atomic_release();
		
		while(1)
		{
			assert(seed != 0);
		}
		break;
	case 1: 
		__VERIFIER_atomic_release();
		
		__VERIFIER_atomic_acquire();
		read = seed;

		do
		{
			nexts = __VERIFIER_nondet_int();
		}
		while(nexts == read || nexts == 0);

		assert(nexts != read); 
		seed = nexts;
		__VERIFIER_atomic_release();
		nextInt_return = nexts % 10;

		myrand = nextInt_return;
		assert(myrand <= 10);
		break;
	}

  return 0;
}

int main()
{
  pthread_t t;

	while(1) { 
		pthread_create(&t, 0, thr1, 0); 
	}
}

