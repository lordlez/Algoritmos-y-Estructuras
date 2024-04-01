#include "ej_2_7_mejorado.h"

int main(){

    char numero1[] = {"11111111111111111111111111111199"};
    char numero2[] = {"111111111111111111111111111999"};
    char vecResultado[] = {};
    int cer = 0;
    char num;
    tPila pila1, pila2, pilaResultado;
    int longitud1 = strlen(numero1);
    int longitud2 = strlen(numero2);
    int longitud3;

    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pilaResultado);

    cargar_pila(&pila1, numero1, longitud1);
    cargar_pila(&pila2, numero2, longitud2);

    // if(ver_tope(&pila1, &num, sizeof(char))){
    //     printf("Tope pila1: %c\n", num);
    // }

    // if(ver_tope(&pila2, &num, sizeof(char))){
    //     printf("Tope pila2: %c\n", num);
    // }

    sumar_pilas(&pila1, &pila2, &pilaResultado);
    cargar_pila_a_vector(&pilaResultado, vecResultado, &cer);
    mostrar_vector(vecResultado, cer);


    return 0;
}