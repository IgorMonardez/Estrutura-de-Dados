#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
	int x;
	int y;
} TPTO2D;

int dentroRet (TPTO2D *inf, TPTO2D *sup, TPTO2D *p);

int main(int argc, char const *argv[]) {
	
	
	TPTO2D *ponto_sup = (TPTO2D *) malloc(sizeof(TPTO2D));
	TPTO2D *ponto_inf = (TPTO2D *) malloc(sizeof(TPTO2D));
	printf("Defina o retângulo (x,y) inferior e superior.\n");
	scanf(" %d %d %d %d", &(ponto_inf->x), &(ponto_inf->y), &(ponto_sup->x), &(ponto_sup->y));

	printf("Retângulo: inf (%d,%d), sup (%d,%d)\n", ponto_inf->x, ponto_inf->y, ponto_sup->x, ponto_sup->y);

	TPTO2D *ponto = (TPTO2D *) malloc(sizeof(TPTO2D));
	printf("Digite o ponto.\n");
	scanf(" %d %d", &ponto->x, &ponto->y);

	int result = dentroRet(ponto_inf, ponto_sup, ponto);

	if(result) 
		printf("Ponto(%d,%d) está dentro do retangulo.\n", ponto->x, ponto->y);
	else
		printf("Ponto(%d,%d) NÃO está dentro do retangulo.\n", ponto->x, ponto->y);
		

	return 0;
}

int dentroRet (TPTO2D *inf, TPTO2D *sup, TPTO2D *p) {
	
	if((p->x >= inf->x && p->x <= sup->x) || (p->x <= inf->x && p->x >= sup->x)) {
		if((p->y >= inf->y && p->y <= sup->y) || (p->y <= inf->y && p->y >= sup->y)) {
			return 1;
		}
	} 

	return 0;



}
