

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


int __unbuffered_p1_EBX;


int __unbuffered_p1_EBX = 0;


int __unbuffered_p3_EAX;


int __unbuffered_p3_EAX = 0;


int __unbuffered_p3_EBX;


int __unbuffered_p3_EBX = 0;


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
void __VERIFIER_atomic_end() { 
  __VERIFIER_assume(__global_lock==1); 
  __global_lock=0; 
  return; 
}
void __VERIFIER_atomic_begin() { 
  __VERIFIER_assume(__global_lock==0); 
  __global_lock=1; 
  return; 
}


void * P0(void *arg)
{
  __VERIFIER_atomic_begin();
  a$w_buff1 = a$w_buff0;
  a$w_buff0 = 1;
  a$w_buff1_used = a$w_buff0_used;
  a$w_buff0_used = TRUE;
  a$r_buff1_thd0 = a$r_buff0_thd0;
  a$r_buff1_thd1 = a$r_buff0_thd1;
  a$r_buff1_thd2 = a$r_buff0_thd2;
  a$r_buff1_thd3 = a$r_buff0_thd3;
  a$r_buff1_thd4 = a$r_buff0_thd4;
  a$r_buff0_thd1 = TRUE;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  x = 1;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  a = a$w_buff0_used && a$r_buff0_thd1 ? a$w_buff0 : (a$w_buff1_used && a$r_buff1_thd1 ? a$w_buff1 : a);
  a$w_buff0_used = a$w_buff0_used && a$r_buff0_thd1 ? FALSE : a$w_buff0_used;
  a$w_buff1_used = a$w_buff0_used && a$r_buff0_thd1 || a$w_buff1_used && a$r_buff1_thd1 ? FALSE : a$w_buff1_used;
  a$r_buff0_thd1 = a$w_buff0_used && a$r_buff0_thd1 ? FALSE : a$r_buff0_thd1;
  a$r_buff1_thd1 = a$w_buff0_used && a$r_buff0_thd1 || a$w_buff1_used && a$r_buff1_thd1 ? FALSE : a$r_buff1_thd1;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  __unbuffered_cnt = __unbuffered_cnt + 1;
  __VERIFIER_atomic_end();
  return nondet_0();
}



void * P1(void *arg)
{
  __VERIFIER_atomic_begin();
  x = 2;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  __unbuffered_p1_EAX = x;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  __unbuffered_p1_EBX = y;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  a = a$w_buff0_used && a$r_buff0_thd2 ? a$w_buff0 : (a$w_buff1_used && a$r_buff1_thd2 ? a$w_buff1 : a);
  a$w_buff0_used = a$w_buff0_used && a$r_buff0_thd2 ? FALSE : a$w_buff0_used;
  a$w_buff1_used = a$w_buff0_used && a$r_buff0_thd2 || a$w_buff1_used && a$r_buff1_thd2 ? FALSE : a$w_buff1_used;
  a$r_buff0_thd2 = a$w_buff0_used && a$r_buff0_thd2 ? FALSE : a$r_buff0_thd2;
  a$r_buff1_thd2 = a$w_buff0_used && a$r_buff0_thd2 || a$w_buff1_used && a$r_buff1_thd2 ? FALSE : a$r_buff1_thd2;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  __unbuffered_cnt = __unbuffered_cnt + 1;
  __VERIFIER_atomic_end();
  return nondet_0();
}



void * P2(void *arg)
{
  __VERIFIER_atomic_begin();
  y = 1;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  z = 1;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  a = a$w_buff0_used && a$r_buff0_thd3 ? a$w_buff0 : (a$w_buff1_used && a$r_buff1_thd3 ? a$w_buff1 : a);
  a$w_buff0_used = a$w_buff0_used && a$r_buff0_thd3 ? FALSE : a$w_buff0_used;
  a$w_buff1_used = a$w_buff0_used && a$r_buff0_thd3 || a$w_buff1_used && a$r_buff1_thd3 ? FALSE : a$w_buff1_used;
  a$r_buff0_thd3 = a$w_buff0_used && a$r_buff0_thd3 ? FALSE : a$r_buff0_thd3;
  a$r_buff1_thd3 = a$w_buff0_used && a$r_buff0_thd3 || a$w_buff1_used && a$r_buff1_thd3 ? FALSE : a$r_buff1_thd3;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  __unbuffered_cnt = __unbuffered_cnt + 1;
  __VERIFIER_atomic_end();
  return nondet_0();
}



