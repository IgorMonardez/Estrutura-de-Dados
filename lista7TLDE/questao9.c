#include <stdio.h>
#include <stdlib.h>
#include "TLDE.h"

TLDE * junta_listas(TLDE* l1, TLDE* l2);


int main(int argc, char const *argv[])
{
	TLDE *lista = inicializa();
	
	TLDE *lista2 = inicializa();
	int elemento;
	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar): \n");
		scanf(" %d", &numero);

		if(!numero) break;

		lista = insere_inicio(lista, numero);

	}

	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar): \n");
		scanf(" %d", &numero);

		if(!numero) break;

		lista2 = insere_inicio(lista2, numero);

	}

	imprime(lista);
	imprime(lista2);
	
	TLDE * resp = junta_listas(lista,lista2);
	

	imprime(resp);
	
	imprime(lista);
	imprime(lista2);
	libera(lista);
	libera(lista2);
	return 0;
}

TLDE * junta_listas(TLDE * l1, TLDE *l2) {
	TLDE * novo = inicializa();

	if(l2) {
		novo = junta_listas(l1, l2->prox);
	
		novo = insere_inicio(novo, l2->info);
	}

	if(l1) {
		novo = junta_listas(l1->prox, l2);
	
		novo = insere_inicio(novo, l1->info);
	}

	return novo;

}

	