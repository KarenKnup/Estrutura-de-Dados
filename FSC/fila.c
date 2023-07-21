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
    f->frente = f->tras = 0;
    f->tamanhoMax = tamanhoMax;
    return f;
}

void destroiFila(Fila* f) {
    free(f->elementos);
    free(f);
}

int enfileira(Fila* f, int valor) {
    int proxTras = (f->tras + 1) % f->tamanhoMax;
    if (proxTras == f->frente) {
        return 0; // erro: fila cheia
    }
    f->elementos[f->tras] = valor;
    f->tras = proxTras;
    return 1;
}

int desenfileira(Fila* f) {
    if (f->frente == f->tras) {
        return 0; // erro: fila vazia
    }
    int valor = f->elementos[f->frente];
    f->frente = (f->frente + 1) % f->tamanhoMax;
    return valor;
}

int frente(Fila* f) {
    if (f->frente == f->tras) {
        return 0; // erro: fila vazia
    }
    return f->elementos[f->frente];
}

int tamanho(Fila* f) {
    if (f->frente <= f->tras) {
        return f->tras - f->frente;
    } else {
        return f->tamanhoMax - f->frente + f->tras;
    }
}

int vazia(Fila* f) {
    return f->frente == f->tras;
}

int cheia(Fila* f) {
    int proxTras = (f->tras + 1) % f->tamanhoMax;
    return proxTras == f->frente;
}
