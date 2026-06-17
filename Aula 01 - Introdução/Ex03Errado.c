#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
	char nome[50];
	char matricula[20];
	char curso[3];
} Aluno;

void verifica_curso(Aluno a);

int main(int argc, char * argv[])
{
	Aluno hokama;
	
	hokama.curso[0] = 'S';
	hokama.curso[1] = 'I';
	hokama.curso[2] = 'N';
	
	int tamanho = 100;
	
	for(int i = 0; i < tamanho; i++)
	{
		verifica_curso(hokama); //está passando todo o bloco de struct Aluno
					//nao faz sentido fazer a copia de todos os campos apenas para verificar um
	}
	
	return 0;
}

void verifica_curso(Aluno a)
{
	if(a.curso[0] == 'S' && a.curso[1] == 'I' && a.curso[2] == 'N') 
		printf("Aluno no curso de Sistemas\n");
}
