#include "circulo.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 struct circ {
    Ponto *O,*A;
  };

Circulo* circ_cria (float x1, float y1,float x2, float y2){
  Circulo *c=(Circulo*)malloc(sizeof(Circulo));
  //considerando sempres que os ptos são não colineraes
  c->O=pto_cria(x1,y1);
  c->A=pto_cria(x2,y2);
    return c;
}

void circ_libera(Circulo* c){
  pto_libera(c->A);
  pto_libera(c->O);
  free(c);
}

void circ_acessa(Circulo* c, float* x1, float* y1,float* x2, float* y2){
  pto_acessa(c->O,x1,y1);
  pto_acessa(c->A,x2,y2);
}

void circ_atribui(Circulo* c, float x1, float y1,float x2, float y2){
  pto_atribui(c->O,x1,y1);
  pto_atribui(c->A,x2,y2);
}

char* circ_getCirculo(Circulo* c){
     char* pt;
    int tam = sizeof(*c)+ 30;
    pt = (char*)malloc(tam);
    sprintf(pt,"O: %s  A: %s", pto_getPonto(c->O),pto_getPonto(c->A));
    return pt;
}

void circ_exibe(Circulo* c){
  printf("\nO: %s",pto_getPonto(c->O));
  printf("\nA: %s",pto_getPonto(c->A));
}

float circ_perimetro(Circulo* c){
  return 2 * pto_distancia(c->O,c->A) * 3.14;
}

float circ_area(Circulo* c){
  return 3.14*(pow(pto_distancia(c->O,c->A), 2));
}