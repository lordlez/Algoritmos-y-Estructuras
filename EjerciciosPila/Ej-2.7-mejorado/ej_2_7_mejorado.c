#include "ej_2_7_mejorado.h"
#include "../Ej-2.1/pila.c"

void cargar_pila(tPila *pp, char *vec, int longitud){
    int i = 0;
    char numero;
    numero = *vec;
    while(!pila_llena(pp, 0) && i < longitud){
        apilar(pp, &numero, sizeof(char));
        printf("Apilo el: %c\n", numero);
        vec++;
        i++;
        numero = *vec;
    }
}

void sumar_pilas(tPila *pp1, tPila *pp2, tPila *ppr){
    int carry = 0, suma, res;
    char numero1, numero2, suma_caracter;
    while(!pila_vacia(pp1) && !pila_vacia(pp2)){
        desapilar(pp1, &numero1, sizeof(char));
        desapilar(pp2, &numero2, sizeof(char));
        suma = (numero1 - '0') + (numero2 - '0') + carry;//paso los numeros caracter a entero
        res = suma / 10;
        if(res >= 1){
            carry = 1;
            suma %= 10;
        }else{
            carry = 0;
        }
        suma_caracter = suma + '0';//paso el valor entero a caracter
        if(!pila_llena(ppr, 0)){
            apilar(ppr, &suma_caracter, sizeof(char));
        }
    }
    while(!pila_vacia(pp1)){
        desapilar(pp1, &numero1, sizeof(char));
        if(!pila_llena(ppr, 0)){
            apilar(ppr, &numero1, sizeof(char));
        }
    }
    while(!pila_vacia(pp2)){
        desapilar(pp2, &numero2, sizeof(char));
        if(!pila_llena(ppr, 0)){
            apilar(ppr, &numero2, sizeof(char));
        }
    }
}


void cargar_pila_a_vector(tPila *ppr, char *vecr, int *cer){
    char numero;
    while(!pila_vacia(ppr)){
        desapilar(ppr, &numero, sizeof(char));
        *vecr = numero;
        vecr++;
        (*cer)++;
    }
}


void mostrar_vector(char *vecr, int cer){
    int i = 0;
    printf("La suma es: ");
    for(i=0; i<cer; i++){
        printf("%c", *vecr);
        vecr++;
    }
}
