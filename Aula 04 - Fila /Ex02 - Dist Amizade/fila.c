//Como complicar | gcc -pedantic-errors -Wall -c fila.c -o fila.o

//Problema de implementação de fila em um vetor --> se ultrapassar o limite do vetor a minha fila para de funcionar
//Como contornar?
//Fazer uma implementação circular

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
  f->valores = (int *)malloc(sizeof(int) * MAX_CAPACITY); //f de valores é um apontador que aponta para o vetor 
  f->ini = 0; //f de ini agora é um apontador que tem o campo ini
  f->fim = 0; //f de fim agora é um apontador que tem o campo ini
  return f;
}

void inserirFila(fila f, int v)
{
  if(f->fim == MAX_CAPACITY)
  {
    printf("Erro: fila cheia\n");
    return;
  }
  f->valores[f->fim] = v;
  f->fim++;
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
