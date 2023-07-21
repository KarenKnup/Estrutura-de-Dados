typedef struct no No;
typedef struct lista Lista;

Lista* criaLista();
void destroiLista(Lista* l);
int insereElemento(Lista* l, int valor);
int removeElemento(Lista* l, int valor);
int buscaElemento(Lista* l, int valor);
void exibeLista(Lista* l);
