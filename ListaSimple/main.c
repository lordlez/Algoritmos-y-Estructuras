#include "listaSimple.h"

int main(){

    tLista lista;
    int numero, n = 0, m = 0;

    crear_lista(&lista);

    while(!lista_llena(&lista, sizeof(int)) && n < 5){
        printf("\nIngrese numero: ");
        scanf("%d", &numero);
        poner_al_inicio(&lista, &numero, sizeof(int));
        n++;
    }

    if(!lista_vacia(&lista)){
        ver_primero(&lista, &numero, sizeof(int));
        printf("\nPrimero: %d", numero);
    }

    if(!lista_vacia(&lista)){
        ver_ultimo(&lista, &numero, sizeof(int));
        printf("\nUltimo: %d", numero);
    }

    if(!lista_vacia(&lista)){
        sacar_al_inicio(&lista, &numero, sizeof(int));
    }

    if(!lista_vacia(&lista)){
        ver_primero(&lista, &numero, sizeof(int));
        printf("\nPrimero: %d", numero);
    }


    if(!lista_vacia(&lista)){
        sacar_al_final(&lista, &numero, sizeof(int));
    }

    if(!lista_vacia(&lista)){
        ver_ultimo(&lista, &numero, sizeof(int));
        printf("\nUltimo: %d", numero);
    }

    if(!lista_llena(&lista, sizeof(int))){
        printf("\nIngresa otro numero: ");
        scanf("%d", &numero);
        poner_al_final(&lista, &numero, sizeof(int));
    }

    if(!lista_vacia(&lista)){
        ver_ultimo(&lista, &numero, sizeof(int));
        printf("\nUltimo: %d", numero);
    }

    printf("\nOrdenada: ");

    ordenar(&lista, cmp_enteros);

    if(!lista_vacia(&lista)){
        ver_primero(&lista, &numero, sizeof(int));
        printf("\nPrimero: %d", numero);
    }

    if(!lista_vacia(&lista)){
        ver_ultimo(&lista, &numero, sizeof(int));
        printf("\nUltimo: %d", numero);
    }

    printf("\nMuestro la lista: ");

    mostrar(&lista, mostrar_lista);

    vaciar_lista(&lista);
    
    if(!lista_vacia(&lista)){
        mostrar(&lista, mostrar_lista);
    }else{
        printf("\nNo se puede mostrar, la lista fue vaciada");
    }

    while(!lista_llena(&lista, sizeof(int)) && m<5){
        printf("\nIngresa numero desorden: ");
        scanf("%d", &numero);
        poner_ordenado(&lista, &numero, sizeof(int), cmp_enteros);
        m++;
    }

    mostrar(&lista, mostrar_lista);



    

    return 0;
}