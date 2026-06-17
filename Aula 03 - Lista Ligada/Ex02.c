//Comando | valgrind /programa mostra o que ocorre no programa em sequência

#include <stdio.h>
#include <stdlib.h>

typedef struct celula cel; //nome do tipo struct celula para se chamar cel
struct celula
{
  int valor;
  cel * prox; //prox ou next
};

void imprimeLista(cel *L);

cel *insereListaComeco(cel *L, int num);

cel *buscaValor(cel *L, int vProcurado);

void insereDepois(cel *L, int v);

void removeValor(cel *L);

cel *buscaAntecessor(cel *L, int vProcurado);

void liberaLista(cel *L);

int main(int argc, char *argv[])
{
  cel *L = NULL;
  L = insereListaComeco(L, 2);
  L = insereListaComeco(L, 5);
  L = insereListaComeco(L, 3);
  L = insereListaComeco(L, 8);
  L = insereListaComeco(L, 4);
  
  imprimeLista(L);
  printf("\n");
  
  cel *B = buscaValor(L, 7);
  if(B == NULL) printf("Nao achou \n");
  else printf("Achou\n");

  B = buscaValor(L, 4);
  if(B == NULL) printf("Nao achou\n");
  else printf("Achou\n");
  
  B = buscaValor(L, 3);
  if(B == NULL) printf("Nao achou\n");
  else printf("Achou\n");
  
  insereDepois(buscaValor(L,3), 30);
  imprimeLista(L);
  printf("\n");
  
  B = buscaAntecessor(L, 30); //busca o antecessor para remover o valor desejado
  removeValor(B); //vai remover o valor com base no antecessor
  imprimeLista(L);
  printf("\n");
  
  liberaLista(L);
  
  return 0;
}

void imprimeLista(cel *L)
{
  if(L == NULL) return;
  printf("%d, ", L->valor);
  imprimeLista(L->prox);
}

cel *insereListaComeco(cel *L, int v)
{
  cel *novaCel = (cel *)malloc(sizeof(cel)); //Utiliza-se alocação dinâmica para não perder o dado
  novaCel->valor = v;
  novaCel->prox = L;
  
  return novaCel;
}

cel *buscaValor(cel *L, int vProcurado)
{
  if(L == NULL) return NULL;
  cel *busca = L;
  if(busca->valor == vProcurado)
    return busca;
  return buscaValor(L->prox, vProcurado);
}

void insereDepois(cel *L, int v)
{
  cel *nova = (cel *)malloc(sizeof(cel));
  nova->valor = v;
  nova->prox = L->prox;
  L->prox = nova;
  return;
}

//Sabe o endereço do antecessor do valor que você quer remover
void removeValor(cel *L)
{
  cel *del = L->prox; //vai salvar o valor que eu quero remover Ex: 20 -> 15 (salvou esse) -> 40 -> 50
  L->prox = del->prox; //vai apontar para o próximo valor de L do valor que eu quero remover Ex: 20 -> 15 -> 40 (salvou esse) -> 50
  free(del); //Ex: 20 -> 15 (apagou esse) -> 40 -> 50
}

cel *buscaAntecessor(cel *L, int vProcurado)
{
  if(L == NULL || L->prox == NULL) return NULL;
  if(L->prox->valor == vProcurado) { //vai analisar o valor do proximo valor que voce vai buscar 
    return L;
  }
  return buscaAntecessor(L->prox, vProcurado);
}

void liberaLista(cel *L)
{
  if(L == NULL) return;
  liberaLista(L->prox); //executa a função varias vezes para depois executar o resto do código
  free(L);
  return;
}
