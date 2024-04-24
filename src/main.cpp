//---------------------------------------------------------------------
// Arquivo      : evalenum.c
// Conteudo     : avaliacao de desempenho de algoritmos de ordenacao 
// Autor        : Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico    : 2023-11-04 - arquivo criado
//---------------------------------------------------------------------

#include <stdio.h>
#include "../include/main.h"
#include "../include/struct.h"
#include "../include/function.h"
#include "../include/selection_sort.h"
#include "../include/insertion_sort.h"
#include "../include/quick_sort.h"
#include "../include/shell_sort.h"

int main (int argc, char ** argv){
  sortperf_t s;
  int * vet;
  char buf[200];
  char pref[100];
  opt_t opt;
  struct timespec inittp, endtp, restp;
  int retp;

  // parse_args
  parse_args(argc,argv,&opt);

  // malloc with opt.size+1 for heapsort
  vet = (int *) malloc((opt.size+1)*sizeof(int));

  // initialize
  resetcounter(&s);
  srand48(opt.seed);
  initVector(vet, opt.size);
  vet[opt.size] = vet[0]; // for heapsort
  //if (opt.size < 100) printVector(vet, opt.size);

  retp = clock_gettime(CLOCK_MONOTONIC, &inittp);
  
  // execute algorithm
  switch (opt.alg){
    case ALGINSERTION:
         insertionSort(vet, 0, opt.size-1, &s);
         //opt.size é o tamanho do vetor
         break;
    case ALGSELECTION:
         selectionSort(vet, 0, opt.size-1, &s);
         break;
    case ALGQSORT:
         quickSort(vet, 0, opt.size-1, &s);
         break;
    case ALGQSORT3:
         quickSort3(vet, 0, opt.size-1, &s);
         break;
    case ALGQSORTINS:
         quickSortIns(vet, 0, opt.size-1, &s);
         break;
    case ALGQSORT3INS:
         quickSort3Ins(vet, 0, opt.size-1, &s);
         break;
    case ALGSHELLSORT:
         shellSort(vet, opt.size, &s);
         break;
    case ALGRECSEL:
         recursiveSelectionSort(vet, 0, opt.size-1, &s);
         break;
  }
  retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
  clkDiff(inittp, endtp, &restp);


  //if (opt.size<100) printVector(vet, opt.size);

  // print stats
  sprintf(pref,"alg %s seed %d size %d time %ld.%.9ld",
          num2name(opt.alg), opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

  printsortperf(&s,buf,pref);
  printf("%s\n",buf);

  exit(0);
}