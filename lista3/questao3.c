#include<stdio.h>

/*
	Verifica se um número é o anagrama de outro.
*/


int verifica_permutacao(int a, int b);

int main(int argc, char*argv) {
	
	while(1) {
		int a,b;
		scanf("%d %d", &a, &b);

		if(a<=0 && b<=0) break;

		int resp = verifica_permutacao(a,b);

		if(resp)
			printf("%d é permutação de %d\n", b, a);
		else
			printf("%d não é permutação de %d\n", b, a);
	}
	
	return 0;
}

int verifica_permutacao(int a, int b) {

	int vet_a[sizeof(int) * 8];
	int i = 0,j = 0;

	while(a > 0) {
		vet_a[i] = a%10;
		a /= 10;
		i++;
	}
	int tam_a = i;
	
	while(b > 0) {
		int numero = b%10;

		for(i = 0; i < tam_a; i++) {
			if(numero == 0) break;
			if(numero == vet_a[i]) {
				vet_a[i] = 0;
				break;
			}
		}
		b /= 10;
	}

	for(i = 0; i<tam_a;i++) 
		if(vet_a[i]) return 0;

	return 1;
}
