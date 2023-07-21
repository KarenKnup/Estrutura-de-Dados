#include "ArvBinBusca.h"

/*----------- Fun�oes Privadas -----------------------------------------*/

char RemoveNoGrau0ou1(ABBusca **ab);
void SubstituiRemoveMenorSucessor(ABBusca **ab, ABBusca **maisesq); 
void CalculaFrequencia(ABBusca *ab, int **f);

/* Trata remo�ao de no folha ou com um unicio filho, retornando 1. Se
   este nao for o caso, retorna 0. */

char RemoveNoGrau0ou1(ABBusca **ab)
{
  ABBusca *aux;

  if ((*ab)->esq == NULL){ /* (*ab) eh folha ou tem unico filho */
    aux   = (*ab);
    (*ab) = (*ab)->dir;
    free(aux);
  } else {
    if ((*ab)->dir == NULL){ /* (*ab) eh folha ou tem unico filho */
      aux   = (*ab);
      (*ab) = (*ab)->esq;
      free(aux);
    } else {
      return(0);
    }
  }

  return(1);
}

/* Substitui o valor de um no, cujo valor esta sendo removido, pelo
   valor do menor sucessor deste no, e remove o no do menor
   sucessor. Auxilia RemoveValor. */ 

void SubstituiRemoveMenorSucessor(ABBusca **ab, ABBusca **maisesq)
{ 
  ABBusca *aux;
  
  if ((*maisesq)->esq == NULL){ 
    (*ab)->info = (*maisesq)->info; /* substitui valor */
    RemoveNoGrau0ou1(maisesq); /* remove no */
  } else { /* busca sucessor */
    SubstituiRemoveMenorSucessor(ab,&((*maisesq)->esq));
  }
}

/* Acumula a frequencia dos valores da arvore ab em vetor f para
   auxiliar a fun�ao Frequencia. */

void CalculaFrequencia(ABBusca *ab, int **f)
{
  if (ab != NULL) {
    (*f)[ab->info] += 1;
    CalculaFrequencia(ab->esq,f);
    CalculaFrequencia(ab->dir,f);
  }
}


/*------------------- Fun�oes Publicas ---------------------------------*/

/* Aloca e preenche um novo n� folha (insercao eh sempre de no
   folha) */

NoABBusca *CriaNovoNo(int info) {
  NoABBusca *p = (NoABBusca *)calloc(1,sizeof(NoABBusca));
  p->esq   = NULL;
  p->dir   = NULL;
  p->info  = info;
  return p;
  
} /* NovoNo */

void InsereValor(ABBusca **ab, int valor)
{
  if ((*ab) == NULL) { 
    (*ab) = CriaNovoNo(valor);
  } else {
    if ((*ab)->info <= valor)
      InsereValor(&((*ab)->dir),valor);
    else
      InsereValor(&((*ab)->esq),valor);		   
  }
}

void VisitaPreOrdem(ABBusca *ab, char **s)
{
  if (ab != NULL) {
    sprintf(*s,"%d ",ab->info);
    (*s) = (*s) + strlen(*s);
    VisitaPreOrdem(ab->esq, s);
    VisitaPreOrdem(ab->dir, s);
  }
}

void VisitaInOrdem(ABBusca *ab, char **s)
{
  if (ab != NULL) {
    VisitaInOrdem(ab->esq, s);
    sprintf(*s,"%d ",ab->info);
    (*s) = (*s) + strlen(*s);
    VisitaInOrdem(ab->dir, s);
  }
}

void VisitaPosOrdem(ABBusca *ab, char **s)
{
  if (ab != NULL) {
    VisitaPosOrdem(ab->esq, s);
    VisitaPosOrdem(ab->dir, s);    
    sprintf(*s,"%d ",ab->info);
    (*s) = (*s) + strlen(*s);
  }
}


void RemoveValor(ABBusca **ab, int valor)
{
  ABBusca *aux;
  
  if ((*ab) != NULL){  
    if ((*ab)->info != valor) {
      if ((*ab)->info < valor) { 
	RemoveValor(&((*ab)->dir),valor);
      } else {
	RemoveValor(&((*ab)->esq),valor);
      }
    } else { /* (*ab)->info == valor */
      if (RemoveNoGrau0ou1(ab)==0) /* Remove no de grau 2 */
	SubstituiRemoveMenorSucessor(ab,&((*ab)->dir));
    }
  }
}

void DestroiABBusca(ABBusca **ab) {

  while((*ab) != NULL) 
    RemoveValor(ab,(*ab)->info); 

}

int NumerodeNos(ABBusca *ab)
{
  if (ab != NULL) 
    return(1 + NumerodeNos(ab->esq) + NumerodeNos(ab->dir));
  else
    return(0);
}

int Altura(ABBusca *ab)
{
  if (ab != NULL) 
    return(1 + MAX(Altura(ab->esq),Altura(ab->dir)));
  else
    return(0);
}

void MaioresValores(ABBusca *ab, char **s, int *k)
{
  if ((ab != NULL)&&((*k) > 0)) {
    MaioresValores(ab->dir,s,k);
    if ((*k) > 0) {
      sprintf(*s,"%d ",ab->info);
      (*s) = (*s) + strlen(*s);
      (*k)--;
    }
    MaioresValores(ab->esq,s,k);
  }
}

void MenoresValores(ABBusca *ab, char **s, int *k)
{
  if ((ab != NULL)&&((*k) > 0)) {
    MenoresValores(ab->esq,s,k);
    if ((*k) > 0) {
    sprintf(*s,"%d ",ab->info);
    (*s) = (*s) + strlen(*s);
    (*k)--;
    }    
    MenoresValores(ab->dir,s,k);
  }
}

void Frequencia(ABBusca *ab, int **f, int *n)
{
  int maior,i;
  char *s,saida[TAM_MAX];

  if (ab != NULL) { 
    s = saida;
    i = 1;
    MaioresValores(ab,&s,&i);
    maior = atoi(saida);
    *n = maior+1;
    if ((*f)!=NULL) free((*f));
    (*f) = (int *) calloc(*n,sizeof(int));  
    CalculaFrequencia(ab,f);
  } else
    *n = 0;
}

void EliminaRepetidos(ABBusca **ab)
{ 
  int i, *f=NULL, n;
 
  if ((*ab) != NULL) { 
    Frequencia((*ab),&f,&n);
    for (i=0; i < n; i++) 
      while (f[i] > 1){ 
	RemoveValor(ab,i);
	f[i] = f[i] - 1;
      }
    free(f);
  }
}

void ImprimeABBusca(ABBusca *ab, int h, int altura)
{
  int i;

  if (ab != NULL) {
    ImprimeABBusca(ab->dir, h+1, altura);
    for (i=0; i < h; i++) 
      printf("   ");
    printf("%d",ab->info);
    for (i=0; i < altura-h; i++) 
      printf("---");
    printf("\n");
    ImprimeABBusca(ab->esq, h+1,altura);    
  }
}

char Equilibrada(ABBusca *ab, int *N)
{
  int Ne, Nd;

  if (ab == NULL) {
    *N = 0;
    return(1);
  } else {
    if (Equilibrada(ab->esq,&Ne) &&
	Equilibrada(ab->dir,&Nd) &&
	(abs(Ne-Nd) <= 1) ){
      (*N) = Ne + Nd + 1;
      printf("info %d Ne %d Nd %d\n",ab->info,Ne,Nd);
      return(1);
    } else {
      return(0);
    }
  }
}
