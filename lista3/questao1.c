#include<stdio.h>

/*

	Primo pelo método da Peneira de Eratosthenes. Basicamente primos com programação dinâmica.

*/


int verifica_primo(int *vet, int n);

int main(int argc, char*argv) {
	
	while(1) {

		int n;

		scanf("%d", &n);

		if(n<2) break;

		int vet[n - 2];

		vet[0] = 2;

		int quantidade = verifica_primo(vet, n - 2);

		for(int i = 0; i<quantidade; i++)
			printf("%d\t", vet[i]);
		printf("\n");
	}


	return 0;
}

int verifica_primo(int *vet, int n) {
	int cont_primos = 1, i = 3, j = 0;

	for(i = 3; i < n; i++) {
		int cont_divisao = 0;

		for(j = 0; j < cont_primos; j++) 
			if((i % (vet[j])) == 0) {
				cont_divisao++;
				break;
			}
		
		if(!cont_divisao) {
			vet[j] = i;
			cont_primos++;
		}
			 
	}

	return cont_primos;

}

