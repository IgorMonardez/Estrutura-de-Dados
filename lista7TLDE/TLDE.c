#include "TLDE.h"

TLDE* inicializa(void) {
	return NULL;
}

TLDE* insere_inicio(TLDE *l, int x) {
	TLDE *novo = (TLDE*) malloc(sizeof(TLDE));
	novo->info = x;
	novo->prox = l;
	novo->ant = NULL;
	if(l) l->ant = novo;
	return novo;
}

void imprime(TLDE *l) {
	if(l) {
		printf("%d -> ", l->info);
		imprime(l->prox);
	}
	else printf("\n");
}

TLDE* insere_ordenado(TLDE *l, int x) {
	if((!l) || (l->info <= x)) {
		TLDE *novo = insere_inicio(l, x);

		return novo;
	}

	l->prox = insere_ordenado(l->prox, x);

	if(!l->prox) l->prox->ant = l;

	return l;
}

TLDE *busca(TLDE *l, int x) {
	if((!l) || l->info==x) return l;

	return busca(l->prox, x); 
}

void libera(TLDE *l) {
	if(l) {
		libera(l->prox);
		free(l);
	}
}

TLDE * retira(TLDE *l, int x) {
	TLDE * no_removido = busca(l, x);
	if(!no_removido) return l;

	if(no_removido == l) 
		l = l->prox;
	else 
		no_removido->ant->prox = no_removido->prox;

	if(no_removido->prox)
		no_removido->prox->ant = no_removido->ant;
	
	free(no_removido);

	return l;

}

TLDE *insere_fim(TLDE *l, int x) {
	if(!l) return insere_inicio(l, x);
	
	TLDE *aux = l;
	
	while(aux->prox) {
		aux = aux->prox;
	}

	aux->prox = insere_inicio(aux->prox, x);

	aux->prox->ant = aux;

	return l;
}

