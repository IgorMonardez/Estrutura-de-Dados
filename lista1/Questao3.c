//
// Created by Igor on 25/03/2026.
//
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv) {
    int h1, m1, h2, m2;

    while(1) {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

        if(!h1 && !m1 && !h2 && !m2) break;

        int minutosCorrente;
        minutosCorrente = (h1*60) + m1;

        int minutosAlarme;
        minutosAlarme = (h2*60) + m2;

        if(minutosAlarme <= minutosCorrente)
            minutosAlarme = minutosAlarme + (24*60);

        int	minutosDescanso;
        minutosDescanso = minutosAlarme - minutosCorrente;

        printf("%d\n", minutosDescanso);
    }


    return 0;
}