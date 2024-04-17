#include "ej_13.h"
#include "../../Ej-2.2/pila.c"

void cargar_pila(tPila *pp){
    int numero, basta = 0;
    while(!pila_llena(pp, sizeof(int)) && basta != 1){
        printf("Ingrese un numero (0 para terminar): ");
        scanf("%d", &numero);
        if(numero == 0){
            basta = 1;
        }else{
            apilar(pp, &numero, sizeof(int));
        }
    }
}


void comparar(tPila *pila1, tPila *limite, tPila *pilaMay, tPila *pilaMen){
    int numLimite, numPila1, numMay, numMen;
    if(!pila_vacia(limite)){
        ver_tope(limite, &numLimite, sizeof(int));
        while(!pila_vacia(pila1)){
            desapilar(pila1, &numPila1, sizeof(int));
            if(numPila1 >= numLimite){
                if(!pila_llena(pilaMay, sizeof(int))){
                    apilar(pilaMay, &numPila1, sizeof(int));
                }
            }else{
                if(!pila_llena(pilaMen, sizeof(int))){
                    apilar(pilaMen, &numPila1, sizeof(int));
                }
            }
        }
    }
}

