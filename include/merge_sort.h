#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "main.h"
#include "function.h"

void merge(int * vet, int inicio, int meio, int fim, sortperf_t * s){
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = false;
  int fim2 = false;
  tamanho = fim - inicio + 1;
  p1 = inicio;
  p2 = meio + 1;
  // aloca vetor temporário
  temp = (int *) malloc(tamanho*sizeof(int));
  if(temp != NULL){
    for(i = 0; i < tamanho; i++){
      if(!fim1 && !fim2){
        if(vet[p1] < vet[p2]){
          temp[i] = vet[p1++];
        }else{
          temp[i] = vet[p2++];
        }
        inccmp(s,1);
        inccmp(s,1);
        // verifica se chegou ao final de um dos vetores
        if(p1 > meio) fim1 = true;
        if(p2 > fim) fim2 = true;
      }else{
        // copia o que sobrou
        if(!fim1){
          temp[i] = vet[p1++];
        }else{
          temp[i] = vet[p2++];
        }
      }
    }
    // copia o vetor temporário para o vetor original
    for(j = 0, k = inicio; j < tamanho; j++, k++){
      vet[k] = temp[j];
      incmove(s,1);
    }
  }
}

void mergeSort(int * vet, int left, int right, sortperf_t * s){
  inccalls(s,1);
  if (left < right){
    int meio = (left + right) / 2;
    mergeSort(vet, left, meio, s);
    mergeSort(vet, meio + 1, right, s);
    merge(vet, left, meio, right, s);
  }
}

#endif // MERGE_SORT_H