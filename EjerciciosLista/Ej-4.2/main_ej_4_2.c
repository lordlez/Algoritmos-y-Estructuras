#include "ej_4_2.h"

int main(){

    char datos1[] = "../../EjerciciosPila/Ej-2.3/datos.dat";
    char datos2[] = "../../EjerciciosPila/Ej-2.3/datos.dat";
    tLista lista1;
    tLista lista2;

    crear_lista(&lista1);
    crear_lista(&lista2);

    ordenar_archivo_v1(datos1, &lista1);
    ordenar_archivo_v2(datos2, &lista2);

    printf("Archivo datos1 ordenado: \n");
    mostrar_archivo(datos1);
    printf("Archivo datos2 ordenado: \n");
    mostrar_archivo(datos2);


    return 0;
}