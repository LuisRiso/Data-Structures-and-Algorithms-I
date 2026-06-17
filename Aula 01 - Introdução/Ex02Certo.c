#include <stdio.h>
#include <stdlib.h>

int *gera_arranjo(int ini, int fim);

int main(int argc, char * argv[])
{
	//int X = 5;
	//int *P = &X;
	int *V = gera_arranjo(0,10); //guardou o endereço de memoria do malloc
	int *W = gera_arranjo(10,20); //forneceu outro espeça de memoria
				      //espaço que nao foi armazenado pelo anterior
	printf("V = ");
	for(int i = 0; i < 11; i++)
	{
		printf("%d, ", V[i]);
	}
	printf("\n");
	
	printf("W = ");
	for(int i = 0; i < 11; i++)
	{
		printf("%d, ", W[i]);
	}
	printf("\n");
	
	int tamanho = 20;
	int *Y = (int *)malloc(tamanho * sizeof(int)); //a alocação te permite criar vetores com o tamanho que você quiser
						       //alocação dinamica puxa memoria do hip e não do stack
	printf("Y = ");
	for(int i = 0; i < 11; i++)
	{
		Y[i] = 20 + i;
		printf("%d, ", Y[i]);
	}
	printf("\n");
	
	free(V);
	free(W);
	
	return 0;
}

int *gera_arranjo(int ini, int fim)
{
	int tamanho = fim - ini + 1;
	int *X = NULL; 
	X = (int *)malloc(tamanho * sizeof(int)); //tem uma memoria persistente
						  //quando o programa morre, a memoria nao morre
						  //permite que o lixo de memoria nao seja atribuido
	for(int i = 0; i < tamanho; i++)
	{
		X[i] = ini + i;
		//printf("%d, ", V[i]);
	}
	//printf("\n");
	
	return X;
}
