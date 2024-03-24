#include "listaDoble.h"

void crear_lista(tListad *pld){
    *pld = NULL;
}

void vaciar_lista(tListad *pld){
    tNodo *act = *pld;
    if(act){
        while(act->ant){
            act = act->ant;
        }
        while(act){
            tNodo *aux = act->sig;
            free(act->info);
            free(act);
            act = aux;
        }
        *pld = NULL;
    }
}


int poner_inicio(tListad *pld, const void *pd, unsigned tam){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);
    tNodo *act = *pld;
    if(act){
        while(act->ant){
            act = act->ant;
        }
    }
    if(!nuevo || !elemNodo){
        free(nuevo);
        free(elemNodo);
        return 0;
    }
    nuevo->info = elemNodo;
    nuevo->tamInfo = tam;
    memcpy(elemNodo, pd, tam);
    nuevo->sig = act;
    nuevo->ant = NULL;
    if(act){
        act->ant = nuevo;
    }
    *pld = nuevo;
    return 1;
}

int poner_final(tListad *pld, const void *pd, unsigned tam){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);
    tNodo *act = *pld;
    if(act){
        while(act->sig){
            act = act->sig;
        }
    }
    if(!nuevo || !elemNodo){
        free(nuevo);
        free(elemNodo);
        return 0;
    }
    nuevo->info = elemNodo;
    nuevo->tamInfo = tam;
    memcpy(elemNodo, pd, tam);
    nuevo->sig = NULL;
    nuevo->ant = act;
    if(act){
        act->sig = nuevo;
    }
    *pld = nuevo;
    return 1;
}


int poner_orden(tListad *pld, const void *pd, unsigned tam, int(*cmp)(const void *, const void *)){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);
    tNodo *act = *pld;
    int comparar;
    tNodo *ant = NULL, *sig = NULL;
    if(act){
        while(act->ant && cmp(pd, act->info) < 0){
            act = act->ant;
        }
        while(act->sig && cmp(pd, act->info) > 0){
            act = act->sig;
        }
        comparar = cmp(pd, act->info);
        if(comparar == 0){
            return DUPLICADO;
        }else if(comparar < 0){
            sig = act;
            ant = act->ant;
        }else{
            ant = act;
            sig = act->sig;
        }
    }
    if(!nuevo || !elemNodo){
        free(nuevo);
        free(elemNodo);
        return 0;
    }
    nuevo->info = elemNodo;
    nuevo->tamInfo = tam;
    memcpy(elemNodo, pd, tam);
    nuevo->sig = sig;
    nuevo->ant = ant;
    if(sig){
        sig->ant = nuevo;
    }
    if(ant){
        ant->sig = nuevo;
    }
    *pld = nuevo;
    return 1;
}

int primero_lista(const tListad *pld, void *pd, unsigned tam){
    if(!*pld){
        return 0;
    }
    while((*pld)->ant){
        pld = &(*pld)->ant;
    }
    memcpy(pd, (*pld)->info, MIN(tam, (*pld)->tamInfo));
    return 1;
}

int ultimo_lista(const tListad *pld, void *pd, unsigned tam){
    if(!*pld){
        return 0;
    }
    while((*pld)->sig){
        pld = &(*pld)->sig;
    }
    memcpy(pd, (*pld)->info, MIN(tam, (*pld)->tamInfo));
    return 1;
}

int lista_llena(const tListad *pld, unsigned tam){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);

    free(nuevo);
    free(elemNodo);

    return nuevo==NULL||elemNodo==NULL;
}

int lista_vacia(const tListad *pld){
    if(*pld == NULL){
        return 1;
    }
    return 0;
}

int cmp_enteros(const void *e1, const void *e2){
    int *n1 = (int*)e1;
    int *n2 = (int*)e2;
    return *n1 - *n2;
}
