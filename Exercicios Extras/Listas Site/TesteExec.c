#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int recursao(int m)
{
    if(m == 0)
        return -1;
    if(m == 1)
        return 2;
    return recursao(m-1)*recursao(m-1)*recursao(m-2);
}

int main() {
    
    long long int r;

    r = recursao(5);
    printf("Resultado = %d\n", r);

    return 0;
}
