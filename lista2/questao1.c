#include<stdio.h>
#include<math.h>

int teste(int n);

int pow_int(int base, int expoente);

int main(int argc, char const *argv[])
{
	int num;

	while(1) {
		scanf("%d", &num);

		if(num == -1) break;

		teste(num);

	}

	return 0;
}

int pow_int(int base, int expoente) {
	int result = 1;
	for(int i = 0; i< expoente; i++) {
		result *= base;
	}
	return result;
}

int teste(int n) {

	int inicio = abs(n); 
	int fim;

	fim = n%100;

	while(inicio >= 100) {
		inicio /=10;
	}

	int numero_esperado = inicio*100 + fim;
	int soma = inicio + fim;

	int numero_comparado = pow_int(soma,2);


	if(numero_comparado == numero_esperado) 
		printf("1\n");
	else
		printf("0\n");

}