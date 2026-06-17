#include <stdio.h>
#include <stdlib.h>
// -------------------------------------------------------------------------------------------------
/* 
 * Recursão | Recursividade
 * Técnica de Projeto e Análise de Algoritmos
 * Para tentar resolver um problema, vamos atrás de fazer subproblemas menores
 * Diminuir um problema grande em problemas menores
 * Obs: toda recursão tem um algoritmo similar que não é recursivo
 */
// -------------------------------------------------------------------------------------------------
 /*
  * Situação em que a recursão é um problema
  * Fibonnaci: começa em 0 e 1 e proximo elemento é a soma dos anteriores
  * Definição: fib(n) = fib(n-1) + fib(n-2)
  * Problema: em vários momentos da recursão o programa vai estar resolvendo o problema várias vezes
  * Nesse caso: a recursão vai tornar o problema muito mais lento do que seu igual sem recursão
 */
// -------------------------------------------------------------------------------------------------
// Tipo: unsigned -> usado para ter somentes valores positivos
// Unsigned -> Libera o Bit destinado para definir se o valor é + ou -
// -------------------------------------------------------------------------------------------------
long unsigned int fatorial(long unsigned int n);

int main(int argc, char *argv[])
{
  printf("5! = %ld\n", fatorial(5));
  printf("10! = %ld\n", fatorial(10));
  return 0;
}

long unsigned int fatorial(long unsigned int n)
{
  if(n == 0)
    return 1;
  return n * fatorial(n-1);
}


