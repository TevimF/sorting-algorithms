#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "main.h"
#include "function.h"
#define MAX 1000

void countingSort(int * vet, int left, int right, sortperf_t * s){
  int baldes[MAX];
  for (int i = 0; i < MAX; i++){
    baldes[i] = 0;
  }
  for (int i = left; i <= right; i++){
    baldes[vet[i]]++;
  }
  for (int i = 0, j = 0; j < MAX; j++){
    for (int k = 0; k < baldes[j]; k++){
      vet[i++] = j;
      incmove(s,1);
    }
  }
}

#endif // COUNTING_SORT_H