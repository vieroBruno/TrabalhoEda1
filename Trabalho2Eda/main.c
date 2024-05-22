#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(int argc, char *argv[]) {
	Grafo g;
	
	carrega_grafo( "entrada.txt", &g );
	mostra_grafo( g );
	
	desaloca_grafo( &g );
	
	return 0;
}
