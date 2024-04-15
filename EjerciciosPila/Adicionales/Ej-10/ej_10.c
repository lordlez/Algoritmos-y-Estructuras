#include "ej_10.h"
#include "../../Ej-2.2/pila.c"

void cargar_pila(tPila *pp, tElemento *el){
    int numero, basta = 1;
    el->pos = 0;
    while(!pila_llena(pp, sizeof(tElemento)) && basta != 0){
        printf("Ingrese un numero(0 para terminar): ");
        scanf("%d", &el->numero);
        if(el->numero == 0){
            basta = 0;
        }else{
            el->pos++;
            apilar(pp, &el, sizeof(tElemento));
        }
        printf("Se apilo el numero: %d\n", el->numero);
    }
}

void comparar_dos_pilas(tPila *pilaA, tPila *pilaB){
    tElemento elA, elB;
    int num = 1, posi = 1, cant = 1, igual = 1;
    while(!pila_vacia(pilaA) && !pila_vacia(pilaB)){
        desapilar(pilaA, &elA.numero, sizeof(tElemento));
        desapilar(pilaB, &elB.numero, sizeof(tElemento));
        printf("Numero A: %d\n", elA.numero);
        printf("Numero B: %d\n", elB.numero);
        if(elA.numero == elB.numero){
            if(elA.pos == elB.pos){
                printf("Pos A: %d\n", elA.pos);
                printf("Pos B: %d\n", elB.pos);
                igual = 1;
            }else{
                posi = 0;
            }
        }else{
            num = 0;
        }
    }
    if(!pila_vacia(pilaA)){
        igual = 0;
    }
    if(!pila_vacia(pilaB)){
        igual = 0;
    }
    if(igual == 1){
        if(posi == 1){
            if(num == 1){
                printf("Las pilas son exactamente iguales en tamanio, valores y posicion\n");
            }else{
                printf("Las pilas no son iguales en valores\n");
            }
        }else{
            printf("Las pilas no son iguales en posicion\n");
        }
    }else{
        printf("Las pilas no son iguales en tamanio\n");
    }
}