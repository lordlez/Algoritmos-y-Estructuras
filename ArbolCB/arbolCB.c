#include "arbolCB.h"


void crear_arbol(tArbol *pa)
{
    *pa = NULL;
}

int poner_arbol(tArbol *pa, const void *pd, unsigned tam, int (*cmp)(const void*, const void*))
{
    tNodo *nuevo;
    int comparar;
    while(*pa)
    {
        if((comparar = cmp(pd, (*pa)->info))<0)
        {
            pa = &(*pa)->izq;
        }
        else if(comparar>0)
        {
            pa = &(*pa)->der;
        }
        else
        {
            return DUPLICADO;
        }
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL)
    {
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    *pa = nuevo;
    return 1;
}

void recorrer_preorden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param)
{
    if(!*pa)
    {
        return;
    }
    accion(&(*pa)->info, (*pa)->tamInfo, param);
    recorrer_preorden(&(*pa)->izq, accion, param);
    recorrer_preorden(&(*pa)->der, accion, param);
}

void recorrer_orden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param)
{
    if(!*pa)
    {
        return;
    }
    recorrer_orden(&(*pa)->izq, accion, param);
    accion((*pa)->info, (*pa)->tamInfo, param);
    recorrer_orden(&(*pa)->der, accion, param);
}

void recorrer_posorden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param)
{
    if(!*pa)
    {
        return;
    }
    recorrer_posorden(&(*pa)->izq, accion, param);
    recorrer_posorden(&(*pa)->der, accion, param);
    accion((*pa)->info, (*pa)->tamInfo, param);
}

int cmp_enteros(const void *e1, const void *e2)
{
    const int *num1 = (const int*)e1;
    const int *num2 = (const int*)e2;
    return *num1-*num2;
}

void imprimir_nodo(void *info, unsigned tam, void *param)
{
    int espacio = *(int*)param;
    int i;

    for (i = 0; i < espacio; i++) {
        printf(" ");
    }
    printf("%d\n", *(int*)info);
}


