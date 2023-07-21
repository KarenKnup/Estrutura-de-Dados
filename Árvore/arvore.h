// Definição da estrutura do nó da árvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Funções da árvore
No* criarNo(int valor);
No* inserirNo(No* raiz, int valor);
void percorrerEmOrdem(No* raiz);
void liberarArvore(No* raiz);
