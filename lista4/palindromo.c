#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int palindromo(char *str1);

int main(void) {

	char str1[50];

	scanf("%49[^\n]", str1);

	int result = palindromo(str1);

	if(result)
		printf("%s é palindromo.\n", str1);
	else
		printf("%s não é palindromo.\n", str1);


	return 0;
}

int palindromo(char *str1) {
	
	long int len = strlen(str1);
	int i = 0, j = len - 1;
	while(1) {
		
		while(str1[i] == ' ') i++;
		while(str1[j] == ' ') j--;

		if(j<=i) break;

		if(str1[i] != str1[j]) return 0;

		i++;
		j--;
	}
	return 1;
}
