extern void __VERIFIER_error() __attribute__ ((__noreturn__));
//original file: EBStack.java
//amino-cbbs\trunk\amino\java\src\main\java\org\amino\ds\lockfree
//push only

#include <pthread.h>

#define assume(e) __VERIFIER_assume(e)
#define assert(e) { if(!(e)) { ERROR: __VERIFIER_error(); (void)0; } }

void __VERIFIER_atomic_acquire(int * m)
{
  assume(*m==0);
  *m = 1;
}

void __VERIFIER_atomic_release(int * m)
{
  assume(*m==1);
  *m = 0;
}

#define MEMSIZE (2*320+1) //0 for "NULL"
int memory[MEMSIZE];
#define INDIR(cell,idx) memory[cell+idx]

int next_alloc_idx = 1;
int m = 0;
int top;

void __VERIFIER_atomic_assert(int r)
{
    assert(!r || !(top == 0));
}


int m2 = 0;
int state = 0;
void* thr1(void* arg)
{
  __VERIFIER_atomic_acquire(&m2);
  switch(state)
  {
  case 0: 
    top = 0;
    state = 1;
    //fall-through
  case 1: 
    __VERIFIER_atomic_release(&m2);
    
    int r = -1;
    int arg = __VERIFIER_nondet_int();
    while(1){
        int oldTop = -1, newTop = -1;
      int curr_alloc_idx = -1;

      __VERIFIER_atomic_acquire(&m);
      if(next_alloc_idx+2-1 > MEMSIZE){
        __VERIFIER_atomic_release(&m);
        curr_alloc_idx = 0;
      }else{
        curr_alloc_idx = next_alloc_idx;
        next_alloc_idx += 2;
        __VERIFIER_atomic_release(&m);
      }
      newTop = curr_alloc_idx;
      if(newTop == 0){
        r = 0;
      }else{
        INDIR(newTop,0) = arg;

        __VERIFIER_atomic_acquire(&m);
        oldTop = top;
        INDIR(newTop,1) = oldTop;
        top = newTop; 
        __VERIFIER_atomic_release(&m);
        r = 1;
      }
      __VERIFIER_atomic_assert(r);
    }
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

