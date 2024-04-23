#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "struct.h"
#include "functions.h"
#include "insertion_sort.h"

//insertion sort
void insertionSort(int v[], int l, int r, sortperf_t * s) {
  // v é o vetor a ser ordenado
  // l é o indice do primeiro elemento
  // r é o indice do ultimo elemento
  // s é a estrutura de estatisticas
  int size = r - l + 1; // tamanho do vetor

  for (int indice_comparado= l+1 ; indice_comparado < size; indice_comparado++){ 
    // começa do segundo porque o primeiro automaticamente nao se enquadra

    int chave = v[indice_comparado]; 
    // a chave recebe o valor a ser inserido pelo indice comparado
    
    inccalls(s,1); // incrementa o numero de chamadas de funcao
    int termo_anterior = indice_comparado - 1;
    while (chave > 0 && v[termo_anterior] > chave){
      swap(&chave, &v[termo_anterior], s); // troca a chave com o elemento anterior se for maior
      inccmp(s,2); 
      // incrementa o numero de comparacoes (duas: maior que zero e maior que a chave)
    }
  }
  return;
}

#endif // INSERTION_SORT_H