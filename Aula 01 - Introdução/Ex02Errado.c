#include <stdio.h>

int *gera_arranjo(int ini, int fim);

int main(int argc, char * argv[])
{
	//int X = 5;
	//int *P = &X;
	int *V = gera_arranjo(0,10);
	int *W = gera_arranjo(10,20); //escreveu na mesma posição de memoria da veriavel V 
				     //já tinha lixo de memoria no espaço de memoria
				     //está acessando uma memoria que voce nao deveria estar acessando
	
	for(int i = 0; i < 11; i++)
	{
		printf("%d, ", V[i]);
	}
	printf("\n");
	
	for(int i = 0; i < 11; i++)
	{
		printf("%d, ", W[i]);
	}
	printf("\n");
	
	return 0;
}

int *gera_arranjo(int ini, int fim)
{
	int tamanho = fim - ini + 1;
	int V[tamanho]; //problema: o V é uma variável local
			//quando você chama uma função o sistema aloca um espaço de memoria para ela
			//quando você da um return ele libera o espaço de memoria
			//quando chama a segunda vez o vetor ainda aponta para a parte da memoria
			//o programa te deixa acessar a parte da memoria, mas voce nao deveria acessar
	int *P = V;
	
	for(int i = 0; i < tamanho; i++)
	{
		V[i] = ini + i;
		//printf("%d, ", V[i]);
	}
	//printf("\n");
	
	return P;
}
