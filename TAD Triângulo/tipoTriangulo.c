#include "tipoPonto.h"
#include "tipoTriangulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* TAD: Triangulo (x1,y1) (x2,y2) (x3,y3)*/
/* Tipo exportado */
struct tri{
  Ponto *A,*B,*C;
};

/* Funções exportadas */
/* Função cria - Aloca e retorna um triângulo com coordenadas (x,y) */
Triangulo* tri_cria(float x1, float y1,float x2, float y2,float x3, float y3){
  Triangulo *p=(Triangulo*)malloc(sizeof(Triangulo));
  //considerando sempres que os ptos são não colineraes
  p->A=pto_cria(x1,y1);
  p->B=pto_cria(x2,y2);
  p->C=pto_cria(x3,y3);
  return p;
}

/* Função libera - Libera a memória de um triangulo previamente criado */
void tri_libera(Triangulo* p){
  pto_libera(p->A);
  pto_libera(p->B);
  pto_libera(p->C);
  free(p);
}

/* Função acessa - Retorna os valores das coordenadas ds pontos do triângulo */
void tri_acessa(Triangulo* p, float* x1, float* y1,float* x2, float* y2,float* x3, float* y3){
  pto_acessa(p->A,x1,y1);
  pto_acessa(p->B,x2,y2);
  pto_acessa(p->C,x3,y3);
}

/* Função atribui - Atribui novos valores às coordenadas ds pontos do triângulo */
void tri_atribui(Triangulo* p, float x1, float y1,float x2, float y2,float x3, float y3){
  pto_atribui(p->A,x1,y1);
  pto_atribui(p->B,x2,y2);
  pto_atribui(p->C,x3,y3);
  
}


/* Função getTriangulo - Retorna uma string com os valores do triângulo formato(x,y)*/
char* tri_getTriangulo(Triangulo* p){
    char* pt;
    int tam = sizeof(*p)+ 30;
    pt = (char*)malloc(tam);
    sprintf(pt,"A: %s  B: %s  C: %s", pto_getPonto(p->A),pto_getPonto(p->B),pto_getPonto(p->C));
    return pt;
  
}

/* Função exibe -Escreve na tela o triangulo */
void tri_exibe(Triangulo* p){
  printf("\nA: %s",pto_getPonto(p->A));
  printf("\nB: %s",pto_getPonto(p->B));
  printf("\nC: %s",pto_getPonto(p->C));
}

/* Função clona -recebe um tri e retorna um novo tri com os mesmos valores do tri recebido*/
Triangulo* tri_clona(Triangulo* p);
/* Função perimetro -recebe um tri e retorna o perimetro*/

float tri_perimetro(Triangulo* p){
  return pto_distancia(p->A,p->B) + pto_distancia(p->A,p->C) +
    pto_distancia(p->B,p->C);
}
/* Função area -recebe um tri e retorna a area*/
float tri_area(Triangulo* p){
  float a,b,c;
  float semi=tri_perimetro(p)/2;
  a=pto_distancia(p->A,p->B) ;
  b= pto_distancia(p->A,p->C) ;
  c=pto_distancia(p->B,p->C);
   return sqrt(semi*(semi-a)*(semi-b)*(semi-c));
  
}