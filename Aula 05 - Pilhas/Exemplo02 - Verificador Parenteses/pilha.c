//Verificador da abertura e fechamento de parenteses para definir se todos os parenteses abertos estão corretos
//vai verificar uma string e ver se está correta ou não

#include <stdlib.h>
#include "pilha.h"
/*
 / Funções Pilha.h
 / pilha criarPilha();
 / void empilhar(pilha P, char c)
 / char desempilhar(pilha P);
 / int pilhaVazia(pilha P);
 / void liberarPilha(pilha P);
*/

//elemento que vai ser utilizado na pilha
typedef struct elemento
{
	char dado;
	struct elemento * prox; //apontador para o próximo elemento da pilha
}elemento;

//definindo a struct criada no pilha.h para um ponteiro pilha
//vai funcionar como a cabeça de uma lista --> para guardar o topo da pilha
//sempre vai ser no topo da pilha e um elemento aponta para o de baixo
struct pilhaa
{
	elemento * topo; //apontado para o elemento da pilha
};

pilha criarPilha()
{
	//Se colocar somente pilha ao invés de struct pilha vai criar um  espaço para guardar o endereço de memoria, com struct pilha você cria um bloco de memoria
	//Esse bloco de memória vai te permitir realizar as demais funções
	pilha P = (pilha)malloc(sizeof(struct pilhaa)); 
	P->topo = NULL; //Quando se está criando uma pilha o topo não tem nada
	return P;
}

void empilhar(pilha P, char c)
{
	elemento * e = (elemento *)malloc(sizeof(elemento)); //criando um apontador para o elemento
	e->dado = c;
	e->prox = P->topo; //Meu dado agora passou a ser o topo da pilha
	P->topo = e; //Faz com que o bloco pilha aponte para o elemento 'e' como o topo --> na hora de desimpilhar irá apontar para ele
	
	return;
}

char desempilhar(pilha P)
{
	elemento * T = P->topo; //Guarda o ponteiro topo para depois libera-lo
	char r = T->dado; //r de return | // T->Dado é igual a P->topo->dado --> Está puxando o Topo da Pilha e pegando um dado dele
	P->topo = T->prox; //T->prox é igual a P->topo->prox --> Faz com que o Topo da pilha aponte para o próximo depois dele
	free(T);
	return r;
}

int pilhaVazia(pilha P)
{
	if(P == NULL) return 1; //se a pilha for nula por qualquer motivo
	if(P->topo == NULL) return 1; //se a  pilha foi criada e nenhum dado armazenado ou se carregou todos os dados
	else return 0;
}

//Função recursiva para liberar todos os apontadores da lista
//Precisa de duas funções diferentes pois há duas structs diferente ou seja dois elementos diferentes
void liberarListaElementos(elemento *e)
{
	if(e == NULL) return; //Caso base da lista, quando chega a lista vazia
	liberarListaElementos(e->prox);
	free(e);
}

void liberarPilha(pilha P)
{
	liberarListaElementos(P->topo);
	free(P);
}


