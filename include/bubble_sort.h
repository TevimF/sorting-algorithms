#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "main.h"
#include "function.h"

void bubbleSort(int * vet, int left, int right, sortperf_t * s){
  inccalls(s,1);
  bool flag = true;
  int tamanho = right - left + 1;
  while(flag){
    flag = false;
    for(int i = 0; i < tamanho - 1; i++){
      if(vet[i] > vet[i+1]){
        inccmp(s,1);
        swap(&vet[i], &vet[i+1], s);
        flag = true;
      }
    }
  }
  return;
}


#endif // BUBBLE_SORT_H