#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Pilha.h"

int intervalo( char c );

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	char *temp = malloc( 50 ), *temp2;
	int tam_str, i, cont = 0, valid = 1;
	do {
		if(!valid) {
			system("CLS");
			printf("\n Valores Inválidos!");
		}
		valid = 1;
		printf("\n Insira a Expressão: ");
		gets( temp );
		tam_str = strlen(temp);
		temp2 = malloc( tam_str );
		for(i=0; temp[i]!='\0' && valid; i++) {
			if( temp[i]!=32 ) {
				if( !intervalo( temp[i]) ) {
					valid = 0;
				}
				if( valid ) {
					temp2[cont++] = temp[i];
				}			
			}
		}
	} while( !valid );
	
	free( temp );
	char E[tam_str];
	strcpy( E, temp2 );
	free( temp2 );
	
	char S[tam_str], c, x;
	Pilha p;
	
	return 0;
}

int intervalo( char c ) {
	if( c<40 || c==44 || c==46 || c>57  ) {
		return 0;
	}
	return 1;
}
