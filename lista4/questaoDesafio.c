#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * maior_sub(char *str1, char *str2);

int main(void) {

	char str1[50];

	char str2[50];

	scanf("%s", str1);

	scanf(" %s", str2);

	char *result = maior_sub(str1, str2);

	if(result)
		printf("Possuem substring %s.\n", result);
	else
		printf("Não possuem substring.\n");


	return 0;
}

char * maior_sub(char *str1, char *str2) {


	long int len1 = strlen(str1);
	long int len2 = strlen(str2);

	int max_len = 0;
	int start_index = -1;

	for(int i = 0; i<len1; i++){
		for(int j = 0; j<len2; j++) {
			int k = 0;
			while( ((i+k) < len1) && ((j + k) < len2) && (str1[i + k] == str2[j + k])) {
				k++;
			}

			if(k > max_len) {
				max_len = k;
				start_index = i;
			}
		}
	}

	char *maior_string = (char*)malloc(sizeof(char) * (max_len + 1));

	if(maior_string == NULL) return NULL;

	if(max_len > 0) {
		strncpy(maior_string, &str1[start_index], max_len);
	}
	if(maior_string[max_len] != '\0') maior_string[max_len] = '\0';

	return maior_string;
}
