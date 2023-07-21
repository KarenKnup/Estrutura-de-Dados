typedef struct fila Fila;

Fila* criaFila(int tamanhoMax);
void destroiFila(Fila* f);
int enfileira(Fila* f, int valor);
int desenfileira(Fila* f);
int frente(Fila* f);
int tamanho(Fila* f);
int vazia(Fila* f);
int cheia(Fila* f);
