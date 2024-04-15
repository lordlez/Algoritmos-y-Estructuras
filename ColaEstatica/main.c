#include "colaEstatica.h"

int main(){

    tCola cola;
    int numero = 2, var;


    crear_cola(&cola);

    if(cola_vacia(&cola)){
        printf("La cola esta vacia\n");
    }else{
        printf("La cola no esta vacia\n");
    }

    if(cola_llena(&cola, sizeof(int))){
        printf("La cola esta llena\n");
    }else{
        printf("La cola no esta llena\n");
    }

    if(!cola_vacia(&cola)){
        vaciar_cola(&cola);
    }else{
        printf("No se puede vaciar, la cola esta vacia\n");
    }

    encolar(&cola, &numero, sizeof(int));

    ver_primero(&cola, &var, sizeof(int));
    printf("El primero de la cola es: %d\n", var);

    if(!cola_vacia(&cola)){
        desencolar(&cola, &numero, sizeof(int));
        printf("Desapile el numero: %d\n", numero);
    }

    if(ver_primero(&cola, &numero, sizeof(int))){
        printf("El primero es: %d\n", numero);
    }else{
        printf("No existe primero\n");
    }




    return 0;
}