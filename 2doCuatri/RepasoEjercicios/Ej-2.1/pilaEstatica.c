#include "pilaEstatica.h"

void crear_pila(tPila *pp){
    pp->tope = TAM;
}

void vaciar_pila(tPila *pp){
    pp->tope = TAM;
}

int apilar(tPila *pp, const void *pd, unsigned tam){
    if(pp->tope < tam + sizeof(unsigned)){
        return 0;
    }
    pp->tope -= tam;
    memcpy(pp->tope + pp->pila, pd, tam);
    pp->tope -= sizeof(unsigned);
    memcpy(pp->tope + pp->pila, &tam, sizeof(unsigned));
    return 1;
}

int desapilar(tPila *pp, void *pd, unsigned tam){
    unsigned tamDatoPila;
    if(pp->tope == TAM){
        return 0;
    }
    memcpy(&tamDatoPila, pp->tope + pp->pila, sizeof(unsigned));
    pp->tope += sizeof(unsigned);
    memcpy(pd, pp->tope + pp->pila, MIN(tam, tamDatoPila));
    pp->tope += tamDatoPila;
    return 1;
}

int ver_tope(const tPila *pp, void *pd, unsigned tam){
    unsigned tamDatoPila;
    if(pp->tope == TAM){
        return 0;
    }
    memcpy(&tamDatoPila, pp->tope + pp->pila, sizeof(unsigned));
    memcpy(pd, pp->tope + pp->pila + sizeof(unsigned), MIN(tam, tamDatoPila));
    return 1;
}

int pila_llena(const tPila *pp, unsigned tam){
    if(pp->tope < (tam + sizeof(unsigned))){
        return 1;
    }
    return 0;
}

int pila_vacia(const tPila *pp){
    if(pp->tope == TAM){
        return 1;
    }
    return 0;
}