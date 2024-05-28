#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "main.h"
#include "function.h"

//insertion sort
void insertionSort(int v[], int l, int r, sortperf_t * s) {
  inccalls(s,1); // incrementa o numero de chamadas de funcao

  for (int i = l+1; i <= r; i++) {
    inccmp(s,1); // incrementa o numero de comparacoes

    int chave = v[i];
    incmove(s,1); // incrementa o numero de movimentacoes
    int anterior = i-1;

    while (anterior >= l && v[anterior] > chave) {
      inccmp(s,1); 

      v[anterior+1] = v[anterior];
      incmove(s,1);
      anterior--;
    }
    incmove(s,1);
    v[anterior+1] = chave;
  }
  return;
}

#endif // INSERTION_SORT_H