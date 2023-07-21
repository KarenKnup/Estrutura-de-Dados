typedef struct no No;
typedef struct fila Fila;

Fila* criaFila();
void destroiFila(Fila* f);
int enfileira(Fila* f, int valor);
int desenfileira(Fila* f);
int primeiro(Fila* f);
int tamanho(Fila* f);
int vazia(Fila* f);

