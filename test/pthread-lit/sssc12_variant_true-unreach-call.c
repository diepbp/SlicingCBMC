// Source: Alejandro Sanchez, Sriram Sankaranarayanan, Cesar Sanchez, Bor-Yuh
// Evan Chang: "Invariant Generation for Paramterized Systems using
// Self-Reflection", SAS 2012

#include <pthread.h>
#include "assert.h"

int *data;
volatile int len;
volatile int next;
volatile int lock;

void __VERIFIER_atomic_acquire() {
    __VERIFIER_assume(lock == 0);
    lock = 1;
}

void __VERIFIER_atomic_release() {
    __VERIFIER_assume(lock == 1);
    lock = 0;
}

void* thr(void* arg) {
    int c, end;
    c = 0;
    end = 0;
    __VERIFIER_atomic_acquire();
    if (next + 10 <= len) {
	c = next;
	next = end = next + 10;
    }
    __VERIFIER_atomic_release();
    while (c < end) {
	data[c] = 0;
	data[c] = 1;
	__VERIFIER_assert(data[c] == 1);
	c = c + 1;
    }
}

void main(int argc, char* argv[]) {
    pthread_t t;
    pthread_mutex_init(&lock, 0);
    next = 0;
    len = __VERIFIER_nondet_int();
    __VERIFIER_assume(len > 0);
    malloc(sizeof(int) * len, 0, data);
    while(1) {
	pthread_create(&t, 0, thr, 0);
    }
}