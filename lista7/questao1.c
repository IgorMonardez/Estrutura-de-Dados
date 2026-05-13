#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

TLSE *inverte(TLSE* l);

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
	lista = inverte(lista);
	imprime(lista);

	return 0;
}

TLSE * inverte(TLSE * l) {
	TLSE * novo = inicializa();

	while(l) {
		novo = insere_inicio(novo, l->info);
		l = l->prox;
	}

	return novo;
}