#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int id;
    struct no *prox, *ant;
} tNo;

typedef struct {
    tNo *prim, *ult;
    int qtdNos, isClassif, comRepet;
} tLDE;

//Funções Auxiliares :
tNo* criaNo(int id) {
    tNo* no = (tNo*) malloc(sizeof(tNo));
    no->id = id;
    no->prox = NULL;
    no->ant = NULL;
    return no;
}

int busca(tLDE* pL, int id, tNo** p) {
    tNo* pRast = NULL;
    if (pL->isClassif) {
        for (*p = pL->prim; *p != NULL && (*p)->id < id; pRast = *p, *p = (*p)->prox);
    } else {
        for (*p = pL->prim; *p != NULL && (*p)->id != id; pRast = *p, *p = (*p)->prox);
    }
    return (*p != NULL && (*p)->id == id);
}

tNo* pLDE_ultimoNo(tLDE *pL) {//Determina o último nó da lista
  if (pL == NULL || pL->prim == NULL) {
    return NULL;
  }
  
  tNo *p = pL->prim;
  while (p->prox != NULL) {
    p = p->prox;
  }
  
  return p;
}

//------------------------------------------------

tLDE* lstDE_criaLista(int isClassif, int comRepet) {
    tLDE* pL = (tLDE*) malloc(sizeof(tLDE));
    pL->qtdNos = 0;
    pL->isClassif = isClassif;
    pL->comRepet = comRepet;
    pL->prim = NULL;
    pL->ult = NULL;
    return pL;
}

int lstDE_isClassif(tLDE* pL) {
    return pL->isClassif;
}

int lstDE_comRepet(tLDE* pL) {
    return pL->comRepet;
}

int lstDE_isVazia(tLDE* pL) {
    return (pL->qtdNos == 0);
}

int lstDE_inclui(tLDE* pL, int id) {
    tNo *pAnt, *pAtual, *pNovo;
    int sit;

    sit = busca(pL, id, &pAtual);
    if (sit && !pL->comRepet)
        return -1; // inclusão de existente em sem repetição

    pNovo = criaNo(id);
    if (pAtual == NULL) {
        pNovo->ant = pL->ult;
        if (pL->ult != NULL) pL->ult->prox = pNovo;
        else pL->prim = pNovo;
        pL->ult = pNovo;
    } else {
        pNovo->prox = pAtual;
        pNovo->ant = pAtual->ant;
        pAtual->ant = pNovo;
        if (pNovo->ant == NULL) pL->prim = pNovo;
        else pNovo->ant->prox = pNovo;
    }

    pL->qtdNos += 1;
    return 1;
}

void lstDE_imprime(tLDE* pL) {
    tNo* p;
    printf("[ ");
    for (p = pL->prim; p != NULL; p = p->prox) {
        printf("%d ", p->id);
    }
    printf("]\n");
}


int lstDE_exclui(tLDE *pL, int id){
  tNo *pAtual = NULL,*p;
  int isClassif,comRepet, existe, qtdDel = 0;

  isClassif = lstDE_isClassif(pL);
  comRepet = lstDE_comRepet(pL);
  existe = busca(pL, id, &pAtual);
  
  if (existe==0)
    return -1; // exclusão de inexistente
  
  if (!comRepet){
     if (pAtual == pL->prim){
      pL->prim=pAtual->prox;
      if (pAtual->prox)
        pAtual->prox->ant = NULL;
    }
    else{
      pAtual->ant->prox=pAtual->prox;
      if (pAtual->prox)
        pAtual->prox->ant = pAtual->ant;
    }
    free(pAtual);
    pL->qtdNos -= 1;
  }
  else{
    if (isClassif) {
      p = pAtual;
      while(p && p->id == id){
          pAtual = p->prox;  
          free(p);
          qtdDel++;
          p = pAtual;
      }
      if(pAtual)
        pAtual->ant = p->ant;
      else
        pL->ult = p->ant;
      if(p->ant)
        p->ant->prox = pAtual;
      else
        pL->prim = pAtual;
    }
    else{
      while(pAtual){
        if (pAtual->id == id){
          p = pAtual;
          pAtual = pAtual->prox;
           if (p == pL->prim){
              pL->prim = pAtual;
              if (pAtual)
                pAtual->ant = NULL;
           }
           else{
              p->ant->prox = pAtual;
              if (pAtual)
                pAtual->ant = p->ant;
           }
            free(p);
            qtdDel++;
        }
        else{
          pAtual = pAtual->prox;
        }
      }
      if(pL->prim)
        pL->ult = pLDE_ultimoNo(pL);
      else
        pL->ult = NULL;
    }
  }  
    
  return qtdDel;
} 

void lstDE_destroi(tLDE* pL) {
  tNo* p = pL->prim;
  while (p) {
    tNo* prox = p->prox;
    free(p);
    p = prox;
  }
  pL->prim = NULL;
  pL->ult = NULL;
  pL->qtdNos = 0;
}
