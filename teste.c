#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioteca.h"

int main(){
int op=0;
Animal pet;
Fila *Normal = CriaFila();
Fila *Emergencia = CriaFila();
Fila *Removidos = CriaFila();

do {

    printf("\nop: ");
    scanf("%d", &op);

    if (op == -1) {
        Teste(Emergencia,Normal,Removidos);
        printf("\nNormal: ");
        imprimeFila(Normal);
        printf("--------------------------------------");

        printf("\nEmergencia: ");
        imprimeFila(Emergencia);
        printf("--------------------------------------");

        printf("\nRemovidos: ");
        imprimeFila(Removidos);
    }


    if (op ==1) {
        InsereFila(Emergencia, Normal);

    printf("\nNormal: ");
    imprimeFila(Normal);
    printf("--------------------------------------");

    printf("\Emergencia: ");
    imprimeFila(Emergencia);
    }




    }while(op!=-2);
}

