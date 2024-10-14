typedef struct{
    void *info;
    struct sNodo *izq, *der;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tArbol;

void crear_arbol(tArbol *pa){
    *pa = NULL;
}

void vaciar_arbol(tArbol *pa){
    if(!*pa){
        return;
    }
    vaciar_arbol((*pa)->izq);
    vaciar_arbol((*pa)->der);
    free((*pa)->info);
    free(*pa);
    *pa = NULL;
}

void recorrer_orden(const tArbol *pa, void(*accion)(void*, unsigned, void *), void *param){
    if(!*pa){
        return;
    }
    recorrer_orden(&(*pa)->izq, accion, param);
    accion((*pa)->info, (*pa)->tamInfo, param);
    recorrer_orden(&(*pa)->der, accion, param);
}

void recorrer_pre(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param){
    if(!*pa){
        return;
    }
    accion((*pa)->info, (*pa)->tamInfo, param);
    recorrer_pre(&(*pa)->izq, accion, param);
    recorrer_pre(&(*pa)->der, accion, param);
}

void recorrer_pos(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param){
    if(!*pa){
        return;
    }
    recorrer_pos(&(*pa)->izq, accion, param);
    recorrer_pos(&(*pa)->der, accion, param);
    accion((*pa)->info, (*pa)->tamInfo, param);
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
        if(comparar = cmp(pd, (*pa)->info)<0){
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
    nuevo->izq = NULL;
    nuevo->der = NULL;
    *pa = nuevo;
    return 1;
}