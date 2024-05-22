#include "Grafo.h"
#include <stdlib.h>
#include <stdio.h>

void inicializa_grafo( Grafo *p, int l, int c ){
	p->lin = l;
	p->col = c;
	p->dados = malloc( sizeof(int*) * l );
	int i, j;
	for( i = 0 ; i < l ; i++ ){
		p->dados[i] = calloc( c, sizeof(int) );
	}
}

void mostra_grafo( Grafo x ){
	printf("Dados do Grafo:\n");
	int i, j;
	for( i = 0 ; i < x.lin ; i++ ){
		for( j = 0 ; j < x.col ; j++ )
			printf("%d\t", x.dados[i][j]);
		printf("\n");
	}
}

int set_valor( Grafo *p, int i, int j, int valor ){
	if( i >= p->lin || j >= p->col || i < 0 || j < 0 )
		return ERRO_COORD_INVALIDA;
			
	p->dados[i][j] = valor;
	return 1; // Sucesso.
}

void desaloca_grafo( Grafo *p ){
	int i;
	for( i = 0 ; i < p->lin ; i++ )
		free( p->dados[i] );
	free( p->dados );
}

int carrega_grafo( char *nome_arq, Grafo *p ){
	FILE *f = fopen( nome_arq, "rt" );
	if( f == NULL )
		return 0; // Erro! (função booleana)
		
	int lin, col, x;
	fscanf( f, "%d %d", &lin, &col );
	inicializa_grafo( p , lin, col );
	int i, j;
	for( i = 0 ; i < p->lin ; i++ )
		for( j = 0 ; j < p->col ; j++ ){
			fscanf( f, "%d", &x);
			set_valor( p, i, j, x );
		}

	return 1; // Sucesso!
}

