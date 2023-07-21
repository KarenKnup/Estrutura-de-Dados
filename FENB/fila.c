#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no {
    int valor;
    No* proximo;
};

struct fila {
    No* inicio;
    No* fim;
    int tamanho;
};

Fila* criaFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    No* noBobo = (No*) malloc(sizeof(No));
    noBobo->proximo = NULL;
    f->inicio = f->fim = noBobo;
    f->tamanho = 0;
    return f;
}

void destroiFila(Fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(f);
}

int enfileira(Fila* f, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    f->fim->proximo = novo;
    f->fim = novo;
    f->tamanho++;
    return 1;
}

int desenfileira(Fila* f) {
    if (vazia(f)) {
        return 0; // erro: fila vazia
    }
    No* primeiro = f->inicio->proximo;
    int valor = primeiro->valor;
    f->inicio->proximo = primeiro->proximo;
    free(primeiro);
    if (f->inicio->proximo == NULL) {
        f->fim = f->inicio;
    }
    f->tamanho--;
    return valor;
}

int primeiro(Fila* f) {
    if (vazia(f)) {
        return 0; // erro: fila vazia
    }
    return f->inicio->proximo->valor;
}

int tamanho(Fila* f) {
    return f->tamanho;
}

int vazia(Fila* f) {
    return f->inicio->proximo == NULL;
}
