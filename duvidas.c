#include<stdio.h>

int main(int argc, char const *argv[])
{
	char c = -128;

	while(c < 127)
		printf("%d,  %c\n", ++c, c);


	return 0;
}