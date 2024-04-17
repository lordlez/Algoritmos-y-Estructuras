#include "ej_13.h"


int main(){


    tPila limite, pila1, pilaMay, pilaMen;
    int mayor, menor;

    crear_pila(&pila1);
    crear_pila(&pilaMay);
    crear_pila(&pilaMen);
    crear_pila(&limite);

    printf("Para la pila 1:\n");
    cargar_pila(&pila1);
    printf("Para el limite:\n");
    cargar_pila(&limite);

    comparar(&pila1, &limite, &pilaMay, &pilaMen);

    if(!pila_vacia(&pilaMay)){
        ver_tope(&pilaMay, &mayor, sizeof(int));
        printf("El tope de la pila es: %d\n", mayor);
    }

    if(!pila_vacia(&pilaMen)){
        ver_tope(&pilaMen, &menor, sizeof(int));
        printf("El tope de la pila es: %d\n", menor);
    }


    return 0;
}