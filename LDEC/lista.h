typedef struct no No;
typedef struct lista Lista;

Lista* criar_lista();
void inserir_no_inicio(Lista *lista, int num);
void inserir_no_fim(Lista *lista, int num);
void inserir_ordenado(Lista *lista, int num);
No* remover(Lista *lista, int num);
No* buscar(Lista *lista, int num);
void imprimir(Lista *lista);
