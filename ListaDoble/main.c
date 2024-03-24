#include "listaDoble.h"

int main(){
    tListad listad;
    int numero, n = 0, numfinal = 9, m = 0, o = 0;

    printf("Creando lista...\n");
    crear_lista(&listad);
    printf("Lista creada\n");


    while(!lista_llena(&listad, sizeof(int)) && n < 3){
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        poner_inicio(&listad, &numero, sizeof(int));
        n++;
    }

    printf("Lista cargada\n");

    while(!lista_llena(&listad, sizeof(int)) && m < 1){
        poner_final(&listad, &numfinal, sizeof(int));
        m++;
    }

    printf("Se inserto num final\n");

    if(!lista_vacia(&listad)){
        primero_lista(&listad, &numero, sizeof(int));
        printf("Primero: %d", numero);
    }

    printf("\n");

    while(!lista_llena(&listad, sizeof(int)) && o < 2){
        printf("Ingrese num: ");
        scanf("%d", &numero);
        poner_orden(&listad, &numero, sizeof(int), cmp_enteros);
        o++;
    }

    if(!lista_vacia(&listad)){
        ultimo_lista(&listad, &numero, sizeof(int));
        printf("Ultimo: %d", numero);
    }

    printf("\n");

    printf("Vaciando lista...");
    if(!lista_vacia(&listad)){
        vaciar_lista(&listad);
    }

    printf("\nLista vacia");








    return 0;
}