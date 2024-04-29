// classificação de shell
#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "main.h"
#include "function.h"

void shellSort(int *A, int n, sortperf_t * s) { 
  // n = tamanho do vetor
  inccalls(s, 1);
  for (int gap = n/ 2; gap > 0; gap /= 2) {
    // Faz a ordenação por inserção para cada gap
    for (int i = gap; i < n; i++) {
      incmove(s, 1);
      int aux = A[i];
      int j;
      
      inccmp(s, 1);
      for (j = i; j >= gap && A[j - gap] > aux; j -= gap) {
        inccmp(s, 1);
        if (A[j - gap] <= aux) {
          break;
        }
        // Se o elemento for menor que o aux, sai do loop

        incmove(s, 1);
        A[j] = A[j - gap];
      }
      incmove(s, 1);
      A[j] = aux;
    }      
  }
}

#endif // SHELL_SORT_H
