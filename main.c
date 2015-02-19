#include <stdio.h>
#include "pqsort/pqsort.h"

int int_sort(const void* a, const void* b){
     if(*(int*)a < *(int*)b){
          return -1;
     }
     else if(*(int*)a == *(int*)b){
          return 0;
     }
     return 1;
};

// ===================================================================
int main(int argc, char** argv){
     int i, num;
     int* data;
     num = 10000000;

     data = (int*)malloc(sizeof(int)*num);

     // data generation
     srand((unsigned int)time(NULL));
     for(i=0;i<num;i++){
          data[i] = rand()%RAND_MAX;
     }

     // parallel sorting
     pqsort(data, num, sizeof(int), int_sort);
     // qsort(data, num, sizeof(int), int_sort);

     // validateion
     for(i=1;i<num;i++){
          if(data[i-1] > data[i]){
               printf("[%d](%x) [%d](%x)\n", i-1, data[i-1], i, data[i]);
          }
     }

     return 0;
};
// ===================================================================
