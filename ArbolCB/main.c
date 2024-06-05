#include "arbolCB.h"

int main()
{
    tArbol arbolito;
    int numeros[] = {1,5,10,4,7,3,9};
    int espacio = 3;

    crear_arbol(&arbolito);

    poner_arbol(&arbolito, &numeros[0], sizeof(int), cmp_enteros);
    poner_arbol(&arbolito, &numeros[1], sizeof(int), cmp_enteros);
    poner_arbol(&arbolito, &numeros[2], sizeof(int), cmp_enteros);
    poner_arbol(&arbolito, &numeros[3], sizeof(int), cmp_enteros);
    poner_arbol(&arbolito, &numeros[4], sizeof(int), cmp_enteros);
    poner_arbol(&arbolito, &numeros[5], sizeof(int), cmp_enteros);
    poner_arbol(&arbolito, &numeros[6], sizeof(int), cmp_enteros);


    printf("\nRecorrido PREORDEN\n");
    recorrer_preorden(&arbolito, imprimir_nodo, &espacio);

    printf("Recorrido ORDEN\n");
    recorrer_orden(&arbolito, imprimir_nodo, &espacio);

    printf("\nRecorrido POSORDEN\n");
    recorrer_posorden(&arbolito, imprimir_nodo, &espacio);




    return 0;
}
