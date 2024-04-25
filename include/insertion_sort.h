#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "main.h"
#include "function.h"
#include "insertion_sort.h"

//insertion sort
void insertionSort(int v[], int l, int r, sortperf_t * s) {
  // v é o vetor a ser ordenado
  // l é o indice do primeiro elemento
  // r é o indice do ultimo elemento
  // s é a estrutura de estatisticas
  int size = r - l + 1; // tamanho do vetor
  inccalls(s,1); // incrementa o numero de chamadas de funcao
  for (int indice_comparado= l+1 ; indice_comparado < size; indice_comparado++){ 
    // começa do segundo porque o primeiro automaticamente nao se enquadra
    while ((indice_comparado - 1) >= 1 && v[(indice_comparado - 1)] > v[indice_comparado]){
      swap(&v[indice_comparado], &v[indice_comparado - 1], s); // troca a chave com o elemento anterior se for maior
      inccmp(s,1); 
    }
  }
  return;
}

#endif // INSERTION_SORT_H