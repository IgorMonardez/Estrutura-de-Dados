#include<stdio.h>
#include<string.h>

char * maior_sub(char *str1, char *str2);

int main(void) {

	char str1[50];

	char str2[50];

	scanf("%s", str1);

	scanf(" %s", str2);

	char *result = maior_sub(str1, str2);

	if(result)
		printf("Possuem substring.\n");
	else
		printf("Não possuem substring.\n");


	return 0;
}

char * maior_sub(char *str1, char *str2) {


	long int len1 = strlen(str1);
	long int len2 = strlen(str2);

	char * maior_string = malloc(sizeof(char) * len1);
	char * substring;
	int len_maior_string = sizeof(maior_string);

	for(int i = 0; i<len1; i++){
		substring = str1;
		substring[i + 1] = '\0';

		if(strstr(substring, str2)) {
			int len_substring = strlen(substring);
			maior_string = (len_substring > len_maior_string) ? substring : maior_string;
		}
	}


	return maior_string;
}
