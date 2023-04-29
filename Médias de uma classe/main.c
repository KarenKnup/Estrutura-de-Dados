#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu (){
  int op;
  printf("\n------------ Menu de operações: ------------\n");
  printf("\t(1) Adicionar um aluno\n");
  printf("\t(2) Remover um aluno\n");
  printf("\t(3) Alterar dados de um aluno\n");
  printf("\t(4) Buscar dados de um aluno\n");
  printf("\t(5) Exibir dados da turma\n");
  printf("\t(0) Sair\n");

  printf("\n\nEntre com a sua opção: ");
  scanf("%d",&op);

  return op;
}

void ExibeTurma (Aluno* turma[], int quant){
  for(int i=0; i<quant; i++){
    aluno_exibe(turma[i]);
  }  
}

int ExibeAluno (Aluno* turma[], int quant, char s[]){
  for(int i=0; i<quant; i++){
    if(strcmp(aluno_acessa(turma[i]),s)==0){
      return i;
    }
  }  
  return -1;
}

int PreencheAluno (Aluno* turma[], int *i){
  char nome[50];
  float n1,n2;
  Aluno *aux;

    printf("Nome: ");
    scanf(" %[^\n]",nome);
      if(ExibeAluno(turma,*i,nome)!=-1){
          return -1;
      }
    printf("AV1: ");
    scanf("%f",&n1);
    printf("AV2: ");
    scanf("%f",&n2);
    
   aux=aluno_cria(nome,n1,n2);
    turma[*i]=aux;
  (*i)++;

  return 0;
}

int MudaAluno (Aluno* turma[], char s[], int quant){
  int a;
  
  for(int i=0; i<quant; i++){
    if(strcmp(aluno_acessa(turma[i]),s)==0){
      aluno_altera(turma[i]);
      return 0;
    }
  }
  return -1;
}

int RemoveAluno (Aluno* turma[], int *quant, char n[]){
  Aluno* aux[*quant-1];
  int q=0, p;

  //Verificar se o aluno "n" existe
  p=ExibeAluno(turma,*quant,n);
  if(p==-1){
    return -1;
        } 
  
  //Remover o aluno "n"
  for(int i=0; i<*quant; i++){
    if(strcmp(aluno_acessa(turma[i]),n)!=0){
      aux[q]=turma[i];
      q++;
    }
  }

  aluno_remove(turma[p]);
  (*quant)--;

  for(int i=0; i<q; i++){
    turma[i]=aux[i];
  }


  return 0;
}

int main(void) {
  Aluno* turma[3];//máximo de 3 alunos na turma
  Aluno *p1,*p2;
  int quant=0, op, r;
  char s[50];

  do {
    op=menu();

    switch(op){
      case 1: if(quant!=3){
        if(PreencheAluno(turma,&quant)==-1){
          printf("\n\tEsse aluno já está registrado!\n");
        }
      } else {
        printf("\n\tTurma lotada!\n");
      }
      break;
      
      case 2: printf("Aluno a ser removido: ");
              scanf(" %[^\n]",s);
        if(RemoveAluno(turma,&quant,s)==-1){
          printf("\n\tAluno inexistente!\n");
        } else {
          printf("\n\tRemoção realizada!\n");
        }
      break;
      
      case 3: printf("Aluno a ser modificado: ");
              scanf(" %[^\n]",s);
        if(MudaAluno(turma,s,quant)==-1){
          printf("\n\tAluno inexistente!\n");
        }
      break;

      case 4: printf("Nome a ser buscado: ");
              scanf(" %[^\n]",s);
        r=ExibeAluno(turma,quant,s);
      if(r==-1){
          printf("\n\tAluno inexistente!\n");
        } else {
        aluno_exibe(turma[r]);
        }
      break;

      case 5: if(quant==0){
        printf("\n\tTurma vazia!\n");
      } else {
        ExibeTurma(turma,quant);
      }
      break;
      
      case 0: printf("\n\nPrograma finalizado!");
      break;

      default: printf("\n\tOpção inválida! Tente novamente.\n");
    }
    
  } while(op!=0);
  
  return 0;
}