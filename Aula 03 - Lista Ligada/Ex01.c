#include <stdio.h>
#include <stdlib.h>

typedef struct celula cel; //nome do tipo struct celula para se chamar cel
struct celula
{
  int valor;
  cel * prox; //padrão usar prox ou next para identificar a lista ligada
  /*
   |*Definição Lista Ligada
   |*Pode ser NULL
   |*Pode ser uma celula que tem valores seguida de outra lista ligada
   |*Ou seja, um elementos que aponta para outra lista liga
   |*Pode ser visto dessa forma como um elemento recursivo
  */
};

void imprimeLista(cel *L);

cel *insereLista(cel *L, int num);

int main(int argc, char *argv[])
{
  /*Exemplo para Entender Lista Ligada
   |*cel A;
   |*A.valor = 10;
   |*A.prox = NULL;
   |*cel B;
   |*B.valor = 20;
   |*B.prox = &A;
  
   |*Ponteiro da struct de B está apontando para o endereço de A
   |*Serve para criar para uma lista ligada
   |*Pega o endereço de um registro e o faz apontar para outro registro
   |*Por que usar?
   |*Quando eu quero guardar listas, mas eu não sei quantos elementos eu vou ter
   |*Te fornece flexibilidade, sem ocupar muita memória
   |*Mais indicado que o realoc devido ao problema de poder errar usando o realoc
  */
									// Primeiro elemento da lista encadeada e é usado para armazenar o endereço da primeira célula da lista.
  cel *L = NULL;  // NULL: Define que L começa com o valor NULL, significa que ele não está apontando para nenhuma célula no momento. 
								  // Este é um indicador comum para listas vazias.
  
  
  //Na primeira inserção:
  //Quando L é NULL (indicando que a lista está vazia), a função insereLista(L, v) cria a primeira célula com malloc.
  //Na linha novaCel->prox = L;, como L é NULL, estamos dizendo que novaCel->prox = NULL;. 
  //Isso define que a nova célula não aponta para nenhuma outra célula, pois não há outras na lista.
	
  L = insereLista(L, 2); //L passa a apontar para a celula com valor 2 que é agora o inicio da lista
  L = insereLista(L, 5); //...
  L = insereLista(L, 3);
  L = insereLista(L, 8);
  L = insereLista(L, 4);
  
  imprimeLista(L);
  
  return 0;
}

void imprimeLista(cel *L)
{
  if(L == NULL) return;
  printf("%d, ", L->valor);
  imprimeLista(L->prox);
}

cel *insereLista(cel *L, int v)
{
	//Criação da celula para armazenar os dados
  cel *novaCel = (cel *)malloc(sizeof(cel)); //Utiliza-se alocação dinâmica para não perder o dado
  
  /*
   |*Aconselhavel
   |*Inserir o valor novo no inicio da lista. Motivo:
   |*Você já sabe a localização que ha a primeira celula sem precisar procura-la
   |*Mas não necessáriamente você sabe o tamanho final da lista
  */
  novaCel->valor = v;
  novaCel->prox = L; //Define o campo prox da nova célula para apontar para a primeira célula atual da lista, representada por L.
	
	//Ex: Imagine que você tem uma lista encadeada com duas células (valores 5 e 3), e agora quer inserir o valor 8 no início:
	//Estado inicial: L aponta para a célula com valor 5. | L -> [5 | *prox] -> [3 | NULL]
	//Cria-se uma nova célula, novaCel, com valor = 8.
	//Com novaCel->prox = L;, novaCel aponta para a célula com valor 5. | novaCel -> [8 | *prox] -> [5 | *prox] -> [3 | NULL]
	//Retornando a nova lista: Agora, novaCel é a primeira célula, e a lista começa com 8. | L -> [8 | *prox] -> [5 | *prox] -> [3 | NULL]
  
  return novaCel;
}
