typedef struct no tNo;
typedef struct LDEC tLDEC;

//Criar uma lista
tLDEC* cria_lista(int isClassif, int comRepet);
//Destruir uma lista
void destroiLDEC(tLDEC* pL);
//Imprimir uma lista 
void imprimeLDEC(tLDEC* pL);
//Inserir um elemento em uma lista
int insereLDEC(tLDEC* pL, int inf);
//Remover um elemento da lista
int removeLDEC(tLDEC* pL, int inf);
