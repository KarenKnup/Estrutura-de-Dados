#include <stdio.h>
#include "Racional.h"

/*       EXERCÍCIO 2
Utilizando o TAD Racional, definido abaixo,  crie o módulo principal de um programa (calculadora.c) que implemente uma calculadora baseada em números racionais. A calculadora deve permitir que o usuário realize as operações de soma, subtração, multiplicação e divisão de números racionais fornecido, exibindo os resultados das operações na tela. Obrigatoriamente todos os números utilizados pela calculadora devem ser representados pelo tipo abstrato Racional.
TAD RACIONAL:  Um número racional positivo é o que pode ser expresso como quociente de dois inteiros positivos:    a/b.
Interface --> Racional.h

Utilizando o TAD Racional, crie o módulo principal de um programa (calculadora.c) que implemente uma calculadora baseada em números racionais. A calculadora deve permitir que o usuário realize as operações de soma, subtração, multiplicação e divisão de números racionais fornecido, exibindo os resultados das operações na tela. Obrigatoriamente todos os números utilizados pela calculadora devem ser representados pelo tipo abstrato Racional.
  */

int menu (){
     int op;
    printf("\n------ MENU DE OPERAÇÕES -------");
    printf("\n(1) Soma");
    printf("\n(2) Subtração");
    printf("\n(3) Multiplicação");
    printf("\n(4) Divisão");
    printf("\n(0) Sair");

      printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      printf("\nDigite a sua opção: ");
      scanf("%d",&op);	  
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  
     return op;
  }

void Dados (int *num, int *den, int *num2, int *den2){
  printf("\n\t**** Primeiro número ****\n");
              printf("Numerador: ");
              scanf("%d",num);
              printf("Denominador: ");
              scanf("%d",den);
  printf("\n\t**** Segundo número ****\n");
              printf("Numerador: ");
              scanf("%d",num2);
              printf("Denominador: ");
              scanf("%d",den2);
}

int main(void) {
  Racional *r, *n1, *n2;
  int num, den, num2, den2, op;
  char *num_1, *num_2, *res;

  do{
    op=menu();

    switch(op){
      case 1: Dados(&num,&den,&num2,&den2);  
               n1=rac_cria(num,den); 
               num_1=rac_exibe(n1);
               n2=rac_cria(num2,den2);
               num_2=rac_exibe(n2);
        printf("\n\tSoma = %s + %s = ",num_1,num_2);
               r=rac_add(n1,n2);
               res=rac_exibe(r);
        printf("%s\n",res);
      break;

      case 2: Dados(&num,&den,&num2,&den2);  
               n1=rac_cria(num,den); 
               num_1=rac_exibe(n1);
               n2=rac_cria(num2,den2);
               num_2=rac_exibe(n2);
        printf("\n\tSubtração = %s - %s = ",num_1,num_2);
               r=rac_sub(n1,n2);
               res=rac_exibe(r);
        printf("%s\n",res);
      break;

      case 3: Dados(&num,&den,&num2,&den2);  
               n1=rac_cria(num,den); 
               num_1=rac_exibe(n1);
               n2=rac_cria(num2,den2);
               num_2=rac_exibe(n2);
        printf("\n\tMultiplicação = %s x %s = ",num_1,num_2);
               r=rac_mul(n1,n2);
               res=rac_exibe(r);
        printf("%s\n",res);
      break;

      case 4: Dados(&num,&den,&num2,&den2);  
               n1=rac_cria(num,den); 
               num_1=rac_exibe(n1);
               n2=rac_cria(num2,den2);
               num_2=rac_exibe(n2);
        printf("\n\tDivisão = %s dividido por %s = ",num_1,num_2);
               r=rac_divide(n1,n2);
               res=rac_exibe(r);
        printf("%s\n",res);
      break;
      
      case 0:         printf("________________________________________");
printf("\n\tPrograma finalizado!");
                break;
      default: printf("\n\tOpção inválida! Tente novamente!\n");
    }
  } while(op!=0);
  
  return 0;
}