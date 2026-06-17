#include<stdio.h>
#include<stdlib.h>

#define DEBUG 0 //Variavel setada para imprimir ou nao o teste do debug | Se DEBUG 1 testar os Debugs

typedef struct sno{
  char * string;
  struct sno * esq;
  struct sno * dir;
}no;

no * cria_no(char * str){ 
  no * novo = (no *) malloc(sizeof(no));
  novo->string = str; //note que isso sÃ³ copia apontador, 
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

no * criar_arvore(char ** perguntas, int num_perguntas){ //recebe o vetor de perguntas e o nro de perguntas | o tamanho total do vetor
  if(num_perguntas <= 0) return NULL; 
  no * arvore = cria_no(perguntas[0]); //cria um no para a primeira pergunta
  
  //Cria a arvore esquerda por recursao
  //Vai falar que o nro de perguntas diminuiu
  //(&(perguntas[1]) está passando endereço de memoria de perg[1]
  //por isso --> vai achar que o vetor começa ali e passa a ser o perg[0]
  //ele entende que o vetor começa por onde seu endereço passou, mas o vetor ainda existe
  //só está mudando aonde é o começo
  arvore->esq = criar_arvore(&(perguntas[1]), num_perguntas-1); 
  arvore->dir = criar_arvore(&(perguntas[1]), num_perguntas-1);
  return arvore;
}

void libera_arvore(no * arvore){
  if(arvore == NULL) return ;
  libera_arvore(arvore->esq);
  libera_arvore(arvore->dir);
  free(arvore);
  return;
}

//vai da esquerda para a direita descobrindo onde inserir o personagem
void insere_personagem(no* arvore, char * nome_personagem, int * respostas, int num_perguntas)
{
  no * atual = arvore; //vai verificar em qual nó você está --> começa na raiz da arvore
                      
  for(int i = 0; i < num_perguntas-1; i++) //vai ondar pelos nós até encontrar aonde inserir --> o nó da última pergunta
  {
    if(respostas[i] == 1) atual = atual->esq; //se for sim, desce para a esquerda
    else atual = atual->dir; //se for não, desce para direita
  }
  //chegou na ultima pergunta
  //faltou a ultima pergunta
  if(respostas[num_perguntas-1] == 1) atual->esq = cria_no(nome_personagem); //se for sim -> faz criar um nó esquerdo para o personagem
  else atual->dir = cria_no(nome_personagem); //se for nao -> faz criar um nó direito para o personagem
  return;
}

void le_ate(FILE * f, char c, char * str){
   char aux;
   int i = 0;
   fscanf(f, "%c", &aux);
   while(aux != c){
     str[i++] = aux;
     fscanf(f, "%c", &aux);
   }
   str[i] = '\0';
   return;
}

int main(int argc, char * argv[])
{
  int num_personagens; //armazena quais personagens vao ter na memoria
  int num_perguntas; //armazena quais perguntas serão feitas
  
  char aux[1024]; // usado para ler lixo
  int auxi;  //usado para ler lixo
  
  //arranjo para guardar as perguntas
  //vetor para as strings (pensar como uma matriz, mas cada linha da matriz guarda uma pergunta)
  char ** perguntas; 
  
  //arranjo para guardar o nome dos personagens
  char ** nome_personagens; 
  
  //arranjo para guardar as respostas reposta[p][i] é a resposta do personagem p para a pergunta i
  int ** respostas; 
  
  //Inicio do código para leitura de um arquivo externo
  //Leitura de um arquivo
  FILE * file_perguntas = fopen("teste.csv", "r");
  if(file_perguntas == NULL){
    printf("Erro ao abrir arquivo\n");
    return -1;
  }
  
  //Lendo o numero de personagens e o numero de perguntas
  fscanf(file_perguntas, "%d", &num_personagens);
  fscanf(file_perguntas, "%d", &num_perguntas);

  //alocando espaço para a matriz de perguntas na memoria
  perguntas = (char**) malloc(sizeof(char *)*num_perguntas);
  for(int i = 0; i < num_perguntas; i++){
    perguntas[i] = (char*) malloc(sizeof(char) * 1024); //nenhuma pergunta vai poder ter mais que 1024 caracteres.
  }
  
  //alocando espaço para a matriz de respostas na memoria
  respostas = (int **) malloc(sizeof(int *)*num_personagens);
  nome_personagens = (char**) malloc(sizeof(char *)*num_personagens);
  for(int p = 0; p < num_personagens; p++){
    respostas[p] = (int *) malloc(sizeof(int)*num_perguntas);
    nome_personagens[p] = (char *) malloc(sizeof(char) * 128); //cada nome nao pode passar de 128
  }
  
  //lendo o arquivo --> aqui está lendo apenas lixo
  le_ate(file_perguntas, ',', aux); //le a primeira virgula --> quando encontrar a virgula devolve
  if(DEBUG) printf("aux = %s\n", aux);
  le_ate(file_perguntas, ',', aux); //le o "Quantos iguais"
  if(DEBUG) printf("aux = %s\n", aux);
  
  //lendo as perguntas --> a partir daqui já fica importante a leitura
  for(int i = 0; i < num_perguntas; i++){
    le_ate(file_perguntas, ',', perguntas[i]);
  }
  
  //Esta só imprimindo
  if(DEBUG){
    for(int i = 0; i < num_perguntas; i++){
      printf("Pergunta %d: %s\n", i+1, perguntas[i]);
    }
  }
  le_ate(file_perguntas, '\n', aux); //ignora tudo ate a quebra de linha
  
  //lendo os personagens e suas respostas
  for(int p = 0; p < num_personagens; p++){
    le_ate(file_perguntas, ',', nome_personagens[p]); //ignora tudo ate a quebra de linha
    fscanf(file_perguntas, "%d,", &auxi); //le o numero de repeticoes
    for(int i = 0; i < num_perguntas; i++){
      fscanf(file_perguntas, "%d,", &(respostas[p][i]));
    }
    //le o resto da linha, exceto o ultimo pois
    //o ultimo personagem talvez nÃ£o tenha uma quebra de linha
    if(p != num_personagens-1) le_ate(file_perguntas, '\n', aux); 
  }
  //Ideal fechar os arquivos --> principalmente se for escrever em cima dele
  fclose(file_perguntas); //fecha o arquivo aberto
  
  //Debug para imprimir e testar
  if(DEBUG){
    for(int p = 0; p < num_personagens; p++){
      printf("%s: ", nome_personagens[p]); 
      for(int i = 0; i < num_perguntas; i++){
        printf("%d ", respostas[p][i]); 
      }
      printf("\n");
    }
  }
  //Fim da leitura do arquivo
  
  
  //COMECANDO A CRIACAO DA ARVORE
  no* arvore = criar_arvore(perguntas, num_perguntas);

  //insere os personagens nas perguntas
  for(int p = 0; p < num_personagens; p++)
  {
    insere_personagem(arvore, nome_personagens[p], respostas[p], num_perguntas); 
  }
  
  int opi = 2;
  no * atual = NULL;
  while(opi != -1){
    if(atual == NULL) atual = arvore;
    printf("%s\n", atual->string);
    scanf("%d", &opi);
    if(opi == 1) atual = atual->esq; 
    if(opi == 0) atual = atual->dir;
    if(opi == -1) break;
  }
  
  
  libera_arvore(arvore);
    
  
  //LIBERANDO MEMORIA lembre de liberar a arvore tambem;  
  for(int i = 0; i < num_perguntas; i++) free(perguntas[i]);
  free(perguntas);
  for(int p = 0; p < num_personagens; p++){
    free(respostas[p]);
    free(nome_personagens[p]);
  }
  free(nome_personagens);
  free(respostas);
}
