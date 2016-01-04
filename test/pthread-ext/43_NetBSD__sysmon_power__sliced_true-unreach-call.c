extern void __VERIFIER_error() __attribute__ ((__noreturn__));

#include <pthread.h>

/*
to correctly model the cv_broadcast(COND) statement "b1_COND := 1;" must be manually changed to "b1_COND$ := 1;" in the abstract BP
*/

#define assume(e) __VERIFIER_assume(e)
#define assert_nl(e) { if(!(e)) { goto ERROR; } }
#define assert(e) { if(!(e)) { ERROR: __VERIFIER_error();(void)0; } }

#define cv_wait(c,m){ \
  c = 0; \
  __VERIFIER_atomic_release(); \
  assume(c); \
  __VERIFIER_atomic_acquire(); }

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

#define PSWITCH_EVENT_RELEASED 1
#define PENVSYS_EVENT_NORMAL 2
#define POWER_EVENT_RECVDICT 3

#define KASSERT(e) assert_nl(e)
#define is_locked(m) (m==LOCKED)


void* thr1(void* arg){
  while(1)
    switch(__VERIFIER_nondet_int()){
    case 0: 
    	if (__VERIFIER_nondet_int()) 
			return __VERIFIER_nondet_int();
		__VERIFIER_atomic_acquire();
		assert_nl(MTX==LOCKED);
		switch (__VERIFIER_nondet_int()) {
		case PSWITCH_EVENT_RELEASED:
			KASSERT(is_locked(MTX));
			if (__VERIFIER_nondet_int()) {
				__VERIFIER_atomic_release();
				goto out;
			}
			break;
		case PENVSYS_EVENT_NORMAL:
			KASSERT(is_locked(MTX));
			if (__VERIFIER_nondet_int()) {
				__VERIFIER_atomic_release();
				goto out;
			}
			break;
		default:
			__VERIFIER_atomic_release();
			goto out;
		}
		sysmon_queue_power_event();
		if (__VERIFIER_nondet_int()) {
			__VERIFIER_atomic_release();
			goto out;
		} 
		else {
			cv_broadcast(COND);
			__VERIFIER_atomic_release();
		}
		out:
	  	assert(1);
    	break;
    case 1: 
    	__VERIFIER_atomic_acquire();
		assert_nl(MTX==LOCKED);
		if (__VERIFIER_nondet_int())
			KASSERT(is_locked(MTX));
		__VERIFIER_atomic_release();
	  	assert(1);
    	break;
    case 2: 
    	__VERIFIER_atomic_acquire();
		assert_nl(MTX==LOCKED);
		KASSERT(is_locked(MTX));
		__VERIFIER_atomic_release();
	  	assert(1);
    	break;
    case 3: 
    	if (__VERIFIER_nondet_int()){
			__VERIFIER_atomic_acquire();
			assert_nl(MTX==LOCKED);
			for (;;) {
				if (sysmon_get_power_event()) {
					break;
				}
				if (__VERIFIER_nondet_int()) {
					break;
				}
				cv_wait(COND,MTX);
	      assert_nl(COND); 
	  		}
			__VERIFIER_atomic_release();
		}
	  	assert(1);
    	break;
    case 4: 
    	if(__VERIFIER_nondet_int()){
		__VERIFIER_atomic_acquire();
		assert_nl(MTX==LOCKED);
		__VERIFIER_atomic_release(); 
		}
	 	 assert(1);
    	break;
    case 5: 
    	__VERIFIER_atomic_acquire();
		assert_nl(MTX==LOCKED);
		__VERIFIER_atomic_release();
	  	assert(1);
    	break;
    case 6: 
    	__VERIFIER_atomic_acquire();
		assert_nl(MTX==LOCKED);
		__VERIFIER_atomic_release();
	  	assert(1);
    	break;
    case 7: 
    	__VERIFIER_atomic_acquire();
		assert_nl(MTX==LOCKED);
		__VERIFIER_atomic_release();
	  	assert(1);
    	break;
    case 8: 
    	switch (__VERIFIER_nondet_int()) {
		case POWER_EVENT_RECVDICT:
			__VERIFIER_atomic_acquire();
			assert_nl(MTX==LOCKED);
			if (__VERIFIER_nondet_int()) {
				__VERIFIER_atomic_release();
				break;
			}
			__VERIFIER_atomic_release();
			__VERIFIER_atomic_acquire();
			assert_nl(MTX==LOCKED);
			__VERIFIER_atomic_release();
			break; 
		}
	  assert(1);
    	break; 
    }
 }

int main(){
  pthread_t t;

  while(1) {
  	pthread_create(&t, 0, thr1, 0);
  }
}