void * P3(void *arg)
{
  __VERIFIER_atomic_begin();
  z = 2;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  __unbuffered_p3_EAX = z;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  weak$$choice0 = nondet_1();
  weak$$choice2 = nondet_1();
  a$flush_delayed = weak$$choice2;
  a$mem_tmp = a;
  a = !a$w_buff0_used || !a$r_buff0_thd4 && !a$w_buff1_used || !a$r_buff0_thd4 && !a$r_buff1_thd4 ? a : (a$w_buff0_used && a$r_buff0_thd4 ? a$w_buff0 : a$w_buff1);
  a$w_buff0 = weak$$choice2 ? a$w_buff0 : (!a$w_buff0_used || !a$r_buff0_thd4 && !a$w_buff1_used || !a$r_buff0_thd4 && !a$r_buff1_thd4 ? a$w_buff0 : (a$w_buff0_used && a$r_buff0_thd4 ? a$w_buff0 : a$w_buff0));
  a$w_buff1 = weak$$choice2 ? a$w_buff1 : (!a$w_buff0_used || !a$r_buff0_thd4 && !a$w_buff1_used || !a$r_buff0_thd4 && !a$r_buff1_thd4 ? a$w_buff1 : (a$w_buff0_used && a$r_buff0_thd4 ? a$w_buff1 : a$w_buff1));
  a$w_buff0_used = weak$$choice2 ? a$w_buff0_used : (!a$w_buff0_used || !a$r_buff0_thd4 && !a$w_buff1_used || !a$r_buff0_thd4 && !a$r_buff1_thd4 ? a$w_buff0_used : (a$w_buff0_used && a$r_buff0_thd4 ? FALSE : a$w_buff0_used));
  a$w_buff1_used = weak$$choice2 ? a$w_buff1_used : (!a$w_buff0_used || !a$r_buff0_thd4 && !a$w_buff1_used || !a$r_buff0_thd4 && !a$r_buff1_thd4 ? a$w_buff1_used : (a$w_buff0_used && a$r_buff0_thd4 ? FALSE : FALSE));
  a$r_buff0_thd4 = weak$$choice2 ? a$r_buff0_thd4 : (!a$w_buff0_used || !a$r_buff0_thd4 && !a$w_buff1_used || !a$r_buff0_thd4 && !a$r_buff1_thd4 ? a$r_buff0_thd4 : (a$w_buff0_used && a$r_buff0_thd4 ? FALSE : a$r_buff0_thd4));
  a$r_buff1_thd4 = weak$$choice2 ? a$r_buff1_thd4 : (!a$w_buff0_used || !a$r_buff0_thd4 && !a$w_buff1_used || !a$r_buff0_thd4 && !a$r_buff1_thd4 ? a$r_buff1_thd4 : (a$w_buff0_used && a$r_buff0_thd4 ? FALSE : FALSE));
  __unbuffered_p3_EBX = a;
  a = a$flush_delayed ? a$mem_tmp : a;
  a$flush_delayed = FALSE;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  a = a$w_buff0_used && a$r_buff0_thd4 ? a$w_buff0 : (a$w_buff1_used && a$r_buff1_thd4 ? a$w_buff1 : a);
  a$w_buff0_used = a$w_buff0_used && a$r_buff0_thd4 ? FALSE : a$w_buff0_used;
  a$w_buff1_used = a$w_buff0_used && a$r_buff0_thd4 || a$w_buff1_used && a$r_buff1_thd4 ? FALSE : a$w_buff1_used;
  a$r_buff0_thd4 = a$w_buff0_used && a$r_buff0_thd4 ? FALSE : a$r_buff0_thd4;
  a$r_buff1_thd4 = a$w_buff0_used && a$r_buff0_thd4 || a$w_buff1_used && a$r_buff1_thd4 ? FALSE : a$r_buff1_thd4;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  __unbuffered_cnt = __unbuffered_cnt + 1;
  __VERIFIER_atomic_end();
  return nondet_0();
}



void fence()
{
  
}



void isync()
{
  
}



void lwfence()
{
  
}



int main()
{
  pthread_create(NULL, NULL, P0, NULL);
  pthread_create(NULL, NULL, P1, NULL);
  pthread_create(NULL, NULL, P2, NULL);
  pthread_create(NULL, NULL, P3, NULL);
  __VERIFIER_atomic_begin();
  main$tmp_guard0 = __unbuffered_cnt == 4;
  __VERIFIER_atomic_end();
  __VERIFIER_assume(main$tmp_guard0);
  __VERIFIER_atomic_begin();
  a = a$w_buff0_used && a$r_buff0_thd0 ? a$w_buff0 : (a$w_buff1_used && a$r_buff1_thd0 ? a$w_buff1 : a);
  a$w_buff0_used = a$w_buff0_used && a$r_buff0_thd0 ? FALSE : a$w_buff0_used;
  a$w_buff1_used = a$w_buff0_used && a$r_buff0_thd0 || a$w_buff1_used && a$r_buff1_thd0 ? FALSE : a$w_buff1_used;
  a$r_buff0_thd0 = a$w_buff0_used && a$r_buff0_thd0 ? FALSE : a$r_buff0_thd0;
  a$r_buff1_thd0 = a$w_buff0_used && a$r_buff0_thd0 || a$w_buff1_used && a$r_buff1_thd0 ? FALSE : a$r_buff1_thd0;
  __VERIFIER_atomic_end();
  __VERIFIER_atomic_begin();
  /* Program proven to be relaxed for X86, model checker says YES. */
  main$tmp_guard1 = !(x == 2 && z == 2 && __unbuffered_p1_EAX == 2 && __unbuffered_p1_EBX == 0 && __unbuffered_p3_EAX == 2 && __unbuffered_p3_EBX == 0);
  __VERIFIER_atomic_end();
  /* Program proven to be relaxed for X86, model checker says YES. */
  assert(!(x == 2 && z == 2 && __unbuffered_p1_EAX == 2 && __unbuffered_p1_EBX == 0 && __unbuffered_p3_EAX == 2 && __unbuffered_p3_EBX == 0));
  return 0;
}

