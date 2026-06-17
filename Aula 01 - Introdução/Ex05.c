//Quero criar minha propria função que concatene duas string
//Ela recebe duas strings
//As duas strings estão bem formatadas -> tem os caracteres uteis e no final há o \0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Formato da função
char *concatena(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char *sres = (char *)malloc((100)*sizeof(char));
	while(1)
	{
		if(s1[i] == '\0')
			break;
		*(sres + i) = *(s1 + i);
		i++;
	}
	while(1)
	{
		if(s2[j] == '\0')
			break;
		*(sres + i + j) = *(s2 + j);
		j++;
	}
	return sres;
}

int main(int argc, char *argv[])
{
	char s1[50];
	char s2[50];
	char *scat;

	scanf(" %[^\n]", s1);
	scanf(" %[^\n]", s2);
	
	scat = concatena(s1, s2);
	
	printf("%s\n", scat);
	
	free(scat);
	
	return 0;
}
