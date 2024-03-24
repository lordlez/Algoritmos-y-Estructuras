#include "colaDinamica.h"

void crear_cola(tCola *pc){
    pc->pri = NULL;
    pc->ult = NULL;
}

void vaciar_cola(tCola *pc){
    tNodo *elim;
    while(pc->pri != NULL){
        elim = pc->pri;
        pc->pri = elim->sig;
        free(elim->info);
        free(elim);
    }
    pc->ult = NULL;
}

int poner_en_cola(tCola *pc, const void *pd, unsigned tam){
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
    nuevo->sig = NULL;
    if(pc->pri == NULL){
        pc->pri = nuevo;
    }else{
        pc->ult->sig = nuevo;
    }
    pc->ult = nuevo;

    return 1;
}

int sacar_de_cola(tCola *pc, void *pd, unsigned tam){
    tNodo *elim;
    if(pc->pri == NULL){
        return 0;
    }
    elim = pc->pri;
    pc->pri = elim->sig;
    memcpy(pd, elim->info, MIN(tam, elim->tamInfo));
    free(elim->info);
    free(elim);
    if(pc->pri == NULL){
        pc->ult = NULL;
    }

    return 1;
}

int ver_primero(const tCola *pc, void *pd, unsigned tam){
    if(pc->pri == NULL){
        return 0;
    }
    memcpy(pd, pc->pri->info, MIN(tam, pc->pri->tamInfo));

    return 1;
}

int cola_llena(const tCola *pc, unsigned tam){
    return 0;
}

int cola_vacia(const tCola *pc){
    if(pc->pri == NULL){
        return 1;
    }
    return 0;
}

