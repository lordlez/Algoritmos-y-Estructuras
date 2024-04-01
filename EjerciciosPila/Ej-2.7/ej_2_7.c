#include "ej_2_7.h"
#include "../Ej-2.1/pila.c"

void cargar_pila(tPila *pp, int *vec, int longitud){
    int numero, i = 0;
    numero = *vec;
    while(!pila_llena(pp, 0) && i < longitud){
        apilar(pp, &numero, sizeof(int));
        vec++;
        i++;
        numero = *vec;
    }
}

void sumar_pilas(tPila *pp1, tPila *pp2, tPila *ppr){
    int carry = 0;
    int numero1, numero2, suma, res;
    while(!pila_vacia(pp1) && !pila_vacia(pp2)){
        desapilar(pp1, &numero1, sizeof(int));
        desapilar(pp2, &numero2, sizeof(int));
        suma = numero1 + numero2 + carry;
        res = suma / 10;
        if(res >= 1){
            carry = 1;
            suma %= 10;
        }else{
            carry = 0;
        }
        if(!pila_llena(ppr, 0)){
            apilar(ppr, &suma, sizeof(int));
        }
    }
    while(!pila_vacia(pp1)){
        desapilar(pp1, &numero1, sizeof(int));
        if(!pila_llena(ppr, 0)){
            apilar(ppr, &numero1, sizeof(int));
        }
    }
    while(!pila_vacia(pp2)){
        desapilar(pp2, &numero2, sizeof(int));
        if(!pila_llena(ppr, 0)){
            apilar(ppr, &numero2, sizeof(int));
        }
    }
}


void cargar_pila_a_vector(tPila *ppr, int *vecr, int *cer){
    int numero;
    while(!pila_vacia(ppr)){
        desapilar(ppr, &numero, sizeof(int));
        *vecr = numero;
        vecr++;
        (*cer)++;
    }
}


void mostrar_vector(int *vecr, int cer){
    int i = 0;
    printf("La suma es: ");
    for(i=0; i<cer; i++){
        printf("%d", *vecr);
        vecr++;
    }
}
