#include <stdlib.h>
typedef struct TPIL tPilha;
/* pilha_cria: recebe um valor max e
cria uma estrutura de Pilha para max itens
*/
tPilha * pilha_cria(int);
/* pilha_tavazia: recebe uma pilha e
   retorna 1, se esta pilha está vazia ou
           0, se não está vazia
*/
int pilha_tavazia(tPilha*);
/* pilha_tacheia: recebe uma pilha e
   retorna 1, se esta pilha está cheia ou
           0, se não está vazia
*/
int pilha_tacheia(tPilha*);
/* pilha_inclui: recebe uma pilha e uma inf
  incluia inf depois do topo da pilha
   retorna 1, se inclusão bem sucedida
           0, cc
*/
int pilha_inclui(tPilha*, int); //Push
/* pilha_exclui: recebe uma pilha e 
                 o endereço de uma variável  
    copia a inf do topo da pilha na variável
    retirando-a
   retorna 1, se exclusão bem sucedida
           0, cc
*/

void pilha_destroi(tPilha * p);

int pilha_exclui(tPilha*, int *); //pop

/* pilha_consultaTopo: recebe uma pilha e 
                 o endereço de uma variável  
    copia a inf do topo da pilha na variável
   retorna 1
*/
int pilha_consultaTopo(tPilha*, int *); 

/* pilha_clona: recebe uma pilha, cria uma auxiliar e retorna o clone ou 0 
*/
int *pilha_clona(tPilha*);