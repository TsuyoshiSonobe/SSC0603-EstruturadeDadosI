#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"

int main(){

    ArvBin* raiz = cria_ArvBin();

    int i = 0, le = 1;  // variaveis auxiliares
    char valor[20], valor_esq[20], valor_dir[20];   // strings auxiliares
    char x[2] = {'X', '\0'};    

    // loop que faz a leitura do teclado ate que o usuario digite "X X X"
    while(le){
        scanf("%s %s %s", &valor[0], &valor_esq[0], &valor_dir[0]);
        if(strcmp(valor, x) != 0 || strcmp(valor_esq, x) != 0 || strcmp(valor_dir, x) != 0){
            insere(raiz, valor, valor_esq, valor_dir, &i);
        }
        else{
            le = 0;
        }
    }

    int *nodos = malloc(sizeof(int));   // armazena o numero total de nodos
    int *nodos_saida = malloc(sizeof(int)); // armazena o numero de nodos de saida (sem filhos)
    *nodos = 0;
    *nodos_saida = 0;
    exibe(raiz, nodos, nodos_saida);
    printf("%d %d", *nodos, *nodos_saida);

    free(nodos);
    free(nodos_saida);
    libera_ArvBin(raiz);

    return 0;
}
