#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define TRUE 1
#define FALSE 0

typedef struct no {
    int inf;
    struct no *prox, *ant;
} tNo;

typedef struct LDEC {
    tNo *prim, *ult;
    tNo *cabeca;
    int qtdNos, //quantidade de nós
        isClassif, //1 para ordem crescente e 0 para desordenado
        comRepet; //1 para com repetição e 0 sem repetição
} tLDEC;

tLDEC* cria_lista (int isClassif, int comRepet){
  tLDEC* pL = (tLDEC*) malloc(sizeof(tLDEC));
    if (pL != NULL) {
        pL->cabeca = (tNo*) malloc(sizeof(tNo));
        if (pL->cabeca != NULL) {
            pL->cabeca->prox = pL->cabeca;
            pL->cabeca->ant = pL->cabeca;
            pL->qtdNos = 0;
            pL->isClassif = isClassif;
            pL->comRepet = comRepet;
        } else {
            free(pL);
            pL = NULL;
        }
    }
    return pL;
}

void destroiLDEC(tLDEC* pL) {
    if (pL != NULL) {
        tNo* pNo = pL->cabeca->prox;
        while (pNo != pL->cabeca) {
            tNo* aux = pNo;
            pNo = pNo->prox;
            free(aux);
        }
        free(pL->cabeca);
        free(pL);
    }
}

void imprimeLDEC(tLDEC* pL) {
    if (pL == NULL) {
        return;
    }
    tNo* pNo = pL->cabeca->prox;
    printf("\n\tLista = ");
    while (pNo != pL->cabeca) {
        printf("%d ", pNo->inf);
        pNo = pNo->prox;
    }
    printf("\n");
}

int conta_ocorrencias (tLDEC* pL, int numero){
  int cont=0;
   if (pL == NULL) {
        return FALSE;
    }
    tNo* pNo = pL->cabeca->prox;
    while (pNo != pL->cabeca) {
        if(pNo -> inf == numero){
          cont++;
        }
        pNo = pNo->prox;
    }

  return cont;
}

int insereLDEC(tLDEC* pL, int inf) {
  int tipo;
    if (pL == NULL) {
        return FALSE;
    }
    if(pL->comRepet == 0){
      if(conta_ocorrencias(pL,inf)==1){
        return FALSE;
      }
    }
    if(pL->qtdNos == 0){
      tipo = 0;
    } else {
      if(pL->isClassif == TRUE){
        tipo = 2;
      } else {
        tipo = 1;
      }
    }
    tNo* novoNo = (tNo*) malloc(sizeof(tNo));
    if (novoNo == NULL) {
        return FALSE;
    }
    novoNo->inf = inf;
    switch(tipo) {
        case 0: // Inserção no início
            novoNo->prox = pL->cabeca->prox;
            novoNo->ant = pL->cabeca;
            pL->cabeca->prox->ant = novoNo;
            pL->cabeca->prox = novoNo;
            break;
        case 1: // Inserção no fim
            novoNo->prox = pL->cabeca;
            novoNo->ant = pL->cabeca->ant;
            pL->cabeca->ant->prox = novoNo;
            pL->cabeca->ant = novoNo;
            break;
        case 2: // Inserção ordenada
            if (pL->qtdNos == 0 || pL->cabeca->prox->inf >= inf) {
                novoNo->prox = pL->cabeca->prox;
                novoNo->ant = pL->cabeca;
                pL->cabeca->prox->ant = novoNo;
                pL->cabeca->prox = novoNo;
            } else {
                tNo* pNo = pL->cabeca->prox;
                while (pNo->prox != pL->cabeca && pNo->prox->inf < inf) {
                    pNo = pNo->prox;
                }
                novoNo->prox = pNo->prox;
                novoNo->ant = pNo;
                pNo->prox->ant = novoNo;
                pNo->prox = novoNo;
            }
            break;
        default:
            free(novoNo);
            return FALSE;
    }
    pL->qtdNos++;
    return TRUE;
}

int removeLDEC(tLDEC* pL, int inf) {
    int contador = conta_ocorrencias(pL,inf);
  
    if (pL == NULL || pL->qtdNos == 0) {
        return FALSE;
    }
  
    while (contador!=0){
      tNo* pNo = pL->cabeca->prox;
      while (pNo != pL->cabeca && pNo->inf != inf) {
          pNo = pNo->prox;
      }
      if (pNo == pL->cabeca) {
          return FALSE;
      }
      pNo->ant->prox = pNo->prox;
      pNo->prox->ant = pNo->ant;
      free(pNo);
      pL->qtdNos--;
    
      contador--;
    }    
    
    return TRUE;
}