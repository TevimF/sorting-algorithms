#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "main.h"
#include "function.h"

// quicksort partition using median of 3
void partition3(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
   inccalls(s, 1);

  *i = l; // o ponteiro i vai apontar para o inicio do vetor
  *j = r; // j aponta para o ultimo elemento

  int pivo = median(A[l], A[(*i+*j)/2], A[r]); // ultimo elemento vai ser o pivo

  do{ // vai passando de posicao em posicao
    while(A[*j] > pivo) {
      inccmp(s, 1);
      (*j)--;  
    }
    while(A[*i] < pivo){
      inccmp(s, 1);
      (*i)++;
    }
    inccmp(s, 2);
    if (*j >= *i ){
      swap(&A[*i], &A[*j], s);
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

// standard quicksort partition
void partition(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
  inccalls(s, 1);

  *i = l; // o ponteiro i vai apontar para o inicio do vetor
  *j = r; // j aponta para o ultimo elemento

  int pivo = A[(*i+*j)/2]; // ultimo elemento vai ser o pivo

  do{ // vai passando de posicao em posicao
    while(A[*j] > pivo) {
      inccmp(s, 1);
      (*j)--;  
    }
    while(A[*i] < pivo){
      inccmp(s, 1);
      (*i)++;
    }
    inccmp(s, 2);
    if (*j >= *i ){
      swap(&A[*i], &A[*j], s);
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

// standard quicksort
void quickSort(int * A, int l, int r, sortperf_t *s) { 
  inccalls(s, 1);

  int inicio, fim;

  partition(A, l, r, &inicio, &fim, s);
  // vai devolver o inicio e o fim do vetor particionado
  if (l < fim){
    quickSort(A, l, fim, s);
    // vai chamar a funcao quicksort para a primeira metade do vetor
  }
  if (inicio < r){
    quickSort(A, inicio, r, s);
    // vai chamar a funcao quicksort para a segunda metade do vetor
  }
}

// quicksort with median of 3
void quickSort3(int * A, int l, int r, sortperf_t *s) { 
  inccalls(s, 1);

  int inicio, fim;

  partition3(A, l, r, &inicio, &fim, s);
  // vai devolver o inicio e o fim do vetor particionado
  if (l < fim){
    quickSort3(A, l, fim, s);
    // vai chamar a funcao quicksort para a primeira metade do vetor
  }
  if (inicio < r){
    quickSort3(A, inicio, r, s);
    // vai chamar a funcao quicksort para a segunda metade do vetor
  }
}

// quicksort with insertion for small partitions
void quickSortIns(int * A, int l, int r, sortperf_t *s) { 
  inccalls(s, 1);

  int inicio, fim;

  partition(A, l, r, &inicio, &fim, s);
  // vai devolver o inicio e o fim do vetor particionado
  if (l < fim){
    if (fim - l > 50){
        quickSortIns(A, l, fim, s);
    }
    else{
        insertionSort(A, l, fim, s);
    }
  }

  if (inicio < r){
    if (r - inicio > 50){
        quickSortIns(A, inicio, r, s);
    }
    else{
        insertionSort(A, inicio, r, s);
    }
  }
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int * A, int l, int r, sortperf_t *s) { 
  inccalls(s, 1);

  int inicio, fim;

  partition3(A, l, r, &inicio, &fim, s);
  // vai devolver o inicio e o fim do vetor particionado
  if (l < fim){
    if (fim - l > 50){ // para particoes menores que 50, chama o insertion sort
        quickSort3Ins(A, l, fim, s);
    }
    else{
        insertionSort(A, l, fim, s);
    }
  }

  if (inicio < r){
    if (r - inicio > 50){
        quickSort3Ins(A, inicio, r, s);
    }
    else{
        insertionSort(A, inicio, r, s);
    }
  }
}

#endif // QUICK_SORT_H