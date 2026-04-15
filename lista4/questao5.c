#include<stdio.h>
#include<string.h>

int cic(char *str1, char *str2);

int main(void) {

	char str1[50];

	char str2[50];

	scanf("%s", str1);

	scanf(" %s", str2);

	int result = cic(str1, str2);

	if(result)
		printf("Possuem substring.\n");
	else
		printf("Não possuem substring.\n");


	return 0;
}

int cic(char *str1, char *str2) {

	long int len1 = strlen(str1);
	long int len2 = strlen(str2);

	for(int i = 0; i<len1; i++) {
		for(int j = 0; j<len2; j++) {
			if(str1[i] == str2[j]) return 1;
			if((str1[i] == 'a' && str2[j] == 'A') || (str1[i] == 'A' && str2[j] == 'a')) return 1;
			if(((str1[i]-32) ==  str2[j]) || ((str2[j] - 32) == str1[j]) || ((str1[i] + 32) == str2[j]) || ((str2[j] + 32) == str1[i])) return 1;
		}
	}

	return 0;
}
