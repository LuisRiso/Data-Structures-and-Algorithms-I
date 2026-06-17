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
  int *V;
  int tamanho = 100;
  
  V = (int *)malloc(sizeof(int)*tamanho);
  
  for(int i = 0; i < tamanho; i++)
    V[i] = 2*i;
  
  //testando a velocidade para encontrar um valor em O(log(n))
  srand(1000);
  for(int i = 0; i < tamanho; i++)
    buscaBinaria(V, 0, tamanho-1, rand()%1001);
    
  return 0;
}

int buscaBinaria(int *V, int ini, int fim, int x)
{
  if(fim < ini) //Vetor vazio
    return 0;

  int meio = (ini + fim) / 2; 
  
  if(V[meio] == x) { printf("V encontrou %d\n", V[meio]); return 1; }
  if(V[meio] > x)  { printf("V maior\n"); return buscaBinaria(V, ini, meio - 1, x); } //O(log(n))}
  if(V[meio] < x)  { printf("V menor\n"); return buscaBinaria(V, meio + 1, fim, x); }//O(log(n))
  
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


