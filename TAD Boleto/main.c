#include <stdio.h>
#include "boleto.h"
#include "Data.h"

/*
  Faça um programa para emitir o carnê de pagamento de uma compra parcelada sem entrada.
  A data da compra, o valor a ser parcelado e o número (n) de parcelas será perguntado ao usuário.
  Em cada boleto deverá constar o número do boleto (1 a n), a data do vencimento e o valor do boleto.
  O intervalo entre as parcelas é de 20 dias.

  b) Resolva o problema utilizando o TAD BOLETO
*/

void Dados_Boleto (int *d, int *m, int *a, int *n, float *valor){
  printf("\n\t ----- Dados do Boleto -------\n");
  printf("Dia da compra: ");
  scanf("%d",d);
  printf("Mês da compra: ");
  scanf("%d",m);
  printf("Ano da compra: ");
  scanf("%d",a);
  printf("Valor da compra: ");
  scanf("%f",valor);
  printf("Quantas parcelas: ");
  scanf("%d",n);
}

void Boletos_Gerados (tData *vencimento, float valor, int n){
  tBoleto *boleto;
  
  printf("\n\t----- BOLETOS GERADOS ------\n");
  for(int qtde=1; qtde<=n; qtde++){
    vencimento=dta_intervalo(vencimento,20);
    boleto=bol_cria(n,valor,vencimento);
    bol_atribui(boleto,qtde,valor/qtde,vencimento);
    bol_exibe(boleto);
    bol_libera(boleto);
    printf("\n\n");
  }  
}

int main(void) {
  int dia, mes, ano, n;
  float valor;
  tData *vencimento;

  Dados_Boleto(&dia,&mes,&ano,&n,&valor);
  vencimento=dta_cria(dia,mes,ano);
  Boletos_Gerados(vencimento,valor,n);
  
  return 0;
}