#include "colaDinamica.h"

int main(){

    tCola cola;
    char cad1[] = "Uno";
    char cad2[] = "Dos";
    char cad3[] = "Tres";
    char cad4[10];

    crear_cola(&cola);

    if(!cola_llena(&cola, sizeof(cad1))){
        poner_en_cola(&cola, &cad1, sizeof(cad1));
        ver_primero(&cola, &cad4, sizeof(cad4));
        puts(cad4);
    }

    if(!cola_vacia(&cola)){
        sacar_de_cola(&cola, &cad4, sizeof(cad4));
    }

    if(!cola_llena(&cola, sizeof(cad2))){
        poner_en_cola(&cola, &cad2, sizeof(cad2));
        ver_primero(&cola, &cad4, sizeof(cad4));
        puts(cad4);
    }

    vaciar_cola(&cola);

    if(!cola_vacia(&cola)){
        ver_primero(&cola, &cad4, sizeof(cad4));
        puts(cad4);
    }else{
        printf("La cola fue vaciada");
    }




    return 0;
}