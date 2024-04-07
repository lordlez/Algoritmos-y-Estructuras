#include "ej_2_7.h"

int main(){

    int numero1[] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,4,5};
    int numero2[] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,4,5,3,4,5,6,3,4,5,6,7,8,6,3};
    int vecResultado[] = {};
    int cer = 0;
    int num;
    tPila pila1, pila2, pilaResultado;
    int longitud1 = sizeof(numero1)/sizeof(int);
    int longitud2 = sizeof(numero2)/sizeof(int);
    int longitud3;

    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pilaResultado);

    cargar_pila(&pila1, numero1, longitud1);
    cargar_pila(&pila2, numero2, longitud2);

    // if(ver_tope(&pila1, &num, sizeof(int))){
    //     printf("Tope pila1: %d", num);
    // }

    // if(ver_tope(&pila2, &num, sizeof(int))){
    //     printf("Tope pila2: %d", num);
    // }

    sumar_pilas(&pila1, &pila2, &pilaResultado);
    cargar_pila_a_vector(&pilaResultado, vecResultado, &cer);
    mostrar_vector(vecResultado, cer);

    return 0;
}