#include <stdio.h>
#include <stdlib.h>

int somaPositivos(int *V, int n);
int somaPos(int *V, int n);

int main(int argc, char *argv[])
{
  int V[] = {5, -5, -10, 0, 10};
  
  printf("%d\n", somaPositivos(V, 5));
  printf("%d\n", somaPos(V, 5));

  return 0;
}

int somaPositivos(int *V, int n)
{
  if(n == 0)
    return 0;
  
  int problemaOriginal;
  //Somando do fim para o inicio
  int atual = V[n-1]; //V[0] = *V  
  int subProblema = somaPositivos(V, n-1); //mantem o tamanho do vetor original
  
  /* Jeito Hokama -> Somando do inicio ao fim
  int atual = V[0]; //V[0] = *V  
  int subProblema = somaPositivos(++V, n-1); 
    *| Com ++V passa o vetor para a recursão sem o valor atual e diminui o tamanho do vetor em -1 
    *| V++ -> usa e depois soma
    *| ++V -> soma depois ele usa
  */
  
  if(atual  > 0) //o elemento atual é positivo
    problemaOriginal = atual + subProblema;
  else //o alemento atual é negativo
    problemaOriginal = subProblema;
      
  return problemaOriginal;
}

//Jeito Compacto
int somaPos(int *V, int n)
{
  if(n == 0) return 0;
  if(V[n-1] > 0) return V[n-1] + somaPos(V, n-1);
  else return somaPos(V, n-1);
}
