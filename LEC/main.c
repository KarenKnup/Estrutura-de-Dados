#include <stdio.h>
#include "lista.h"

int main(void) {
  tLSECC *lista, *lista2, *lista3, *lista4;

  printf("\nLista com repetição e ordenada : \n");
  lista=cria_lista(1,1); //isClassif,comRepet
  inserir(lista,1);
  inserir(lista,1);
  inserir(lista,2);
  inserir(lista,6);
  inserir(lista,3);
  exibir_lista(lista);

  printf("\nLista sem repetição e ordenada : \n");
  lista2=cria_lista(1,0); 
  inserir(lista2,1);
  inserir(lista2,1);
  inserir(lista2,2);
  inserir(lista2,6);
  inserir(lista2,3);
  exibir_lista(lista2);

  printf("\nLista com repetição e não ordenada : \n");
  lista3=cria_lista(0,1); 
  inserir(lista3,1);
  inserir(lista3,1);
  inserir(lista3,2);
  inserir(lista3,6);
  inserir(lista3,3);
  exibir_lista(lista3);

  printf("\nLista sem repetição e não ordenada : \n");
  lista4=cria_lista(0,0); 
  inserir(lista4,1);
  inserir(lista4,1);
  inserir(lista4,2);
  inserir(lista4,6);
  inserir(lista4,3);
  exibir_lista(lista4);

  printf("\n\t ---> Remover o 1 da lista 1 :\n");
  remover(lista,1);
  exibir_lista(lista);

  printf("\n\t ---> Remover o 1 da lista 2 :\n");
  remover(lista2,1);
  exibir_lista(lista2);

  return 0;
}