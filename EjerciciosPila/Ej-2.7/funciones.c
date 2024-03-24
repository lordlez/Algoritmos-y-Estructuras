#include "header.h"

void crear_pila(tPila *pp){
    *pp = NULL;
}

void vaciar_pila(tPila *pp){
    tNodo *elim;
    while(*pp){
        elim = *pp;
        *pp = elim->sig;
        free(elim->info);
        free(elim);
    }
}

int apilar(tPila *pp, const void *pd, unsigned tam){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);
    if(!nuevo || !elemNodo){
        free(nuevo);
        free(elemNodo);
        return 0;
    }

    nuevo->info = elemNodo;
    nuevo->tamInfo = tam;
    memcpy(elemNodo, pd, tam);
    nuevo->sig = *pp;
    *pp = nuevo;

    return 1;
}

int desapilar(tPila *pp, void *pd, unsigned tam){
    tNodo *elim;
    if(*pp == NULL){
        return 0;
    }
    elim = *pp;
    *pp = elim->sig;
    memcpy(pd, elim->info, MIN(tam, elim->tamInfo));
    free(elim->info);
    free(elim);

    return 1;
}

int ver_tope(const tPila *pp, void *pd, unsigned tam){
    if(*pp == NULL){
        return 0;
    }
    memcpy(pd, (*pp)->info, MIN(tam, (*pp)->tamInfo));
    return 1;
}

int pila_llena(const tPila *pp, unsigned tam){
    tNodo *vnodo = malloc(sizeof(tNodo));
    void *velem = malloc(tam);

    free(vnodo);
    free(velem);

    return vnodo == NULL || velem == NULL;
}

int pila_vacia(const tPila *pp){
    if(*pp == NULL){
        return 1;
    }
    return 0;
}

void cargar_pila(tPila *pila, int *num, int ce){
    int i;

    for(i=0; i<ce; i++){
        if(!pila_llena(pila, sizeof(int))){
            apilar(pila, num, sizeof(int));
            num++;
        }
    }
}


void cargar_ceros(tPila *pila1, tPila *pila2, int diferencia){
    int i, cero = 0;

    if(diferencia < 0){
        for(i=0; i<(diferencia*-1); i++){
            if(!pila_llena(pila1, sizeof(int))){
                apilar(pila1, &cero, sizeof(int));
            }
        }
    }else{
        for(i=0; i<diferencia; i++){
            if(!pila_llena(pila2, sizeof(int))){
                apilar(pila2, &cero, sizeof(int));
            }
        }
    }
}

void sumar_pilas(tPila *pila1, tPila *pila2, tPila *pilaResultado){
    int numero1, numero2, resultado, carry = 0;

    while(!pila_vacia(pila1)){
        desapilar(pila1, &numero1, sizeof(int));
        desapilar(pila2, &numero2, sizeof(int));
        resultado = numero1 + numero2 + carry;
        if(resultado > 9){
            carry = 1;
            resultado = resultado % 10;
        }else{
            carry = 0;
            resultado = resultado % 10;
        }
        apilar(pilaResultado, &resultado, sizeof(int));
    }
}

void cargar_vector(tPila *pilaResultado, int *resultado, int *ce){
    int valor;

    while(!pila_vacia(pilaResultado)){
        desapilar(pilaResultado, &valor, sizeof(int));
        *resultado = valor;
        resultado++;
        (*ce)++;
    }
}

void mostrar_vector(int *vector, int ce){
    int i;

    for(i=0; i<ce; i++){
        printf("%d", *vector);
        vector++;
    }
}









