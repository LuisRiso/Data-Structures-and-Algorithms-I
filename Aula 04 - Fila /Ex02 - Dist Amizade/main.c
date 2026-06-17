#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void distancias(int ** M, char **nomes, int n, int ini)
{
  int *dist = (int *)malloc(sizeof(int)*n); //Definindo o tamanho do vetor com base no maior caminho possível, no caso n
  for(int i = 0; i < n; i++)
  {
    dist[i] = n; //pode ser infinito
  }
  dist[ini] = 0;
  
  fila f = criarFila();
  inserirFila(f, ini);
  
  while(!filaVazia(f))
  {
    int atual = removerFila(f);
    for(int j = 0; j < n; j++)
    {
      if(M[atual][j] == 1 && dist[j] == n) //Significa que acabou de descobrir um caminho novo para o j
      {
        inserirFila(f, j); //acabou de descobrir a distancia dele
        dist[j] = dist[atual] + 1; //é a distancia do atual que eu acabei de remover da fila + 1
      }
    }
  }
  for(int i = 0; i < n; i++)
  {
    printf("%s dist %d\n", nomes[i], dist[i]);
  }
  printf("\n");
  //Liberar memória
  liberarFila(f);
  free(dist);
}

int main(int argc, char* argv[])
{
  int ** M;
  char **nomes;
  int n = 0;
  char ch;
  
  //contando o numero de pessoas
  while ((ch = getchar()) != '\n') {
     if (ch == ',') {
        n++;  
     }
  }
  
  //alocando memoria
  M = (int**) malloc(n * sizeof(int*));
  nomes = (char**) malloc(n * sizeof(char*));
  for(int i = 0; i < n; i++){
    M[i] = (int*) malloc(n * sizeof(int));
    nomes[i] = (char*) malloc(50 * sizeof(char));
  }

  //lendo a matriz
  for(int i = 0; i < n; i++){
    int length = 0;
    
    //ler ate a virgula
    while ((ch = getchar()) != ',' && length < 49) { 
        nomes[i][length] = ch;  
        length++;
    }
    nomes[i][length] = '\0';  
    //printf("%s = ", nomes[i]);
    for(int j = 0; j < n; j++){
      scanf("%d,", &(M[i][j]));
      //printf("%d, ", M[i][j]);
    }
    scanf("\n");
    //printf("\n");
  }
  
  //calcular as distancias
  distancias(M, nomes, n, 0); //Alterar o ultimo valor para buscar

  //liberar a memoria
  for(int i = 0; i < n; i++){
    free(nomes[i]);
    free(M[i]);
  }
  free(nomes);
  free(M);
  
  return 0;
}

