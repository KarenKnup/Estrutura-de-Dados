#define MAX 100 // tamanho máximo da lista

typedef struct {
    int elementos[MAX]; // vetor de elementos da lista
    int qtd; // quantidade atual de elementos na lista
} Lista;

// Funções para manipulação da lista
void inicializaLista(Lista* l);
int tamanhoLista(Lista* l);
int listaVazia(Lista* l);
int listaCheia(Lista* l);
int buscaSequencial(Lista* l, int valor);
int buscaBinaria(Lista* l, int valor);
int insereOrdenado(Lista* l, int valor);
int removeElemento(Lista* l, int valor);
void exibeLista(Lista* l);
