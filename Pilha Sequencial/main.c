#include <stdio.h>
#include "Pilha.h"

void exibePilha(tPilha * minhaPilha){
  tPilha * tuaPilha;
  int inf;
  tuaPilha=pilha_cria(40);
  while (!pilha_tavazia(minhaPilha)){
    pilha_exclui(minhaPilha,&inf);
    printf("\n\nvalor do topo: %d",inf);
    pilha_inclui(tuaPilha,inf);
  }
  while (!pilha_tavazia(tuaPilha)){
    pilha_exclui(tuaPilha,&inf);
    pilha_inclui(minhaPilha,inf);
  }
  pilha_destroi(tuaPilha);
}

int main(void) {
  tPilha * minhaPilha, *aux;
  tPilha * tuaPilha;
  int i;
  int inf;
  minhaPilha=pilha_cria(4);
  tuaPilha=pilha_cria(2);
  if (pilha_tavazia(minhaPilha))
    printf("Pilha Vazia");
  for(i=0;i<3;i++) //0 2 4 
    pilha_inclui(minhaPilha,2*i);
  // consultar o topo
  /*
  pilha_exclui(minhaPilha,&inf);
  printf("\n\nvalor do topo: %d",inf);
  pilha_inclui(minhaPilha,inf);
  */
  //pilha_consultaTopo(minhaPilha,&inf);
  //printf("\n\nvalor do topo: %d",inf);

  exibePilha(minhaPilha);
  
  return 0;
}