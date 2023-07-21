#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

// Função para criar um novo nó da árvore
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore
No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        raiz = criarNo(valor);
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    return raiz;
}

// Função para percorrer a árvore em ordem (esquerda, raiz, direita)
void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        percorrerEmOrdem(raiz->direita);
    }
}

// Função para liberar a memória ocupada pela árvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}
