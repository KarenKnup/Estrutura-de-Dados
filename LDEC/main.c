#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
    int opcao, valor, anterior;
    //No *lista = NULL;
    Lista *lista;
    No *removido;

    lista=criar_lista();

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirO\n\t4 - Remover\n\t5 - Imprimir\n\t6 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(lista, valor);
            break;
         case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(lista, valor);
            break;
        case 3:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(lista, valor);
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(lista, valor);
            if(removido){
                printf("Elemento removido: %d\n", valor);
                free(removido);
            }
            else
                printf("elemento inexistente!\n");
            break;
        case 5:
            imprimir(lista);
            break;
        case 6:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(lista, valor);
            if(removido)
                printf("Valor encontrado: %d\n",valor);
            else
                printf("Valor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}