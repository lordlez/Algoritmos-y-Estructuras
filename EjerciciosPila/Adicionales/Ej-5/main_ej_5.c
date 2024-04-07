#include "ej_5.h"

int main(){

//Primero declaro las variables que voy a utilizar antes de declarar a la pila, de lo contrario
//me arroja segmentation foult

    int numero;
    int vec[] = {};
    int ce = 0;
    tPila pila1;

    crear_pila(&pila1);
    
    cargar_pila(&pila1);

    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope sin invertir: %d\n", numero);
    }

    cargar_pila_a_vector(&pila1, vec, &ce);

    de_vector_a_pila(vec, ce, &pila1);
    
    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope invertido: %d\n", numero);
    }

    return 0;
}


