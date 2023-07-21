typedef struct tlst TLista;

//Cria uma lista de números inteiros
TLista* lst_cria (int max, int classif, int repet);

//Verifica se uma lista está cheia
int lst_cheia (TLista* l);

//Verifica se uma lista está vazia
int lst_vazia (TLista *l);

//Verifica se a lista é Classificada 
int lst_ehClassif (TLista* l);

//Verifica se a lista tem Repetições
int lst_temRepet (TLista* l);

//Busca em uma lista um número "chave" e armazena a posição desse número na lista em "pos"
int busca (TLista* l, int chave, int *pos);

//Inserir um elemento na lista
int lst_inclusao (TLista *l, int n);

//Remover um elemento da lista
int lst_remocao (TLista* l, int n);
