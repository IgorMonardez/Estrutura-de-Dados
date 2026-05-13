#include <stdio.h>
#include <stdlib.h>
#include "TLDE.h"

void i_p_refer(TLDE* l);
TLDE *i_p(TLDE * l);

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

	imprime(lista);
	TLDE *lista_ip = i_p(lista);

	imprime(lista);

	imprime(lista_ip);

	i_p_refer(lista);

	imprime(lista);
	
	return 0;
}

void i_p_refer(TLDE * l) {
	TLDE *aux = l, *par = inicializa(), *impar = inicializa();

	while(aux) {
		if((aux->info % 2) == 0) 
			par = insere_inicio(par, aux->info);
		else
			impar = insere_inicio(impar, aux->info);

		aux = aux->prox;
	}

	TLDE *ultimo_impar = impar;

	while(ultimo_impar->prox) ultimo_impar = ultimo_impar->prox;

	ultimo_impar->prox = par->prox;

	if(par->prox) par->prox->ant = ultimo_impar;

	l = impar;

}

TLDE *i_p(TLDE * l) {
	TLDE *par = inicializa();
	TLDE *impar = inicializa();


	while(l) {
		if(l->info % 2 == 0) 
			par = insere_inicio(par, l->info);
		else 
			impar = insere_inicio(impar, l->info);
		l = l->prox;
	}

	TLDE *novo = inicializa();
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

	return novo;
}
