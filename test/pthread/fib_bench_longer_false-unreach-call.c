extern void __VERIFIER_error() __attribute__ ((__noreturn__));

#include <pthread.h>

int i=1, j=1;

void *t1(void* arg)
{
  int k = 0;

  while (k < 6)
  {
    i+=j;
    k = k + 1;
  }
  pthread_exit(NULL);
}

void *t2(void* arg)
{
  int k = 0;

  while (k < 6)
  {
    j+=i;
    k = k + 1;
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv)
{
  pthread_t id1, id2;

  pthread_create(&id1, NULL, t1, NULL);
  pthread_create(&id2, NULL, t2, NULL);

  assert(!(i >= 377 || j >= 377));

  return 0;
}
