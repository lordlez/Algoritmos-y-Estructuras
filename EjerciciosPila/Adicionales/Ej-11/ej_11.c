#include "ej_11.h"
#include "../../Ej-2.2/pila.c"


void cargar_pila(tPila *pp){
    int num, limite = 0;
    while(!pila_llena(pp, sizeof(int)) && limite < 5){
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        apilar(pp, &num, sizeof(int));
        limite++;
    }
}


void eliminar_iguales(tPila *pp1, tPila *modelo, tPila *aux){
    int num, num2;
    while(!pila_vacia(pp1) && !pila_vacia(modelo)){
        ver_tope(pp1, &num, sizeof(int));
        ver_tope(modelo, &num2, sizeof(int));
        if(num != num2){
            desapilar(pp1, &num, sizeof(int));
            apilar(aux, &num, sizeof(int));
        }else{
            desapilar(pp1, &num, sizeof(int));
        }        
    }

    while(!pila_vacia(aux)){
        desapilar(aux, &num, sizeof(int));
        if(!pila_llena(pp1, sizeof(int))){
            apilar(pp1, &num, sizeof(int));
        }
    }
}





