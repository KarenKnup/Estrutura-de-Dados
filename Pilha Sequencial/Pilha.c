#include <stdlib.h>
#include "Pilha.h"
struct TPIL{
  int max;
  int topo;
  int*vNos;
} ;
tPilha * pilha_cria(int max){
  tPilha * p=  (tPilha*) malloc(sizeof(tPilha));
  if (p==NULL)
    return p;
  p->vNos=(int*)malloc(sizeof(int)*max);
  if (p->vNos==NULL){
    free(p);
    return NULL;
  }
  p->topo=-1;
  p->max=max;
  return p;
}
    
/* pilha_tavazia: recebe uma pilha e
   retorna 1, se esta pilha está vazia ou
           0, se não está vazia
*/
int pilha_tavazia(tPilha*p){
  return p->topo == -1;
}
/* pilha_tacheia: recebe uma pilha e
   retorna 1, se esta pilha está cheia ou
           0, se não está vazia
*/


int pilha_tacheia(tPilha*p){
  return p->topo == p->max;
}

/* pilha_inclui: recebe uma pilha e 
                 o endereço de uma variável  
    copia a inf do topo da pilha na variável
    retirando-a
   retorna 1, se exclusão bem sucedida
           0, cc
*/
int pilha_inclui(tPilha*p, int inf){
  if (pilha_tacheia(p))
    return 0;
  (p->topo)++;
  p->vNos[p->topo]=inf;
  return 1;
  
}
/* pilha_exclui: recebe uma pilha e 
                 o endereço de uma variável  
    copia a inf do topo da pilha na variável
    retirando-a
   retorna 1, se exclusão bem sucedida
           0, cc
*/
int pilha_exclui(tPilha*p, int * inf){
   if (pilha_tavazia(p))
      return 0;
  (*inf) = p->vNos[p->topo];
  (p->topo)--;
  return 1;
}

void pilha_destroi(tPilha * p){
  free(p->vNos);
  free(p);
}   

/* pilha_consultaTopo: recebe uma pilha e 
                 o endereço de uma variável  
    copia a inf do topo da pilha na variável
   retorna 1, se exclusão bem sucedida
           0, cc
*/
int pilha_consultaTopo(tPilha*p, int *inf){
  if (pilha_tavazia(p))
      return 0;
  (*inf) = p->vNos[p->topo];
  return 1;
}

/* pilha_clona: recebe uma pilha, cria uma auxiliar e retorna o clone ou 0 
*/
int *pilha_clona(tPilha*p) {
  tPilha* aux = pilha_cria(p->max); 
  aux = p;
  
}