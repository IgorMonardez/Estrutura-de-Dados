#include<stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	while(1) {
		scanf("%d", &n);

		if(!n) break;

		int i, maior_suspeito = 0, seg_maior_suspeito = 0;
		int terc_maior_suspeito = 100001;
		int i_maior, i_seg_maior;
		for(i = 0; i<n; i++) {
			int aux;
			scanf("%d", &aux);
			if(aux > maior_suspeito) {
				int temp = maior_suspeito;
				int temp2 = seg_maior_suspeito;
				maior_suspeito = aux;
				seg_maior_suspeito = temp;
				terc_maior_suspeito = temp2;
				int temp_i = i_maior;
				i_maior = i + 1;
				i_seg_maior = temp_i;
			} else if(aux > seg_maior_suspeito) {
				int temp = seg_maior_suspeito;
				seg_maior_suspeito = aux;
				terc_maior_suspeito = temp;
				i_seg_maior = i + 1;

			} else if(aux > terc_maior_suspeito)
				terc_maior_suspeito = aux;
		
		}
		
		printf("%d\n",i_seg_maior);

	}


	return 0;
}