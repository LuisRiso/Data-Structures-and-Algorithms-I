#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

//Caracteres ASCII validos [' 'até '~')
#define TAMANHO_ALFABETO 95
//Primeiro caractere considerado na ASCII(' ')
#define INICIO_ALFABETO 32  
//Tamanho máximo do texto de entrada permitido no código
#define TAMANHO_MAX_ENTRADA 5000

//Estrutura que irah representar um noh de uma árvore binaria
typedef struct node {
    char ch; //Caractere que sera armazenado no noh
    float chave; //Frequencia ou peso do noh
    struct node *esq; //Ponteiro para os filhos esquerdos
    struct node *dir; //Ponteiro para os filhos direitos
} node;

//Função para criar um noh da arvore binaria de Huffman
node *criar_node(char ch, float chave, node *esq, node *dir) {
    node *no = (node *) malloc(sizeof(node));
    no->ch = ch; //Inicializa o caractere
    no->chave = chave; //Inicializa a frequencia
    no->esq = esq; //Define o apontador do filho esquerdo
    no->dir = dir; //Define o apontador do filho direito
    return no;        
}

/*
 * Funcoes para imprimir a arvore em formato graphViz
 * Função criada usando recursividade para imprimir a árvore em formato Graphviz
 * A arvore pode ser visualizada em uma plataforma online como https://dreampuf.github.io/GraphvizOnline
 */
int print_tree_rec(node *r, int *node_num) 
{
  if (r == NULL) return -1;                 
  int my_number = *node_num;                
  printf("  %d[label=\"%c\"];\n", my_number, r->ch); 
  (*node_num)++;                            
  int esq = print_tree_rec(r->esq, node_num); 
  (*node_num)++;                             
  int dir = print_tree_rec(r->dir, node_num); 
  if (esq != -1) printf("  %d -> %d;\n", my_number, esq); 
  if (dir != -1) printf("  %d -> %d;\n", my_number, dir); 
  return my_number;                        
}
void print_tree(node *r) 
{
  if (r == NULL) return;                   
  printf("digraph G{\n  graph [ordering=\"out\"];\n"); 
  int num_node = 0;                        
  print_tree_rec(r, &num_node);            
  printf("}\n");                           
}

//Funcao recursiva para percorrer a arvore e preencher a tabela de codicos
//Ira percorrer a arvore para cada caractere da tabela ASCII
//Aqueles que apareceram no texto viraram nohs folhas
//Cada noh que eh uma folha recebera um codigo binario correspondente com base na posicao na arvore
void percorre_arvore_rec(node *r, int *aux_codigo, int profundidade, int **tabela) 
{
  //Se o noh possui um filho esquerdo
  if (r->esq) 
  {                           
    //Adiciona 0 ao código
    //Filhos esquerdos sao definidos como o bit 0 do codificador
    aux_codigo[profundidade] = 0;
    percorre_arvore_rec(r->esq, aux_codigo, profundidade + 1, tabela);
  }
  //Se o noh possui um filho direito
  if (r->dir) 
  {                     
    //Adiciona 1 ao código
    //Filhos direitos sao definidos como o bit 1 do codificador
    aux_codigo[profundidade] = 1; 
    percorre_arvore_rec(r->dir, aux_codigo, profundidade + 1, tabela);
  }
  //Se o noh da arvore for uma folha (não hah nohs abaixos)
  //Chegada do codigo recursivo para o preenchimento da codificacao binaria do caractere
  if (r->esq == NULL && r->dir == NULL) 
  { 
    //escreve em codigo[c - 32] o codigo adequado
    for (int i = 0; i < profundidade; ++i) 
      tabela[r->ch - 32][i] = aux_codigo[i];

    //tabela armazena os codigos binarios para cada caractere
    //no final: marca o fim do codigo binario como 2 para representar ateh onde vai -> similar ao \0 da string
    tabela[r->ch - 32][profundidade] = 2; 
  }
}

//Wrapper para iniciar o percurso de "leitura" da arvore criada
void percorre_arvore(node *r, int **tabela) 
{
  //Vetor auxiliar que irah armazenar codigos temporarios
  int aux_codigo[TAMANHO_ALFABETO];

  //Nivel atual na arvore -> inicia em 0 pois começa no inicio da arvore
  int profundidade = 0;

  percorre_arvore_rec(r, aux_codigo, profundidade, tabela);
}

