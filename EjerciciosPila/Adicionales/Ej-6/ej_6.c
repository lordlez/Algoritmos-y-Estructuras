#include "ej_6.h"
#include "../../Ej-2.2/pila.c"


void cargar_pila(tPila *pp){
    int i = 0, numero;
    while(!pila_llena(pp, sizeof(int)) && i<5){
        printf("Ingrese un numero para apilar en la pila: ");
        scanf("%d", &numero);
        apilar(pp, &numero, sizeof(int));
        i++;
    }
}

void primero_al_ultimo_de_pila(tPila *pp, int *vec){
    int numero, aux, i = 0;
    int *pri = vec;
    while(!pila_vacia(pp) && i<1){
        desapilar(pp, &numero, sizeof(int));
        aux = numero;
        printf("En aux quedo: %d\n", numero);
        i++;
    }
    while(!pila_vacia(pp)){
        desapilar(pp, &numero, sizeof(int));
        *vec = numero;
        vec++;
        printf("Al vector puse: %d\n", numero);
    }
    vec--;
    if(!pila_llena(pp, sizeof(int))){
        apilar(pp, &aux, sizeof(int));
        printf("A la pila puse: %d\n", aux);
    }
    while(vec >= pri){
        if(!pila_llena(pp, sizeof(int))){
            numero = *vec;
            apilar(pp, &numero, sizeof(int));
            vec--;
            printf("A la pila puse: %d\n", numero);
        }
    }
}