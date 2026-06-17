// Trabalho das N Rainhas com Pilha - Camily Victal Finamor e Pedro Luiz de Moraes Ferreira
//-----------------------------------------------------------------------------------------------
//OBSERVAÇÕES:
//Professor, para uma melhor visualização de nossos comentários, recomendamos que use o word wrap
//Também  decidimos utilizar dos comentários para criar "sessões" como esta das observações, para ficar mais fácil pro professor corrigir e ver onde está cada coisa e também para nós não nos perdermos enquanto fazemos o trabalho
//-----------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// ASSINATURAS DAS FUNÇÕES:
//Aprendemos com o professor Olmes que é melhor e mais organizado pro código colocar as assinaturas das funções antes do main e implementar elas depois do main, então fizemos assim
//Estas são as assinaturas das funções que fizemos para nosso trabalho

void imprimeTabuleiro(int n, int *r);
void ResolveTabuleiro(int n, int *r, int atual);


//-----------------------------------------------------------------------------------------------
//MAIN:
int main(int argc, char* argv[]){

    int n;
    scanf("%d", &n);

    int *r = (int *)malloc(n * sizeof(int));

	ResolveTabuleiro(n, r, 0);

	free(r);

    return 0;
}

//-----------------------------------------------------------------------------------------------
//CRIAÇÃO DAS FUNÇÕES:
//Essa eh nossa funcao para imprimir os resultados, basicamente reutilizamos o modo que  você imprimiu professor
void imprimeTabuleiro(int n, int *r) {
	int linha, coluna;

	for(linha = 0; linha < n; linha++) {
		for(coluna = 0; coluna < n; coluna++) {
			if(r[linha] == coluna)
				printf("R ");
			else
				printf("_ ");
		}
		printf("\n");
	}
}

//Aqui eh nossa funcao para resolver o tabuleirp com pilha, seguimos por base o algoritmo recursivo que você fez em sala, mas adaptamos a recursividade em uma pilha
void ResolveTabuleiro(int n, int *r, int linhaAtual) {
	int coluna = 0;
    int anterior;
    int viavel;
	
	pilha p = cria_pilha();

	while(linhaAtual<n){

		viavel = 0;

		while(coluna<n){
			
			viavel = 1;

			for(anterior = 0; anterior < linhaAtual; anterior++) {
				int dist = linhaAtual - anterior;
				if (r[anterior] == coluna || r[anterior] - coluna == dist || coluna - r[anterior] == dist) {
					viavel = 0;
					break;
				}
			}

			if(viavel == 1) {
				r[linhaAtual] = coluna;
				empilhar(p, coluna);
				linhaAtual++;
				coluna = 0;
				break;
			}
			coluna++;
		}

		if(linhaAtual == n) {
			imprimeTabuleiro(n, r);
			printf("\n");
			if(!pilha_vazia(p)){
				coluna = desempilhar(p) + 1;
				linhaAtual--;
			}
		}
		else if(coluna == n){
			if(!pilha_vazia(p)){
				coluna = desempilhar(p) + 1;
				linhaAtual--;
			}
			else{
				break;
			}
		}

	}
	libera_pilha(p);
	return;
}