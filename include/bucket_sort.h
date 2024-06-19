#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include "main.h"
#include "function.h"
#define MAX 1000

void bucketSort(int * vet, int begin, int end, sortperf_t * s){
  int baldes[MAX];
  for (int i = 0; i < MAX; i++){
    baldes[i] = 0;
  }
  for (int i = begin; i <= end; i++){
    baldes[vet[i]]++;
  }
  for (int i = 0; i < MAX; i++) {
        int tamanhoBalde = baldes[i];
        for (int j = 1; j < tamanhoBalde; j++) {
            int atual = vet[i + j];
            int indice = j - 1;

            while (indice >= 0 && vet[i + indice] > atual) {
                vet[i + indice + 1] = vet[i + indice];
                indice--;
            }

            vet[i + indice + 1] = atual;
        }
    }
}

#endif // BUCKET_SORT_H