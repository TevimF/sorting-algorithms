#ifndef ESTEVAO_SORT_H
#define ESTEVAO_SORT_H

#include "main.h"
#include "function.h"
#include "insertion_sort.h"
#include "shell_sort.h"
#include "bucket_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"

void estevao_sort(int * vet, int begin, int end, sortperf_t * s) {
  int size = end - begin + 1; 
  int *v = vet + begin; 

  if (size < 50) {
    insertionSort(v, 0, size - 1, s); 
  } else if (size < 100) {
    shellSort(v, size, s);
  } else if (size < 1000) {
    bucketSort(v, begin, end, s);
  } else {
    quickSort3(v, 0, size - 1, s); 
  }
}

#endif // ESTEVAO_SORT_H
