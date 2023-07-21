#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Representa�o do TAD: TData
//-----------
// Interface
//-----------

typedef struct data tData;

/* Fun�es exportadas */
/* Fun�o cria - Aloca e retorna uma data dia/m�s/ano */
tData* dta_cria(int dia, int mes, int ano);

/* Fun�o libera � Libera  mem�ria de uma Data criada */
void dta_libera(tData* p);

/* Fun�o acessa - Retorna os valores de uma Data */
void dta_acessa(tData* p, int* dia, int* mes, int* ano);

/* Fun�o atribui - Atribui novos valores � Data */
void dta_atribui(tData* p, int dia, int mes, int ano);

/* Fun�o Intervalo - Retorna a data ap�s X dias */
tData* dta_intervalo(tData* p1, int X);

/* Fun�o Exibe � Escreve na tela a data  no formato dd/mm/aaaa */
void dta_exibe(tData* p1);

/* Fun�o getData - Retorna uma string com os valores da data no formato dd/mm/aaaa*/
char* dta_getData(tData* p);