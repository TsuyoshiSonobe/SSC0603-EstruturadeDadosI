#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Prototipos

//Funcao que cria a lista
Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

//Funcao que desaloca a memoria destinada a lista
void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

//Funcao que insere um dado ao final da lista
int insere_lista_final(Lista* li, Tipo_Dado dado){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = dado;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere inicio
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

//Funcao que insere um caractere em uma determinada posicao na lista
int insere_lista_cripto(Lista *li, Tipo_Dado dt, int pos){
    if(li == NULL){
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = dt;

    Elem *atual = *li;
    int aux = 1;
    while(atual != NULL && aux != pos){
        atual = atual->prox;
        aux++;
    }
    if(atual->prox == NULL){  //insere no final
        atual->prox = no;
        no->prox = NULL;
    }
    else{
        no->prox = atual->prox;
        atual->prox = no;
    }
    return 1;
}

//Funcao que remove um dado de uma determinada posicao na lista
int remove_lista_cripto(Lista *li, int pos){
    if(li == NULL){
        return 0;
    }

    Elem *atual, *prox;
    atual = *li;
    int aux = 1;
    while(atual != NULL && aux != pos){
        atual = atual->prox;
        prox = atual->prox;
        aux++;
    }
    if(atual == NULL || prox == NULL){
        return 0;
    }
    else{
        atual->prox = prox->prox;
        free(prox);
    }
    return 1;
}

//Funcao que insere todos os dados (caracteres, neste caso) na lista
void insere_lista(Lista *li){
    char c = fgetc(stdin);
    while(c != '\n' && c!= '\r'){
        insere_lista_final(li, c);
        c = fgetc(stdin);
    }
}

//Funcao que imprime a lista
void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%c",no->dados);
        no = no->prox;
    }
}

//Faz a criptografia do tipo cifra cesar
void cripto_cesar(Lista *li, int num){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        no->dados = (no->dados + num);
        no = no->prox;
    }
}

//Faz a descriptografia do tipo cifra cesar
void descripto_cesar(Lista *li, int num){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        no->dados = (no->dados - num);
        no = no->prox;
    }
}

//Faz a criptografia do tipo cesar para uma sequencia de 1 a 3
void cripto_cesar_sequencia(Lista *li){
    if(li == NULL)
        return;
    Elem* no = *li;
    int num = 1;
    while(no != NULL){
        no->dados = (no->dados + num);
        no = no->prox;
        if(num < 3){
            num++;
        }
        else{
            num = 1;
        }
    }
}

//Faz a descriptografia do tipo cesar para uma sequencia de 1 a 3
void descripto_cesar_sequencia(Lista *li){
    if(li == NULL)
        return;
    Elem* no = *li;
    int num = 1;
    while(no != NULL){
        no->dados = (no->dados - num);
        no = no->prox;
        if(num < 3){
            num++;
        }
        else{
            num = 1;
        }
    }
}

//Faz a criptografia com o uso de chaves
void cripto_chave(Lista *li, int chave[5]){
    if(li == NULL)
        return;
    Elem* no = *li;
    int aux = 0;
    while(no != NULL){
        no->dados = (no->dados + chave[aux]);
        no = no->prox;
        if(aux < 4){
            aux++;
        }
        else{
            aux = 0;
        }
    }
}

//Faz a descriptografia com o uso de chaves
void descripto_chave(Lista *li, int chave[5]){
    if(li == NULL)
        return;
    Elem* no = *li;
    int aux = 0;
    while(no != NULL){
        no->dados = (no->dados - chave[aux]);
        no = no->prox;
        if(aux < 4){
            aux++;
        }
        else{
            aux = 0;
        }
    }
}

//Faz a criptografia com o uso de chaves e insercao de caractere no texto
void cripto_chave_insercao(Lista *li, int chave[5]){
    if(li == NULL)
        return;
    Elem* no = *li;
    int aux = 0;
    int pos = 3;

    while(no != NULL){
        for(int i = 0; i < 3; i++){
            if(no != NULL){
                no->dados = (no->dados + chave[aux]);
                if(aux < 4){
                    aux++;
                }
                else{
                    aux = 0;
                }
                no = no->prox;
                if(i == 2){
                    insere_lista_cripto(li, '*', pos);
                    pos += 4;
                }
            }
            else{
                break;
            }
        }
    }
}

//Faz a descriptografia com o uso de chaves e retira os caracteres inserido no texto
void descripto_chave_insercao(Lista *li, int chave[5]){
    if(li == NULL)
        return;
    Elem* no = *li;
    int aux = 0;
    int pos = 3;

    while(no != NULL){
        for(int i = 0; i < 3; i++){
            if(no != NULL){
                no->dados = (no->dados - chave[aux]);
                if(aux < 4){
                    aux++;
                }
                else{
                    aux = 0;
                }
                no = no->prox;
                if(i == 2){
                    remove_lista_cripto(li, pos);
                    pos += 3;
                    no = no->prox;
                }
            }
            else{
                break;
            }
        }
    }
}