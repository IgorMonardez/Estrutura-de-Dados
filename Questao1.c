#include<stdio.h>
#include<stdlib.h>

void verifica_primo(int i);

int main(int argc, char* argv) {

    int n;
    while(1) {
        printf("Digite um número, se quiser terminar esse número é <=0: ");
        scanf("%d", &n);

        if(n <= 0) break;

        printf("Segue abaixo os números primos <=n:\n");
        for (int i = 1; i<=n; i++) {
            verifica_primo(i);
        }
        printf("\n");
    }

    return 0;
}


void verifica_primo(int i) {
    if(i%2 == 0 && i != 2) return;

    for(int j = 3; j<i; j++) {
        if(i%j == 0) return;
    }

    printf("%d\t", i);

}