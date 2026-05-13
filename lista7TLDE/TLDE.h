#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int info;
	struct lista *prox;
	struct lista *ant;
}
TLDE;

TLDE* inicializa(void);

TLDE* insere_inicio(TLDE *l, int x);

TLDE* insere_fim(TLDE *l, int x);

void imprime(TLDE *l);

TLDE* insere_ordenado(TLDE *l, int x);

TLDE *busca(TLDE *l, int x);

void libera(TLDE *l);

TLDE * retira(TLDE *l, int x);
