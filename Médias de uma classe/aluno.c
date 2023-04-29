//Desenvolvimento dos protótipos de funções
#include "aluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct aluno {
  char *nome;
  float n1,n2,m;
};

//Média de aluno
float aluno_media (float n1, float n2){
  return (n1+n2)/2;
}

//Criar um aluno
Aluno* aluno_cria (char n[], float n1, float n2){
  Aluno* a = (Aluno*) malloc(sizeof(Aluno));
  int qtCaracteres= sizeof(*a) + strlen(n) +1;

  if (a == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  
  a->n1 = n1;
  a->n2 = n2;
  
  a->nome =(char*)malloc(qtCaracteres);
  strcpy(a->nome,n);
  
  a->m=aluno_media(n1,n2);
  
  return a;  
}

void aluno_exibe (Aluno* a){
   printf("\n\t~~~~~~ Dados de %s ~~~~~~\nAV1: %.2f\nAV2: %.2f\nMédia: %.2f\n",a->nome, a->n1, a->n2, a->m);
  return;
}

void aluno_altera (Aluno* a){
  int op;
  char n_nome[50];
  float n_av1, n_av2;
  
  do{
    printf("\n\t~~~~~~ Qual dado do aluno %s deseja alterar? ~~~~~~~\n",a->nome);
  printf("\t(1) Nome\n");
  printf("\t(2) AV1\n");
  printf("\t(3) AV2\n");
  printf("\t(0) Sair\n");
    
    printf("\n\nAlterar: ");
    scanf("%d",&op);
    
    switch(op){
      case 1: printf("Nome: ");
              scanf(" %[^\n]",n_nome);
        a->nome=realloc(a->nome,strlen(n_nome)+1);
        strcpy(a->nome,n_nome);
      break;
      
      case 2: printf("AV1: ");
              scanf("%f",&n_av1);
        a->n1=n_av1;
        a->m=aluno_media(n_av1,a->n2);
      break;

       case 3: printf("AV2: ");
              scanf("%f",&n_av2);
         a->n2=n_av2;
         a->m=aluno_media(a->n1,n_av2);
      break;
      
      case 0: printf("\n\nModificação realizada!\n");
        aluno_exibe(a);
      break;

      default: printf("\n\tOpção inválida! Tente novamente.\n");
    }
  }while(op!=0);

  return;
}

char* aluno_acessa (Aluno* a){
  return a->nome;
}

void aluno_remove (Aluno* a){
  free(a);
}
