#ifndef PQSORT_H
#define PQSORT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<pthread.h>
#include<omp.h>

typedef struct _qsort_args{
     void*  base;
     int    num;
     size_t bsize;
     int (*compare)(const void*, const void*);
}qsort_args;

void merge(void *base1, int bnum1,
           void *base2, int bnum2, size_t bsize,
           int (*compare)(const void*, const void*));

void pqsort(void *base, int num, size_t bsize,
            int (*compare)(const void*, const void*));

pthread_t pqsort_thread(qsort_args* pqs_args);

#endif
