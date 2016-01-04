int nondet_int();
extern void __VERIFIER_error() __attribute__ ((__noreturn__));

#include <assert.h>
#include <pthread.h>
#ifndef TRUE
#define TRUE (_Bool)1
#endif
#ifndef FALSE
#define FALSE (_Bool)0
#endif
#ifndef NULL
#define NULL ((void*)0)
#endif
#ifndef FENCE
#define FENCE(x) ((void)0)
#endif
#ifndef IEEE_FLOAT_EQUAL
#define IEEE_FLOAT_EQUAL(x,y) (x==y)
#endif
#ifndef IEEE_FLOAT_NOTEQUAL
#define IEEE_FLOAT_NOTEQUAL(x,y) (x!=y)
#endif


int __unbuffered_cnt;


int __unbuffered_cnt = 0;


int __unbuffered_p1_EAX;


int __unbuffered_p1_EAX = 0;


int __unbuffered_p2_EAX;


int __unbuffered_p2_EAX = 0;


int __unbuffered_p3_EAX;


int __unbuffered_p3_EAX = 0;


int a;


int a = 0;


_Bool a$flush_delayed;


int a$mem_tmp;


_Bool a$r_buff0_thd0;


_Bool a$r_buff0_thd1;


_Bool a$r_buff0_thd2;


_Bool a$r_buff0_thd3;


_Bool a$r_buff0_thd4;


_Bool a$r_buff1_thd0;


_Bool a$r_buff1_thd1;


_Bool a$r_buff1_thd2;


_Bool a$r_buff1_thd3;


_Bool a$r_buff1_thd4;


_Bool a$read_delayed;


int *a$read_delayed_var;


int a$w_buff0;


_Bool a$w_buff0_used;


int a$w_buff1;


_Bool a$w_buff1_used;


_Bool main$tmp_guard0;


_Bool main$tmp_guard1;


int x;


int x = 0;


int y;


int y = 0;


int z;


int z = 0;


_Bool weak$$choice0;


_Bool weak$$choice2;

int __global_lock;

void __VERIFIER_atomic_begin() { 
  __VERIFIER_assume(__global_lock==0); 
  __global_lock=1; 
  return; 
}
void __VERIFIER_atomic_end() { 
  __VERIFIER_assume(__global_lock==1); 
  __global_lock=0; 
  return; 
}

void *P0(void *arg){













  x = 1;


  a = nondet_int();






  __unbuffered_cnt = __unbuffered_cnt + 1;

  return nondet_0();
}



void *P1(void *arg){

  x = 2;


  __unbuffered_p1_EAX = y;


  a = nondet_int();






  __unbuffered_cnt = __unbuffered_cnt + 1;

  return nondet_0();
}



void *P2(void *arg){

  y = 1;


  __unbuffered_p2_EAX = z;


  a = nondet_int();






  __unbuffered_cnt = __unbuffered_cnt + 1;

  return nondet_0();
}



void *P3(void *arg){

  z = 1;

  __VERIFIER_atomic_begin();




  a = nondet_int();






  __unbuffered_p3_EAX = a;
  a = nondet_int();

  __VERIFIER_atomic_end();

  a = nondet_int();






  __unbuffered_cnt = __unbuffered_cnt + 1;

  return nondet_0();
}



void fence(){
  
}



void isync(){
  
}



void lwfence(){
  
}



int main(){
pthread_create(NULL, NULL, P0, NULL);
pthread_create(NULL, NULL, P1, NULL);
pthread_create(NULL, NULL, P2, NULL);
pthread_create(NULL, NULL, P3, NULL);

  main$tmp_guard0 = __unbuffered_cnt == 4;

  __VERIFIER_assume(main$tmp_guard0);

  a = nondet_int();






  /* Program proven to be relaxed for X86, model checker says YES. */


  /* Program proven to be relaxed for X86, model checker says YES. */
  assert(!(x == 2 && __unbuffered_p1_EAX == 0 && __unbuffered_p2_EAX == 0 && __unbuffered_p3_EAX == 0));
  return 0;
}

