#include "ej_4_4.h"
#include "../../EjerciciosLista/Ej-4.1/lista.c"

int buscar_cla(tLista *pl,void *pd, unsigned tam, int (*cmp)(const void *, const void *)){
    while(*pl && cmp(pd, (*pl)->info) != 0){
        pl = &(*pl)->sig;
    }
    if(!*pl){
        return 0;
    }
    memcpy(pd, (*pl)->info, MIN(tam, (*pl)->tamInfo));
    return 1;
}

int cmp_enteros(const void *a, const void *b){
    int *num1 = (int *)a;
    int *num2 = (int *)b;
    return *num1 - *num2;
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

int contar_cla(tLista *pl, void *pd, unsigned tam, int (*cmp)(const void *, const void *)){
    int cont = 0;
    while(*pl){
        if(cmp(pd, (*pl)->info) == 0){
            cont++;
        }
        pl = &(*pl)->sig;
    }
    return cont;
}

void mostrar_entero(void *a){
    int *num = (int *)a;
    printf("%d\n", *num);
}

