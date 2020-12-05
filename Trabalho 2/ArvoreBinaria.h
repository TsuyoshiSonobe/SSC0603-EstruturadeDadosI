#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef char Tipo_Dado[20];

//Definicao do tipo Arvore
struct NO{
    Tipo_Dado info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin *raiz);
int insere(ArvBin *raiz, Tipo_Dado valor, Tipo_Dado valor_esq, Tipo_Dado valor_dir, int *achou);
void procura_insere(ArvBin *raiz, Tipo_Dado valor, Tipo_Dado valor_esq, Tipo_Dado valor_dir, int *achou);
int exibe(ArvBin *raiz, int *nodos, int *nodos_saida);
