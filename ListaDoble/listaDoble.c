#include "listaDoble.h"

void crear_lista(tListaD *pld){
    *pld = NULL;
}

void vaciar_lista(tListaD *pld){
    tNodo *act = *pld;
    tNodo *aux;
    if(act){
        while(act->ant){
            act = act->ant;
        }
        while(act){
            aux = act->sig;
            free(act->info);
            free(act);
            act = aux;
        }
        *pld = NULL;
    }
}

int poner_inicio(tListaD *pld, const void *pd, unsigned tam){
    tNodo *nuevo;
    tNodo *act = *pld;
    if(act){
        while(act->ant){
            act = act->ant;
        }
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->sig = act;
    nuevo->ant = NULL;
    if(act){
        act->ant = nuevo;
    }
    *pld = nuevo;
    return 1;
}

int poner_final(tListaD *pld, const void *pd, unsigned tam){
    tNodo *nuevo;
    tNodo *act = *pld;
    if(act){
        while(act->sig){
            act = act->sig;
        }
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->sig = NULL;
    nuevo->ant = act;
    if(act){
        act->sig = nuevo;
    }
    *pld = nuevo;
    return 1;
}

int poner_orden(tListaD *pld, const void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    tNodo *nuevo;
    tNodo *act = *pld;
    tNodo *ant = NULL, *sig = NULL;
    int comparar;
    if(act){
        while(act->ant && cmp(pd, act->info)<0){
            act = act->ant;
        }
        while(act->sig && cmp(pd, act->info)>0){
            act = act->sig;
        }
        comparar = cmp(pd, act->info);
        if(comparar == 0){
            return DUPLICADO;
        }else if(comparar<0){
            sig = act;
            ant = act->ant;
        }else{
            ant = act;
            sig = act->sig;
        }
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
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

int primero(const tListaD *pld, void *pd, unsigned tam){
    if(!*pld){
        return 0;
    }
    while((*pld)->ant){
        pld = &(*pld)->ant;
    }
    memcpy(pd, (*pld)->info, MIN(tam, (*pld)->tamInfo));
    return 1;
}

int ultimo(const tListaD *pld, void *pd, unsigned tam){
    if(!*pld){
        return 0;
    }
    while((*pld)->sig){
        pld = &(*pld)->sig;
    }
    memcpy(pd, (*pld)->info, MIN(tam, (*pld)->tamInfo));
    return 1;
}

int lista_llena(const tListaD *pld, unsigned tam){
    tNodo *nodo = malloc(sizeof(tNodo));
    void *elem = malloc(tam);

    free(nodo);
    free(elem);

    return nodo==NULL || elem==NULL;
}

int lista_vacia(const tListaD *pld){
    if(*pld == NULL){
        return 1;
    }
    return 0;
}


void ordenar_lista(tListaD *pld, int(*cmp)(const void*, const void*)){
    tNodo *act = *pld;
    tNodo *inf = NULL, *sup = NULL;
    int marca = 1;

    if(act==NULL){
        return;
    }
    while(act->ant){
        act = act->ant;
    }
    while(marca){
        marca = 0;
        while(act->sig != sup){
            if(cmp(act->info, act->sig->info)>0){
                void *inf = act->info;
                unsigned tam = act->tamInfo;
                marca = 1;
                act->info = act->sig->info;
                act->sig->info = inf;
                act->tamInfo = act->sig->tamInfo;
                act->sig->tamInfo = tam;
            }
            act = act->sig;
        }
        sup = act;
        while(act->ant != inf){
            if(cmp(act->info, act->ant->info)<0){
                void *inf = act->info;
                unsigned tam = act->tamInfo;
                marca = 1;
                act->info = act->ant->info;
                act->ant->info = inf;
                act->tamInfo = act->ant->tamInfo;
                act->ant->tamInfo = tam;
            }
            act = act->ant;
        }
        inf = act;
    }
}

int eliminar_de_ordenada(tListaD *pld, void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    tNodo *act = *pld;
    if(!*pld){
        return 0;
    }
    while(act->ant && cmp(pd, act->info)<0){
        act = act->ant;
    }
    while(act->sig && cmp(pd, act->info)>0){
        act = act->sig;
    }
    if(cmp(pd, act->info)!=0){
        return 0;
    }
    if(act->ant){
        act->ant->sig = act->sig;
    }
    if(act->sig){
        act->sig->ant = act->ant;
    }
    if(act == *pld){
        if(act->sig){
            *pld = act->sig;
        }else{
            *pld = act->ant;
        }
    }
    memcpy(pd, act->info, MIN(tam, act->tamInfo));
    free(act->info);
    free(act);
    return 1;
}

void mostrar_lista(const tListaD *pld, void(*mostrar)(const void*)){
    if(*pld){
        while((*pld)->ant){
            pld = &(*pld)->ant;
        }
        while(*pld){
            mostrar((*pld)->info);
            pld = &(*pld)->sig;
        }
    }
}
