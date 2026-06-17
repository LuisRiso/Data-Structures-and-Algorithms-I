//Na fila de prioridade
//Quanto mais baixo, maior a prioridade

//Usado em varior algoritmos que você tem que pegar o minimo -> você quer usar uma fila de prioridade

//Implementação é feita pela estrutura Heap

/*
 * Heap
 * É uma árvore binária quase completa (quase cheia)
 * Quase completa porque todos os níveis exceto o último estão cheios
 * No último nível, todos os nós estão à esquerda (não significa que são os filhos esquerdos) -> significa que estão mais a esquerda se alinha-los
 * O pai tem sempre uma prioridade maior do que os filhos
 * O de cima tem um valor menor do que o de baixo
 * O pai é sempre menor que os filhos
 * Listando regras:
 *  1) O pai é sempre menor que os filhos
 *  2) Arvore Binária
 *  3) Quase Completa
 * Obs -> não é uma arvore binária de busca -> os algoritmos de busca não se aplicam como outras árvores de busca
 * Vantagem -> o menor vai sempre estar em cima
 
 * Quando vai inserir um menor elemento -> algumas regras vão ser quebradas, mas vai tentar manter a maior parte das regras
 * Depois de inserir, as regras são consertadas
 * Ex: função sobe-heap (corrige-subindo) para organizar um elemento da arvore para cima
 * Ex: desce-heap (corrige-descendo) para organizar um elemento da arvore para baixo
 *     Na descida -> vai trocar sempre com o menor filho | vai garantir que o que sobe vai estar no lugar certo
 
 * Principais funções: extrair o minimo e inserir no Heap
 * Jeito mais eficiente de implementar o heap -> dar números para os nós (de cima para baixo, da esquerda para direita)
 * Como os nós sempre vão estar corretos -> é possível implementá-los em um vetor
 * Cada uma das posições vai abrigar um dos elementos da arvore
 * Vai interpretar o vetor como se fosse uma árvore-binária
 * Dado um nó i
 * Esq(i) = 2i + 1
 * Dir(i) = 2i + 2
 * Pai(i) = teto(i/2 - 1) -> vai arredondar para cima
 */

//IMPORTANTE: fila de prioridade (heap) vai usar sempre em algum lugar que tem remove minimo -> pensar direto em usar o heap

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 //vai guardar um vetor de 1000, mas não necessáriamente vai estar usando as posições

//minHeap -> para definir que é o minimo
//vai supor que nenhuma utilizar vai estourar o tamanho do vetor
typedef struct minHeap
{
  int *v;
  int n;
} minHeap;

//Funções para calcular as posições do vetor como uma árvore-binária
int pai(int i);
int esq(int i);
int dir(int i);

//Cria a struct inicial e define o tamanho do vetor
minHeap *cria_minHeap();

//Insere um valor no final do vetor e depois ajustas considerando as Regras do Heap
void insere_minHeap(minHeap *H, int valor);

void sobe_minHeap(minHeap *H, int posicao);

void desce_minHeap(minHeap *H, int posicao);

void printHeap(minHeap *H);

int remove_minHeap(minHeap *H);

int main (int argc, char *argv [])
{
  minHeap *H = cria_minHeap();

  insere_minHeap(H, 4);
  printHeap(H);
  insere_minHeap(H, 5);
  printHeap(H);
  insere_minHeap(H, 6);
  printHeap(H);
  insere_minHeap(H, 3);
  printHeap(H);

  int m = remove_minHeap(H);
  printf("min = %d\n", m);
  printHeap(H);

  return 0;
}

minHeap *cria_minHeap()
{
  minHeap *H = malloc(sizeof(minHeap));
  H->v = (int *)malloc(sizeof(int) * MAX);
  H->n = 0;
  return H;
}

void printHeap(minHeap *H)
{
  for(int i = 0; i < H->n; i++)
  {
    printf("%d, ", H->v[i]);
  }
  printf("\n");
}

void insere_minHeap(minHeap *H, int valor)
{
  //colocar o valor no final do vetor
  H->v[H->n] = valor; //insere o valor no final da arvore
  
  sobe_minHeap(H, H->n); //vai fazer o ajuste das posições
  
  H->n = H->n + 1; //H->n + 1 passa a ser o final da arvore
}

int remove_minHeap(minHeap *H)
{
  //TODO: verificar se o heap esta vazio  
  int min = H->v[0];
  
  //subir o último elemento do vetor e colocar no inicio
  H->v[0] = H->v[H->n-1];
  H->n = H->n-1;
  
  desce_minHeap(H, 0);
  
  return min;
}

void sobe_minHeap(minHeap *H, int posicao) //vai comparar o elemento da posicao com o pai
{
  if(posicao == 0) return;

  int papai = pai(posicao);
  
  if(H->v[posicao] < H->v[papai])
  {
    int aux = H->v[posicao];
    H->v[posicao] = H->v[papai];
    H->v[papai] = aux;
    sobe_minHeap(H, papai); //vai continuar comparando para alterar os valores a partir do pai
  }
}

void desce_minHeap(minHeap *H, int posicao)
{
  //verificação se tem filho esquerdo da arvore
  int e = esq(posicao); //vai pegar o filho esquerdo para comparar
  //se posicao jah eh folha, nao desce mais
  if(e > H->n-1) return;
  
  int menorFilho = e;
  
  //verificao se tem filho direito da arvore
  int d = dir(posicao);
  //se eu tenho um filho direito e, se eu tiver um filho direito, se é maior que o esquerdo
  if(d <= H->n-1 && H->v[d] < H->v[e]) //tenho filho direito && ele é menor que o esquerdo
    menorFilho = d;
    
  if(H->v[posicao] > H->v[menorFilho]) //não precisa descer mais na arvore
  {
    int aux = H->v[posicao];
    H->v[posicao] = H->v[menorFilho];
    H->v[menorFilho] = aux;
    desce_minHeap(H, menorFilho);
  }
  
  return; 
}

int pai(int i)
{
  return (i-1)/2;
}

int esq(int i)
{
  return (2*i) + 1;
}

int dir(int i)
{
  return (2*i) + 2;
}

