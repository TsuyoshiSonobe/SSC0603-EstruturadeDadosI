#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef char Tipo_Dado[26]; // definicao do tipo dado 

// definicao do tipo arvore
struct NO{
    int n_acessos;
    Tipo_Dado palavra_original;
    Tipo_Dado palavra_traduzida;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL* raiz, int valor, Tipo_Dado dado1, Tipo_Dado dado2);
void traducao(ArvAVL *raiz, Tipo_Dado dado);
void autocompletar_ArvAVL(ArvAVL *raiz, Tipo_Dado dado, int n_acessos);
int compara_string(Tipo_Dado palavra1, Tipo_Dado palavra2);
