#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

void i_p_refer(TLSE* l);
TLSE *i_p(TLSE * l);

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

	imprime(lista);
	lista = i_p(lista);
	imprime(lista);

	return 0;
}

void i_p_refer(TLSE * l) {



}

TLSE *i_p(TLSE * l) {
	TLSE *par = inicializa();
	TLSE *impar = inicializa();


	while(l) {
		if(l->info % 2 == 0) 
			par = insere_inicio(par, l->info);
		else 
			impar = insere_inicio(impar, l->info);
		l = l->prox;
	}

	TLSE *novo = inicializa();
	while(par) {
		novo = insere_inicio(novo, par->info);
		par = par->prox;
	}

	while(impar) {
		novo = insere_inicio(novo, impar->info);
		impar = impar->prox;
	}

	libera(par);
	libera(impar);
	libera(l);

	return novo;
}
