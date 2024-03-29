#include "pila.h"

void crear_pila(tPila *pp){
    pp->tope = TAM;
}

void vaciar_pila(tPila *pp){
    pp->tope = TAM;
}

int apilar(tPila *pp, const void *pd, unsigned tam){
    if(pp->tope < sizeof(unsigned) + tam){
        return 0; //PILA LLENA
    }
    pp->tope -= tam;
    memcpy(pp->pila + pp->tope, pd, tam);
    pp->tope -= sizeof(unsigned);
    memcpy(pp->tope + pp->pila, &tam, sizeof(unsigned));
    return 1; //TODO OK
}

int desapilar(tPila *pp, void *pd, unsigned tam){
    unsigned tamDatoPila;
    if(pp->tope == TAM){
        return 0; //PILA VACIA
    }
    memcpy(&tamDatoPila, pp->tope + pp->pila, sizeof(unsigned));
    pp->tope += sizeof(unsigned);
    memcpy(pd, pp->tope + pp->pila, MIN(tam, tamDatoPila));
    pp->tope += tamDatoPila;
    return 1; //TODO OK
}

int ver_tope(const tPila *pp, void *pd, unsigned tam){
    unsigned tamDatoPila;
    if(pp->tope == TAM){
        return 0; //PILA VACIA
    }
    memcpy(&tamDatoPila, pp->tope + pp->pila, sizeof(unsigned));
    memcpy(pd, pp->tope + pp->pila + sizeof(unsigned), MIN(tam, tamDatoPila));
    return 1; //TODO OK
}

int pila_llena(const tPila *pp, unsigned tam){
    if(pp->tope < sizeof(unsigned) + tam){
        return 1; //PILA LLENA
    }
    return 0; //PILA NO LLENA
}

int pila_vacia(const tPila *pp){
    if(pp->tope == TAM){
        return 1; //PILA VACIA
    }
    return 0; //PILA NO VACIA
}