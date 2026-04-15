#include<stdio.h>

/*
	URI ONLINE JUDGE 1318
*/

int verifica_copias(int *vet, int n);


int main(int argc, char*argv) {
	
	while(1) {
		int m,n;
		scanf("%d %d", &n, &m);

		if(m==0 && m==n) break;


		int vet[m];
		for(int i = 0; i<m;i++) {
			scanf(" %d", &vet[i]);
		}

		printf("%d\n", verifica_copias(vet,m));

	}	
	
	return 0;
}

int verifica_copias(int *vet, int n) {

	int copias = 0, i, j;

	for(i = 0; i<n; i++) 
		for(j = 0; j<n; j++)
			if((i != j) && (vet[i] == vet[j])) copias++;

	return copias/2;
}

