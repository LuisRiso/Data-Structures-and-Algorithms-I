//Obs: todo algoritmo recursivo tem um algoritmo não recursivo dele
//Na pilha --> quando tiver que fazer uma decisão, você empilhar essas decisões
//Mesma idea da busca do labirinto
//Se preocupar: imprimir na mesma ordem que a recursão imprime
//Obrigatoriamente: usar a função de pilha fornecida pelo Hokama
//Precisa decidir como vai armazenar os dados
#include <stdio.h>
#include <stdlib.h>

void solve(int n, int *r, int atual); // n = numero de rainhas, r = posição da rainha, atual = rainha atual 
void imprimeTabuleiro(int n, int *r);

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  
  int *r = (int *)malloc(n * sizeof(int));
  
  solve(n, r, 0); //--> decide aonde tem que colocar a rainha zero e depois vai ocorrer de forma recursiva
  
  return 0;
}

void solve(int n, int *r, int atual)
{
  if(atual == n)
  {
    imprimeTabuleiro(n, r);
    printf("\n");
    return;
  }
  //x --> posição que vou tentar colocar a rainha 
  //looping para chegagem
  for(int x = 0; x < n; x++) //você só precisa se preocupar com as rainhas que já foram decididas
  {
    //verificar se as rainhas anteriores não estão atacando x
    int viavel = 1; //flag para verificação
    for(int j = 0; j < atual; j++) //looping para verificar as rainhas já decididas
    {
      //Posição X --> posição que a rainha atual vai entrar
      //Posição J --> posição de verificação sempre menor que X e atual
      
      int dist = atual - j; //distancia da rainha de cima e da rainha atual
                            //r[j] = posição das rainhas já armazenas nas linhas do tabileiro
      if(r[j] == x || abs(r[j] - x) == dist || abs(x - r[j]) == dist) //verifica se está na mesma coluna ou nas diagonais
      {
        viavel = 0;
        break;
      } 
    }
    if(viavel == 1)
    {
      r[atual] = x; //atual foi decidida, está em X
      solve(n, r, atual+1);
    }
  }
  return;
}

void imprimeTabuleiro(int n, int *r)
{
  for(int y = 0; y < n; y++)
  {
    for(int x = 0; x < n; x++)
    {
      if(r[y] == x) printf("R "); //se tiver uma rainha
      else printf("_ "); //se não tiver uma rainha
    }
    printf("\n");
  }
}
