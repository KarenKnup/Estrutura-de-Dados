#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tlst {
    int nMax;
    int qtdeNos;
    int *vNos;
    int repeticoes; //1(não) ou 0 (sim)
    int classificacao; //1(não) ou 0 (sim)
};

TLista* lst_cria (int max, int classif, int repet){
  TLista *l = (TLista*)malloc(sizeof(TLista));//cria 1 caixinha do vetor
  if (l == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);//finaliza o programa e retorna 1
    //convenção: 0-sucesso / 1-falha
  } else {
      l->vNos = (int*)malloc(sizeof(int)*max); //cria o vetor
    if (l->vNos == NULL) {
      printf("Memória insuficiente!\n");
      exit(1);
    } else {
        l->nMax = max;
        l->qtdeNos = 0;
        l->repeticoes = repet;
        l->classificacao = classif;
      
        return l;
    }
  }
}

int lst_cheia (TLista* l){
  if(l->nMax == l->qtdeNos){
    return 0;
  } else {
    return 1;
  }
}

int lst_vazia (TLista *l){
  if(l->qtdeNos == 0){
    return 0;
  } else {
    return 1;
  }
}

int lst_ehClassif (TLista* l){
  return l->classificacao;
}

int lst_temRepet (TLista* l){
  return l->repeticoes;
}

int busca (TLista* l, int chave, int *pos){
  int i=0, temchance=1, achou=0;

  while(temchance && achou){//vai funcionar enquanto temchance=1 e achou=0
    if (l->vNos[i] == chave){
      *pos = i;
      achou = 1;
    } else {
      if (lst_ehClassif(l)){//se a lista for classificada
        if(l->vNos[i] > chave){
          temchance = 0;
          *pos = i;
        } else {
          if(i == l->qtdeNos-1){
            *pos = i+1;
            temchance=0;
          } else {
            i++;
          }
        }
      }
    }
  }

  return achou;
}

int lst_inclusao (TLista *l, int n){
  int pos, sit;
  
  if (lst_temRepet(l) && lst_ehClassif(l)){
    pos = l->qtdeNos;
  } else {
    sit = busca(l,n,&pos);
    if(sit==1 && lst_temRepet(l)==0){
      return -1; //não existe
    }
  }

  memcpy(l->vNos+pos+1, l->vNos+pos, (l->qtdeNos-pos)*sizeof(int));

  l->vNos[pos]=n;
  (l->qtdeNos)++;
    return 0;
}

int lst_remocao (TLista* l, int n){
  
}