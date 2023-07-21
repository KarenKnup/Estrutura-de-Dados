#define MAX 100

typedef struct {
    int elementos[MAX];
    int qtd;
} Lista;

Lista* criaLista();
void destroiLista(Lista* l);
int insereElemento(Lista* l, int valor);
int removeElemento(Lista* l, int valor);
int buscaSequencial(Lista* l, int valor);
void exibeLista(Lista* l);
