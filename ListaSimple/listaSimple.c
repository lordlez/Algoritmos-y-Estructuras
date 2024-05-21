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
    tNodo *nuevo;
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->sig = *pl;
    *pl = nuevo;
    return 1;
}

int poner_al_final(tLista *pl, void *pd, unsigned tam){
    tNodo *nuevo;
    while(*pl){
        pl = &(*pl)->sig
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->sig = NULL;
    *pl = nuevo;
    return 1;
}

int poner_ordenado(tLista *pl, const void *pd, unsigned tam, int (*cmp)(const void *, const void *)){
    tNodo *nuevo;
    while(*pl && cmp(pd, (*pl)->info) > 0){
        pl = &(*pl)->sig;
    }
    if(*pl && cmp(pd, (*pl)->info) == 0){
        return DUPLICADO;
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
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

void recorrer_lista(tLista *pl, void (*mostrar)(void*)){
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

int buscar_clave(tLista *pl,void *pd, unsigned tam, int (*cmp)(const void *, const void *)){
    while(*pl && cmp(pd, (*pl)->info) != 0){
        pl = &(*pl)->sig;
    }
    if(!*pl){
        return 0;
    }
    memcpy(pd, (*pl)->info, MIN(tam, (*pl)->tamInfo));
    return 1;
}

tLista buscar_clave_sub_lista(tLista *pl, const void *pd, int(*cmp)(const void*, const void*)){
    while(*pl && cmp((*pl)->info, pd)){
        pl = &(*pl)->sig;
    }
    if(!*pl){
        return NULL;
    }
    return *pl;
}

int buscar_cla_y_eliminar(tLista *pl, void *pd, unsigned tam, int (*cmp)(const void *, const void *)) {
    tNodo *elim;
    while (*pl && cmp(pd, (*pl)->info) != 0) {
        pl = &(*pl)->sig;
    }
    if (!*pl) {
        return 0;
    }
    elim = *pl;
    *pl = elim->sig;
    free(elim->info);
    free(elim);
    return 1;
}