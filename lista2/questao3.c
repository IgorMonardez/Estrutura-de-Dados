#include<stdio.h>

int bin_num(int n);

int main(int argc, char const *argv[])
{
	int num;
	while(1) {
		scanf("%d", &num);
		
		if(num < 0) break;

		if(num == 0) 
			printf("0");
		else
			bin_num(num);

		printf("\n");
	}

	return 0;
}

int bin_num(int n) {
	if(n>1) {
		bin_num(n/2);
	}
	
	printf("%d", n%2);
}
