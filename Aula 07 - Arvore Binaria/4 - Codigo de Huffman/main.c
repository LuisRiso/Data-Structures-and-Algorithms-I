//Vou considerar um alfabeto de 6 letras: a, b, c, d, e, f
//Todo caractere tem o mesmo número de Bits (normalmente 8)
//Para esse alfabeto, vou considerar uma representação de 3 bits
//a = 000
//b = 001
//c = 010
//d = 011
//e = 100
//f = 101

//Para escrever babaca == 001 000 001 000 010 000 = 18 bits
//Para representar 100.000 caracteres, vai precisar de 300.000 bits

//O problema: quero comprimir os meus dados alocados, para passar para uma quantidade menor de bits
//Quero uma codificação do alfabeto de forma que economize esses bits
//O segredo é que não é preciso que todo caractere tenha a mesma quantidade de representações de bits

//Queremos fazer uma codificação de tamanho variavel livre de prefixos
//Livre de prefixo --> dado qualquer caractere, o prefixo dele não é a representação de outro caractere

//Solução: vai receber um determinado texto e criar uma codifição especifica para cada texto

//Codigo de Huffman
//Cria uma arvore binaria que representa uma codificação
//Cada ramificação para esquerda temos um bit 0 e cada ramificação a direita temos um bit 1
//As folhas representam os caracteres (todas as letras estão nas folhas)
//Os nós internos não representam nenhuma letra (Livre de Prefixos)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Estrutura para representar um noh da Arrvore de Huffman
typedef struct No 
{
    char data;
    unsigned freq;
    struct No *left, *right;
}No;

// Funcao para criar um novo no da Arvore de Huffman
No* cria_no(char data, unsigned freq)  //passa o caractere e a frenquencia que ele aparece
{
    No* node = (No*)malloc(sizeof(No));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Funcao para contar a frequencia de cada caractere em um arquivo
void calculaFreq(const char *filename, int freq[]) 
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    
    // Inicializa a frequencia de todos os caracteres com zero
    for (int i = 0; i < MAX_CHARS; i++) freq[i] = 0;

    char ch;
    //fgetc -> vai ser cada caractere do arquivo
    //file vai guardar o apontador do arquivo
    //end o file (EOF) mostra que o arquivo acabou
    while ((ch = fgetc(file)) != EOF) 
    {
        freq[(unsigned char)ch]++; //unsigned char vai transformar o caractere em um valor da tabela ASC
                                   //freq[256] -> funciona como um sinal de contagem
                                   //toda vez que um caractere aparece, 
                                   //acrescente +1 na posição desse caractere no vetor
    }

    fclose(file);
}

int encontrarMinimo(No **Q, int tam)
{
  int menor = 0; //representa que você não sabe quem é o menor ainda
  for(int i = 1; i < tam; i++)
  {
    if(Q[menor]->freq > Q[i]->freq)
    {
      menor = i;
    }
  }
  return menor;
}

//**** Implementar *****/
No *huffman(int freq[]) //freq[] = *freq
{
  //1o passo -> criar um vetor para guardar os nohs
  
  No *Q[MAX_CHARS]; //vai guardar enderecos de nohs
                   //como o numero de caracteres é fixo --> você sabe que o numero maximo de nohs é MAX_CHARS
                   
  int tam = 0;
  for(int i = 0; i < MAX_CHARS; i++)
  {
    if(freq[i] > 0) //Só vai colocar no Q os caracteres que tem uma freq > 0
    {
      Q[tam++] = cria_no((char)i, freq[i]);
    }
  }
  
  //vai juntar duas folhas em um no
  while(tam > 1)
  {
    int min1 = encontrarMinimo(Q, tam);
    No *left = Q[min1]; //salvou qual é o minimo
    Q[min1] = Q[tam-1]; //vai colocar o de menor frequencia no minimo
    tam--; //vai diminuir o tamanho do vetor
    
    int min2 = encontrarMinimo(Q, tam);
    No *right = Q[min2];
    Q[min2] = Q[tam-1];
    tam--;
    
    No *novo = cria_no('\0', left->freq + right->freq); //vai juntar os dois menores encontrados
    novo->left = left; //esquerdo aponta para o menor valor1
    novo->right = right; //direito aponta para o menor valor2
    
    Q[tam] = novo;
    tam++;
  }
  return Q[0];
}


//Quero que ela percorra minha arvore e quando chegar em uma filha
//Imprima o caractere e qual o código do caractere
//Vai fazer uma busca em profundidade
//char code[] --> está ai para lembrar qual caminho foi percorrido
void imprimeCodigo(No *arvore, char code[], int posicao)
{
  //vai percorrer na esquerda e na direita codificando os nohs
  //vai inserir 0 na esquerda
  //vai inserir 1 na direita
  if(arvore->left != NULL)
  {
    code[posicao] = '0';
    imprimeCodigo(arvore->left, code, posicao+1);
  }
  if(arvore->right != NULL)
  {
    code[posicao] = '1';
    imprimeCodigo(arvore->right, code, posicao+1);
  }
  
  //se estiver em uma folha sem filho e esquerdo e filho direito 
  //significa que chegou em um caractere de fato
  //a arvore do jeito que foi construida --> sempre tem dois filhos
  if(arvore->left == NULL && arvore->right == NULL) //cheguei em um caractere
  {
    code[posicao] = '\0'; //insere o \0 para poder imprimir o code como um string em seguida
                          //o code impresso sera o codigo de 0 e 1 do caractere
    printf("%c = %s\n", arvore->data, code);
  }
  
}

int main() {
    char *filename = "texto.txt";
    int freq[MAX_CHARS];
    calculaFreq(filename, freq); //vai pegar o arquivo e vai preencher o valor de frequencia 
                                 //com quantas vezes cada caractere aparece

    No *root = huffman(freq);    //vai construir a arvore e passar para o alg de huffman

    char code[MAX_CHARS];
    printf("Codigos de Huffman:\n");
    imprimeCodigo(root, code, 0);

    return 0;
}

