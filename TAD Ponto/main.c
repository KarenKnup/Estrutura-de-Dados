#include <stdio.h>
#include "ponto.h"

int main(void) {
  Ponto *p1,*p2;
  float x1,y1;
  char * pontoTexto;
  p1=pto_cria(12,5);
  p2=pto_cria(1,4);
  //pto_exibe(p1);
  //pto_exibe(p2);
  //pto_atribui(p1,34,35);
  //variável = a representação textual de um ponto (...,...)
  pto_exibe(p1);
  pontoTexto=pto_getPonto(p1);
  printf("%s",pontoTexto);
  sscanf(pontoTexto,"(%f , %f)",&x1,&y1);//string scanf
  printf("%f - %f",x1,y1);
  return 0;
}