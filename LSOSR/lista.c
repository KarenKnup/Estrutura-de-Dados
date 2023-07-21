#include <stdio.h>
#include "lista.h"

void inicializaLista(Lista* l) {
    l->qtd = 0;
}

int tamanhoLista(Lista* l) {
    return l->qtd;
}

int listaVazia(Lista* l) {
    return l->qtd == 0;
}

int listaCheia(Lista* l) {
    return l->qtd == MAX;
}

int buscaSequencial(Lista* l, int valor) {
    int i;
    for (i = 0; i < l->qtd; i++) {
        if (l->elementos[i] == valor) {
            return i;
        }
    }
    return -1; // elemento não encontrado
}

int buscaBinaria(Lista* l, int valor) {
    int ini = 0, fim = l->qtd - 1, meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (l->elementos[meio] == valor) {
            return meio;
        } else if (l->elementos[meio] < valor) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // elemento não encontrado
}

int insereOrdenado(Lista* l, int valor) {
    int i, pos;
    if (listaCheia(l)) {
        return 0; // erro: lista cheia
    }
    pos = 0;
    while (pos < l->qtd && l->elementos[pos] < valor) {
        pos++;
    }
    for (i = l->qtd - 1; i >= pos; i--) {
        l->elementos[i+1] = l->elementos[i];
    }
    l->elementos[pos] = valor;
    l->qtd++;
    return 1; // sucesso: elemento inserido
}

int removeElemento(Lista* l, int valor) {
    int pos, i;
    pos = buscaBinaria(l, valor); // busca a posição do elemento a ser removido
    if (pos == -1) {
        return 0; // erro: elemento não encontrado
    }
    for (i = pos; i < l->qtd - 1; i++) { // desloca os elementos à direita da posição do elemento a ser removido
        l->elementos[i] = l->elementos[i+1];
    }
    l->qtd--; // decrementa a quantidade de elementos da lista
    return 1; // sucesso: elemento removido
}

void exibeLista(Lista* l) {
    int i;
    for (i = 0; i < l->qtd; i++) {
        printf("%d ", l->elementos[i]);
    }
    printf("\n");
}
