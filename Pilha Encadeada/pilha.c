#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no {
    float valor;
    No* proximo;
};

struct pilha {
    No* topo;
    int tamanho;
};

Pilha* criaPilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void destroiPilha(Pilha* p) {
    No* atual = p->topo;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(p);
}

int push (Pilha* p, float valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
    return 1;
}

float pop (Pilha* p) {
    if (vazia(p)) {
        return 0; // erro: pilha vazia
    }
    No* topoAntigo = p->topo;
    int valor = topoAntigo->valor;
    p->topo = topoAntigo->proximo;
    free(topoAntigo);
    p->tamanho--;
    return valor;
}

int topo(Pilha* p) {
    if (vazia(p)) {
        return 0; // erro: pilha vazia
    }
    return p->topo->valor;
}

Pilha* clona_pilha(Pilha *p){
  Pilha *aux=criaPilha();
  while(p!=NULL){
    push(aux,pop(p));
  }
  return aux;
}

float topo(Pilha* p) {
    if (pilha_vazia(p)) {        
        return 0;
    }
    Pilha* aux = pilha_cria();
    float top_element;
    // usa Pop até chegar no topo
    while (!pilha_vazia(p)) {
        float element = pilha_pop(p);
        pilha_push(aux, element);
        // Capturando o elemento do topo
        if (pilha_vazia(p)) {
            top_element = element;
        }
    }
    // Restaurando o conteúdo original da pilha
    while (!pilha_vazia(aux)) {
        float element = pilha_pop(aux);
        pilha_push(p, element);
    }
    pilha_libera(aux);

    return top_element;
}

void concatena_pilhas(Pilha* p1, Pilha* p2) {
    Pilha* aux = pilha_cria();
    // Transfere os elementos de p1 para o aux
    while (!pilha_vazia(p1)) {
        float element = pilha_pop(p1);
        pilha_push(aux, element);
    }
    //Transfere os elementos de p2 para p1
    while (!pilha_vazia(p2)) {
        float element = pilha_pop(p2);
        pilha_push(p1, element);
    }
    // Restaura os elementos de aux para p1
    while (!pilha_vazia(aux)) {
        float element = pilha_pop(aux);
        pilha_push(p1, element);
    }
    pilha_libera(aux);
}


int tamanho(Pilha* p) {
    return p->tamanho;
}

int vazia(Pilha* p) {
    return p->topo == NULL;
}
