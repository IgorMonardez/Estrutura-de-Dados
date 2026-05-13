#include <stdio.h>
#include <stdlib.h>
#include "TLDE.h"

int igual(TLDE* l1, TLDE* l2);


int main(int argc, char const *argv[])
{
	TLDE *lista = inicializa();
	
	TLDE *lista2 = inicializa();
	int elemento;
	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar): ");
		scanf("%d", &numero);

		if(!numero) break;

		lista = insere_inicio(lista, numero);

	}

	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar): ");
		scanf("%d", &numero);

		if(!numero) break;

		lista2 = insere_inicio(lista2, numero);

	}

	imprime(lista);
	imprime(lista2);
	
	int resp = igual(lista, lista2);

	if(resp) 
		printf("As listas são iguais.\n");
	else
		printf("As listas são diferentes\n");
	
	return 0;
}

int igual(TLDE * l1, TLDE *l2) {

	if(!l1 && !l2) return 1;

	if(!l1 || !l2) return 0;

	if(l1->info != l2->info) return 0;

	return igual(l1->prox, l2->prox);

}

