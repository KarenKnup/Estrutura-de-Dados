#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Racional.h"
struct rac	    
{	
	int a;	
	int b; 
};
// Protótipos das funções auxiliares
// obtém o numerador do Racional 	
int getN(Racional* x);
// obtém o denominador do Racional	
int getD(Racional* x);

// Implementação das funções
int getN(Racional* x){ return x->a;}
int getD(Racional* x){ return x->b;}

Racional* rac_cria(int x, int y)
{
	Racional* r=(Racional*) malloc(sizeof(Racional));
	r->a = x;
	r->b = y; 
	return r;
}

void rac_libera(Racional* x){
	free(x);
}

Racional* rac_add(Racional* x, Racional *y)
{
	Racional* r=(Racional*) malloc(sizeof(Racional));
	r->a = (getN(x)*getD(y) )+ (getN(y)*getD(x));
	r->b = getD(x) * getD(y); 
	return(r);
}
Racional* rac_sub(Racional* x, Racional*  y)
{ 
	Racional* r=(Racional*)malloc(sizeof(Racional));
	r->a = ((getN(x)*getD(y)) - (getN(y)*getD(x)));
	r->b = getD(x) * getD(y); 
	return(r);
}
Racional* rac_mul(Racional* x, Racional* y)
{ 
	Racional* r=(Racional*)malloc(sizeof(Racional));
	r->a = getN(x) * getN(y);
	r->b = getD(x) * getD(y); 
	return(r);
}
Racional* rac_divide(Racional* x, Racional* y)
{ 
	Racional* r=(Racional*)malloc(sizeof(Racional));
	r->a = getN(x) * getD(y);
	r->b = getD(x) * getN(y); 
	return(r);
}
char * rac_exibe(Racional* x)
{ 
	static char s[30];
	sprintf(s, "%i / %i", getN(x), getD(x));
	return s;  
}
