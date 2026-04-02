#include<stdio.h>
#include<math.h>

int bin_num(int n);

int main(int argc, char const *argv[])
{
	int num;
	while(1) {
		scanf("%d", &num);
		
		if(num <= 0) break;

		bin_num(num);
	}

	return 0;
}

int bin_num(int n) {
	int i = 0;
	int vet[sizeof(n) * 8];
	while(n > 0) {
		vet[i] = n%2; 
		n /= 2;		
		i++;
	}
	
	for(int j = i - 1; j>=0; j--) {
		printf("%d",vet[j]);
	}
	printf("\n");
}