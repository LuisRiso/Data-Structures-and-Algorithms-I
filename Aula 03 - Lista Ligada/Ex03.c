#include <stdio.h>
#include <stdlib.h>

typedef struct celula celula;

struct celula{
  int valor;
  celula * prox; //next
};

void imprime_lista(celula* L){
  if(L == NULL) return;
  printf("%d, ", L->valor);
  imprime_lista(L->prox);
}

celula * busca(celula * L, int v){
  if(L == NULL) return NULL;
  celula * atual = L;
  if(atual->valor == v){
    return atual;
  }
  return busca(atual->prox, v);
}

celula * busca_antecessor(celula * L, int v){
  if(L == NULL || L->prox == NULL) return NULL;
  if(L->prox->valor == v){
    return L;
  }
  return busca_antecessor(L->prox, v);
}

celula * insere_lista(celula* L, int v){
  celula * nova = (celula*) malloc(sizeof(celula));
  nova->valor = v;
  nova->prox = L;
  return nova;
}

void insere_depois(celula * L, int v){
  celula * nova = (celula *) malloc(sizeof(celula));
  nova->valor = v;
  nova->prox = L->prox;
  L->prox = nova;
  return;
}

//remove uma celula que esta em L->prox
void remove_prox(celula * L){
  celula * del = L->prox;
  L->prox = del->prox;
  free(del);
}

void libera_lista(celula * L){
  if(L == NULL) return;
  libera_lista(L->prox);
  free(L);
  return;
}

int main(int argc, char* argv[]){
  celula * L = NULL;
  L = insere_lista(L, 2);
  L = insere_lista(L, 5);
  L = insere_lista(L, 3);
  L = insere_lista(L, 8);
  L = insere_lista(L, 4);
  
  celula * b = busca(L, 7);
  if(b == NULL) printf("NÃ£o achou 7\n");
  else printf("achou o %d\n", b->valor);
    
  b = busca(L, 4);
  if(b == NULL) printf("NÃ£o achou 4\n");
  else printf("achou o %d\n", b->valor);
  
  b = busca(L, 2);
  if(b == NULL) printf("NÃ£o achou 2\n");
  else printf("achou o %d\n", b->valor);
  
  imprime_lista(L);
  printf("\n"); 
    
  insere_depois(busca(L, 3), 30);
  
  imprime_lista(L);
  printf("\n"); 
  
  b = busca_antecessor(L, 30);
  remove_prox(b);
  
  imprime_lista(L);
  printf("\n"); 
  
  libera_lista(L);
  return 0;
}


