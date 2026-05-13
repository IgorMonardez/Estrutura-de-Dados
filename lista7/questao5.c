#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

void rto(TLSE* l, int elem);
TLSE *rto_nova(TLSE * l, int elem);

int main(int argc, char const *argv[])
{
	TLSE *lista = malloc(sizeof(TLSE));
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
	imprime(lista);
	rto(lista, elemento);
	imprime(lista);

	return 0;
}

void rto(TLSE * l, int elem) {
	if((!l) || (!l->prox)) return;

	if(l->prox->info == elem) {
		TLSE * rem = l->prox;
		l->prox = rem->prox;
		free(rem);

		rto(l, elem);
	} 
	else rto(l->prox, elem);
}

TLSE *rto_nova(TLSE * l, int elem) {
	if(!l) return NULL;

	if(l->info == elem)
		l = retira(l, elem);
	
	l->prox = rto(l->prox, elem);
	return l;
}
