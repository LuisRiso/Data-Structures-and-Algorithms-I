//Torre de Hanoi
/*Esse código resolve o clássico 
 *Problema das Torres de Hanoi, que consiste em mover uma pilha de discos de uma torre para outra, 
 *obedecendo a algumas regras: 
 *só se pode mover um disco de cada vez, 
 *um disco maior não pode ser colocado sobre um menor, 
 *e temos uma torre auxiliar para ajudar no processo.
*/
#include <stdio.h>
#include <stdlib.h>


//Função para Imprimir os movimentos para levar n discos de ini até dest
//Usando aux para ajudar
void hanoi(int n, int ini, int dest, int aux);

int main(int argc, char *argv[])
{
  hanoi(4, 1, 3, 2);
  return 0;
}

//int n -> Representa o número de discos que precisamos mover. 
//int ini -> Representa a torre de origem, ou seja, a torre onde estão empilhados os discos no início do movimento.
//int dest -> Representa a torre de destino, ou seja, a torre para onde queremos mover todos os discos, organizados na mesma ordem que estavam na torre inicial.
//int aux -> Representa a torre auxiliar, usada temporariamente para armazenar discos enquanto movemos outros discos entre a torre inicial e a torre de destino.

//Cada chamada recursiva diminui o valor de n até que atinja 1, o caso base, onde o disco é movido diretamente.
//n é o fator que controla a profundidade da recursão, quebrando o problema em partes menores.

void hanoi(int n, int ini, int dest, int aux)
{
  if(n == 1)
  {
    printf("Mova disco %d, de Torre %d para Torre %d\n", n, ini, dest);
    return;
  }
  //Mover os n-1 de ini até aux, posso usar dest como auxiliar
  //Muda os n-1 discos menores da torre inicial ini para a torre auxiliar aux, deixando o disco n sozinho em ini.
  hanoi(n-1, ini, aux, dest);
  
  //Mover o disco grande de ini até dest
  //Move o disco n da torre inicial ini diretamente para a torre de destino dest.
  printf("Mova disco %d, de Torre %d para Torre %d\n", n, ini, dest);
  
  //Mover os n-1 discos de aux até dest, posso usar ini como auxiliar
  //Move os n-1 discos da torre auxiliar aux para a torre de destino dest, usando ini como auxiliar.
  hanoi(n-1, aux, dest, ini);
  return;
}

