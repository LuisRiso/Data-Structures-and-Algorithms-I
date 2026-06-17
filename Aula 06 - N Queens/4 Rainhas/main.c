//Problema das N Rainhas
//Há um tabuleiro de xadrez com N linhas e N colunas
//A ideia do tabuleiro é colocar N rainhas de tal forma que nenhuma rainha se ataque
//A ataca da linha, coluna e diagonais dela

//Para esse problema, vamos considerar uma rainha por linha, só tendo que considerar as colunas e diagonais

#include <stdio.h>
#include <stdlib.h>

void imprimirTabuleiro(int r0, int r1, int r2, int r3);

//Neste problema, vamos considerar 4 rainhas para esse problema
//No caso, será o problema das 4 rainhas em uma tabuleiro 3 x 3
int main(int argc, char *argv [])
{
  //Vai testar todas as soluções possiveis para cada uma delas  
  //Quer imprimir todas as soluções possíveis
  int r0, r1, r2, r3; //são as colunas para cada rainha ser colocada
   
   for(r0 = 0; r0 < 4; r0++) 
    for(r1 = 0; r1 < 4; r1++) 
      for(r2 = 0; r2 < 4; r2++) 
        for(r3 = 0; r3 < 4; r3++)
        {
          //Verificar se a solução é viável
          //Verificar se alguma está se atacando porque está na mesma colucana
          if(r0 == r1 || r0 == r2 || r0 == r3 || r1 == r2 || r1 == r3 || r2 == r3)
            continue; // vai para próxima iteração do looping mais próximo
          //Verificar se alguma está se atacando porque está na diagonal
          //Entre 0 e 1
          if(r0 == r1 - 1 || r0 == r1 + 1)
            continue;
          //Entre 0 e 2
          if(r0 == r2 - 2 || r0 == r2 + 2)
            continue;
          //Entre 0 e 3
          if(r0 == r3 - 3 || r0 == r3 + 3)
            continue;
          //Entre 1 e 2
          if(r1 == r2 - 1 || r1 == r2 + 1)
            continue;
          //Entre 1 e 3
          if(r1 == r3 - 2 || r1 == r3 + 2)
            continue;
          //Entre 2 e 3
          if(r2 == r3 - 1 || r2 == r3 + 1)
            continue;
          imprimirTabuleiro(r0, r1, r2, r3);
          printf("----------------\n");
        }
  
  return 0;
}

void imprimirTabuleiro(int r0, int r1, int r2, int r3)
{
  for(int i = 0; i < 4; i++)
  {
    printf("| ");
    if(r0 == i)
      printf("R ");
    else
      printf("0 ");
  }
  printf("\n");
  for(int i = 0; i < 4; i++)
  {
    printf("| ");
    if(r1 == i)
      printf("R ");
    else
      printf("0 ");
  }
  printf("\n");
  for(int i = 0; i < 4; i++)
  {
    printf("| ");
    if(r2 == i)
      printf("R ");
    else
      printf("0 ");
  }
  printf("\n");
  for(int i = 0; i < 4; i++)
  {
    printf("| ");
    if(r3 == i)
      printf("R ");
    else
      printf("0 ");
  }
  printf("\n");
  
}
