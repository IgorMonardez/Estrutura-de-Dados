#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	char nome[31];
	char mat[10], turma[3];
	float p1, p2;
} TALUNO;

void imprime(TALUNO **mat, int n);

int main(int argc, char const *argv[])
{
	int n;

	while(1) {
		printf("Quantos alunos na turma: ");
		scanf("%d", &n);
		if(!n) break;

		TALUNO ** alunos = malloc(sizeof(TALUNO*) * n);

		for(int i = 0; i < n; i++)
			alunos[i] = malloc(sizeof(TALUNO));
		
		for(int i = 0; i < n; i++) {
			printf("Aluno %d\n", i);
			printf("Nome: ");
			scanf(" %s", alunos[i]->nome);

			printf("Matrícula: ");
			scanf(" %s", alunos[i]->mat);
			printf("Turma: ");
			scanf(" %s", alunos[i]->turma);

			printf("Nota P1: ");
			scanf(" %f", &alunos[i]->p1);
			printf("Nota P2: ");
			scanf(" %f", &alunos[i]->p2);
		}
		imprime(alunos, n);

		for(int i = 0; i<n; i++) 
			free(alunos[i]);

		free(alunos);

	}


	
	return 0;
}

void imprime(TALUNO **mat, int n) {
	printf("Alunos na média\n");
	for(int i = 0; i<n;i++) {
		if(mat[i]->p1 + mat[i]->p2 > 12.0) {
			printf("Nome: %s\n", mat[i]->nome);
			printf("Turma: %s\n", mat[i]->turma);
			printf("Matrícula: %s\n", mat[i]->mat);
			printf("P1: %.2f\n", mat[i]->p1);
			printf("P2: %.2f\n", mat[i]->p2);

			printf("Média: %.2f\n", (mat[i]->p1 + mat[i]->p2) / 2);
		}
	}
}