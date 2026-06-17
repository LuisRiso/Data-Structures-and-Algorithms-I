//Usar uma fila para guardar mais de um endereço de memoria para o próximo valor
//Pode ser usado para criar uma arvore binária --> a fila cresce como se fosse uma arvore --> Binária porque cada celula tem dois filhos
//Há uma raiz (primeiro nó) --> nó que abrange todos os filhos
//Nós intermediários --> entre a raiz e as folhas
//Celulas (nós) mais em baixo são as folhas --> Nós que não tem filhos
//Cada celular pode ser observada separadamente como uma arvore binária também

//Não é util so para armazenar dados
//Pode ser util para fazer algumas aplicações

//A definição de arvore também é recursivo
//É uma celular que ou é nulo ou que tem dois filhos que também são arvores binarias

//Jeitos de percorrer uma arvore
//ERD (Esquerda - Raiz - Direita) = in order
//RED (Raiz - Esquerda - Direita) = pre order
//EDR (Esquerda - Direita - Raiz) = pos order

//Altura arvore
//Maior distancia entre a raiz e uma folha
//Iniciar a altura como 1

//Na raiz
//Filho esquerdo = subarvore esqueda
//Filho direito = subarvore direita

//Antecessor do filho é chamado de pai

#include <stdio.h>
#include <stdlib.h>

typedef struct cel cel;

struct cel
{
  char dado; //só um caracter, aspas simples
  cel *esq; //apontadores para os filhos -> filho esquerdo
  cel *dir; //apontadores para os filhos -> filho direito
};

//Função para criar uma celular
cel *criaCelula(char dado);

//Quer imprimir o caracter da arvore pelo jeito ERD
void inorder(cel *arvore);
//Quer imprimir o caracter da arvore pelo jeito RED
void preorder(cel *arvore);
//Quer imprimir o caracter da arvore pelo jeito EDR
void posorder(cel *arvore);
//Devolve a altura de uma arvore
int calculaAltura(cel *arvore);

int main(int argc, char *argv[])
{
  cel *arvore = criaCelula('C'); //há uma celular que tem o C dentro
  arvore->esq = criaCelula('A');  //colocou um filho esquerdo para a arvore
  arvore->esq->dir = criaCelula('B'); //criou um filho direito para o filho esquerdo da arvore
  arvore->esq->dir->esq = criaCelula('W');
  arvore->dir = criaCelula('D');
  
  inorder(arvore); printf("\n");
  preorder(arvore); printf("\n");
  posorder(arvore); printf("\n");
  
  printf("Altura = %d\n", calculaAltura(arvore));
  
  return 0;
}

//Precisa alocar memoria
//Colar o dado no campo dado
//Setar os filhos esquerdo e direito para nulo
cel *criaCelula(char dado)
{
  cel *novo = (cel *)malloc(sizeof(cel)); //Criando a nova celular
  novo->dado = dado;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

//Precisa imprimir A-W-B-C-D
//Primeiro a arvore esquerda
//Depois a raiz
//Depois a arvore direita
void inorder(cel *arvore)
{
  if(arvore == NULL) return;
  
  inorder(arvore->esq); //chama a função para imprimir a arvore esquerda;
  printf("%c", arvore->dado);
  inorder(arvore->dir);

}

//Precisa imprimir C-A-B-W-D
//Primeiro a raiz
//Depois a arvore esquerda
//Depois a arvore direita
void preorder(cel *arvore)
{
  if(arvore == NULL) return;
  
  printf("%c", arvore->dado);
  preorder(arvore->esq); //chama a função para imprimir a arvore esquerda;
  preorder(arvore->dir);

}

//Precisa imprimir W-B-A-D-C
//Primeiro a raiz
//Depois a arvore esquerda
//Depois a arvore direita
void posorder(cel *arvore)
{
  if(arvore == NULL) return;
  
  posorder(arvore->esq); //chama a função para imprimir a arvore esquerda;
  posorder(arvore->dir);
  printf("%c", arvore->dado);

}

int calculaAltura(cel *arvore)
{
  if(arvore == NULL) return 0;
  int alturaEsq = calculaAltura(arvore->esq);
  int alturaDir = calculaAltura(arvore->dir);
  if(alturaEsq > alturaDir) return alturaEsq + 1;
  else return alturaDir + 1;
}
