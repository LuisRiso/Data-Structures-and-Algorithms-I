#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int *x = (int *)malloc(sizeof(int) * 10);
  for(int i = 0; i < 10; i++)
    printf("%d\n", x[i]);
  
  free(x);
  return 0;
}
