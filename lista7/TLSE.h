#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int info;
	struct lista *prox;
}
TLSE;

TLSE* inicializa(void);

TLSE* insere_inicio(TLSE *l, int x);

TLSE* insere_fim(TLSE *l, int x);

void imprime(TLSE *l);

TLSE* insere_ordenado(TLSE *l, int x);

TLSE *busca(TLSE *l, int x);

void libera(TLSE *l);

TLSE * retira(TLSE *l, int x);

