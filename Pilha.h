#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2

typedef struct{
	int *dados;
	int topo, capacidade;
}Pilha;

void inicializa_pilha( Pilha *p, int c );
int pilha_vazia( Pilha p );
int pilha_cheia( Pilha p );
int empilha1(Pilha *p, char info );
int desempilha1( Pilha *p, char *info );
int empilha2(Pilha *p, int info );
int desempilha2( Pilha *p, int *info );
int le_topo( Pilha p, char *info );
void mostra_pilha( Pilha p );
void desaloca_pilha( Pilha *p );
int precedencia( char info );

