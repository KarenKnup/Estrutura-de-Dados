#include <stdio.h>
#include "matriz.h"

void VendeuMais (int dia, int modelo, Matriz *a, Matriz *b){
  dia--;
  modelo--;
  
  if(mat_acessa(a,modelo,dia) > mat_acessa(b,modelo,dia)){
    printf("\n\tA loja A vendeu mais unidades do modelo %d no dia %d.\n",modelo+1,dia+1);
  } else {
        printf("\n\tA loja B vendeu mais unidades do modelo %d no dia %d.\n",modelo+1,dia+1);
  }
}

void ComparaDesempenho (Matriz *a, Matriz *b){ //compara desempenho de A com B
  int linhas, colunas;
  
  if((mat_linhas(a) == mat_linhas(b)) && (mat_colunas(a) == mat_colunas(b))){
    linhas = mat_linhas(a);
    colunas = mat_colunas(a);
  } else {
    printf("\n\tComparação não é possível!\n");
  }
   
  Matriz *r = mat_cria(linhas,colunas);

  for(int i=0; i<linhas; i++){
    for(int j=0; j<colunas; j++){
      mat_atribui(r,i,j,mat_acessa(a,i,j)-mat_acessa(b,i,j));
    }
  }
  
  printf("\n\t ----- Desempenho -----\nExemplo: +1 = uma unidade a mais vendida do que a outra loja\n\n");
  for(int i=0; i<linhas; i++){
    for(int j=0; j<colunas; j++){
      if(mat_acessa(r,i,j) > 0){
        printf("+%.2f ", mat_acessa(r,i,j)); 
      } else {
        if(mat_acessa(r,i,j) == 0){
          printf(" 0.00 ");
        } else {
          printf("%.2f ", mat_acessa(r,i,j));
        }
      }
    }
    printf("\n");
  }
}

int main(void) {
  Matriz *lojaA, *lojaB;

  /* a matriz A = (aij) descreve o desempenho da loja A, de modo que cada elemento aij é o número de unidades vendidas do modelo i no dia j; por exemplo, o elemento A23 = 5 informa que na loja A foram vendidas 5 unidades do modelo 2 no dia 3
  i = modelo
  j = dia
  aij = quantidade vendida no dia
  */
  lojaA=mat_cria(2,4);
  mat_atribui(lojaA,0,0,2);
  mat_atribui(lojaA,0,1,3);
  mat_atribui(lojaA,0,2,1);
  mat_atribui(lojaA,0,3,5);
  mat_atribui(lojaA,1,0,1);
  mat_atribui(lojaA,1,1,2);
  mat_atribui(lojaA,1,2,5);
  mat_atribui(lojaA,1,3,3);
  printf("\n ---- Loja A ------ \n");
  mat_exibe(lojaA);

  /* a matriz B = (bij) descreve o desempenho da loja B, de modo que cada elemento bij é o número de unidades vendidas do modelo i no dia j. */
  lojaB=mat_cria(2,4);
  mat_atribui(lojaB,0,0,3);
  mat_atribui(lojaB,0,1,0);
  mat_atribui(lojaB,0,2,2);
  mat_atribui(lojaB,0,3,3);
  mat_atribui(lojaB,1,0,4);
  mat_atribui(lojaB,1,1,2);
  mat_atribui(lojaB,1,2,4);
  mat_atribui(lojaB,1,3,5);
   printf("\n ---- Loja B ------ \n");
  mat_exibe(lojaB);

 // No dia 3, qual loja vendeu mais o modelo 1? 
  VendeuMais(3,1,lojaA,lojaB);
  
  //Quantos veículos dos novos modelos foram vendidos?
  printf("\n\tA loja A vendeu %.1f unidades do modelo 2",mat_somaLin(lojaA,1));
    printf("\n\tA loja B vendeu %.1f unidades do modelo 2\n",mat_somaLin(lojaB,1));

  //No período considerado, construa e exiba uma matriz que compare o desempenho da loja A em relação à loja B, nas vendas diárias de cada modelo
  printf("\n\n\tDesempenho da loja A em relação à loja B: ");
  ComparaDesempenho(lojaA,lojaB);
  
  return 0;
}