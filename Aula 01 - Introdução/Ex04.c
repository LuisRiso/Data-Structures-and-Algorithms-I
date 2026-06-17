#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
	char Nome[50];
	char matricula[20];
	//char curso[3];
	char *curso; //cria um ponteiro para apontar para o endereço do primeiro caracter
} Aluno;

 int main(int argc, char *argv[])
{
	int *x = (int *)malloc(sizeof(int) * 10);
	//É preciso fazer essa verificação sempre que haja alocação dinamica de memoria
	if(x == NULL)
	{
		printf("Sem memória\n");
		exit(1);
	}
	for(int i = 0; i < 10; i++)
	{
		x[i] = 0;
		printf("%d, ", x[i]);
	}
	printf("\n");
	
	int *y = (int *)calloc(10, sizeof(int));
	if(y == NULL)
	{
		printf("Sem memória\n");
		exit(1);
	}
	for(int i = 0; i < 10; i++)
	{
		printf("%d, ", y[i]);
	}
	printf("\n");
	
	
	/*
	 *Realocação de memoria para o tamanho do vetor do jeito errado
	 *Alterar o tamanho do vetor com a função Realloc
	 *A função realloc aumenta o espaço de memoria em espaço sequêncial
	 *Dependendo do tamanho do vetor original, ele irá demorar para copiar os dados anteriores
	 *em um espaço de memoria sequêncial disponível para o novo tamanho
	 *Caso não consiga alocar, ele irá devolver o valor NULL
	 *Caso não consiga alocar, os dados originais viram lixo de memória
	 *Você perde os dados originais e a cópia
	*/
	//Usando o Realloc
	//y = (int *)realloc(y, 200 * sizeof(int));
	
	/*
	 *Realocação de memoria para o tamanho do vetor do jeito certo
	 *Alterar o tamanho do vetor usando um auxiliar no Realloc
	 *Dessa forma, caso não seja possível criar o vetor, você não perde os dados originais
	*/
	int *aux = (int *)realloc(y, 200 * sizeof(int));
	if(aux != NULL)
	{
		y = aux;
	}
	
	//Liberação do espaço de memoria alocado anteriormente
	free(x);
	free(y);
	
	//Quero guardar 10 endereços de memória 
	//Endereços de memória que guardam inteiros
	//** -> Endereço de memoria que guarda um endereço que guarda variaveis
	int **Z = (int **)malloc(10 * sizeof(int*));
	
	//**Z = 10 //Está indo para a primeira posição e pegando o valor da qual esse inteiro aponta
		   //Vai dar uma falha de segmentação porque ele não sabe se pode escrever no endereço fornecido
	
	for(int i = 0; i < 10; i++)
	{
		Z[i] = (int *)malloc(sizeof(int) * 10); //vai criar um vetor de inteiro para guardar os valores
		for(int j = 0; j < 10; j++)
		{
			Z[i][j] = i*10 + j;
		}
	}
	
	char curso[4]; //já é um ponteiro
	strcpy(curso, "SIN");
	
	//Criando uma matriz de struct
	Aluno **A = (Aluno **)malloc(10 * sizeof(Aluno*));
	
	for(int i = 0; i < 10; i++)
	{
		A[i] = (Aluno *)malloc(sizeof(Aluno) * 10); //vai criar um vetor de struct para guardar os valores
		for(int j = 0; j < 10; j++)
		{
			//strcpy(A[i][j].curso, "SIN"); escrevendo diretamente na variavel
			A[i][j].curso = curso;
		}
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
			printf("%s, ", A[i][j].curso); //%s já está esperando receber o endereço de memoria da string
		printf("\n");
	}
	
	return 0;
}
