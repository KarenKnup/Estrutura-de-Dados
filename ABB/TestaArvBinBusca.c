#include "ArvBinBusca.h"

/* gcc TestaArvBinariaBusca.c -o TestaArvBinariaBusca */

void ImprimeMenu()
{

  printf("Digite:\n");
  printf("i <valor> para inserir valor\n");
  printf("d <valor> para deletar valor\n");
  printf("p         para imprimir em pre ordem\n");
  printf("q         para imprimir em in  ordem\n");
  printf("r         para imprimir em pos ordem\n");
  printf("e         para eliminar valores repetidos\n");
  printf("E         para verificar se eh equilibrada \n");
  printf("M <n>     para imprimir os n maiores valores\n");
  printf("m <n>     para imprimir os n menores valores\n");
  printf("f         para imprimir o vetor de frequencias \n");
  printf("a         para imprimir a altura da arvore\n");
  printf("n         para imprimir o numero de nos da arvore\n");
  printf("I         para imprimir a figura da arvore\n");
  printf("s         para sair do programa\n");

}

int main()
{
  int    i, n, valor;
  char   c;
   ABBusca *ab = NULL;
  char   *s = (char *)calloc(100,sizeof(char)), *saux;
  int    *f = NULL;


  ImprimeMenu();
  c = (char) fgetc(stdin);

  while (c != 's') {

    switch(c) {

    case 'i': 
      scanf("%d",&valor);
      InsereValor(&ab,valor);
      break;
      
    case 'd':
      scanf("%d",&valor);
      RemoveValor(&ab,valor);
      break;

    case 'p': 
      saux = s;
      VisitaPreOrdem(ab,&saux);
      printf("Pre Ordem: %s\n",s);
      break;

    case 'q': 
      ImprimeABBusca(ab,0,Altura(ab));
      saux = s;
      VisitaInOrdem(ab,&saux);
      printf("In Ordem: %s\n",s);
      break;

    case 'r': 
      saux = s;
      VisitaPosOrdem(ab,&saux);
      printf("Pos Ordem: %s\n",s);
      break;

    case 'f':
      Frequencia(ab,&f,&n);
      for (i=0; i < n; i++) 
	printf("f[%d]=%d;",i,f[i]);
      printf("\n");
      break;

    case 'e':
      EliminaRepetidos(&ab);
      break;

    case 'E':
      if (Equilibrada(ab,&n)) 
	printf("Equilibrada\n");
      else 
	printf("Nao Equilibrada\n");
      break;
      
    case 'M':
      scanf("%d",&n);
      saux = s;
      MaioresValores(ab,&saux,&n);
      printf("%s\n",s);
      break;

    case 'm':
      scanf("%d",&n);
      saux = s;
      MenoresValores(ab,&saux,&n);
      printf("%s\n",s);
      break;

    case 'a':
      printf("Altura: %d\n",Altura(ab));
      break;

    case 'n':
      printf("Numero de nos: %d\n",NumerodeNos(ab));
      break;

    case 'I':
      ImprimeABBusca(ab,0,Altura(ab));
      break;

    default:
      ImprimeMenu();
    }

    while ((c=(char)fgetc(stdin))=='\n');
  }

  free(s);
  free(f);
  DestroiABBusca(&ab);

  return 0;
}
