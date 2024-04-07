#include "ej_9.h"
#include "../../Ej-2.2/pila.c"


void cargar_pila(tPila *pp){
    int numero, basta = 1;
    while(!pila_llena(pp, sizeof(int)) && basta != 0){
        printf("Ingrese un numero (0 para finalizar): ");
        scanf("%d", &numero);
        if(numero == 0){
            basta = 0;
        }else{
            apilar(pp, &numero, sizeof(int));
        }
    }
}

void comparar_pilas(tPila *pilaA, tPila *pilaB){
    int numero, contadorA = 0, contadorB = 0, res;
    while(!pila_vacia(pilaA)){
        desapilar(pilaA, &numero, sizeof(int));
        contadorA++;
    }
    while(!pila_vacia(pilaB)){
        desapilar(pilaB, &numero, sizeof(int));
        contadorB++;
    }
    if(contadorA > contadorB){
        res = contadorA - contadorB;
        printf("La pila A tiene mas elementos que B, exactamente %d elementos mas\n", res);
    }else{
        if(contadorA < contadorB){
            res = contadorB - contadorA;
            printf("La pila B tiene mas elementos que A, exactamente %d elementos mas\n", res);
        }else{
            printf("La pila A tiene igual de elementos que B\n");
        }
    }
}