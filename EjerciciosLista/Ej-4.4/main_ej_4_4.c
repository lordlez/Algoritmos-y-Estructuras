#include "ej_4_4.h"


int main(){
    tLista lista;
    int a = 1, b = 2, c = 3, d = 4, contador;

    crear_lista(&lista);

    //asumo que la lista tiene espacio para poner sin preguntar
    poner_al_inicio(&lista, &a, sizeof(int));
    poner_al_inicio(&lista, &b, sizeof(int));
    poner_al_inicio(&lista, &c, sizeof(int));
    poner_al_inicio(&lista, &a, sizeof(int));
    poner_al_inicio(&lista, &a, sizeof(int));

    // if(buscar_cla(&lista, &d, sizeof(int), cmp_enteros)){
    //     printf("El elemento %d se encuentra en la lista\n", d);
    // }else{
    //     printf("El elemento %d no se encuentra en la lista\n", d);
    // }

    // if(buscar_cla_y_eliminar(&lista, &b, sizeof(int), cmp_enteros)){
    //     printf("El elemento %d se encontraba en la lista y fue eliminado\n", b);
    // }

    //recorrer_lista(&lista, mostrar_entero);

    contador = contar_cla(&lista, &d, sizeof(int), cmp_enteros);
    printf("El elemento %d se repite %d veces\n", d, contador);

    
    

    return 0;
}