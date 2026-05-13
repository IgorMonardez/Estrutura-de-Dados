#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

TLSE *inverte(TLSE *l1);

int contrario(TLSE *l1, TLSE *l2);

int main(int argc, char const *argv[])
{
	TLSE *lista = inicializa();
	
	TLSE *lista2 = inicializa();
	int elemento;
	int numero;
	while(1) {
		printf("Digite um valor(0 se quiser terminar): \n");
		scanf("%d", &numero);

		if(!numero) break;

		lista = insere_inicio(lista, numero);

	}

	while(1) {
		printf("Digite um valor(0 se quiser terminar): \n");
		scanf(" %d", &numero);

		if(!numero) break;

		lista2 = insere_inicio(lista2, numero);

	}

	imprime(inverte(lista));
	imprime(lista2);

	int result = contrario(lista, lista2);

	if(result)
		printf("Listas ao contrario.\n");
	else
		printf("Listas não estão ao contrário.\n");

	libera(lista);
	libera(lista2);
	return 0;
}

TLSE *inverte(TLSE *l1) {
	TLSE *aux = inicializa();

	while(l1) {
		aux = insere_inicio(aux,l1->info);
		l1 = l1->prox;
	}

	return aux;
}

int contrario(TLSE *l1, TLSE *l2) {

	TLSE *aux = inverte(l1);

	while(1) {
		if(!l2 && !aux) break;

		if((!l2 && aux) || (!aux && l2)) return 0;

		if(aux->info != l2->info) return 0;

		aux = aux->prox;
		l2 = l2->prox;
	}

	return 1;

}