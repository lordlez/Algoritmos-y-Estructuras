#include "listaSimple.h"


void crear_lista(tLista *pl){
    *pl = NULL;
}

void vaciar_lista(tLista *pl){
    tNodo *elim;
    while(*pl){
        elim = *pl;
        *pl = elim->sig;
        free(elim->info);
        free(elim);
    }
}

int poner_al_inicio(tLista *pl, const void *pd, unsigned tam){
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
    nuevo->sig = *pl;
    *pl = nuevo;
    return 1;
}

int poner_al_final(tLista *pl, const void *pd, unsigned tam){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);
    while(*pl){
        pl = &(*pl)->sig;
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
    *pl = nuevo;
    return 1;
}

int poner_ordenado(tLista *pl, const void *pd, unsigned tam, int (*cmp)(const void *, const void *)){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);
    while(*pl && cmp(pd, (*pl)->info) > 0){
        pl = &(*pl)->sig;
    }
    if(*pl && cmp(pd, (*pl)->info) == 0){
        return DUPLICADO;
    }
    if(!nuevo || !elemNodo){
        free(nuevo);
        free(elemNodo);
        return 0;
    }
    nuevo->info = elemNodo;
    nuevo->tamInfo = tam;
    memcpy(elemNodo, pd, tam);
    nuevo->sig = *pl;
    *pl = nuevo;
    return 1;
}

int sacar_al_inicio(tLista *pl, void *pd, unsigned tam){
    tNodo *elim;
    if(*pl == NULL){
        return 0;
    }
    elim = *pl;
    *pl = elim->sig;
    memcpy(pd, elim->info, MIN(tam, elim->tamInfo));
    free(elim->info);
    free(elim);
    return 1;
}

int sacar_al_final(tLista *pl, void *pd, unsigned tam){
    tNodo *elim;
    if(*pl == NULL){
        return 0;
    }
    while((*pl)->sig){
        pl = &(*pl)->sig;
    }
    elim = *pl;
    memcpy(pd, elim->info, MIN(tam, elim->tamInfo));
    free(elim->info);
    free(elim);
    *pl = NULL;
    return 1;
}

int ver_primero(const tLista *pl, void *pd, unsigned tam){
    if(*pl == NULL){
        return 0;
    }
    memcpy(pd, (*pl)->info, MIN(tam, (*pl)->tamInfo));
    return 1;
}

int ver_ultimo(const tLista *pl, void *pd, unsigned tam){
    if(*pl == NULL){
        return 0;
    }
    while((*pl)->sig){
        pl = &(*pl)->sig;
    }
    memcpy(pd, (*pl)->info, MIN(tam, (*pl)->tamInfo));
    return 1;
}

void ordenar(tLista *pl, int (*cmp)(const void *, const void *)){
    tLista lord = NULL;
    tLista *plord;
    tNodo *nodo;
    while(*pl){
        nodo = *pl;
        *pl = nodo->sig;
        plord = &lord;
        while(*plord && cmp(nodo->info, (*plord)->info) > 0){
            plord = &(*plord)->sig;
        }
        nodo->sig = *plord;
        *plord = nodo;
    }
    *pl = lord;
}

void mostrar(tLista *pl, void(*mostrar)(void*)){
    while(*pl){
        mostrar((*pl)->info);
        pl = &(*pl)->sig;
    }
}

int lista_llena(const tLista *pl, unsigned tam){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);

    free(nuevo);
    free(elemNodo);

    return nuevo == NULL || elemNodo == NULL;
}

int lista_vacia(const tLista *pl){
    if(*pl == NULL){
        return 1;
    }
    return 0;
}

int cmp_enteros(const void *e1, const void *e2){
    int *num1 = (int*)e1;
    int *num2 = (int*)e2;
    return *num1-*num2;
}

void mostrar_lista(void *e){
    int *elm = (int*)e;
    printf("%d", *elm);
    printf("\n");
}