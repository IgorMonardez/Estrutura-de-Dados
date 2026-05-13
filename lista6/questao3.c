#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	char nome[31];
	char mat[10], turma[3];
	float p1, p2;
} TALUNO;

float media_geral(TALUNO **mat, int n, char * turma);
int f_cmp(char *s1, char *s2);

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

		while(1) {

			char turma[3];

			printf("Digite a turma que deseja ver a média: ");
			scanf(" %3[^\n]", turma);

			if(!turma) break;

			float media_turma = media_geral(alunos, n, turma);

			printf("A turma %s tem média %.2f", turma, media_turma);
	
		}

	}


	
	return 0;
}

int f_cmp(char *s1, char *s2) {
	if((s1[0] == '\0') && (s2[0] == '\0'))
		return 0;
	if((s1[0] == '\0') || (s1[0] < s2[0]))
		return -1;
	if((s2[0] == '\0') || (s1[0] > s2[0]))
		return 1;
	
	return f_cmp(&s1[1], &s2[1]);
}

float media_geral(TALUNO **mat, int n, char * turma) {
	float media = 0.0;
	int quantidade_turma = 0;
	for(int i = 0; i<n;i++) {
		if(!f_cmp(mat[i]->turma, turma)) {
			media = (mat[i]->p1 + mat[i]->p2)/2;	
			quantidade_turma++;
		}
	}

	return media/quantidade_turma;
}