//Baseado na solução de Lucas Beriba
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct no {
  int inf; 
  tNo* prox;
};

struct LSECC {
  tNo* cabeca;
  int qtdNos; //quantidade de nós
  int isClassif, //TRUE(1) para ordem crescente e FALSE(0) para desordenado
      comRepet; //TRUE(1) para com repetição e FALSE(0) sem repetição
};

tNo* criaNo(int inf){
  tNo* no = (tNo*) malloc(sizeof(tNo));

  no->inf = inf;
  no->prox = NULL;

  return no;
}

int busca(tLSECC* l, int inf, tNo** pAnt){
  int isClassif = l->isClassif;
  int comRepet = l->comRepet;
  tNo *p,*pRast;
             
  if (isClassif){                 
    for (p = l->cabeca->prox,pRast = l->cabeca; p!=l->cabeca && p->inf < inf;pRast=p,p=p->prox);
 }   
 else{ 
   for (p = l->cabeca->prox,pRast = l->cabeca; p->inf != inf && p != l->cabeca ;pRast=p,p=p->prox);
 }                                         
  (*pAnt)=pRast;
  
  return (p != l->cabeca && p->inf == inf);
}


//Criar uma lista
tLSECC* cria_lista (int isClassif, int comRepet){
  tNo* cabeca = (tNo*) malloc(sizeof(tNo));
  tLSECC* l = (tLSECC*) malloc(sizeof(tLSECC));
  
  cabeca->inf = 0;
  cabeca->prox = cabeca;
  
  if (l != NULL){
    l->cabeca = cabeca; 
    l->qtdNos = 0;
    l->isClassif = isClassif;
    l->comRepet = comRepet;
  } else {
    return FALSE;
  }

  return l;
}


//inserir um elemento na lista
int inserir (tLSECC *l, int inf){
  tNo *pNovo, *pAnt, *pAtual;
  int isClassif, comRepet, sit;

  isClassif = l->isClassif;
  comRepet = l->comRepet;
  
   if (isClassif==FALSE && comRepet==TRUE){
     pAnt=l->cabeca;
     sit=FALSE;
   } else{
    sit = busca(l, inf, &pAnt); 
  } 
  
  if (sit==TRUE && comRepet==FALSE){
      return FALSE;
  }
  
  pNovo = criaNo(inf);     
  if (pAnt == l->cabeca){
    pNovo->prox = l->cabeca->prox;
    l->cabeca->prox = pNovo; 
  } else{
    pNovo->prox = pAnt->prox;
    pAnt->prox = pNovo;  
  }
  l->qtdNos += 1;
  
  return TRUE;
}

//Exibir a lista
void exibir_lista (tLSECC *l){
  if (l == NULL) {
        return;
    }
    tNo* pNo = l->cabeca->prox;
    printf("\n\tLista = ");
    while (pNo != l->cabeca) {
        printf("%d ", pNo->inf);
        pNo = pNo->prox;
    }
    printf("\n");
}

//Remover um elemento da lista
int remover (tLSECC *l, int inf){
  tNo *pSuc = NULL, *pAnt = NULL, *pAtual = NULL,*p;
  int isClassif,comRepet, existe, qtdDel = 0;

  isClassif = l->isClassif;
  comRepet = l->comRepet;
  existe = busca(l, inf, &pAnt);
  
  if (existe==FALSE){
    return FALSE;
  }  
  
  if (comRepet==FALSE){
    pAtual=pAnt->prox;
    pAnt->prox=pAtual->prox;
    free(pAtual);
    l->qtdNos -= 1;
    qtdDel++;
  } else{
    p=pAnt->prox;
    if (isClassif==TRUE){
      while(p != l->cabeca && p->inf == inf){
        pSuc=p->prox;  
        free(p);
        qtdDel++;
        p=pSuc;
      }
      pAnt->prox = p;
    } else{
      while(p != l->cabeca){
        if (p->inf==inf){
          pSuc=p->prox;
          pAnt->prox=pSuc;
          free(p);
          qtdDel++;
          p=pSuc;
        }
        else{
          pAnt=p;
          p=p->prox;
        }
      }
    }
  }  
  return qtdDel;
}

void destroiLDEC(tLSECC* l) {
    if (l != NULL) {
        tNo* pNo = l->cabeca->prox;
        while (pNo != l->cabeca) {
            tNo* aux = pNo;
            pNo = pNo->prox;
            free(aux);
        }
        free(l->cabeca);
        free(l);
    }
}