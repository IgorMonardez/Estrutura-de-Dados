#include<stdio.h>
#include<string.h>

void retira_fim_n(char *str, int n);

int main(void) {

	char palavra[50];
	int n;

	scanf("%s", palavra);

	scanf(" %d", &n);

	retira_fim_n(palavra, n);

	return 0;
}

void retira_fim_n(char *str, int n) {
	long int len = strlen(str);

	if(len < n) {
		printf("erro\n");
		return;
	}

	str[len-n] = '\0';

	printf("Palavra sem os %d caracteres de fim %s\n", n, str);
}
