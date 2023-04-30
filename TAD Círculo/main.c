#include <stdio.h>
#include "circulo.h"

//Douglas Garcia e Karen Knup

int main(void) {
 Circulo *c;

  c=circ_cria(2,2,2,6);
  circ_exibe(c);
  printf("\nPerímetro: %.2f",circ_perimetro(c));
  printf("\nÁrea: %.2f",circ_area(c));
  
  return 0;
}