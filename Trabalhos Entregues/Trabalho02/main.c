//O problema das N-Rainhas: 
//Colocar um número N de rainhas em um tabuleiro NxN de forma que elas não se ataquem. 
//Ataque = duas rainhas não podem compartilhar a mesma linha, coluna ou diagonal.

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Função para imprimir o tabuleiro de forma modificada
void imprimeTabuleiro(int n, int *r);

// Função Booleana para verificar a posição (linha, coluna) das rainhas anteriores
// Verifica se as rainhas anteriores estão na mesma coluna da rainha atual
// Ou se, diagonalmente elas se ataquem
// Retorna 1 caso não ocorra e 0 caso uma dessas condições ocorra
int verificaPosicao(int *rainhas, int linhaAtual, int colunaAtual);

// Função para resolver o problema das n-rainhas
void ResolveRainhas(int n);

int main()
{
    //n -> nro de rainhas e tamanho do tabuleio n x n
    int n;
    scanf("%d", &n);
    
    //N < 3 não possui solução
    if(n>=4)
      ResolveRainhas(n);
    
    return 0;
}

void ResolveRainhas(int numRainhas)
{
  //Pilha P -> armazenar estados das posições em que foi posivel alocar uma rainha
    pilha P = cria_pilha();
    
    // Alocação Dinâmica para armazenar as coluna em que foi possível posicionar uma rainha em sua linha
    // Ex: rainhas[0] = 1 -> a rainha da 1a linha está na coluna 2
    int *rainhas = (int *)malloc(numRainhas * sizeof(int)); 

    // Variáveis de controle: a linha e a coluna atual
    int linha = 0, coluna = 0; 

    // Loop principal para posicionar rainhas de forma segura em cada linha do tabuleiro.
    while (linha < numRainhas)
    {
        // Alocação da rainha em uma coluna da linha atual
        while (coluna < numRainhas)
        {
            // Verifica se é seguro colocar a rainha na posição atual
            if (verificaPosicao(rainhas, linha, coluna))
            {
                rainhas[linha] = coluna; // Define a coluna da rainha na linha atual

                // Se todas as rainhas foram colocadas em suas devidas linhas, imprime a solução
                if (linha == numRainhas - 1)
                    imprimeTabuleiro(numRainhas, rainhas); // Chama a nova função para imprimir a solução
                
                //Caso ainda não tenham sido todas alocadas
                else
                {
                    empilhar(P, linha); // Salva a linha da rainha atual na pilha para armazenar a posição, será usado depois caso não encontremos uma solução
                    linha++;            // Avança para a próxima linha do tabuleiro para a alocação de uma nova rainha
                    coluna = 0;         // Reinicia a coluna para a nova linha do tabuleiro para buscar a posição da nova rainha
                    continue;           // Continua o loop do while(col < numRainhas) para encontrar a rainha da próxima linha
                }
            }
            coluna++; // Avança para a próxima coluna
        }

        // Encerra o loop se a pilha está vazia e não há mais soluções para explorar
        if (pilha_vazia(P))
            break;
        
        //Momento em que percorremos todo o tabuleiro, mas não encontramos uma solução viável
        //Ira desempilha a última posição armazenada na pilha e tentar novamente
        //Dessa forma, ira testar a linha anterior, mas somando 1 ao nro da coluna da rainha da linha desempilhada
        linha = desempilhar(P);      // Retorna para a linha anterior
        coluna = rainhas[linha] + 1; // Avança para a próxima coluna da linha anterior
    }

    free(rainhas);
    libera_pilha(P);
}

int verificaPosicao(int *rainhas, int linhaAtual, int colunaAtual)
{
    //Laço que verifica cada rainha já colocada em linhas anteriores
    for (int linhaAnterior = 0; linhaAnterior < linhaAtual; linhaAnterior++)
    {
        if( rainhas[linhaAnterior] == colunaAtual                              || // Verifica se Está na Mesma Coluna
            linhaAnterior - rainhas[linhaAnterior] == linhaAtual - colunaAtual || // Verifica se Atinge uma Rainha na Diagonal Esq p/ Dir
            linhaAnterior + rainhas[linhaAnterior] == linhaAtual + colunaAtual  ) // Verifica se Atinge uma Rainha na Diagonal Dir p/ Esq
              return 0;
    }
    return 1;
}

void imprimeTabuleiro(int numRainhas, int *rainhas)
{
    for (int linhaTab = 0; linhaTab < numRainhas; linhaTab++) //linha do tabuleiro
    {
        for (int colunaTab = 0; colunaTab < numRainhas; colunaTab++) //coluna do tabuleiro
        {
            // Se a coluna da rainha da linha atual é igual a coluna atual do tabuleiro
            if (rainhas[linhaTab] == colunaTab) 
                printf("R ");
            else
                printf("_ ");
        }
        printf("\n");
    }
    printf("\n");
}

