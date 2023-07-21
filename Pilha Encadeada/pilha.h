typedef struct no No;
typedef struct pilha Pilha;

Pilha* criaPilha();
void destroiPilha(Pilha* p);
int push (Pilha* p, float valor);//empilha
float pop (Pilha* p);//desempilha

void concatena_pilhas(Pilha* p1, Pilha* p2);
int topo(Pilha* p);

float top (Pilha* p);
int tamanho(Pilha* p);
int vazia(Pilha* p);
