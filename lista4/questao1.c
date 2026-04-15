#include<stdio.h>
#include<string.h>

void shift_troca_string(char *str);

int main(void) {

	char palavra[15];

	scanf("%s", palavra);

	shift_troca_string(palavra);

	printf("palavra = %s\n", palavra);

	return 0;
}

void shift_troca_string(char *str) {
	long int len = strlen(str);
	int i = 0;

	for(i = 0; i < len; i++) {
		
		if((str[i] < 65) || (str[i]>90 && str[i]<97) || str[i] > 122) 
			str[i] = '!';
		else if(str[i] > 65 && str[i] <= 90) 
			str[i] = str[i] - 1 + 32;
		else if(str[i] > 97 && str[i] <= 122)
			str[i] = str[i] - 1 - 32;
		else if(str[i] == 65) 
			str[i] = 122;
		else 
			str[i] = 90;

	}

}
