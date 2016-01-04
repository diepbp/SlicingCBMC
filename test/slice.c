#include <pthread.h>

int x = 1, y = 1;

void *p2() {
  y = 1;
  y = 3;
  x = 5;
}

void *p3() {
  int yt = y;
  int xt = x;
  yt = y;
  __CPROVER_assert(xt == yt, "");
}

int main() {
  pthread_t t1, t2, t3;
  pthread_create(&t2, 0, p2, 0);
//  pthread_create(&t1, 0, p1, 0);
  pthread_create(&t3, 0, p3, 0);
//  pthread_join(t1, 0);
  pthread_join(t3, 0);
  pthread_join(t2, 0);
}
