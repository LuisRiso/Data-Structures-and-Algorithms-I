//Atua como uma interface
//Comunicação entre o main.c e o fila.c

typedef struct filaPonteiro * fila; //fila vai ser implementado para a struct filaPonteiro

//Função para criar uma fila
fila criarFila();

//Função para inserir um inteiro em uma fila passsada por parametro
void inserirFila(fila, int);

//Função para remover o inteiro que está na fila e devolver o próximo valor
int removerFila(fila);

//Função para liberar o valor que está na fila
void liberarFila(fila);

//Devolve 1 se a fila estiver vazia e 0 se não
int filaVazia(fila);
