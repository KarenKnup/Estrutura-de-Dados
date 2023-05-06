#include <stdio.h>
#include "conjunto.h"

/*       EXERCÍCIO 1
Usando o TAD conjunto abaixo, resolva o seguinte problema:
José Carlos e Marlene são os pais de Valéria. A família quer viajar nas férias de julho. José Carlos conseguiu tirar suas férias na fábrica do dia 2 ao dia 28. Marlene obteve licença no escritório de 5 a 30. As férias de Valéria na escola vão de 1 a 25. Durante quais dias a família poderá viajar sem faltar as suas obrigações?
  */

int main(void) {
  Conjunto *jose, *marlene, *valeria, *j_m, *inter;

   //Cria um conjunto de inteiros vazio
  jose=conj_Cria();
  marlene=conj_Cria();
  valeria=conj_Cria();

  //Inclui um novo nº no Conjunto caso ele ainda não pertenca ao conjunto
    //José
  for(int i=2; i<=28; i++){
    conj_Insere(jose,i);
  }
  
    //Valéria
  for(int i=1; i<=25; i++){
    conj_Insere(valeria,i);
  }

    //Marlene
  for(int i=5; i<=30; i++){
    conj_Insere(marlene,i);
  }

  //Exibir conjuntos
    printf("\n---- JOSÉ ----\n");
  conj_exibe(jose);
    printf("\n---- MARLENE ----\n");
  conj_exibe(marlene);
    printf("\n---- VALÉRIA ----\n");
  conj_exibe(valeria);

  //Interseção dos conjuntos - dias que todos podem estar juntos
    printf("\n\tJosé e Marlene\n");
    j_m=conj_Intersecao(jose,marlene);
    conj_exibe(j_m);
    printf("\n\tResposta --- Todos os três\n");
    inter=conj_Intersecao(j_m,valeria);
    conj_exibe(inter); //do dia 5 ao 25

  return 0;
}