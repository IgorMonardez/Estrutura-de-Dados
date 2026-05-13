#include <stdio.h>
#include <stdlib.h>
#include "TLDE.h"

TLDE *copia(TLDE* l);

int main(int argc, char const *argv[])
{
	TLDE *lista = inicializa();

	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar): ");
		scanf("%d", &numero);

		if(!numero) break;

		lista = insere_inicio(lista, numero);

	}

	imprime(lista);
	TLDE *lista_copiada = copia(lista);
	imprime(lista_copiada);

	return 0;
}

TLDE *copia(TLDE * l) {
	if(!l) return NULL;

	TLDE *novo = (TLDE*) malloc(sizeof(TLDE));
	novo->info = l->info;
	novo->prox = copia(l->prox);
	if(l) novo->ant = l;
	
	return novo;	
}