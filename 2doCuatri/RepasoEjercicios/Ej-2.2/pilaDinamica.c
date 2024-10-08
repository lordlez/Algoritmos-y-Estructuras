#include "pilaDinamica.h"

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
    tNodo *nuevo;
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
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
    tNodo *nuevo = (tNodo*)malloc(sizeof(tNodo));
    void *elem = malloc(tam);

    free(nuevo);
    free(elem);

    return nuevo==NULL||elem==NULL;
}

int pila_vacia(const tPila *pp){
    if(*pp == NULL){
        return 1;
    }
    return 0;
}

