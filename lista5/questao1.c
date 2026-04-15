#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int verifica_sudoku(int mat[][9], int nl, int nc);

int verifica_linha(int mat[][9], int linha, int nc);

int verifica_coluna(int mat[][9], int coluna, int nl);

int verifica_bloco(int mat[][9], int quadrante);

int main(void) {

	int mat[9][9];

	for(int i = 0; i<9; i++)
		for(int j = 0; j<9; j++)
			scanf(" %d", &mat[i][j]);

	int result = verifica_sudoku(mat, 9, 9);

	for(int i = 0; i<9; i++) {
		for(int j = 0; j<9; j++)
			printf(" %d", mat[i][j]);
		printf("\n");
	}

	if(result) 
		printf("É válido no sudoku.\n");
	else
		printf("Não é valido no sudoku.\n");

	return 0;
}


int verifica_sudoku(int mat[][9], int nl, int nc) {
	
	for(int i = 0; i<nl;i++) 
		if(!verifica_linha(mat, i, nc)) return 0;
	
	for(int i = 0; i<nc; i++) 
		if(!verifica_coluna(mat, i, nl)) return 0;

	for(int i = 0; i<9;i++)
		if(!verifica_bloco(mat, i)) return 0;

	return 1;
}

int verifica_linha(int mat[][9], int linha, int nc) {
	

	int presente[10] = {0};
	for(int i = 0; i<nc; i++) {
		int valor = mat[linha][i];
		if(presente[valor]) return 0;
		presente[valor] = 1;
	}

	return 1;
}

int verifica_coluna(int mat[][9], int coluna, int nl) {
	
	int presente[10] = {0};
	for(int i = 0; i<nl; i++) {
		int valor = mat[i][coluna];
		if(presente[valor]) return 0;
		presente[valor] = 1;
	}
	return 1;
}


int verifica_bloco(int mat[][9], int quadrante) {

	int inicio_linha = (quadrante/3)*3;
	int fim_linha = (quadrante%3)*3;
	int presente[10] = {0};


	for(int i = 0;i<3; i++) {
		for(int j =0;j<3;j++) {
			int valor = mat[i + inicio_linha][j + fim_linha];
			if(presente[valor]) return 0;
			presente[valor] = 1;
		}
	}
	return 1;


}