//Funcao para escrever o codigo em binario de um caractere
//Leva como base o peso da string e como foi posicionado na árvore para considerar o codigo binario
//Recebe uma tabela de codigo e um caractere c e escreve em str o codigo binario de 'c' descrito pela tabela
void write_code(char *str, char c, int **tabela) 
{
  int i = c - 32;  //Mapeia o indice na tabela -> serah usado para encontrar a posicao da linha do caractere na tabela
  int j = 0; //Irah representar a posicao do bit nas colunas da tabela da linha (i) do caractere

  //Looping que irah percorrer o codigo ateh encontrar o marcador de fim
  //Enquanto nao encontrar, vai concatenar na string os bits codificados do caractere
  while (tabela[i][j] != 2) 
  {             
    char bit_string[2]; //Vai armazar o bit (0 ou 1) + \0 na string
    sprintf(bit_string, "%d", tabela[i][j]); //Funcao da bibliota string.h para converte um int (bit) para string
    strcat(str, bit_string); //Concatena o bit do caractere convertido em string na str de bits codificados       
    j++;
  }
}

//******************************* INICIO DO HEAP *******************************
/*
 * Normalmente isso deveria ser uma TAD em arquivos separados, mas para simplificar deixei aqui mesmo.
 * Minha sugestao eh naum se preocupar demais com ela, mas entender o uso do:
 * criar_fila_prioridade, insere_na_fila e extrai_min_fila_prioridade.
 * Isso deve ser suficiente para usar a fila de prioridade
 */

//Definição das estruturas do heap para fila de prioridade
//Representa um elemento no heap
typedef struct heapElement 
{
  float chave;  //Chave usada para priorizacao
  void *no;     //Ponteiro para o noh associado
} heapElement;

//Estrutura da fila de prioridade que serah utilizada
typedef struct 
{
  int tamanho;       //Inteiro para contabilizar a quantidade atual de elementos na fila de prioridade
  heapElement *heap; //Array de elementos que serão armazenados na fila -> garante a contabilizacao da frequencia (chave) de cada elemento
} filaPrioridade;

//Função para criar uma fila de prioridade de minimos
filaPrioridade *criar_fila_prioridade(int tamanho_maximo) 
{
  //Alocação de memoria para a estrutura da fila
  filaPrioridade *Q = (filaPrioridade *) malloc(sizeof(filaPrioridade));
    
  //Aloca memoria para o heap interno com base no TAMANHO_ALFABETO definido
  //O tamanho com base no TAMANHO_ALFABETO permite que para cada letra seja armazenada sua frequencia
  //A posicao de cada letra no array será com base no seu número ASCII - 32
  //Isso irah garantir que o array seja contabilizado desde o 0 ateh o TAMANHO_ALFABETO
  Q->heap = (heapElement *) calloc(tamanho_maximo + 1, sizeof(heapElement));
    
  //Inicializa o tamanho de elementos da fila como 0 = fila vazia
  Q->tamanho = 0; 

  return Q; 
}

//Funcao para diminuir a chave de um elemento no heap
//Usado para correção do elemento inserido anteriomente
void diminui_chave(int i, float chaveNova, heapElement *A) 
{ 
  heapElement x; // Elemento auxiliar que serah usado para trocas de valores

  //Verificador que garante que a nova chave seja menor que a atual
  if (chaveNova > A[i].chave)  return;
    
  //Atualizacao da chave do elemento
  A[i].chave = chaveNova; 
   
  //Ajuste da posição do elemento no heap
  //Interrompe o laco caso chegue no topo da fila ou filho esquerdo for menor que o pai
  while (i > 1 && A[i / 2].chave > A[i].chave) 
  { 
    x = A[i / 2]; //Troca o elemento atual com o pai
    A[i / 2] = A[i];
    A[i] = x;
    i = i / 2; //Sobe no heap -> noh pai
  }
}

//Função para inserir um elemento na fila de prioridade
void insere_na_fila(filaPrioridade *Q, void *no, float chave) 
{
  //Incremento do tamanho da fila conforme inserção de um novo elemento na fila
  Q->tamanho++; 

  //Inserção de um novo noh no final da fila de prioriade -> posteriormente serah ajustado
  Q->heap[Q->tamanho].no = no;

  //Inicializa a chave como infinita
  //Usado para garantir que o novo elemento esteja temporariamente maior que todos os outros
  Q->heap[Q->tamanho].chave = INT_MAX; 

  //Ajusta a posição do elemento com a chave correta
  //O ajuste eh feito, pois durante insercao do novo elemento algumas regras do heap sao desconsideradas
  //Dessa forma, eh preciso ajustar essas regras desconsideradas apos a insercao
  diminui_chave(Q->tamanho, chave, Q->heap); 
}

