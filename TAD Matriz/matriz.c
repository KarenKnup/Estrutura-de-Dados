#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

typedef struct matriz {
    int m; // número de linhas
    int n; // número de colunas
    float** v; // ponteiro para os elementos
} Matriz;

/* Função mat_cria - Aloca e retorna matriz m por n */
Matriz* mat_cria(int m, int n) {
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz)); // aloca struct
    mat->m = m;
    mat->n = n;
    mat->v = (float**)malloc(m * sizeof(float*)); // aloca vetor de ponteiros
    for (int i = 0; i < m; i++) {
        mat->v[i] = (float*)malloc(n * sizeof(float)); // aloca linha i
        for (int j = 0; j < n; j++) {
            mat->v[i][j] = 0; // inicializa elemento (i,j) com zero
        }
    }
    return mat;
}

/* Função mat_libera - Libera a memória de uma matriz */
void mat_libera(Matriz* mat) {
    for (int i = 0; i < mat->m; i++) {
        free(mat->v[i]); // libera linha i
    }
    free(mat->v); // libera vetor de ponteiros
    free(mat); // libera struct
}

/* Função mat_acessa - Retorna o valor do elemento [i][j] */
float mat_acessa(Matriz* mat, int i, int j) {
    return mat->v[i][j];
}

/* Função mat_atribui - Atribui valor ao elemento [i][j] */
void mat_atribui(Matriz* mat, int i, int j, float v) {
    mat->v[i][j] = v;
}

/* Função mat_linhas - Retorna o no. de linhas da matriz */
int mat_linhas(Matriz* mat) {
    return mat->m;
}

/* Função mat_colunas - Retorna o no. de colunas da matriz */
int mat_colunas(Matriz* mat) {
    return mat->n;
}

/* Função mat_exibe - Imprime a matriz */
void mat_exibe(Matriz* mat) {
    for (int i = 0; i < mat->m; i++) {
        for (int j = 0; j < mat->n; j++) {
            printf("%.2f ", mat->v[i][j]); // imprime elemento (i,j) com duas casas decimais
        }
        printf("\n"); // pula linha
    }
}

/* Função mat_multiplica - retorna a matriz resultante da multiplicação das 2 matrizes recebidas */
Matriz* mat_multiplica(Matriz* mA, Matriz* mB) {
    int mA_linhas = mat_linhas(mA);
    int mA_colunas = mat_colunas(mA);
    int mB_linhas = mat_linhas(mB);
    int mB_colunas = mat_colunas(mB);

    if (mA_colunas != mB_linhas) {
        printf("Erro: Numero de colunas de mA deve ser igual ao numero de linhas de mB\n");
        return NULL;
    }

    Matriz* mC = mat_cria(mA_linhas, mB_colunas);
    int i, j, k;
    for (i = 0; i < mA_linhas; i++) {
        for (j = 0; j < mB_colunas; j++) {
            float soma = 0;
            for (k = 0; k < mA_colunas; k++) {
                soma += mat_acessa(mA, i, k) * mat_acessa(mB, k, j);
            }
            mat_atribui(mC, i, j, soma);
        }
    }
    return mC;
}

/* Função mat_soma - retorna a matriz resutante da soma das 2 matrizes recebidas */
Matriz* mat_soma(Matriz* mA, Matriz* mB) {
    int linhasA = mat_linhas(mA);
    int colunasA = mat_colunas(mA);
    int linhasB = mat_linhas(mB);
    int colunasB = mat_colunas(mB);

    // Verifica se as matrizes têm as mesmas dimensões
    if (linhasA != linhasB || colunasA != colunasB) {
        printf("Erro: as matrizes precisam ter as mesmas dimensões.\n");
        return NULL;
    }

    // Cria uma nova matriz para armazenar o resultado da soma
    Matriz* mC = mat_cria(linhasA, colunasA);

    // Realiza a soma das matrizes
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasA; j++) {
            float valorA = mat_acessa(mA, i, j);
            float valorB = mat_acessa(mB, i, j);
            float valorC = valorA + valorB;
            mat_atribui(mC, i, j, valorC);
        }
    }

    return mC;
}

/* Função mat_subtrai - retorna a matriz resutante da subtração das 2 matrizes recebidas */
Matriz* mat_subtrai(Matriz* mA, Matriz* mB) {
    int linhasA = mat_linhas(mA);
    int colunasA = mat_colunas(mA);
    int linhasB = mat_linhas(mB);
    int colunasB = mat_colunas(mB);

    // Verifica se as matrizes têm o mesmo tamanho
    if (linhasA != linhasB || colunasA != colunasB) {
        printf("Erro: as matrizes não têm o mesmo tamanho\n");
        return NULL;
    }

    // Cria a matriz resultante
    Matriz* resultado = mat_cria(linhasA, colunasA);

    // Subtrai cada elemento da matriz A com o correspondente na matriz B
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasA; j++) {
            float valorA = mat_acessa(mA, i, j);
            float valorB = mat_acessa(mB, i, j);
            mat_atribui(resultado, i, j, valorA - valorB);
        }
    }

    return resultado;
}

/* Função mat_somaLinha - Retorna a soma dos elementos da linha recebida */
float mat_somaLin (Matriz* mat, int l) {
    int n = mat->n; // número de colunas da matriz
    float soma = 0;

    for (int j = 0; j < n; j++) {
        soma += mat_acessa(mat, l, j); // soma os elementos da linha l
    }

    return soma;
}

/* Função mat_somaCol - Retorna a soma dos elementos da coluna recebida */
float mat_somaCol(Matriz* mat, int c) {
    float soma = 0;
    int i;
    
    if (c < 0 || c >= mat_colunas(mat)) {
        printf("Indice de coluna invalido.\n");
        return 0;
    }

    for (i = 0; i < mat_linhas(mat); i++) {
        soma += mat_acessa(mat, i, c);
    }

    return soma;
}
