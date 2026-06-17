/*Função de Busca Binaria
 *Busca o valor procurado na metade do vetor
 *Depois busca novamente o elemento na metade do vetor que o elemento está
 *Faz isso até encontrar o elemento
 *Por que mais rápida? A cada iteração da busca binária a gente elimina metade dos valores 
 */
 
#include <stdio.h>
#include <stdlib.h>

/*Obs: em um problema, conseguimos utilizar todas as informações que temos para resolve-lo*/

//Busca do Vetor com uma Função - Não usa as informações do problema
int encontra(int V[], int n, int x);

//Busca do Vetor com uma Função | Usando informação do problema | Encontra x em um vetor ornado crescente
int encontra2(int V[], int n, int x);

//Encontra x nas posições de ini e fim em um vetor ordenado
int buscaBinaria(int *V, int ini, int fim, int x);

int main(int argc, char *argv[])
{
  int V[] = {50, 52, 56, 60, 61, 67, 70, 91}; //Vetor ordenado em ordem crescente
  int x = 52;
  printf("Funcao: encontrou? %d\n", encontra(V, 8, x)); //Função sem recursão
  
  printf("Busca Binaria: encontrou? %d\n", buscaBinaria(V, 0, 7, x)); //Busca Binaria | Com recursão
  return 0;
}

int buscaBinaria(int *V, int ini, int fim, int x)
{
  if(fim < ini)  //Vetor vazio
    return 0;

  int meio = (ini + fim) / 2; printf("Meio = %d\n", meio);
  
  if(V[meio] == x) return 1;
  if(V[meio] > x) return buscaBinaria(V, ini, meio - 1, x); //O(log(n))
  if(V[meio] < x) return buscaBinaria(V, meio + 1, fim, x); //O(log(n))
  
  return 0;
}

int encontra(int V[], int n, int x)
{
  for(int i = 0; i < n; i++)
   if(V[i] == x) return 1;
  return 0;
}

int encontra2(int V[], int n, int x)
{
  for(int i = 0; i < n; i++)
  {
   if(V[i] == x) return 1;
   if(V[i] > x) return 0; //Se o vetor for maior que o elemento, ele retorna 0
  }
  return 0;
}
