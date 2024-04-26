#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "main.h"
#include "function.h"

// recursive selection sort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t * s)
{
    // find the minimum element in the unsorted subarray `[i…n-1]`
    // and swap it with `arr[i]`
    int min = l;
    inccalls(s,1);
    for (int j = l + 1; j <= r; j++)
    {
        // if `arr[j]` is less, then it is the new minimum
	inccmp(s,1);
        if (arr[j] < arr[min]) {
            min = j;    // update the index of minimum element
        }
    }

    // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
    if (min!=l)
      swap(&arr[min], &arr[l], s);

    if (l + 1 < r) {
        recursiveSelectionSort(arr, l + 1, r, s);
    }
}

// selection sort
void selectionSort(int arr[], int l, int r, sortperf_t * s) {
  // arr é o vetor a ser ordenado
  // l é o indice do primeiro elemento
  // r é o indice do ultimo elemento
  // s é a estrutura de estatisticas
  inccalls(s,1); // chamou uma vez
  int andamento = l;
  for (int i = l; i <= r; i++){
    int menor = i;
    //printf("menor é: %d\n", arr[menor]);

    for (int indice = i+1; indice <= r; indice++){
      inccmp(s, 1);

      // loop para encontrar o menor elemento
      if (arr[indice] < arr[menor]){
        menor = indice;
        //printf("menor agora é: %d\n", arr[menor]);
      }
    }
    if (menor != i){
      swap(&arr[menor], &arr[andamento], s);
      //printf("trocando %d com %d\n", arr[menor], arr[andamento]);
      //printVector(arr, r);
    }
    
    andamento++;
    //printf("andamento: %d\n", andamento);
  } 
  return;
}

#endif // SELECTION_SORT_H