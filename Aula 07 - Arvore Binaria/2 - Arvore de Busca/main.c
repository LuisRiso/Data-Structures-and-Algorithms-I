//Propriedade arvore binaria de busca
//Todos os nós a esquerda da raiz são menores que a raiz
//Todos os nós a direita da raiz são maiores que a raiz
//Isso vale recursivamente
//Permite fazer uma busca eficiente de um valor

//Provavelmente é o que escolhe-se para guardar numeros
//Para fazer busca, se tiver bem distribuida, auxilia na busca
//Bem balanceada = cada nível está totalmente preenchido
//Complexidade para buscar o elemento O(log n) niveis --> cada comparação tira metade dos nós

#include <stdio.h>
#include <stdlib.h>

typedef struct cel cel;

struct cel
{
  int dado; //só um caracter, aspas simples
  cel *esq; //apontadores para os filhos -> filho esquerdo
  cel *dir; //apontadores para os filhos -> filho direito
};

//Função para criar uma celular
cel *criaCelula(int dado);

//Quer imprimir o caracter da arvore pelo jeito ERD
void inorder(cel *arvore);
//Quer imprimir o caracter da arvore pelo jeito RED
void preorder(cel *arvore);
//Quer imprimir o caracter da arvore pelo jeito EDR
void posorder(cel *arvore);
//Devolve a altura de uma arvore
int calculaAltura(cel *arvore);
//Devolve o endereço da ceular com o valor ou NULL
cel *buscaValor(cel *arvore, int valor);
//Vai inserir o valor na arvore
cel *insereArvore(cel *arvore, int valor);

int main(int argc, char *argv[])
{
  cel *arvore = NULL;
  arvore = insereArvore(arvore, 10);
  arvore = insereArvore(arvore, 5);
  arvore = insereArvore(arvore, 7);
  arvore = insereArvore(arvore, 6);
  arvore = insereArvore(arvore, 11);
  
  inorder(arvore); printf("\n");
  
  printf("Altura = %d\n", calculaAltura(arvore));
  
  cel *busca = buscaValor(arvore, 7);
  if(busca == NULL)
    printf("Nao estah na arvore\n");
  else
    printf("Esta na arvore\n");
    
  busca = buscaValor(arvore, 12);
  if(busca == NULL)
    printf("Nao estah na arvore\n");
  else
    printf("Esta na arvore\n");
  
  return 0;
}

cel *criaCelula(int dado)
{
  cel *novo = (cel *)malloc(sizeof(cel)); //Criando a nova celular
  novo->dado = dado;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

void inorder(cel *arvore)
{
  if(arvore == NULL) return;
  
  inorder(arvore->esq);
  printf("%d", arvore->dado);
  inorder(arvore->dir);

}

void preorder(cel *arvore)
{
  if(arvore == NULL) return;
  
  printf("%d", arvore->dado);
  preorder(arvore->esq);
  preorder(arvore->dir);

}

void posorder(cel *arvore)
{
  if(arvore == NULL) return;
  
  posorder(arvore->esq);
  posorder(arvore->dir);
  printf("%d", arvore->dado);

}

int calculaAltura(cel *arvore)
{
  if(arvore == NULL) return 0;
  int alturaEsq = calculaAltura(arvore->esq);
  int alturaDir = calculaAltura(arvore->dir);
  if(alturaEsq > alturaDir) return alturaEsq + 1;
  else return alturaDir + 1;
}

//Devolve o endereço de onde está o valor buscado
//Se não encontrar, devolve NULL
cel *buscaValor(cel *arvore, int valor)
{
  if(arvore == NULL) return NULL; //indica que nao encontrou
  if(arvore->dado == valor) return arvore;
  if(arvore->dado > valor) return buscaValor(arvore->esq, valor);
  else return buscaValor(arvore->dir, valor);
}

//Quando insere o valor, pode ser que a arvore modifique o endereço da arvore
//Insere valor na arvore e devolve o endereco da nova arvore
cel *insereArvore(cel *arvore, int valor)
{
  if(arvore == NULL)
    return criaCelula(valor);
  if(arvore->dado > valor) //Vai supor que os dados vai ser sempre diferente
    arvore->esq = insereArvore(arvore->esq, valor);
  else
    arvore->dir = insereArvore(arvore->dir, valor);
  return arvore;
}
