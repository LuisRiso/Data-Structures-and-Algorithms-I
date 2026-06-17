//Como complicar | gcc -pedantic-errors -Wall -c main.c -o main.o
//Como complicar | gcc -pedantic-errors -Wall main.o fila.o -o exerc | Link o meu main com o programa que eu quero rodar junto

#include <stdio.h>
#include <stdlib.h>
#include "fila.h" //implementação de um diretório implementado por alguém

//Conteudo Tratado
//Fila e TAD (Tipos Abstratos de Dados)
//Fila --> FIFO --> First-in First-out
//Fila é um tipo abstrato de dados

//argc --> conta os argumentos/parametros passados para o programa
//argv --> armazena os valores dos argumentos/parametros
int main(int argc, char *argv[])
{
  fila f = criarFila();
  inserirFila(f, 10);
  inserirFila(f, 20);
  inserirFila(f, 30);
  inserirFila(f, 40);
  int aux = removerFila(f);
  printf("%d\n", aux);
  inserirFila(f, 10);
  inserirFila(f, 5);
  aux = removerFila(f);
  printf("%d\n", aux);
  liberarFila(f);
  
  return 0;
}
