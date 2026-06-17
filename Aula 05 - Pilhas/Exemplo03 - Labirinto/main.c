//Tenho um labirinto e quero sair desse labirinto
//Vai colocar na pilha as casas que você já sabe o caminho para ir
//Chamada de Busca por Profundidade ou DFS ou Algoritmo de Backtracking
//Enquanto tiver alguém na pilha --> Vai tirar a casa da pilha e é como se você tivesse na casa 0, 0
//A partir da casa 00 --> Vai olhar os caminhos que você pode seguir e empilhar os caminhos que você descobriu uma direção que pode seguir
//Vai passar para o próximo caminho após a verificação.
//Precisa guardar as casas que você já visitou
//Consequencia de usar a busca em profundidade --> Vai te devolver o primeiro caminho que ele encontrar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
/*
 / Funções Pilha.h
 / pilha criarPilha();
 / void empilhar(pilha P, int x, int y)
 / void desempilhar(pilha P, int *x, int *y);
 / int pilhaVazia(pilha P);
 / void liberarPilha(pilha P);
*/

void resolveLabirinto(int n, char **labirinto);

int main()
{
	int n;
	scanf("%d\n", &n);
	
	char **labirinto;
	labirinto = (char**)malloc(sizeof(char *) * n);
	for(int i = 0; i < n; i++)
	{
	  labirinto[i] = (char *)malloc(sizeof(char) * n); //Vai ler no formato labirinto[x][y] --> Vai ler a coluna 1 como X e a coluna 2 como y
	}
	for(int y = 0; y < n; y++)
	{
	  for(int x = 0; x < n; x++)
	  {
	    scanf("%c", &(labirinto[x][y])); 
	  }
	  scanf("\n");
	}
	for(int y = 0; y < n; y++)
	{
	  for(int x = 0; x < n; x++)
	  {
	    printf("%c", labirinto[x][y]); 
	  }
	  printf("\n");
	}
	
	resolveLabirinto(n, labirinto);
	
	return 0;
}

void resolveLabirinto(int n, char **labirinto)
{
  char **visitado = (char **)malloc(sizeof(char *) *n);
  for(int i = 0; i < n; i++)
  {
    visitado[i] = (char *)malloc(sizeof(char) * n);
    for(int j = 0; j < n; j++)
    {
      visitado[i][j] = '0'; //Matriz que faz a marcação se foi visitado ou não
    }
  }
  
  pilha P = criarPilha(); //Na pilha vao as casas que eu já sei o caminho
  
  empilhar(P, 0, 0);
  visitado[0][0] = 'E'; //'E' = entrar
  
  //Aqui vai tirar alguem da pilha
  while(!pilhaVazia(P)) //Enquanto a pilha não estiver vazia ele vai fazer o laço
  {
    int xAtual;
    int yAtual;
    
    desempilhar(P, &xAtual, &yAtual); //A função empilhar espera receber um endereço de memoria porque são ponteiros
    printf("xAtual = %d, yAtual = %d\n", xAtual, yAtual);
    
    if(labirinto[xAtual][yAtual] == 'S')
    {
      printf("Cheguei na saída\n");
      for(int y = 0; y < n; y++)
      {
        for(int x = 0; x < n; x++)
        {
          printf("%c", visitado[x][y]);
        }
        printf("\n");
      }
      return;
    }
    
    //Descobrindo Novos Caminhos -->  Se é do tamanho do labirinto, não é uma parede e não foi visitado, coloca ele na pilha
    //Tentar ir para o sul
    if(yAtual + 1 < n && labirinto[xAtual][yAtual + 1] != 'X' && visitado[xAtual][yAtual + 1] == '0' /*Significa que ainda não foi visitado*/)
    {
      empilhar(P, xAtual, yAtual+1);
      visitado[xAtual][yAtual+1] = 'C'; //'C' --> Indica que você veio do norte (cima) 
    }
    //Tentar ir para o norte
    if(yAtual - 1 >= 0 && labirinto[xAtual][yAtual-1] != 'X' && visitado[xAtual][yAtual-1] == '0')
    {
      empilhar(P, xAtual, yAtual-1);
      visitado[xAtual][yAtual-1] = 'B'; //'B' --> Indica que você veio do sul (baixo) 
    }
    //Tentar ir para o leste
    if(xAtual + 1 < n && labirinto[xAtual+1][yAtual] != 'X' && visitado[xAtual+1][yAtual] == '0')
    {
      empilhar(P, xAtual+1, yAtual);
      visitado[xAtual+1][yAtual] = 'L'; //'L' --> Indica que você veio do oeste (left - esquerda)
    }
    //Tentar ir para o oeste
    if(xAtual - 1 >= 0 && labirinto[xAtual-1][yAtual] != 'X' && visitado[xAtual-1][yAtual] == '0')
    {
      empilhar(P, xAtual-1, yAtual);
      visitado[xAtual-1][yAtual] = 'R'; //'R' --> Indica que você veio do leste (right - direita) 
    }
  }
  printf("Sem saída\n");
  
  liberarPilha(P);  
  return;
}
