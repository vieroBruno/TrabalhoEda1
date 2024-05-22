#define ERRO_COORD_INVALIDA -1

typedef struct{
	int **dados;
	int lin, col;
} Grafo;

void inicializa_grafo( Grafo *p, int l, int c );
void mostra_grafo( Grafo x );
int set_valor( Grafo *p, int i, int j, int valor );
void desaloca_grafo( Grafo *p );
int carrega_grafo( char *nome_arq, Grafo *p );

