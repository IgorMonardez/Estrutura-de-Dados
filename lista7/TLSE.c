#include "TLSE.h"

TLSE* inicializa(void) {
	return NULL;
}

TLSE* insere_inicio(TLSE *l, int x) {
	TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
	novo->info = x;
	novo->prox = l;
	return novo;
}

void imprime(TLSE *l) {
	if(l) {
		printf("%d -> ", l->info);
		imprime(l->prox);
	}
	else printf("\n");
}

TLSE* insere_ordenado(TLSE *l, int x) {
	if((!l) || (l->info >= x)) {
		TLSE *novo = insere_inicio(l, x);
		return novo;
	}

	l->prox = insere_ordenado(l->prox, x);
	return l;
}

TLSE *busca(TLSE *l, int x) {
	if((!l) || l->info==x) return l;

	return busca(l->prox, x); 
}

void libera(TLSE *l) {
	if(l) {
		libera(l->prox);
		free(l);
	}
}

TLSE * retira(TLSE *l, int x) {
	if(!l) return l;
	
	if(l->info == x) {
		TLSE *p = l;
		l = l->prox;
		free(p);
	}
	else 
		l->prox = retira(l->prox, x);

	return l;
}


TLSE * insere_fim(TLSE *l, int x) {

	TLSE *aux = l;

	while(aux->prox) {
		aux = aux->prox;
	}

	aux = insere_inicio(aux, x);

	return l;
}
