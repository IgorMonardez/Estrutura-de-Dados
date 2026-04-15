#include<stdio.h>
#include<string.h>

void retira_inicio_n(char *str, int n);

int main(void) {

	char palavra[50];
	int n;

	scanf("%s", palavra);

	scanf(" %d", &n);

	retira_inicio_n(palavra, n);


	return 0;
}

void retira_inicio_n(char *str, int n) {
	long int len = strlen(str);

	if(len < n) {
		printf("erro\n");
		return;
	}

	for(int i = 0; i<=len;i++) {
		str[i] = str[i + n];
	}

	printf("Palavra sem os %d caracteres de inicio %s\n", n, palavra);

}
