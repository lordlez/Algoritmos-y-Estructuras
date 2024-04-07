//PILA ESTATICA

#define TAM 100

typedef struct{
    char pila[TAM];
    unsigned tope;
}tPila;

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
    if(pp->tope < tam + sizeof(unsigned)){
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

//PILA DINAMICA

typedef struct sNodo{
    void *info;
    struct sNodo *sig;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tPila;

void crear_pila(tPila *pp){
    *pp = NULL;
}

void vaciar_pila(tPila *pp){
    tNodo *elim;
    while(*pp){
        elim = *pp;
        *pp = elim->sig;
        free(elim->info);
        free(elim);
    }
}

int apilar(tPila *pp, const void *pd, unsigned tam){
    tNodo *nuevo;
    if((nuevo = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nuevo->info = malloc(tam)) == NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->sig = *pp;
    *pp = nuevo;
    return 1;
}

int desapilar(tPila *pp, void *pd, unsigned tam){
    tNodo *elim;
    if(*pp == NULL){
        return 0;
    }
    elim = *pp;
    *pp = elim->sig;
    memcpy(elim->info, pd, MIN(tam, elim->tamInfo));
    free(elim->info);
    free(elim);
    return 1;
}

int ver_tope(const tPila *pp, void *pd, unsigned tam){
    if(*pp == NULL){
        return 0;
    }
    memcpy((*pp)->info, pd, MIN(tam, (*pp)->tamInfo));
    return 1;
}

int pila_llena(const tPila *pp, unsigned tam){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);

    free(nuevo);
    free(elemNodo);

    return nuevo == NULL || elemNodo == NULL;
}

int pila_vacia(const tPila *pp){
    if(*pp == NULL){
        return 1;
    }
    return 0;
}

