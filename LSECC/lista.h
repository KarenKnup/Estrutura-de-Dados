typedef struct no tNo;
typedef struct LSECC tLSECC;

//Criar uma lista - retorna a lista ou FALSE (0), caso não tenha espaço
tLSECC* cria_lista (int isClassif, int comRepet);

//inserir um elemento na lista - retorna TRUE(1) se for possível ou FALSE(0) se não for
int inserir (tLSECC *l, int id);

//Exibir a lista
void exibir_lista (tLSECC *l);

//Remover um elemento da lista - retorna TRUE(1) se for possível ou FALSE(0) se não for
int remover (tLSECC *l, int id);

//Destruir uma lista
void destroiLDEC(tLSECC* l);

tLSECC* cria_sublista (tLSECC* l1, int qtde) ;
