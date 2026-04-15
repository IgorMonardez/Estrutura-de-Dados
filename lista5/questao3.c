#include <stdio.h>
#include <stdlib.h>

int ** matriz_hadamard(int n);

void imprime(int ** matriz, int nl, int nc);

int main(int argc, char const *argv[])
{
	
	while(1) {
		int n;
		printf("Digite os grau(>=0) da matriz de hadamard que deseja.\n");
		scanf(" %d", &n);

		if(n<0) break;

		matriz_hadamard(n);
	}


	return 0;
}

void imprime(int **matriz, int nl, int nc) {
	for(int i = 0; i<nl;i++) {
		for(int j = 0; j<nc; j++)
			printf(" %d", matriz[i][j]);
		printf("\n");
	}
}

int ** matriz_hadamard(int n) {
	int ** matriz;

	if(n == 0) {
		matriz = (int**) malloc(sizeof(int*));
		matriz[0] = (int*) malloc(sizeof(int));
		matriz[0][0] = 1;
		printf("H(1)\n");
		imprime(matriz, 1, 1);
		return matriz;
	}

	int m = 1;
	for(int i = 0; i<(n-1); i++)
		m *= 2;
		
	matriz = matriz_hadamard(n-1);

	int tamanho = m * 2;
	int **nova =  (int**) malloc(sizeof(int*) * tamanho);

	for(int i = 0; i<tamanho;i++) 
		nova[i] = (int*) malloc(sizeof(int) * tamanho);

	for(int i = 0; i< m;i++) {
		for(int j = 0; j< m; j++) {
			nova[i][j] = matriz[i][j];
			nova[i][j+m] = matriz[i][j];
			nova[i + m][j] = matriz[i][j];
			nova[i+m][j+m] = !matriz[i][j];
		}
	}
	for(int i = 0; i<m;i++) free(matriz[i]);

	free(matriz);
	
	printf("H(%d)\n", tamanho);
	imprime(nova, tamanho, tamanho);
	return nova;

}
