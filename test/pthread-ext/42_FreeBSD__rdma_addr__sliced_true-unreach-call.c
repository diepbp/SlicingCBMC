extern void __VERIFIER_error() __attribute__ ((__noreturn__));

#include <pthread.h>

/*
to correctly model the cv_broadcast(COND) statement "b1_COND := 1;" must be manually changed to "b1_COND$ := 1;" in the abstract BP
*/

#define assume(e) __VERIFIER_assume(e)
#define assert_nl(e) { if(!(e)) { goto ERROR; } }
#define assert(e) { if(!(e)) { ERROR: __VERIFIER_error();(void)0; } }


#define cv_broadcast(c) c = 1 //overapproximates semantics (for threader)

#define LOCKED 1

volatile _Bool MTX = !LOCKED;
__thread _Bool COND = 0;

void __VERIFIER_atomic_acquire()
{
	assume(MTX==0);
	MTX = 1;
}

void __VERIFIER_atomic_release()
{
	assume(MTX==1);
	MTX = 0;
}

volatile int refctr = 0;


void* thr1(void* arg){
  while(1)
  {
    switch(__VERIFIER_nondet_int()){
    case 0: 
	    __VERIFIER_atomic_acquire();
	    assert_nl(MTX==LOCKED);
		--refctr;
		if (refctr == 0) {
			cv_broadcast(COND); 
		}
		__VERIFIER_atomic_release();
	  	assert(1);
		__VERIFIER_atomic_acquire();
	    assert_nl(MTX==LOCKED);
		if (refctr) {
			  COND = 0; 
		  __VERIFIER_atomic_release(); 
		  assume(COND); 
		  __VERIFIER_atomic_acquire(); 
		}
		__VERIFIER_atomic_release();
	  	assert(1);
	    break;
    case 1: 
    	__VERIFIER_atomic_acquire();
	    assert_nl(MTX==LOCKED);
		__VERIFIER_atomic_release();
	  	assert(1);
    	break;
    case 2: 
    	__VERIFIER_atomic_acquire();
	    assert_nl(MTX==LOCKED);
		__VERIFIER_atomic_release();
	  	assert(1);
    	break;
    case 3: 
    	__VERIFIER_atomic_acquire();
	    assert_nl(MTX==LOCKED);
		refctr++;
		__VERIFIER_atomic_release();
		if(__VERIFIER_nondet_int()){
			__VERIFIER_atomic_acquire();
	    	assert_nl(MTX==LOCKED);
			refctr--;
			__VERIFIER_atomic_release();
		}
	  	assert(1);
    	break;
    case 4: 
    	__VERIFIER_atomic_acquire();
	    assert_nl(MTX==LOCKED);
		__VERIFIER_atomic_release();
	  	assert(1);
    	break; 
  }
}

  return 0;
}

int main(){
  pthread_t t;

  while(1) {
  	pthread_create(&t, 0, thr1, 0);
  }
}

