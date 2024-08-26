#include "arbol.h"

void crear_arbol(tArbol *pa){
    *pa = NULL;
}

void vaciar_arbol(tArbol *pa){
    if(!*pa){
        return;
    }
    vaciar_arbol(&(*pa)->izq);
    vaciar_arbol(&(*pa)->der);
    free((*pa)->info);
    free(*pa);
    *pa = NULL;
}

void podar_nivel(tArbol *pa, int n){
    if(!*pa){
        return;
    }
    podar_nivel(&(*pa)->izq, n-1);
    podar_nivel(&(*pa)->der, n-1);
    if(n<0){
        free((*pa)->info);
        free(*pa);
        *pa = NULL;
    }
}

void recorrer_orden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param){
    if(!*pa){
        return;
    }
    recorrer_orden(&(*pa)->izq, accion, param);
    accion((*pa)->info, (*pa)->tamInfo, param);
    recorrer_orden(&(*pa)->der, accion, param);
}

void recorrer_posorden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param){
    if(!*pa){
        return;
    }
    recorrer_posorden(&(*pa)->izq, accion, param);
    recorrer_posorden(&(*pa)->der, accion, param);
    accion((*pa)->info, (*pa)->tamInfo, param);
}

void recorrer_preorden(const tArbol *pa, void(*accion)(void*,  unsigned, void*), void *param){
    if(!*pa){
        return;
    }
    accion((*pa)->info, (*pa)->tamInfo, param);
    recorrer_preorden(&(*pa)->izq, accion, param);
    recorrer_preorden(&(*pa)->der, accion, param);
}

int contar_nodos(tArbol *pa){
    if(!*pa){
        return 0;
    }
    return contar_nodos(&(*pa)->izq)+contar_nodos(&(*pa)->der)+1;
}

int poner_en_arbol(tArbol *pa, const void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    tNodo *nuevo;
    int comparar;
    while(*pa){
        if((comparar = cmp(pd, (*pa)->info))<0){
            pa = &(*pa)->izq;
        }else if(comparar > 0){
            pa = &(*pa)->der;
        }else{
            return DUPLICADO;
        }
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    *pa = nuevo;
    return 1;
}

int eliminar_elemento(tArbol *pa, void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    if(!(pa = buscar_nodo(pa, pd, cmp))){
        return 0;
    }
    memcpy(pd, (*pa)->info, MIN(tam, (*pa)->tamInfo));
    return eliminar_raiz(pa);
}

int buscar_elemento(const tArbol *pa, void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    if(!(pa = buscar_nodo(pa, pd, cmp))){
        return 0;
    }
    memcpy(pd, (*pa)->info, MIN(tam, (*pa)->tamInfo));
    return 1;
}

tNodo **buscar_nodo(const tArbol *pa, const void *pd, int(*cmp)(const void*, const void*)){
    int rc;
    while(*pa && (rc = cmp(pd, (*pa)->info))){
        if(rc<0){
            pa = &(*pa)->izq;
        }else{
            pa = &(*pa)->der;
        }
    }
    if(!*pa){
        return NULL;
    }
    return (tNodo**)pa;
}

int eliminar_raiz(tArbol *pa){
    tNodo **remp, *elim;
    if(!*pa){
        return 0;
    }
    free((*pa)->info);
    if(!(*pa)->izq && !(*pa)->der){
        free(*pa);
        *pa = NULL;
        return 1;
    }
    remp = altura(&(*pa)->izq)>altura(&(*pa)->der)?mayor_nodo(&(*pa)->izq):menor_nodo(&(*pa)->der);
    elim = *remp;
    (*pa)->info = elim->info;
    (*pa)->tamInfo = elim->tamInfo;
    *remp = elim->izq?elim->izq:elim->der;
    free(elim);
    return 1;
}

int altura(const tArbol *pa){
    int hizq, hder;
    if(!*pa){
        return 0;
    }
    hizq = altura(&(*pa)->izq);
    hder = altura(&(*pa)->der);
    return (hizq>hder?hizq:hder)+1;
}

tNodo **mayor_nodo(const tArbol *pa){
    if(!*pa){
        return NULL;
    }
    while((*pa)->der){
        pa = &(*pa)->der;
    }
    return (tNodo**)pa;
}

tNodo **menor_nodo(const tArbol *pa){
    if(!*pa){
        return NULL;
    }
    while((*pa)->izq){
        pa = &(*pa)->izq;
    }
    return (tNodo**)pa;
}

int tipo_balance(const tArbol *pa){
    if(arbol_completo(pa)){
        return COMPLETO;
    }
    if(arbol_balanceado(pa)){
        return BALANCEADO;
    }
    if(arbol_avl(pa)){
        return AVL;
    }
    return DESBALANCEADO;
}

int arbol_completo(const tArbol *pa){
    return completo_hasta(pa, altura(pa)-1);
}

int arbol_balanceado(const tArbol *pa){
    return completo_hasta(pa, altura(pa)-1);
}

int arbol_avl(const tArbol *pa){
    int hi, hd;
    if(!*pa){
        return 1;
    }
    hi = altura(&(*pa)->izq);
    hd = altura(&(*pa)->der);
    if(abs(hi-hd)>1){
        return 0;
    }
    return arbol_avl(&(*pa)->izq)&&arbol_avl(&(*pa)->der);
}

int completo_hasta(const tArbol *pa, int n){
    if(!*pa){
        return n<0;
    }
    if(n==0){
        return 1;
    }
    return completo_hasta(&(*pa)->izq, n-1) && completo_hasta(&(*pa)->der, n-1);
}

// accion en recorrer pre, in y pos
void imprimir(void *info, void *param){
    int *i = (int*)info;
    printf("-%d-", *i);
}
