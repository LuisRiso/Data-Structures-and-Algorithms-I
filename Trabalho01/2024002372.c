//Trabalho Multiplicacao de Matrizes

#include <stdio.h>
#include <stdlib.h>

typedef struct pixelImagem pixImg;
typedef struct filtroImagem filImg;

//Struct que ira receber tanto os pixels inicias, quanto os pixel da multiplizacao com o filtro
struct pixelImagem
{
  int pixel1;
  int pixel2;
  int pixel3;
  int pixelFiltro1; //valores indefinidos
  int pixelFiltro2; //valores indefinidos
  int pixelFiltro3; //valores indefinidos
};

//Struct que ira receber os filtro de imagem
//Feito separamente para ter uma maior clareza na multiplicacao da matriz
//Poderia estar inserido tambem na Struct pixelImagem
struct filtroImagem
{
  int filtro1;
  int filtro2;
  int filtro3;
};

//Funcoes chamadas inicialmente no codigo
pixImg** alocacaoPixel(int lin, int col);
filImg** alocacaoFiltro(int lin, int col);
void multiplicaMatriz(pixImg **pixel, filImg **filtro, int lin, int col);
void liberarPonteiro(pixImg **pixel, int lin);

int main(int argc, char *argv[])
{
  char PPM[3];      //Variavel para ler a string inicial dos codigos (P3)
  int lin, col;     //Linhas e colunas dos pixels que a matriz ira receber -- no exercicial, ambos possuem o mesmo valor (matriz quadrada)
  int escalaMaxima; //Escala maxima do pixel, para o codigo, ira apenas receber o valor
  int i, j;         //Variaveis para percorrer as matrizes
  pixImg **pixel = NULL;  //Ponteiro de ponteiro para alocar a matriz dos Pixels
  filImg **filtro = NULL; //Ponteiro de ponteiro para alocar a matriz dos Filtros

//Leitura Inicial das Informacoes
  scanf(" %[^\n]", PPM);
  scanf(" %d %d", &lin, &col);
  scanf(" %d", &escalaMaxima);
  
//Chamada das funcoes para alocacao das matriz
//Havera duas funcoes de alocacao devido a diferenca de nomes das variaveis nas structs
  pixel = alocacaoPixel(lin, col);    
  filtro = alocacaoFiltro(lin, col);
  multiplicaMatriz(pixel, filtro, lin, col);

//Impressao da imagem com o filtro
  printf("P3\n");
  printf("%d %d\n", lin, col);
  printf("%d\n", escalaMaxima);
  //printf("\nMultiplicacao Comeca Aqui\n");
  for(i = 0; i < lin; i++)
  {
    for(j = 0; j < col; j++)
    {
      printf("%d", pixel[i][j].pixelFiltro1);
      printf(" %d", pixel[i][j].pixelFiltro2);
      printf(" %d ", pixel[i][j].pixelFiltro3);
    }
    printf("\n");  
  }
  liberarPonteiro(pixel, lin);
  return 0;
}

//Funcao para alocar a Matriz Pixel
//Ira receber as linhas e colunas (poderia ser apenas um dos valores) e devolver um ponteiro de ponteiro com a matriz
pixImg** alocacaoPixel(int lin, int col)
{
  int i, j;
  pixImg **matrizP = (pixImg **)malloc(lin * sizeof(pixImg *));
  for(i = 0; i < lin; i++)
  {
    matrizP[i] = (pixImg *)malloc(lin * sizeof(pixImg));
    for(j = 0; j < col; j++)
    {
      scanf(" %d", &matrizP[i][j].pixel1);
      scanf(" %d", &matrizP[i][j].pixel2);
      scanf(" %d", &matrizP[i][j].pixel3);
    }
  }
  return matrizP;
}

//Funcao para alocar a Matriz Filtro
//Ira receber as linhas e colunas (poderia ser apenas um dos valores) e devolver um ponteiro de ponteiro com a matriz
filImg** alocacaoFiltro(int lin, int col)
{
  int i, j;
  filImg **matrizF = (filImg **)malloc(lin * sizeof(filImg *));
  for(i = 0; i < lin; i++)
  {
    matrizF[i] = (filImg *)malloc(lin * sizeof(filImg));
    for(j = 0; j < col; j++)
    {
      scanf(" %d", &matrizF[i][j].filtro1);
      scanf(" %d", &matrizF[i][j].filtro2);
      scanf(" %d", &matrizF[i][j].filtro3);
    }
  }
  return matrizF;
}

//Funcao para realizar a Multiplicacao das Matriz
//O looping inicia zerando os valores a serem multiplicados para nao haver lixo de memoria alocado e garantir os valores corretos
//Utiliza-se uma variavel K auxiliar para percorrer os vetores e multiplicar a matriz
void multiplicaMatriz(pixImg **pixel, filImg **filtro, int lin, int col)
{
  int i, j, k;
  for(i = 0; i < lin; i++)
  {
    for(j = 0; j < col; j++)
    {
      pixel[i][j].pixelFiltro1 = 0;
      pixel[i][j].pixelFiltro2 = 0;
      pixel[i][j].pixelFiltro3 = 0;
      for(k = 0; k < lin; k++)
      {
	      pixel[i][j].pixelFiltro1 += pixel[i][k].pixel1 * filtro[k][j].filtro1;
        pixel[i][j].pixelFiltro2 += pixel[i][k].pixel2 * filtro[k][j].filtro2;
        pixel[i][j].pixelFiltro3 += pixel[i][k].pixel3 * filtro[k][j].filtro3;
      }
    }
  }
}

//Funcao recursiva para desalocar a memoria que foi alocado para as matriz
//Recebera a matriz e o tamanho maximo de linhas
//Ira remover o pixel da linha criada para a matriz e chamar a funcao novamente para a linha anterior ate chegar ao caso base
void liberarPonteiro(pixImg **pixel, int lin)
{
  if(lin == 0)
  {
    free(pixel[lin]);
    free(pixel);
    return;
  }
  free(pixel[lin]);
  liberarPonteiro(pixel, lin-1);
}

