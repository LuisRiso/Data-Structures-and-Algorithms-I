//Multiplicacao de Matrizes

#include <stdio.h>
#include <stdlib.h>

typedef struct pixelImagem pixImg;

struct pixelImagem
{
  int pixel1; //pixels de entrada, sempre serão 3 valores
  int pixel2;
  int pixel3;
  int filtro1; //filtros de imagem, sempre serão 3 valores
  int filtro2;
  int filtro3;
  int pixelFiltro1; //valores para multiplicação entre o pixel e o filtro
  int pixelFiltro2; //resultado obtido por uma multiplicação de matrizes
  int pixelFiltro3; //m[i][j] = m[i][k] * m[k][j]
};

pixImg** alocacaoPixel(int lin);
void leituraPixel(pixImg **pixel, int lin, int col);
void multiplicaMatriz(pixImg **pixel, int lin, int col);
void imprimeResultado(pixImg **pixel, int lin, int col, int escalaMaxima);
void liberarPonteiro(pixImg **pixel, int lin);

int main(int argc, char *argv[])
{
  char PPM[3];
  int lin, col;
  int escalaMaxima;
  pixImg **pixel = NULL;

  scanf(" %[^\n]", PPM);
  scanf(" %d %d", &lin, &col);
  scanf(" %d", &escalaMaxima);
  
  pixel = alocacaoPixel(lin);
  leituraPixel(pixel, lin, col);
  multiplicaMatriz(pixel, lin, col);
  imprimeResultado(pixel, lin, col, escalaMaxima);
  liberarPonteiro(pixel, lin);

  return 0;
}

pixImg** alocacaoPixel(int lin)
{
  int i;
  pixImg **matriz = (pixImg **)malloc(lin * sizeof(pixImg *));
  for(i = 0; i < lin; i++)
  {
    matriz[i] = (pixImg *)malloc(lin * sizeof(pixImg));
  }
  return matriz;
}

void leituraPixel(pixImg **pixel, int lin, int col)
{
  int i, j;

  for(i = 0; i < lin; i++)
  {
    for(j = 0; j < col; j++)
    {
      scanf(" %d", &pixel[i][j].pixel1);
      scanf(" %d", &pixel[i][j].pixel2);
      scanf(" %d", &pixel[i][j].pixel3);
    }
  }

  for(i = 0; i < lin; i++)
  {
    for(j = 0; j < col; j++)
    {
      scanf(" %d", &pixel[i][j].filtro1);
      scanf(" %d", &pixel[i][j].filtro2);
      scanf(" %d", &pixel[i][j].filtro3);
    }
  }
}

void multiplicaMatriz(pixImg **pixel, int lin, int col)
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
	pixel[i][j].pixelFiltro1 += pixel[i][k].pixel1 * pixel[k][j].filtro1;
        pixel[i][j].pixelFiltro2 += pixel[i][k].pixel2 * pixel[k][j].filtro2;
        pixel[i][j].pixelFiltro3 += pixel[i][k].pixel3 * pixel[k][j].filtro3;
      }
    }
  }
}

void imprimeResultado(pixImg **pixel, int lin, int col, int escalaMaxima)
{
  int i, j;
  printf("P3\n");
  printf("%d %d\n", lin, col);
  printf("%d\n", escalaMaxima);
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
}

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


