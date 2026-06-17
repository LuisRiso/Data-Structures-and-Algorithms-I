typedef struct pilhaa *pilha;

//Cria a pilha iniciar que vai ser usada como uma lista ligada
pilha criarPilha();

//Empilhar caracteres em uma pilha (push)
void empilhar(pilha P, int x, int y); //--> vai empilhar caracteres

//Devolver um caracter da pilha (pop)
void desempilhar(pilha P, int *x, int *y);

//Verifica se a pilha está vázia ou não, devolve 0 ou 1
int pilhaVazia(pilha P);

//Apaga a fila para liberar memória
void liberarPilha(pilha P);