//Funcao para reorganizar a fila apos a remocao de um elemento
//Garante que o menor elemento esteja no inicio da fila -> mantem a propriedade como o minimo no topo
void corrige_heap(int Esq, int Dir, heapElement *A) 
{
  //Indices que serao usados para percorrer o heap
  int i = Esq; 
  int j = i * 2; //indice do filho esquerdo

  //Armazena o elemento inicial da fila -> serah usado para reposicionar
  //Eh o elemento que serah reajustado
  heapElement x = A[i];

  //Vai percorre a fila para corrigir a posicao ate que o elemento a esquerda seja maior que o tamanho da fila
  while (j <= Dir) 
  { 
    //Condicao de escolha para o menor dos filhos
    //verifica se o filho esquedo eh menor que o tamanho do array -> se ha um filho direito
    //e, compara se filho esquerdo eh maior que o filho direito -> escolhe o filho direito como j com j++
    if (j < Dir && A[j].chave > A[j + 1].chave) j++;

    //Verificador da posicao, se estiver correta, interrompe o laco
    //x deve ser menor ou igual ao menor filho
    if (x.chave <= A[j].chave) break;

    A[i] = A[j]; //Move o menor filho para cima
    i = j;       //Avança para o próximo nível o noh de ajuste
    j = i * 2;   //Avança para o próximo nível o filho esquerdo
  }
  //Aloca o elemento na posição correta
  A[i] = x; 
}

//Função para extrair o menor elemento da fila de prioridade
//Responsavel por remover da fila e retornar o menor elemento da fila de prioridade
void *extrai_min_fila_prioridade(filaPrioridade *Q) 
{
  int * n =  &(Q->tamanho); 
  heapElement Min;

  //Verifica se a fila estivah vazia
  if (*n < 1) 
  {
    printf("Erro: heap vazio \n" );
    return NULL; 
  }

  else
  {
    //Armazena o menor elemento da fila -> noh principal
    //E move o ultimo elemento para a topo da fila (raiz)
    Min = Q->heap[1]; 
    Q->heap[1] = Q->heap[*n]; 
    (*n)--; 

    //Reorganiza o heap apos remocao do elemento
    corrige_heap(1, Q->tamanho, Q->heap); 
  }
  return Min.no;
}
//******************************** FIM DO HEAP ********************************

