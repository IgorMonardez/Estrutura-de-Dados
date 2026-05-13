#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

TLSE *copia(TLSE* l);

int main(int argc, char const *argv[])
{
	TLSE *lista = malloc(sizeof(TLSE));

	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar): ");
		scanf("%d", &numero);

		if(!numero) break;

		lista = insere_inicio(lista, numero);

	}

	imprime(lista);
	TLSE *lista_copiada = copia(lista);
	imprime(lista_copiada);

	return 0;
}

TLSE *copia(TLSE * l) {
	if(!l) return NULL;

	TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
	novo->info = l->info;
	novo->prox = copia(l->prox);
	return novo;	
}