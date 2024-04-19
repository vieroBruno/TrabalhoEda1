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
				if(i!=0) {
					if( ( temp[i]>=48 && temp[i]<=57 ) && ( temp2[cont-1]>=48 && temp2[cont-1]<=57 ) ) {
						valid = 0;
					}
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
	
	Pilha p;
	int deu_erro = 0;
	char S[tam_str], c, x;
	
	inic_pilha( &p, tam_str );
	
	cont = 0;
	for(i=0; E[i]!='\0' && !deu_erro; i++) {
		c = E[i];
		switch( c ) {
			case '0'...'9':
				S[cont++] = c;
				break;
			case '(':
				empilha( &p, c );
				break;
			case ')':
				while( ( le_topo( p, &x ) != ERRO_PILHA_VAZIA ) && ( x != '(' ) ) {
					desempilha( &p, &x );
					S[cont++] = x;
				}
				if( pilha_vazia( p ) ) {
					system("CLS");
					printf("\n Erro: ')' sem '('!");
					deu_erro = 1;
				} else {
					desempilha( &p, &x );
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				le_topo( p, &x );
				if( pilha_vazia( p ) || ( x == '(' ) ) {
					empilha( &p, c );
				} else {
					while( ( le_topo( p, &x ) != ERRO_PILHA_VAZIA ) && ( precedencia( x ) >= precedencia( c ) ) ) {
						desempilha( &p, &x );
						S[cont++] = x;
					}
					empilha( &p, c );
				}
				break;
		}
	}
	
	if(!deu_erro) {
		while( ( le_topo( p, &x ) != ERRO_PILHA_VAZIA ) && ( x != '(' ) ) {
			desempilha( &p, &x );
			S[cont++] = x;
		}
		if( pilha_vazia ) {
			S[cont] = '\0';
			system("CLS");
			printf("\n Expressão Original: \n\n");
			for(i=0; E[i]!='\0'; i++) {
				printf(" %c", E[i]);
			}
			printf("\n\n Expressão Final: \n\n");
			for(i=0; S[i]!='\0'; i++) {
				printf(" %c", S[i]);
			}			
		} else {
			system("CLS");
			printf("\n Erro: '(' não foi Fechado!");
		}
	}
	
	return 0;
}

int intervalo( char c ) {
	if( c<40 || c==44 || c==46 || c>57  ) {
		return 0;
	}
	return 1;
}
