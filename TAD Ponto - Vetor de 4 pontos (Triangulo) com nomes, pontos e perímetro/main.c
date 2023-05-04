#include <stdio.h>
#include <string.h>
#include "ponto.h"

// Obter as coordenadas dos pontos
// calc perim a partir dos ptos
// exibir perim bonitinho
// Mostre para cada uma das pessoas (total 4)
// seu nome , as coordenadas e perímetro de seu triângulo, classificados crescentemente pelo perímetro

typedef struct {
    Ponto *pontos[3];
    char nome[10];
    float perimetro;
} Triangulo;

void desenhaMoldura(void){
  printf("\n==============================");
  printf("\n==============================");
  return;
}

void exibeResposta(Triangulo *t, int i){
  // mostrar o perímetro calculado pelo programa
  // desenha moldura, escreve o perim, desenha a moldura
  desenhaMoldura();
  printf("\n%s - Perímetro: %.1f",t[i].nome,t[i].perimetro);
  desenhaMoldura();
  return;
}

void Inverte (Triangulo *t){
  float aux;
  char aux2[10];
  Ponto *p;
  
   for (int i=0; i<4; i++){
    for (int j=i+1; j<4; j++){
      if (t[i].perimetro > t[j].perimetro){
        aux=t[i].perimetro;
        t[i].perimetro=t[j].perimetro;
        t[j].perimetro=aux;

        for(int n=0; n<3; n++){
         p=t[i].pontos[n];
         t[i].pontos[n]=t[j].pontos[n];
         t[j].pontos[n]=p;
        }     
        
        strcpy(aux2,t[i].nome);
        strcpy(t[i].nome,t[j].nome);
        strcpy(t[j].nome,aux2);
      }
    }
  }  
}

float tri_perimetro (Ponto *p1, Ponto *p2, Ponto *p3){
  return pto_distancia(p1,p2)+pto_distancia(p1,p3)+pto_distancia(p2,p3);
}

int main(void) {
  Triangulo t[4];
  int mCoordenadas[4][6];

  for(int i=0; i<4; i++){//Quantas pessoas
    printf("\nNome da %dª pessoa? ",i+1);
    scanf("%s", t[i].nome);
    for (int j=0;j<6;j+=2){
      printf("Digite x: ");
      scanf("%d", &mCoordenadas[i][j]   );
      printf("Digite y: ");
      scanf("%d", &mCoordenadas[i][j+1]   );
    }
    t[i].pontos[0]=pto_cria(mCoordenadas[i][0], mCoordenadas[i][1]);
    t[i].pontos[1]=pto_cria(mCoordenadas[i][2], mCoordenadas[i][3]);
    t[i].pontos[2]=pto_cria(mCoordenadas[i][4], mCoordenadas[i][5]);
    t[i].perimetro=tri_perimetro(t[i].pontos[0],t[i].pontos[1],t[i].pontos[2]);
    exibeResposta(t,i);
  }  

  // organizar os vetores/matriz em ordem crescente de perímetro
  Inverte(t);

  // exibir os vetores
  printf("\n\n\n---- RESULTADO ----\n");
  for(int i=0; i<4; i++){
    exibeResposta(t,i);
  }
  
  return 0;
}