#include "ej_5.h"

int main(){

    tPila pila1;
    int numero;
    int vec[100];
    int ce = 0;

    cargar_pila(&pila1);

    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope sin invertir: %d\n", numero);
    }

    cargar_pila_a_vector(&pila1, vec, &ce);

    // de_vector_a_pila(vec, ce, &pila1);
    
    // if(ver_tope(&pila1, &numero, sizeof(int))){
    //     printf("Tope invertido: %d\n", numero);
    // }

    return 0;
}


