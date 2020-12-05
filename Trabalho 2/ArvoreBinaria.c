#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h" //inclui os Prototipos

// cria a raiz da arvore
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

// desaloca cada nodo
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

// desaloca a arvore toda
void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
}

// insere os dados na arvore
int insere(ArvBin *raiz, Tipo_Dado valor, Tipo_Dado valor_esq, Tipo_Dado valor_dir, int *achou){
    if(raiz == NULL){
        return 0;
    }
    *achou = 0;
    procura_insere(raiz, valor, valor_esq, valor_dir, achou);

    if((*achou) == 0){
        struct NO* novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        strcpy(novo->info, valor);
        novo->dir = NULL;
        novo->esq = NULL;

        char x[2] = {'X', '\0'};
        if(strcmp(valor_esq, x) != 0){
            struct NO* novo_esq;
            novo_esq = (struct NO*) malloc(sizeof(struct NO));
            if(novo_esq == NULL)
                return 0;
            strcpy(novo_esq->info, valor_esq);
            novo_esq->dir = NULL;
            novo_esq->esq = NULL;
            novo->esq = novo_esq;
        }
        if(strcmp(valor_dir, x) != 0){
            struct NO* novo_dir;
            novo_dir = (struct NO*) malloc(sizeof(struct NO));
            if(novo_dir == NULL)
                return 0;
            strcpy(novo_dir->info, valor_dir);
            novo_dir->dir = NULL;
            novo_dir->esq = NULL;
            novo->dir = novo_dir;
        }
        *raiz = novo;
    }
    return 1;
}

// procura os dados para inserir os seus filhos
void procura_insere(ArvBin *raiz, Tipo_Dado valor, Tipo_Dado valor_esq, Tipo_Dado valor_dir, int *achou){
    if(raiz == NULL){
        return;
    }
    if(*achou){
        return;
    }
    if(*raiz != NULL){
        if(strcmp(valor, (*raiz)->info) == 0){
            *achou = 1;

            struct NO* novo;
            novo = (struct NO*) malloc(sizeof(struct NO));
            if(novo == NULL)
                return;

            strcpy(novo->info, valor);
            novo->dir = NULL;
            novo->esq = NULL;

            char x[2] = {'X', '\0'};
            if(strcmp(valor_esq, x) != 0){
                struct NO* novo_esq;
                novo_esq = (struct NO*) malloc(sizeof(struct NO));
                if(novo_esq == NULL)
                    return;
                strcpy(novo_esq->info, valor_esq);
                novo_esq->dir = NULL;
                novo_esq->esq = NULL;
                novo->esq = novo_esq;
            }
            if(strcmp(valor_dir, x) != 0){
                struct NO* novo_dir;
                novo_dir = (struct NO*) malloc(sizeof(struct NO));
                if(novo_dir == NULL)
                    return;
                strcpy(novo_dir->info, valor_dir);
                novo_dir->dir = NULL;
                novo_dir->esq = NULL;
                novo->dir = novo_dir;
            }
            *raiz = novo;
        }
    }
    else{
        return;
    }
    procura_insere(&((*raiz)->esq), valor, valor_esq, valor_dir, achou);
    procura_insere(&((*raiz)->dir), valor, valor_esq, valor_dir, achou);
}

// exibe as informacoes de saida sobre a arvore
int exibe(ArvBin *raiz, int *nodos, int *nodos_saida){
    int num_filhos = 0;
    char filhos[3] = {'F', ' ', '\0'};

    if(raiz == NULL)
        return 0;
    if(raiz != NULL){
        printf("%s ", (*raiz)->info);
        (*nodos)++;
        if((*raiz)->esq != NULL){
            num_filhos++;
            filhos[0] = 'E';
        }
        if((*raiz)->dir != NULL){
            num_filhos++;
            if(filhos[0] == 'E'){
                filhos[1] = 'D';
            }
            else{
                filhos[0] = 'D';
            }
        }

        printf("%d ", num_filhos);
        if(num_filhos == 0){
            printf("%c\n", filhos[0]);
            (*nodos_saida)++;
        }
        else{
            for(int i = 0; i < num_filhos; i++){
                printf("%c", filhos[i]);
            }
            printf("\n");
        }

        if(filhos[0] == 'F'){
            return 0;
        }
        if(filhos[0] == 'E'){
            exibe(&((*raiz)->esq), nodos, nodos_saida);
            if(filhos[1] == 'D'){
                exibe(&((*raiz)->dir), nodos, nodos_saida);
            }
        }
        else{
            exibe(&((*raiz)->dir), nodos, nodos_saida);
        }
    }
    return 1;
}
