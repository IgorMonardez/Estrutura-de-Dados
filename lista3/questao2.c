#include<stdio.h>

/*
	Derivadas e integrais usando apenas vetores.
*/
void calcula_derivada(int *vet, int grau, int *derivada);

void calcula_integral(int *vet, int grau, int *integral);

int main(int argc, char*argv) {
	
	while(1) {

		int grau;

		scanf("%d", &grau);

		if(grau <= 0) break;

		int vet[grau + 1];

		for(int i = 0; i<(grau + 1); i++)
			scanf(" %d", &vet[i]);

		int derivada[grau];
		int integral[grau + 2];

		calcula_derivada(vet, grau, derivada);
		
		printf("Derivada\n{");
		for(int i = 0; i<(grau); i++)
			printf("%d\t", derivada[i]);
		printf("}\n");

		calcula_integral(vet, grau, integral);
	
		printf("Integral\n{");
		for(int i = 0; i<(grau + 2); i++)
			printf("%d\t", integral[i]);
		printf("}\n");



	}
	
	return 0;
}


void calcula_derivada(int* vet, int grau, int *derivada) {
	for(int i = 1; i<(grau + 1); i++)
		derivada[i-1] = vet[i]*i;

}



void calcula_integral(int* vet, int grau, int *integral) {
	integral[0] = 0;
	for(int i = 0; i<(grau + 1); i++) 	
		integral[i + 1] = ((vet[i])/(i+1));
}