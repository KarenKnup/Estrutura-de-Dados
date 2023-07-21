#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criaLista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->qtd = 0;
    return l;
}

void destroiLista(Lista* l) {
    free(l);
}

int insereElemento(Lista* l, int valor) {
    int i;
    if (l->qtd == MAX) {
        return 0; // erro: lista cheia
    }
    for (i = 0; i < l->qtd; i++) { // verifica se o elemento já está na lista
        if (l->elementos[i] == valor) {
            return 0; // erro: elemento já está na lista
        }
    }
    l->elementos[l->qtd] = valor; // insere o elemento no final da lista
    l->qtd++; // incrementa a quantidade de elementos da lista
    return 1; // sucesso: elemento inserido
}

int removeElemento(Lista* l, int valor) {
    int pos, i;
    pos = buscaSequencial(l, valor); // busca a posição do elemento a ser removido
    if (pos == -1) {
        return 0; // erro: elemento não encontrado
    }
    for (i = pos; i < l->qtd - 1; i++) { // desloca os elementos à direita da posição do elemento a ser removido
        l->elementos[i] = l->elementos[i+1];
    }
    l->qtd--; // decrementa a quantidade de elementos da lista
    return 1; // sucesso: elemento removido
}

int buscaSequencial(Lista* l, int valor) {
    int i;
    for (i = 0; i < l->qtd; i++) {
        if (l->elementos[i] == valor) {
            return i; // sucesso: elemento encontrado na posição i
        }
    }
    return -1; // erro: elemento não encontrado
}

void exibeLista(Lista* l) {
    int i;
    for (i = 0; i < l->qtd; i++) {
        printf("%d ", l->elementos[i]);
    }
    printf("\n");
}
