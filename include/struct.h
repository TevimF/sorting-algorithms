// sortperf.h
#ifndef STRUCT_H
#define STRUCT_H

typedef struct opt{
  int size;
  int seed;
  int alg;
} opt_t;

typedef struct sortperf{
  int cmp;
  int move;
  int calls;
} sortperf_t;

#endif // SORTPERF_H