#include "./header.h"

// Ejercicio 1

void crear_pila(tPila *pp){
    pp->tope = TAM;
}

int poner_en_pila(tPila *pp, const void *pd, unsigned tam){
    if(pp->tope < tam + sizeof(unsigned)){
        return 0;
    }
    pp->tope -= tam;
    memcpy(pp->pila + pp->tope, pd, tam);
    pp->tope -= sizeof(unsigned);
    memcpy(pp->pila + pp->tope, &tam, sizeof(unsigned));
    return 1;
}

int sacar_de_pila(tPila *pp, void *pd, unsigned tam){
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

int pila_llena(const tPila *pp, unsigned tam){
    if(pp->tope < (tam + sizeof(unsigned))){
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


// Ejercicio 2

int validar_cadena(const char *cadena){
    tPila pila;
    int i;
    char c, tope;

    crear_pila(&pila);
    for(i = 0; cadena[i] != '\0'; i++){ // recorro todas las letras de la cadena
        c = cadena[i]; // tomo una letra de la cadena
        if(c == '(' || c == '[' || c == '{'){ // veo si la letra es de apertura
            if(!poner_en_pila(&pila, &c, sizeof(char))){
                return 0; // no se pudo apilar
            }
        }else{ // si no es de apertura la letra
            if(pila_vacia(&pila)){ // veo si hay algo en la pila
                return 0; // no habia nada en la pila y lo que quiero apilar no es apertura
            }
            sacar_de_pila(&pila, &tope, sizeof(char));
            if((c == ')' && tope != '(') || (c == ']' && tope != '[') || (c == '}' && tope != '{')){
                return 0; // no coincide la apertura con el cierre
            }
        }
    }

    return pila_vacia(&pila); // si la pila esta vacia es porque todo lo que se abrio se cerro
}