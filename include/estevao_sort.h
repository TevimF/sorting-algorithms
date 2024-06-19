#ifndef ESTEVAO_SORT_H
#define ESTEVAO_SORT_H

#include "main.h"
#include "function.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include "bubble_sort.h"
#include "merge_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "bucket_sort.h"

void initVectorOrd(int * vet, int size){
  int i;
  // inicializa a parte alocada da vetor com valores ordenados
  for (i=0; i<size; i++){
    vet[i] = i;
  }
}
void initVectorInversamenteOrd(int * vet, int size){
  int i;
  // incializa a parte alocada do vetor com valores ordenados de forma inversa
  for (i=0; i<size; i++){
    vet[i] = size-i;
  }
}
// teste de ordenaçaõ dos algoritmos

void estevao_sort(int * vet, int begin, int end, sortperf_t * s) {
  int size = end - begin + 1;
  //selection sort

  /*
  

  printf("\n vetor já ordenado");
  initVectorOrd(vet, size);
  */

  
  
  printf("\n vetor inversamente ordenado");
  initVectorInversamenteOrd(vet, size);
  
  printf("\n buble \n");
  bubbleSort(vet, begin, end, s);

  
  /*
  selectionSort(vet, begin, end, s);
  insertionSort(vet, begin, end, s);
  quickSort(vet, begin, end, s);
  shellSort(vet, size, s);
  bubbleSort(vet, begin, end, s);
  mergeSort(vet, begin, end, s);
  countingSort(vet, begin, end, s);
  radixSort(vet, begin, end, s);
  bucketSort(vet, begin, end, s);
  */

}

#endif // ESTEVAO_SORT_H
