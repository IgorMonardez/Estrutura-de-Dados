//
// Created by Igor on 25/03/2026.
//
#include<stdio.h>
#include<stdlib.h>

int verifica_primo(int i) {
    if(i%2 == 0 && i != 2) return 0;

    for(int j = 3; j<i; j++) {
        if(i%j == 0) return 0;
    }

    printf("%d\t", i);
    return 1;
}


int main(int argc, char* argv) {

    int n;
    while (1) {
        printf("Digite um número, se quiser terminar esse número é <=0: ");
        scanf("%d", &n);

        if (n <= 0) break;

        printf("Segue abaixo os n números primos >=n:\n");
        int quantidade_primos;
        int i = n + 1;
        for(quantidade_primos = 0; quantidade_primos < n; i++) {
            if(verifica_primo(i)) quantidade_primos++;
        }

        printf("\n");
    }

    return 0;
}
