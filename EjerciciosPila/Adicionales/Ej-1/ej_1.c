#include "ej_1.h"
#include "../../Ej-2.1/pila.c"

void cargar_pila(tPila *pp){
    int i = 0, numero; 
    while(!pila_llena(pp, 0) && i < 5){
        printf("Ingrese un elemento entero: ");
        scanf("%d", &numero);
        apilar(pp, &numero, sizeof(int));
        i++;
    }
}

void de_pila_a_pilas(tPila *pp1, tPila *ppAux1, tPila *ppAux2){
    int numero, i = 0;
    while(!pila_vacia(pp1)){
        desapilar(pp1, &numero, sizeof(int));
        if(i < 3){
            if(!pila_llena(ppAux1, 0)){
                apilar(ppAux1, &numero, sizeof(int));
            }
            i++;
        }else{
            if(!pila_llena(ppAux2, 0)){
                apilar(ppAux2, &numero, sizeof(int));
            }
        }
    }
}