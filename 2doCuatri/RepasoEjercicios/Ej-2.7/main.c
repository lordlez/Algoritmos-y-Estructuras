#include "ej-2_7.h"


int main(){

    char numero1[] = {"11111111111111111111"};
    char numero2[] = {"33333333333333333"};
    char resultado[] = {};
    int cer = 0;
    tPila p1, p2, pr;
    int longn1 = strlen(numero1);
    int longn2 = strlen(numero2);

    crear_pila(&p1);
    crear_pila(&p2);
    crear_pila(&pr);

    cargar_en_pila(&p1, numero1, longn1);
    cargar_en_pila(&p2, numero2, longn2);
    sumar_pilas(&p1, &p2, &pr);
    cargar_pila_a_vector(&pr, resultado, &cer);
    mostrar_vector(resultado, cer);


    return 0;
}