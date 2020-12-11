#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreAVL.h"

FILE *ArqIn;

int main(){
    int n_acessos, tamanho;
    Tipo_Dado dado1, dado2;
    
    // cria arvore binaria balanceada
    ArvAVL* avl;
    avl = cria_ArvAVL();

    // abre arquivo
    ArqIn=fopen("dict.txt","rt");
    if (ArqIn == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        exit(0); 
    }
    // le dados do arquivo
    while(!feof(ArqIn)){   
        fscanf(ArqIn, "%d", &n_acessos);
        if(n_acessos == -1){
            break;
        }
        fscanf(ArqIn, "%s", &dado1[0]);
        tamanho = strlen(dado1);
        fscanf(ArqIn, "%s", &dado2[0]);
        insere_ArvAVL(avl, n_acessos, dado1, dado2);
    }
    fclose(ArqIn);  // fecha o arquivo

    // loop de execucao do programa (0 para traducao, >0 para autocompletar e -1 para sair)
    int num = 0;
    while(num != -1){
        scanf("%d", &num);
        if(num == -1){
            break;
        }
        else{
            Tipo_Dado palavra;
            scanf("%s", &palavra[0]);
            if(num == 0){
                traducao(avl, palavra);
            }
            else if(num > 0){
                autocompletar_ArvAVL(avl, palavra, num);
            }
        }
    }

    libera_ArvAVL(avl); // desaloca a arvore

    return 0;
}



