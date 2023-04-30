#include <stdio.h>
#include "tipoTriangulo.h"

/*
TAD Triangulo - pto A,B,C (perime)
- criar
- liberar
- acessar
- atribuir
- exibir
- monta texto

- perimetro
- area -> Fórmula de Heron
  */

int main(void) {
  Triangulo*t1;
  t1=tri_cria(1,1,0,1,1,0);
  tri_exibe(t1);
  printf("\nPerímetro: %.2f",tri_perimetro(t1));
  printf("\nÁrea: %.2f",tri_area(t1));
  
  return 0;
}