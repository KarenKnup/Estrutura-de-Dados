#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila {
    int* elementos;
    int frente, tras;
    int tamanhoMax;
};

Fila* criaFila(int tamanhoMax) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->elementos = (int*) malloc(tamanhoMax * sizeof(int));
    f->frente = f->tras = -1;
    f->tamanhoMax = tamanhoMax;
    return f;
}

void destroiFila(Fila* f) {
    free(f->elementos);
    free(f);
}

int enfileira(Fila* f, int valor) {
    if (f->tras == f->tamanhoMax - 1) {
        return 0; // erro: fila cheia
    }
    if (f->frente == -1) {
        f->frente = 0;
    }
    f->tras++;
    f->elementos[f->tras] = valor;
    return 1;
}

int desenfileira(Fila* f) {
    if (f->frente == -1) {
        return 0; // erro: fila vazia
    }
    int valor = f->elementos[f->frente];
    if (f->frente == f->tras) {
        f->frente = f->tras = -1;
    } else {
        f->frente++;
    }
    return valor;
}

int frente(Fila* f) {
    if (f->frente == -1) {
        return 0; // erro: fila vazia
    }
    return f->elementos[f->frente];
}

int tamanho(Fila* f) {
    if (f->frente == -1) {
        return 0;
    }
    return f->tras - f->frente + 1;
}

int vazia(Fila* f) {
    return f->frente == -1;
}

int cheia(Fila* f) {
    return f->tras == f->tamanhoMax - 1;
}
