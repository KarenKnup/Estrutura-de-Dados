#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
struct conj{
    Elem*prim;
};

struct elemento{

    int elem;
    struct elemento *prox;
};

Conjunto* conj_Cria(void)
{
    Conjunto *p;
    p=(Conjunto*)malloc(sizeof(Conjunto));
    p->prim=NULL;
    return p;
}
int conj_Ehmembro(Conjunto*A, int x)
{
    Elem *p;
    for(p=A->prim;p!=NULL;p=p->prox)
    {
        if(p->elem==x)
            return 1;
    }
    return 0;
}

void conj_Insere(Conjunto*C, int x)
{
    Elem *p,*novo;
    if(conj_Ehmembro(C,x)==1)
        return ;
    novo=(Elem*)malloc(sizeof(Elem));
    novo->elem=x;
    novo->prox=NULL;
    if(C->prim==NULL)
        C->prim=novo;
    else
    {
        for(p=C->prim;p->prox!=NULL;p=p->prox);
        p->prox=novo;
    }
    return ;

}

int  conj_Remove(int x, Conjunto *C)
{
    Elem *p,*ant;
    if(conj_Ehmembro(C,x)==0)
        return 0;
    for(ant=NULL, p=C->prim;p->elem!=x;ant=p,p=p->prox);
	if(ant == NULL)
		C->prim=p->prox;
	else
		ant->prox=p->prox;
    free(p);
    return 1;
}



Conjunto* conj_Intersecao(Conjunto* A, Conjunto* B)
{
    Conjunto *salvador;
    Elem*novo=NULL,*andante,*p;
    salvador=conj_Cria();
    
    for(p=A->prim;p!=NULL;p=p->prox)
    {
        if(conj_Ehmembro(B,p->elem)==1)
        {
            conj_Insere(salvador,p->elem);
        }
    }
    return salvador;
}

Conjunto* conj_Uniao(Conjunto* A, Conjunto* B)
{
    Conjunto *salvador;
    Elem*novo=NULL,*andante,*p;
    salvador=conj_Cria();
    
    for(p=A->prim;p!=NULL;p=p->prox)
    {
         conj_Insere(salvador,p->elem);
        
    }
	for(p=B->prim;p!=NULL;p=p->prox)
    {
        if(conj_Ehmembro(A,p->elem)==0)
        {
            conj_Insere(salvador,p->elem);
        }
    }
    return salvador;
}

Conjunto* conj_Diferenca(Conjunto* A, Conjunto* B)
{
    Conjunto *salvador;
    Elem*novo=NULL,*andante,*p;
    salvador=conj_Cria();
    
    for(p=A->prim;p!=NULL;p=p->prox)
    {
		
        if(conj_Ehmembro(B,p->elem)==0)
        {
            conj_Insere(salvador,p->elem);
        }
        
    }
	return salvador;
}

        

void conj_exibe(Conjunto*A)
{
    Elem*p;
    for(p=A->prim;p!=NULL;p=p->prox)
        printf("%d\t",p->elem);
    printf("\n");
    return;
}

void conj_Libera (Conjunto*A)
{
    Elem*p,*ant;
    p=A->prim;
    while(p!=NULL)
    {
        ant=p;
        p=p->prox;
        free(ant);
    }
    return;
}