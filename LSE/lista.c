#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    int valor;
    No* prox;
};

struct lista {
    No* inicio;
    int qtd;
};

Lista* criaLista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->qtd = 0;
    return l;
}

void destroiLista(Lista* l) {
    No* p = l->inicio;
    while (p != NULL) {
        No* t = p->prox;
        free(p);
        p = t;
    }
    free(l);
}

int insereElemento(Lista* l, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->qtd++;
    return 1;
}

int removeElemento(Lista* l, int valor) {
    No* ant = NULL;
    No* p = l->inicio;
    while (p != NULL && p->valor != valor) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        return 0; // erro: elemento não encontrado
    }
    if (ant == NULL) {
        l->inicio = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    l->qtd--;
    return 1;
}

int buscaElemento(Lista* l, int valor) {
    No* p = l->inicio;
    int i = 0;
    while (p != NULL && p->valor != valor) {
        p = p->prox;
        i++;
    }
    if (p == NULL) {
        return -1; // erro: elemento não encontrado
    }
    return i;
}

void exibeLista(Lista* l) {
    No* p = l->inicio;
    while (p != NULL) {
        printf("%d ", p->valor);
        p = p->prox;
    }
    printf("\n");
}
