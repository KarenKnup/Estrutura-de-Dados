#include <stdio.h>
#include "lista.h"

int main(void) {
  tLSECC *lista, *lista2;
  int qtde;

  printf("\nLista sem repetição e ordenada : \n");
  lista=cria_lista(1,0); //isClassif,comRepet
  inserir(lista,1);
  inserir(lista,1);
  inserir(lista,2);
  inserir(lista,6);
  inserir(lista,3);
  exibir_lista(lista);

  printf("\n ------ Lista 2 ---\n\n");
  printf("Qual valor? ");
  scanf("%d",&qtde);
  lista2 = cria_sublista(lista,qtde);
  if(lista2!=NULL){
      exibir_lista(lista2);
  } else {
    printf("\n\tQuantidade de nós não é compatível com a lista 1!");
  }
  
  return 0;
}