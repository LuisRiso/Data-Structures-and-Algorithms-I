//Como complicar | gcc -pedantic-errors -Wall -c fila.c -o fila.o

//Fazer uma implementação circular 
//  Quando chega ao fim o valor do fim volta ao valor do inicio
//  Nesse exemplo: quando o fim chega no fim do MAX_CAPACITY o valor de fim volta para o 0

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX_CAPACITY 2500

struct filaPonteiro
{
  int ini;
  int fim;
  int *valores;
};

fila criarFila()
{
  fila f = (fila)malloc(sizeof(struct filaPonteiro)); //fila já é um apontador
  f->valores = (int*)malloc(sizeof(int) * MAX_CAPACITY); //f de valores é um apontador que aponta para o vetor 
  f->ini = 0; //f de ini agora é um apontador que tem o campo ini
  f->fim = 0; //f de fim agora é um apontador que tem o campo ini
  return f;
}

void inserirFila(fila f, int v)
{
  if((f->fim + 1) % MAX_CAPACITY == f->ini) //O Módulo vai fazer que quando chegar em no valor máximo do MAX_CAPCITY o módulo devolve 0
  {                                         //A última posição da fila passa agora a representar a diferença de uma fila vazia e uma fila cheia
    printf("Erro: fila cheia\n");
    return;
  }
  f->valores[f->fim] = v;
  f->fim++;
  if(f->fim == MAX_CAPACITY) //Quando chegar ao final do MAX_CAPACITY --> Ele retorna a 0
    f->fim = 0;
  return;
}


int removerFila(fila f)
{
  if(f->ini == f->fim)
  {
    printf("Erro: fila vazia\n");
    return -1;
  }
  int v = f->valores[f->ini];
  f->ini++;
  if(f->ini == MAX_CAPACITY)
    f->ini = 0;
  return v;
}

void liberarFila(fila f)
{
  free(f->valores);
  free(f);
  return;
}

//A fila é vazia quando é o inicio e o fim apontam para o mesmo bloco de memória
int filaVazia(fila f)
{
  if(f->ini == f->fim)
    return 1;
  else
    return 0;
}
