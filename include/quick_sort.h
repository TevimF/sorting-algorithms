#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "main.h"
#include "function.h"

// quicksort partition using median of 3
void partition3(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
}

// standard quicksort partition
void partition(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
}

// standard quicksort
void quickSort(int * A, int l, int r, sortperf_t *s) { 
}

// quicksort with median of 3
void quickSort3(int * A, int l, int r, sortperf_t *s) { 
}

// quicksort with insertion for small partitions
void quickSortIns(int * A, int l, int r, sortperf_t *s) { 
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int * A, int l, int r, sortperf_t *s) { 
}

#endif // QUICK_SORT_H