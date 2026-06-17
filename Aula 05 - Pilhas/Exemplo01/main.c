#include <stdio.h>
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


//Ideia da pilha -> o próximo a ser resgatado é o último que entrou --> Análogo a uma pilha de pratos
//Formato LIFO --> Last In First Out --> Último a entrar Primeiro a Sair
//O indice de entrada e saída serão os mesmos --> Diferença da fila que o indice de entrada e saida diferem
//Não há sentido em fazer um vetor ciruclar
//Faz sentido fazer uma lista ligada
//Complexidade: O(1) --> Tranto para empilhar quanto para desimpilhar

int main(int argc, char *argv[])
{
	pilha P = criarPilha();
	empilhar(P, 'a');
	empilhar(P, 'b');
	empilhar(P, 'c');
	printf("%c\n", desempilhar(P));
	printf("%c\n", desempilhar(P));
	empilhar(P, 'd');
	printf("%c\n", desempilhar(P));
	liberarPilha(P);
	
	return 0;
}
