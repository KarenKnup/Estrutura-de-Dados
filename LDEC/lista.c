#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    int valor;
    No* ant;
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
    while (p != NULL && p->prox != l->inicio) {
        No* t = p->prox;
        free(p);
        p = t;
    }
    free(p);
    free(l);
}

int insereElemento(Lista* l, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    if (l->inicio == NULL) {
        l->inicio = novo;
        novo->ant = novo;
        novo->prox = novo;
    } else {
        novo->prox = l->inicio;
        novo->ant = l->inicio->ant;
        l->inicio->ant->prox = novo;
        l->inicio->ant = novo;
    }
    l->qtd++;
    return 1;
}

int removeElemento(Lista* l, int valor) {
    No* p = l->inicio;
    while (p != NULL && p->valor != valor) {
        p = p->prox;
        if (p == l->inicio) {
            return 0; // erro: elemento não encontrado
        }
    }
    if (p->ant == p) {
        l->inicio = NULL;
    } else {
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        if (p == l->inicio) {
            l->inicio = p->prox;
        }
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
        if (p == l->inicio) {
            return -1; // erro: elemento não encontrado
        }
    }
    return i;
}

void exibeLista(Lista* l) {
    No* p = l->inicio;
    while (p != NULL && p->prox != l->inicio) {
        printf("%d ", p->valor);
        p = p->prox;
    }
    if (p != NULL) {
        printf("%d ", p->valor);
    }
    printf("\n");
}
