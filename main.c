#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Pilha.h"

int intervalo( char c );

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	char *temp = malloc( 50 );
	printf("\n Insira a Expressão: ");
	gets( temp );
	int tam_str = strlen(temp);
	
	int i, cont = 0, valid = 1;
	char *temp2 = malloc( tam_str );
	for(i=0; temp[i]!='\0' && valid; i++) {
		if( temp[i]!=32 ) {
			temp2[cont] = temp[i];
			if( !intervalo( temp2[cont++]) ) {
				valid = 0;
			}
		}
	}
	
	free( temp );
	char E[tam_str];
	strcpy( E, temp2 );
	free( temp2 );
	
	char S[tam_str], c, x;
	Pilha p;
	
	return 0;
}

int intervalo( char c ) {
	if( c<40 || ( c>43 && c<45 ) || ( c>45 && c<47 ) || c>57  ) {
		return 0;
	}
	return 1;
}
