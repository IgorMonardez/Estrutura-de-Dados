#include <stdio.h>
#include <stdlib.h>

int **mult(int **mat1, int m1, int n1, int **mat2, int m2, int n2);

int main(int argc, char const *argv[])
{	

	int m1, n1, m2, n2;
	int i,j;
	scanf("%d %d", &m1, &n1);

	int **mat1 = (int**) malloc(sizeof(int*) * m1);

	for(i = 0; i<m1;i++)
		mat1[i] = (int*) malloc(sizeof(int) * n1);

	for(i = 0; i<m1; i++)
		for(int j = 0; j<n1; j++)
			scanf(" %d", &mat1[i][j]);

	scanf("%d %d", &m2, &n2);

	int **mat2 = (int**) malloc(sizeof(int*) * m2);

	for(i = 0; i<m2;i++)
		mat2[i] = (int*) malloc(sizeof(int) * n2);

	for(i = 0; i<m2; i++)
		for(int j = 0; j<n2; j++)
			scanf(" %d", &mat2[i][j]);

	int **result = mult(mat1, m1, n1, mat2, m2,n2);

	for(i = 0; i<m1; i++) {
		for(j = 0; j<n2;j++)
			printf(" %d", result[i][j]);
		printf("\n");
	}

	return 0;	
}

int **mult(int **mat1, int m1, int n1, int **mat2, int m2, int n2) {

	int **result = (int**)malloc(sizeof(int*) * m1);
	int i,j, k;
	for(i = 0; i< m1;i++) 
		result[i] = (int*)malloc(sizeof(int) * n2);
	
	if(n1 != m2) return 0;

	for(i = 0; i<m1; i++) {
		for(j = 0; j<n2; j++) {

			result[i][j] = 0;
			for(k = 0; k<n1; k++)
				result[i][j] += mat1[i][k] * mat2[k][j];
		}
	}

	return result;

}