#include "header.h"

int main(){
    
    tPila pila1, pila2, pilaResultado;
    int num1[] = {1,8,3,5};
    int num2[] = {2,8,4};
    int resultado[50];
    int res;
    int ce1 = 4, ce2 = 3, ceResultado = 0, diferencia;

    cargar_pila(&pila1, num1, ce1); //ok
    cargar_pila(&pila2, num2, ce2); //ok

    if(!pila_vacia(&pila1)){
        ver_tope(&pila1, &res, sizeof(int));
        printf("TOPE1: %d", res);
    }

    if(!pila_vacia(&pila2)){
        ver_tope(&pila2, &res, sizeof(int));
        printf("TOPE2: %d", res);
    }

 

    diferencia = ce1 - ce2;

    cargar_ceros(&pila1, &pila2, diferencia); // ok

    if(!pila_vacia(&pila1)){
        ver_tope(&pila1, &res, sizeof(int));
        printf("TOPE1: %d", res);
    }

    if(!pila_vacia(&pila2)){
        ver_tope(&pila2, &res, sizeof(int));
        printf("TOPE2: %d", res);
    }


    sumar_pilas(&pila1, &pila2, &pilaResultado); // ok

    if(!pila_vacia(&pilaResultado)){
        ver_tope(&pilaResultado, &res, sizeof(int));
        printf("TOPEres: %d", res);
    }


/*
    cargar_vector(&pilaResultado, resultado, &ceResultado); // ERROR

    printf("OK");


    mostrar_vector(resultado, ceResultado);
    

*/
    return 0;

}