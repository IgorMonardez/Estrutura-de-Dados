#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

TLSE *ordena(TLSE *l);


int main(int argc, char const *argv[])
{

	TLSE *lista = inicializa();

	while(1) {
		int numero;
		printf("Digite um valor(0 se quiser terminar): \n");
		scanf(" %d", &numero);

		if(!numero) break;

		lista = insere_inicio(lista, numero);

	}
	
	imprime(lista);

	TLSE * lista_ordenada = ordena(lista);

	imprime(lista);
	imprime(lista_ordenada);


	libera(lista);
	libera(lista_ordenada);
	return 0;
}

TLSE *ordena(TLSE *l) {
	if(!l) return NULL;

	TLSE *aux;
	TLSE *ant = inicializa();

	while(1) {
		troca = 0;
		aux = l;
		while(aux->prox != ant) {
			if(aux->info > aux->prox->info) {
				int temp = aux->info;
				aux->info = aux->prox->info;
				aux->prox->info = temp;
				troca = 1;
			}

			aux = aux->prox;
		}
		ant = aux;
		if(!troca) break;
	}

	return aux;
} 