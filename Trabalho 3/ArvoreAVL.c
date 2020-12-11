#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreAVL.h" //inclui os Prototipos

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);   //libera cada no
    free(raiz); //libera a raiz
}

int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

// funcao que procura e imprime a palavra traduzida a partir da palavra original 
void traducao(ArvAVL *raiz, Tipo_Dado dado){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        if(strcmp((*raiz)->palavra_original, dado) == 0){
            printf("%s\n", (*raiz)->palavra_traduzida);
            (*raiz)->n_acessos++;
            return;
        }
        traducao(&((*raiz)->esq), dado);
        traducao(&((*raiz)->dir), dado);
    }
}

// funcao que procura as palavras na arvore a partir de uma "parte" da palavra e imprime aqueles que tiverem certo numero de acessos
void autocompletar_ArvAVL(ArvAVL *raiz, Tipo_Dado dado, int n_acessos){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        int compara = compara_string(dado, (*raiz)->palavra_original);

        if(compara == 0){
            autocompletar_ArvAVL(&((*raiz)->esq), dado, n_acessos);
            if((*raiz)->n_acessos >= n_acessos){
                printf("%s\n", (*raiz)->palavra_original);
            }
            autocompletar_ArvAVL(&((*raiz)->dir), dado, n_acessos);
        }
        else if(compara < 0){
            autocompletar_ArvAVL(&((*raiz)->esq), dado, n_acessos);
        }
        else{
            autocompletar_ArvAVL(&((*raiz)->dir), dado, n_acessos);
        }
    }
}

// funcao para comparar strings de tamanhos iguais ou diferentes
int compara_string(Tipo_Dado palavra1, Tipo_Dado palavra2){                                               
    int tamanho1 = strlen(palavra1);
    int tamanho2 = strlen(palavra2);
    Tipo_Dado aux1, aux2;

    if(tamanho1 == tamanho2){
        return strcmp(palavra1, palavra2);
    }                   
    else{
        for(int i = 0; i < tamanho1; i++){                      
            aux1[i] = palavra1[i];
            aux2[i] = palavra2[i];
        }
        aux1[tamanho1] = '\0';
        aux2[tamanho1] = '\0';  
        return strcmp(aux1, aux2);
    }
}

//=================================
void RotacaoLL(ArvAVL *A){//LL
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A){//RR
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL* raiz, int valor, Tipo_Dado dado1, Tipo_Dado dado2){
    int res;
    if(*raiz == NULL){//arvore vazia ou no folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;
        novo->n_acessos = valor;
        novo->altura = 0;
        strcpy(novo->palavra_original, dado1);    
        strcpy(novo->palavra_traduzida, dado2);
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(strcmp(dado1, atual->palavra_original) < 0){
        if((res = insere_ArvAVL(&(atual->esq), valor, dado1, dado2)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(strcmp(dado1, (*raiz)->esq->palavra_original) < 0){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(strcmp(dado1, atual->palavra_original) > 0){
            if((res = insere_ArvAVL(&(atual->dir), valor, dado1, dado2)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if(strcmp((*raiz)->dir->palavra_original, dado1) < 0){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}