#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *codifica(char *str);

int main(void) {

	char str[50];

	scanf(" %s", str);

	char *aux = codifica(str);

	printf("Palavra original: %s\n", str);

	printf("Palavra codificada: %s\n", aux);

	return 0;
}

char * codifica(char *str) {
	char *aux = malloc(sizeof(char) * 50);

	long int len = strlen(str);

	for(int i = 0; i< len;i++) 
		if(str[i] >=97 && str[i] <=122)
			aux[i] = '?';
		else
			aux[i] = str[i];

	return aux;
}


