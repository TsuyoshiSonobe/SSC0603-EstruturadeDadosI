//Arquivo ListaDinEncad.h


//Definicao do tipo lista
typedef char Tipo_Dado;

struct elemento{
    Tipo_Dado dados;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, Tipo_Dado dado);
int insere_lista_cripto(Lista *li, Tipo_Dado dt, int pos);
int remove_lista_cripto(Lista *li, int pos);
void insere_lista(Lista *li);
void imprime_lista(Lista* li);
void cripto_cesar(Lista *li, int num);
void descripto_cesar(Lista *li, int num);
void cripto_cesar_sequencia(Lista *li);
void descripto_cesar_sequencia(Lista *li);
void cripto_chave(Lista *li, int chave[5]);
void descripto_chave(Lista *li, int chave[5]);
void cripto_chave_insercao(Lista *li, int chave[5]);
void descripto_chave_insercao(Lista *li, int chave[5]);