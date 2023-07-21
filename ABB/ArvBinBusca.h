#ifndef _ABBusca_H_
#define _ABBusca_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a > b)?a:b)
#define TAM_MAX 100

/* Arvore Binaria de Busca com valores menores na subarvore esquerda e
   maiores ou iguais na subarvore direita de cada no */

typedef struct NoABBusca {  /* Registro que representa nó em árvore binária */
  int info;
  struct NoABBusca *esq, *dir;
} NoABBusca, ABBusca;


/* cria no folha (insercao eh sempre de no folha) */

NoABBusca *CriaNovoNo(int info); 

/* Esta fun�o deve inserir o valor da vari�vel "valor" na �rvore
   bin�ria de busca representada pela vari�vel "ab". Note que valores
   iguais devem ser inseridos sempre � direita. */

void InsereValor(ABBusca **ab, int valor); 

/* Esta fun�o deve percorrer a �rvore ab em pr�-ordem e gerar uma
   cadeia de caracteres s com os valores visitados em pr�-ordem
   separados por um espa�o em branco. */

void VisitaPreOrdem(ABBusca *ab, char **s); 

/* Esta fun�o deve percorrer a �rvore ab em in-ordem e gerar uma
   cadeia de caracteres s com os valores visitados em in-ordem
   separados por um espa�o em branco. */

void VisitaInOrdem(ABBusca *ab, char **s); 

/* Esta fun�o deve percorrer a �rvore ab em p�s-ordem e gerar uma
   cadeia de caracteres s com os valores visitados em p�s-ordem
   separados por um espa�o em branco. */

void VisitaPosOrdem(ABBusca *ab, char **s);  

/* Esta fun�o deve remover o valor da vari�vel "valor" da �rvore
   bin�ria de busca representada pela vari�vel "ab". Note que no caso
   de remo�o de n� de grau 2, seu valor deve ser substitu�do pelo
   valor do menor sucessor (no a esquerda com menor valor da subarvore
   direita), e o no sucessor deve ser removido. Isso porque a arvore
   resolve a igualdade inserindo o no na subarvore direita. Este
   sucessor nao tem filho a esquerda, mas pode ter filho a
   direita. Portanto, o no pai do sucessor deve apontar para o seu
   filho a direita antes da remocao do sucessor. Se a igualdade fosse
   resolvida com insercao na subarvore esquerda, deveriamos procurar o
   maior antecessor para substituicao. Neste caso, ele nao teria filho
   a direita, mas poderia ter filho a esquerda e o seu no pai deveria
   apontar para o filho a esquerda antes da remocao. */

void RemoveValor(ABBusca **ab, int valor); 

/* Esta fun�o deve liberar todo espa�o de mem�ria alocado para a
   �rvore */

void DestroiABBusca(ABBusca **ab); 

/* Esta fun�o deve calcular e retornar o n�mero de n�s da �rvore
   ab */

int  NumerodeNos(ABBusca *ab); 

/* Esta fun�o deve calcular e retornar a altura da �rvore ab */

int  Altura(ABBusca *ab); 

/* Esta fun�o deve calcular os k maiores valores armazenados na
   �rvore ab e retorn�-los em ordem decrescente e separados por um
   espa�o em branco na cadeia de caracteres s */

void MaioresValores(ABBusca *ab, char **s, int *k); 

/* Esta fun�o deve calcular os k menores valores armazenados na
   �rvore ab e retorn�-los em ordem crescente e separados por um
   espa�o em branco na cadeia de caracteres s */

void MenoresValores(ABBusca *ab, char **s, int *k); 

/* Esta fun�o sup�e que a �rvore ab armazena apenas valores n�o
   negativos. Ela deve calcular o maior valor K armazenado na �rvore e
   criar um vetor de freq�ncia f de tamanho n=K+1. Depois ela deve
   calcular e armazenar em f[i] o n�mero de ocorr�ncias do valor i na
   �rvore ab. Por fim, ela deve retornar o vetor f e seu tamanho n. */

void Frequencia(ABBusca *ab, int **f, int *n); 

/* Esta fun�o deve remover da �rvore ab todos os valores repetidos
   deixando apenas uma ocorr�ncia de cada valor. */

void EliminaRepetidos(ABBusca **ab); 

/* Imprime arvore binaria na tela onde h (altura do no) indica que ele
   sera precedido de h caracteres '-' antes de sua impressao. A funcao
   e chamada com h=0. */

void ImprimeABBusca(ABBusca *ab, int h, int altura);

/* Arvore Equilibrada: aquela que os numeros de nos das subarvores
   direita e esquerda nao diferem mais do que 1 para qualquer no. */

char Equilibrada(ABBusca *ab, int *N); 

#endif









