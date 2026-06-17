//Verificador da abertura e fechamento de parenteses para definir se todos os parenteses abertos estão corretos
//vai verificar uma string e ver se está correta ou não
#include <stdio.h>
#include <string.h>
#include "pilha.h"

int casaCaracter(char t, char c);

int main()
{
	pilha P = criarPilha();
	char sequencia[100];
	scanf(" %[^\n]", sequencia);
	
	for(int i = 0; i < strlen(sequencia); i++)
	{
		char c = sequencia[i];
		if(c == '(' || c == '[' || c == '{') {
			empilhar(P, c);
		}
		else if(c == ')' || c == ']' || c == '}')
		{
			if(pilhaVazia(P))
			{
				printf("Sequencia Desbalanceada\n");
				liberarPilha(P);
				return 0;
			}
			char topo = desempilhar(P);
			if(casaCaracter(topo, c) == 0)
			{
				printf("Sequencia Desbalanceada\n");
				liberarPilha(P);
				return 0;
			}
		}
	}
	if(pilhaVazia(P))
	{
		printf("Sequencia Balanceada\n");
	}
	else
	{
		printf("Sequencia Desbalanceada\n");
		liberarPilha(P);
		return 0;
	}
	
	return 0;
}

int casaCaracter(char t, char c)
{
	if(t == '(' && c == ')') return 1;
	if(t == '[' && c == ']') return 1;
	if(t == '{' && c == '}') return 1;
	return 0;
}
