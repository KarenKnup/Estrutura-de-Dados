#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct no {
  int id; 
  tNo* prox;
};

struct LSE {
  tNo* prim;
  int qtdNos;
  int isClassif, comRepet;
};

// FUNÇÕES AUXILARES
/* busca:
Retorna TRUE (1) ou FALSE (0) dependendo se o ID {id}
  encontra-se na lista simplesmente encadeada {pL},
  respectivamente. Se o ID for encontrado, {pAtual, pAnt}
  guardarão os endereços do nó com o ID e do nó
  imeadiatamente anterior, respectivamente.
*/ 
int busca(tLSE* pL, int id, tNo** pAnt){
  int isClassif = lstSE_isClassif(pL);
  int comRepet = lstSE_comRepet(pL);
  tNo *p,*pRast;//rastreador - vai atrás de p

  if(isClassif){
    for(p=pL->prim, pRast=NULL; p!=NULL && p->id<id; pRast=p, p=p->prox);
  } else {
    for(p=pL->prim, pRast=NULL; p!=NULL && p->id!=id; pRast=p, p=p->prox);
  }
  (*pAnt)=pRast;
  
  return (p!=NULL && p->id == id);
}

/* cria_no
  Cria e retorna um nó de LSE com ID {id}.
*/
tNo* criaNo(int id){
  tNo* no = (tNo*) malloc(sizeof(tNo));
    no->id = id;
    no->prox=NULL;
  return no;
}
/*=======================================*/

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} é classificada ou não,
  respectivamente.
*/
int lstSE_isClassif(tLSE *pL){
  /*if(pL->isClassif == 1){
    return TRUE;
  } else {
    return FALSE;
  }*/
  return pL->isClassif;
}

/*
  Retorna TRUE (1) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} permite ou não repetição,
  respectivamente.
*/
int lstSE_comRepet(tLSE *pL){
  return pL->comRepet;
}

/*
  Retorna TRUE (<>0) ou FALSE (0) dependendo se a lista
  simplesmente encadeada {pL} está ou não vazia,
  respectivamente.
*/
int lstSE_isVazia(tLSE *pL){
  return pL->qtdNos;
}


/*
  Cria e retorna uma lista simplesmente encadeada.
  {isClassif, comRepet} determinam, respectivamente, se
  a lista é classificada e se pode haver repetição de
  elementos. (0 = Não; <>0 = Sim)
*/
tLSE *lstSE_criaLista(int isClassif, int comRepet){
  tLSE* pL = (tLSE*) malloc(sizeof(tLSE));//cabeça
    pL->qtdNos=0;
    pL->comRepet = comRepet;
    pL->isClassif = isClassif;
    pL->prim = NULL;
  return pL;
}

/*
Tenta inserir o ID {id} na lista simplesmente encadeada
  {pL}, retornando TRUE (1) ou FALSE (0) dependendo se a
  operação foi bem-sucedida ou não, respectivamente.

  Possíveis impedidores: memória insuficiente; {id} já
  existe e {pL} não permite repetição; etc.
*/
int lstSE_inclui(tLSE *pL, int id){
   tNo *pNovo, *pAnt, *pAtual;
  int isClassif, comRepet, sit;

  isClassif = lstSE_isClassif(pL);
  comRepet = lstSE_comRepet(pL);

  tNo *pNovo, *pAnt, *pAtual;
  int isClassif, comRepet, sit;

  isClassif = lstSE_isClassif(pL);
  comRepet = lstSE_comRepet(pL);

   if (!isClassif && comRepet){
     pAnt=NULL;
     sit=FALSE;
   }
  else{
    sit = busca(pL, id, &pAnt);
  }
  if (sit &&  !comRepet)
    return -1; //inclusão de existente em sem repetição
  pNovo = criaNo(id);
  if (pAnt == NULL){
    pNovo->prox=pL->prim;
    pL->prim=pNovo;
  }
  else{
    pNovo->prox = pAnt->prox;
    pAnt->prox = pNovo;
  }
  
  pL->qtdNos += 1;
  return TRUE;

}

/*
  Imprime no console os elementos de uma lista
  simplesmente encadeada {pL}.
*/
void lstSE_imprime(tLSE *pL){
  tNo* p = pL->prim;
  
  while (p) {
    printf("\n%x - %d ", p,p->id);
    p = p->prox;
  }

  puts("");
}

/*
  Remove todas as ocorrências do ID {id} na lista
  simplesmente encadeada {pL}, retornando a quantidade
  de instâncias excluídas.
*/
int lstSE_exclui(tLSE *pL, int id){
  tNo *pSuc = NULL, *pAnt = NULL, *pAtual = NULL,*p;
  int isClassif,comRepet, existe, qtdDel = 0;

  isClassif = lstSE_isClassif(pL);
  comRepet = lstSE_comRepet(pL);
  existe = busca(pL, id, &pAnt);
  //printf("\n %x %x",pAnt,pAnt->prox);
  
  if (existe==0)
    return -1; // exclusão de inexistente
  
  if (!comRepet){
     if (pAnt == NULL){
      pAtual=pL->prim;
      pL->prim=pAnt->prox;
    }
    else{
      pAtual=pAnt->prox;
      pAnt->prox=pAtual->prox;
    }
    free(pAtual);
    pL->qtdNos -= 1;
  }
  else{
    if(pAnt == NULL)
        p=pL->prim;
      else
        p=pAnt->prox;
    
    if (isClassif) {
         
      while(p&&p->id == id){
          pSuc=p->prox;  
          free(p);
          qtdDel++;
          p=pSuc;
      }
      if(pAnt == NULL)
        pL->prim=p;
      else
        pAnt->prox=p;
        
    }
    else{
      
      while(p){
        if (p->id==id){
          pSuc=p->prox;
           if(pAnt == NULL)
              pL->prim=pSuc;
            else
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