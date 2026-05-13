#include <stdio.h>
#include <stdlib.h>
#include "TLDE.h"

TLDE *inverte(TLDE* l);

int main(int argc, char const *argv[])
{
	TLDE *lista = inicializa();

	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar):\n");
		scanf("%d", &numero);

		if(!numero) break;

		lista = insere_fim(lista, numero);


	}
	imprime(lista);
	TLDE *lista_invertida = inverte(lista);
	imprime(lista);
	imprime(lista_invertida);

	return 0;
}

TLDE * inverte(TLDE * l) {
	TLDE * novo = inicializa();

	while(l) {
		novo = insere_inicio(novo, l->info);
		l = l->prox;
	}

	return novo;
}