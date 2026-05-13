#include <stdio.h>
#include <stdlib.h>
#include "TLDE.h"

void rto(TLDE* l, int elem);
TLDE *rto_nova(TLDE * l, int elem);

int main(int argc, char const *argv[])
{
	TLDE *lista = inicializa();
	int elemento;
	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar): ");
		scanf("%d", &numero);

		if(!numero) break;

		lista = insere_inicio(lista, numero);

	}

	printf("Digite o elemento que deseja retirar da lista: ");
	scanf("%d", &elemento);
	printf("Pré-remoção.\n");

	imprime(lista);
	
	TLDE * lista_rto = rto_nova(lista, elemento);

	printf("Pós remoção usando o método da nova.\n");

	imprime(lista);
	imprime(lista_rto);



	printf("Pós remoção usando o método que altera a original.\n");
	rto(lista, elemento);
	imprime(lista);



	return 0;
}

void rto(TLDE * l, int elem) {
	if((!l) || (!l->prox)) return;

	if(l->prox->info == elem) {
		TLDE * rem = l->prox;
		l->prox = rem->prox;
		free(rem);

		rto(l, elem);
	} 
	else rto(l->prox, elem);
}

TLDE *rto_nova(TLDE * l, int elem) {
	if(!l) return NULL;

	TLDE *novo = inicializa();
	if(l->info != elem) {
		novo = insere_inicio(novo, l->info);
		novo->prox = rto_nova(l->prox, elem);

		return novo;
	}

	return rto_nova(l->prox, elem);
}
