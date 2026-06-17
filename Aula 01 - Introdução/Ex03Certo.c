#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
	char nome[50];
	char matricula[20];
	char curso[3];
} Aluno;

void verifica_curso(Aluno *a);

int main(int argc, char * argv[])
{
	Aluno hokama;
	
	hokama.curso[0] = 'S';
	hokama.curso[1] = 'I';
	hokama.curso[2] = 'N';
	
	int tamanho = 20;
	
	for(int i = 0; i < tamanho; i++)
	{
		verifica_curso(&hokama); //está passando o endereço direto da struct
					 //nao perde tempo fazendo a copia da struct para verificar algo
	}
	
	return 0;
}

void verifica_curso(Aluno *a)
{
	//*a.p - diferente dos outros
	//(*a).p - diferente dos outros
	//*(a.p) - diferente dos outros

	if((*a).curso[0] == 'S' && a->curso[1] == 'I' && a->curso[2] == 'N') 
		printf("Aluno no curso de Sistemas\n");
}
