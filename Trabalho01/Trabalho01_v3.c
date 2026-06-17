//Multiplicacao de Matrizes

#include <stdio.h>
#include <stdlib.h>

typedef struct pixelImagem pixImg;
typedef struct filtroImagem filImg;

struct pixelImagem
{
  int pixel1;
  int pixel2;
  int pixel3;
  int pixelFiltro1; //valores indefinidos
  int pixelFiltro2; //valores indefinidos
  int pixelFiltro3; //valores indefinidos
};

struct filtroImagem
{
  int filtro1;
  int filtro2;
  int filtro3;
};

pixImg** alocacaoPixel(int lin, int col);
filImg** alocacaoFiltro(int lin, int col);
void multiplicaMatriz(pixImg **pixel, filImg **filtro, int lin, int col);
void liberarPonteiro(pixImg **pixel, int lin);

int main(int argc, char *argv[])
{
  char PPM[3];
  int lin, col;
  int escalaMaxima;
  int i, j;
  pixImg **pixel = NULL;
  filImg **filtro = NULL;

  scanf(" %[^\n]", PPM);
  scanf(" %d %d", &lin, &col);
  scanf(" %d", &escalaMaxima);
  
  pixel = alocacaoPixel(lin, col);
  filtro = alocacaoFiltro(lin, col);
  multiplicaMatriz(pixel, filtro, lin, col);

  //system("clear");
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

