//
// Created by Igor on 25/03/2026.
//
#include<stdio.h>
#include<stdlib.h>

int verifica_divisibilidade(int f1, int f2);

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++) {
        int f1, f2;
        scanf("%d %d", &f1, &f2);

        int pilha = verifica_divisibilidade(f1,f2);

        printf("%d\n", pilha);
    }
    return 0;
}

int verifica_divisibilidade(int f1, int f2) {
    while (f2 != 0) {
        int resto = f1 % f2;
        f1 = f2;
        f2 = resto;
    }
    return f1;
}
