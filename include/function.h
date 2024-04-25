#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "main.h"


int name2num(char * name){
  int i=0;
  while (algvet[i].num){
    if (!strcmp(algvet[i].name,name)) return algvet[i].num;
    i++;
  }
  return 0;
}

char * num2name(int num){
  int i=0;
  while (algvet[i].num){
    if (algvet[i].num==num) return algvet[i].name;
    i++;
  }
  return 0;
}

void initVector(int * vet, int size){
// Descricao: inicializa vet com valores aleatorios
// Entrada: vet
// Saida: vet
  int i;
  // inicializa a parte alocada da vetor com valores aleatorios
  for (i=0; i<size; i++){
    vet[i] = (int)(drand48()*size);
  }
}

void printVector(int * vet, int size){
// Descricao: inicializa vet com valores aleatorios
// Entrada: vet
// Saida: vet
  int i;
  for (i=0; i<size; i++){
    printf("%d ",vet[i]);
  }
  printf("\n");
}

void swap(int *xp, int *yp, sortperf_t *s){
    // troca os valores de xp e yp
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    incmove(s,3);
}

// median of 3 integers
int median (int a, int b, int c) {
    if ((a <= b) && (b <= c)) return b;  // a b c
    if ((a <= c) && (c <= b)) return c;  // a c b
    if ((b <= a) && (a <= c)) return a;  // b a c
    if ((b <= c) && (c <= a)) return c;  // b c a
    if ((c <= a) && (a <= b)) return a;  // c a b
    return b;                            // c b a
}


void parse_args(int argc, char ** argv, opt_t * opt)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc, argv, opt
// Saida: opt
{
     // variaveis externas do getopt
     extern char * optarg;
     extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opt->seed = 1;
     opt->size = 10;
     opt->alg = 1;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "z:s:a:h")) != EOF){
       switch(c) {
         case 'z':
	          opt->size = atoi(optarg);
                  break;
         case 's':
	          opt->seed = atoi(optarg);
                  break;
         case 'a':
		  opt->alg = name2num(optarg);
                  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
     }
     if (!opt->alg) {
       uso();
       exit(1);
     }
}

void clkDiff(struct timespec t1, struct timespec t2,
                   struct timespec * res)
// Descricao: calcula a diferenca entre t2 e t1, que e armazenada em res
// Entrada: t1, t2
// Saida: res
{
  if (t2.tv_nsec < t1.tv_nsec){
    // ajuste necessario, utilizando um segundo de tv_sec
    res-> tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
    res-> tv_sec = t2.tv_sec-t1.tv_sec-1;
  } else {
    // nao e necessario ajuste
    res-> tv_nsec = t2.tv_nsec-t1.tv_nsec;
    res-> tv_sec = t2.tv_sec-t1.tv_sec;
  }
}


#endif // FUNCTIONS_H