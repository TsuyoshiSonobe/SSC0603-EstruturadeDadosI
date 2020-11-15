#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main()
{   
    //Recebe a opcao de criptografia/descriptografia escolhida pelo usuario
    int opcao;
    scanf("%d", &opcao);

    scanf("\r\n");  //Remove buffer

    Lista *li = cria_lista();
    
    //Chama a funcao de criptografia/descriptografia corresponde a cada opcao 
    switch(opcao){

        case 1:{
            insere_lista(li);
            cripto_cesar(li, 1);
        }break;

        case -1:{
            insere_lista(li);
            descripto_cesar(li, 1);
        }break;

        case 2:{
            insere_lista(li);
            cripto_cesar(li, 3);
        }break;

        case -2:{
            insere_lista(li);
            descripto_cesar(li, 3);
        }break;

        case 3:{
            insere_lista(li);
            cripto_cesar_sequencia(li);
        }break;

        case -3:{
            insere_lista(li);
            descripto_cesar_sequencia(li);
        }break;

        case 4:{
            //Recebe a chave usada na criptografia
            int chave[5];
            char chave_c[5];
            for(int i = 0; i < 5; i++){
                chave_c[i] = fgetc(stdin);
                chave[i] = chave_c[i] - '0';
            }

            scanf("\r\n");

            insere_lista(li);
            cripto_chave(li, chave);

        }break;

        case -4:{
            //Recebe a chave usada na descriptografia
            int chave[5];
            char chave_c[5];
            for(int i = 0; i < 5; i++){
                chave_c[i] = fgetc(stdin);
                chave[i] = chave_c[i] - '0';
            }

            scanf("\r\n");

            insere_lista(li);
            descripto_chave(li, chave);

        }break;

        case 5:{
            //Recebe a chave usada na criptografia
            int chave[5];
            char chave_c[5];
            for(int i = 0; i < 5; i++){
                chave_c[i] = fgetc(stdin);
                chave[i] = chave_c[i] - '0';
            }

            scanf("\r\n");

            insere_lista(li);
            cripto_chave_insercao(li, chave);
        }break;

        case -5:{
            //Recebe a chave usada na descriptografia
            int chave[5];
            char chave_c[5];
            for(int i = 0; i < 5; i++){
                chave_c[i] = fgetc(stdin);
                chave[i] = chave_c[i] - '0';
            }

            scanf("\r\n");

            insere_lista(li);
            descripto_chave_insercao(li, chave);
        }break;

    }

    imprime_lista(li);
    libera_lista(li);

    return 0;
}
