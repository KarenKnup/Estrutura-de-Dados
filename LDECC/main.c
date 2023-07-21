#include <stdio.h>
#include "lista.h"

//TAD lista duplamente encadeada circular com nó cabeça

/*
Uma lista duplamente encadeada circular com nó cabeça é uma estrutura de dados que consiste em um conjunto de elementos, chamados de nós, onde cada nó contém um valor e dois ponteiros que apontam para o nó anterior e o próximo nó na lista. 
A lista é circular porque o último nó da lista aponta para o primeiro nó e o primeiro nó da lista aponta para o último nó. A presença do nó cabeça permite manipular a lista de forma mais fácil e eficiente.
  */

int main(void) {
  tLDEC *lista, *lista2, *lista3, *lista4;

  printf("\nLista com repetição e ordenada : \n");
  lista=cria_lista(1,1); //isClassif,comRepet
  insereLDEC(lista,1);
  insereLDEC(lista,1);
  insereLDEC(lista,2);
  insereLDEC(lista,6);
  insereLDEC(lista,3);
  imprimeLDEC(lista);

  printf("\nLista sem repetição e ordenada : \n");
  lista2=cria_lista(1,0); 
  insereLDEC(lista2,1);
  insereLDEC(lista2,1);
  insereLDEC(lista2,2);
  insereLDEC(lista2,6);
  insereLDEC(lista2,3);
  imprimeLDEC(lista2);

  printf("\nLista com repetição e não ordenada : \n");
  lista3=cria_lista(0,1); 
  insereLDEC(lista3,1);
  insereLDEC(lista3,1);
  insereLDEC(lista3,2);
  insereLDEC(lista3,6);
  insereLDEC(lista3,3);
  imprimeLDEC(lista3);

  printf("\nLista sem repetição e não ordenada : \n");
  lista4=cria_lista(0,0); 
  insereLDEC(lista4,1);
  insereLDEC(lista4,1);
  insereLDEC(lista4,2);
  insereLDEC(lista4,6);
  insereLDEC(lista4,3);
  imprimeLDEC(lista4);

  printf("\n\t ---> Remover o 1 da lista 1 :\n");
  removeLDEC(lista,1);
  imprimeLDEC(lista);

  printf("\n\t ---> Remover o 1 da lista 2 :\n");
  removeLDEC(lista2,1);
  imprimeLDEC(lista2);


  

  return 0;
}