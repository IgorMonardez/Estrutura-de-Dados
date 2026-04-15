#include<stdio.h>

int testa_palindromo(int num);
	
int main(int argc, char const *argv[])
{
	int num;

	while(1) {
		scanf("%d", &num);

		if(num < 0) break;

		int result = testa_palindromo(num);

		if(result) 
			printf("VERDADEIRO\n");
		else
			printf("FALSO\n");		
	}



	return 0;
}

int testa_palindromo(int num) {
	int original = num;
	int reverso = 0;

	while(num > 0){
		int ultimo_digito = num%10;
		reverso = (reverso * 10) + ultimo_digito;
		num/=10;
	}

	return original == reverso;
}