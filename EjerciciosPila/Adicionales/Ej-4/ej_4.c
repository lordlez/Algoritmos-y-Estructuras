#include "ej_4.h"
#include "../../Ej-2.2/pila.c"


void cargar_pila(tPila *pp){
    int numero, i;
    for(i=0;i<5;i++){
        if(!pila_llena(pp, 0)){
            printf("Ingrese un numero: ");
            scanf("%d", &numero);
            apilar(pp, &numero, sizeof(int));
        }
    }
}

void de_origen_a_destino(tPila *origen, tPila *destino){
    int numero;
    while(!pila_vacia(origen)){
        desapilar(origen, &numero, sizeof(int));//si pongo estto dentro del if, puedo crear un bucle infinito
        if(!pila_llena(destino, 0)){
            apilar(destino, &numero, sizeof(int));
        }
    }
}