int main(int argc, char *argv[]) 
{
  // Primeiramente vamos ler a entrada e contabilizar a quantidade de cada caractere
  //a entrada serah salva no array entrada para depois fazer a codificacao
  char c; //serah usado para leitura de caracteres
  char entrada[TAMANHO_MAX_ENTRADA]; //serah usado para armazenar a string
  int count[TAMANHO_ALFABETO]; //serah usado para armazena a frequência de cada caractere
  int tam_entrada = 0;

  //Zerar a quantidade da frequencia do contador
  for (int i = 0; i < TAMANHO_ALFABETO; i++) 
    count[i] = 0; //Inicializacao de cada posição do array com uma frequencia de 0
    
  //lendo a entrada
  scanf("%c", &c);
    
  //Enquanto forem os caracteres validos continua lendo
  //Quando for um fim de texto, quebra de linha ou fim de arquivo, o loop se encerra tambem
  while(c >= INICIO_ALFABETO && c <= INICIO_ALFABETO + TAMANHO_ALFABETO)
  {
    //Incrementa na contagem a frequencia do caractere correspondente ao codigo da tabela ASCII
    count[c - INICIO_ALFABETO]++;
    //Armazena o caractere lido na string de entrada
    entrada[tam_entrada] = c;
    //Incrementa o tamanho da entrada para garantir que não ultrapasse 5000 caracteres
    tam_entrada++; 
    scanf("%c", &c);
  }

  /* Impressao do contador para verificacao
  for (int i = 0; i < TAMANHO_ALFABETO; i++)
  {
    if (count[i] > 0)
    {
      printf("count[%c] = %d\n", (char) i+32, count[i]);
    }
  } */

  //Cria a fila de prioridade com nohs para os caracteres
  filaPrioridade *Q = criar_fila_prioridade(TAMANHO_ALFABETO);

  //Looping de criação dos nohs na arvore de prioridade
  for (int i = 0; i < TAMANHO_ALFABETO; i++) 
  {
    //Caso o caractere tenha aparecido na string de entrada:
    if (count[i] > 0) 
    {
      node *no = criar_node(i + INICIO_ALFABETO, count[i], NULL, NULL); //Cria um noh (folha) na arvore
      insere_na_fila(Q, no, no->chave); //Insere o noh na fila com sua frequência
    }
  }

  //Construção da árvore de Huffman com os nohs criados a partir dos caracteres que apareceram
  //Looping que vai rodar enquanto houver mais de um elemento na fila
  //A cada iteração do looping irah reduzir a fila de prioridade
  while (Q->tamanho > 1) 
  {
    //Extrai o noh com menor frequencia para esquerdo e o segundo menor para o direito da fila de prioridade
    //Os dois nohs filhos com menor frequencia serao combinados para formar um noh pai
    node *filhoEsquerdo = (node *)extrai_min_fila_prioridade(Q); 
    node *filhodireiro = (node *)extrai_min_fila_prioridade(Q);
    //Cria um novo noh combinando os dois nohs extraidos
    //A frequencia do novo noh seria a combinacao da frequencia dos filhos -> garante uma boa organizacao da arvore
    node *novoNoh = criar_node(0, filhoEsquerdo->chave + filhodireiro->chave, filhoEsquerdo, filhodireiro); 
    //Insere o novo noh na fila de prioridade
    //A fila de prioridade eh reorganizada para garantir que a propriedade da fila (a minima frequencia) seja mantida
    insere_na_fila(Q, novoNoh, novoNoh->chave); 
  }
  //A raiz da arvore de Huffman
  //Serah o noh central que irah armazenar os demais nohs para a codificacao binaria
  //No final da criacao da arvore, os nohs mais ao topo terao uma frequência maior do que os nohs mais profundos que eles
  node *arvoreHufmman = (node *)extrai_min_fila_prioridade(Q); 

  //Imprime a arvore para teste (comente no final)
  //print_tree(arvoreHufmman); printf("\n");

  /*
   * Caracteres simples na tabela ASCII tem valores entre 32 ateh 126
   * Ou seja, existem 95 caracteres validos e no pior caso essa eh a altura da arvore
   * Se vc fosse fazer uma implementacao real, talvez aqui vc precisaria manipular bits
   * Aqui, com objetivo didatico, vamos fazer um arranjo de int mesmo.
   */

  //Alocacao memoria para a tabela de ccdigos
  int **tabela = (int **)calloc(TAMANHO_ALFABETO, sizeof(int *)); 

  //Geracao da tabela de ccdigos para os caracteres
  for (int i = 0; i < TAMANHO_ALFABETO; i++) 
  { 
    //Aloca memoria para cada linha da tabela
    //Ao todo, a quantidade de linhas serah o TAMANHO_ALFABETO que corresponde a um caractere
    //A quantidade de colunas por linhas tambem serah o TAMANHO_ALFABETO
    //As colunas irao servir para armazenar os bits de codificacao de cada caractere
    tabela[i] = (int *)calloc(TAMANHO_ALFABETO, sizeof(int));
    tabela[i][0] = 2; //Inicializa o código com o marcador de fim -> caso o caractere apareca ele serah alterado
  }

  percorre_arvore(arvoreHufmman, tabela); // Preenche a tabela com os códigos de Huffman

  //impressao do codigo para verificacao (comente no final)
  /*
  for (int i = 0; i < TAMANHO_ALFABETO; ++i) 
  {
    printf("%c: ", (char) i + 32);
    int j = 0;
    while(tabela[i][j] != 2)
    {
      printf("%d", tabela[i][j]);
      j++;
    }
    printf("\n");
  }
  for (int i = 0; i < tam_entrada; ++i) 
  {
    printf("%c", entrada[i]);
  }
  printf("\n");
  */

  //Inicio para escrever todo o codigo binario codificado dos caracteres em uma string
  //Eh alocado com o tamanho maximo possivel para evitar problemas de estouro, assume-se como base o pior caso
  char str[TAMANHO_MAX_ENTRADA * TAMANHO_ALFABETO] = {0};
  //Iteracao para cada caractere da entrada a fim de montar a codificacao um a um
  for (int i = 0; i < tam_entrada; i++) 
  { 
    //Adiciona o codigo correspondente ah string compactada
    //Encontra o codigo codificado correspondente ao caractere da (entrada[i]) na tabela de códigos
    write_code(str, entrada[i], tabela); 
  }

  //Impressao da string em binario para conferencia (comente no final)
  //printf("\n%s\n", str);

  //Tamanho da string compactada
  printf("%ld\n", strlen(str)); 
  return 0;
}
