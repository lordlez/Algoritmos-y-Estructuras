#include "ej-2_7.h"
#include "../Ej-2.2/pilaDinamica.c"


void cargar_en_pila(tPila *pp, char *vec, int longitud){
    int i = 0;
    char numero;
    numero = *vec;
    while(!pila_llena(pp, sizeof(char)) &&  i<longitud){
        apilar(pp, &numero, sizeof(char)); //apilo caracter por caracter en la pila
        printf("Apilo el: %c\n", numero);
        i++;
        vec++;
        numero = *vec; 
    }
}

void sumar_pilas(tPila *p1, tPila *p2, tPila *pr){
    char numero1, numero2;
    int suma;
    int carry = 0;
    int res;
    char sumaCaracter;
    while(!pila_vacia(p1) && !pila_vacia(p2)){
        desapilar(p1, &numero1, sizeof(char));//saco caracter de la pila
        desapilar(p2, &numero2, sizeof(char));
        suma = (numero1 - '0') + (numero2 - '0') + carry;//paso mis dos caracteres a enteros y los sumo
        res = suma/10;
        if(res >= 1){
            carry = 1;
            suma %= 10;
        }else{
            carry = 0;
        }
        sumaCaracter = suma + '0'; //vuelvo a convertir a char mi resto de suma
        if(!pila_llena(pr, sizeof(char))){
            apilar(pr, &sumaCaracter, sizeof(char));
        }
    }
    while(!pila_vacia(p1)){//si alguna pila quedo con datos, lo apilo en pr
        desapilar(p1, &numero1, sizeof(char));
        if(!pila_llena(pr, sizeof(char))){
            apilar(pr, &numero1, sizeof(char));
        }
    }
        while(!pila_vacia(p2)){
        desapilar(p2, &numero2, sizeof(char));
        if(!pila_llena(pr, sizeof(char))){
            apilar(pr, &numero2, sizeof(char));
        }
    }
}

void cargar_pila_a_vector(tPila *pp, char *vec, int *cer){
    char numero;
    while(!pila_vacia(pp)){
        desapilar(pp, &numero, sizeof(char));
        *vec = numero;
        vec++;
        (*cer)++;
    }
}

void mostrar_vector(char *vec, int cer){
    int i;
    printf("La suma: ");
    for(i = 0; i<cer; i++){
        printf("%c", *vec);
        vec++;
    }
}