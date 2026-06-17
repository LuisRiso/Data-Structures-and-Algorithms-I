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
  fila f = (fila)malloc(sizeof(struct filaPonteiro));
  //fila já é um apontador
  //f já é um ponteiro para uma estrutura filaPonteiro, e você pode alocar memória diretamente
  //Definido em fila.h -> typedef struct filaPonteiro * fila;
  //(fila) -> fila é automaticamente um ponteiro para struct filaPonteiro
  //(fila) como uma redundância: O (fila) antes do malloc é uma conversão de tipo (typecast), 
  //que transforma o ponteiro retornado por malloc (que é do tipo void *) para o tipo fila. 
  
  //A razão pela qual usamos sizeof(struct filaPonteiro) em vez de sizeof(fila) 
  //está no fato de que fila é definido como um ponteiro para a estrutura struct filaPonteiro. 
  //Quando usamos sizeof(fila), o compilador retorna o tamanho de um ponteiro, não o tamanho da estrutura.
  
  //sizeof(struct filaPonteiro) retorna o tamanho da estrutura completa, 
  //ou seja, o espaço necessário para armazenar todos os seus membros (ini, fim, valores), 
  //que é o que queremos alocar na função criarFila.

  //sizeof(fila) retorna o tamanho de um ponteiro para a estrutura, e não o tamanho da estrutura em si. 
  //Esse valor representa apenas o espaço necessário para armazenar o endereço de memória, normalmente 4 ou 8 bytes, 
  //e seria insuficiente para alocar a estrutura inteira.
  
  //Esse malloc cria um espaço para a estrutura filaPonteiro e retorna um ponteiro para ele, que é atribuído a f. 
  //Como f já é um ponteiro para a estrutura, todas as operações de acesso aos membros, 
  //como f->valores, f->ini, e f->fim, usam a sintaxe de ponteiro (->) para acessar os campos.
  
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
