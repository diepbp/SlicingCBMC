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
__thread _Bool COND = 0; //local
_Bool buf = 0;

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

void* thr1(void* arg){
  while(1)
  {
    switch(__VERIFIER_nondet_int())
    {
    case 0: 
    	__VERIFIER_atomic_acquire();
    	assert(MTX==LOCKED);
		__VERIFIER_atomic_release();
		cv_broadcast(COND);
    	break;
    case 1: 
    	__VERIFIER_atomic_acquire();
    	assert(MTX==LOCKED);
		__VERIFIER_atomic_release();
    	break;
    case 2: 
    	__VERIFIER_atomic_acquire();
    	assert(MTX==LOCKED);
		
	if (!buf && __VERIFIER_nondet_int()){
		  COND = 0; 
		  __VERIFIER_atomic_release(); 
		  assume(COND); 
		  __VERIFIER_atomic_acquire(); 
		assert_nl(COND);
	}
	if (!buf) {
		__VERIFIER_atomic_release();
		return; 	
	}
	__VERIFIER_atomic_release();
    	break;
    case 3: 
    	    	__VERIFIER_atomic_acquire();
    	assert(MTX==LOCKED);
		buf = 0;
		__VERIFIER_atomic_release();
    	break;
    case 4: 
    while(1){
            	__VERIFIER_atomic_acquire();
    	assert(MTX==LOCKED);
        buf = !buf;
        __VERIFIER_atomic_release();
      }
    }
  }

  return 0;
}

int main(){
  pthread_t t;

  while(1) 
  {
  	pthread_create(&t, 0, thr1, 0);
  }
}

