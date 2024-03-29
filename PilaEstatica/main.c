#include "pilaEstatica.h"

int main(){
    
    /* Codigo hecho en clase */

    // tPila pila;
    // int vec[] = {1,2,3};
    // int i;

    // crear_pila(&pila);
    
    // if(pila_vacia(&pila)){
    //     printf("Pila vacia\n");
    // }else{
    //     printf("Pila no vacia\n");
    // }

    //le mando un cero por defecto
    // if(pila_llena(&pila, 0)){ 
    //     printf("Pila llena\n");
    // }else{
    //     printf( "Pila no llena\n");
    // }

    // i<sizeof(vec)/sizeof(int) sirve para ver hasta donde recorrer el array
    // for(i=0; i<sizeof(vec)/sizeof(int); i++){
    //     if(apilar(&pila, &vec[i], sizeof(int))){
    //         printf("Apilo bien\n");
    //     }else{
    //         printf("No pudo apilar\n");
    //     }
    // }


    /* Mi codigo */

    tPila pila1, pila2;
    int vec[] = {1,2,3,4,5};
    int i = 0, numero, j = 0;
    tAlumno alumnos[] = {
        {"Arturo Pendragon", 'M', 35, {12,04,1820}, 10},
        {"Sir Lancelot", 'M', 29, {26,07,1850}, 8.5},
        {"Sir Galahad", 'M', 38, {9,01,1805}, 7.4},
        {"Bors Desterrado", 'M', 42, {15,10,1800}, 7},
    };


    crear_pila(&pila1);

    ///Para el vector de enteros:
    while(!pila_llena(&pila1, 0) && i < sizeof(vec)/sizeof(int)){
        if(apilar(&pila1, &vec[i], sizeof(int))){
            printf("Apilo bien: %d\n", vec[i]);
        }else{
            printf("Error al apilar\n");
        }
        i++;
    }

    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope: %d\n", numero);
    }

    while(!pila_vacia(&pila1) && j < 2){
        if(desapilar(&pila1, &numero, sizeof(int))){
            printf("Desapilo bien: %d\n", numero);
        }else{
            printf("Error al desapilar\n");
        }
        j++;
    }

    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope: %d\n", numero);
    }

    vaciar_pila(&pila1);

    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope: %d", numero);
    }else{
        printf("No hay tope\n");
    }


    /// Para el vector de estructuras:
    crear_pila(&pila2);

    i = 0;

    while(!pila_llena(&pila2, 0) && i < sizeof(alumnos)/sizeof(tAlumno)){
        if(apilar(&pila2, &alumnos[i], sizeof(tAlumno))){
            printf("Apilo bien\n");
            printf("Apellido y nombre: %s\n", alumnos[i].apyn);
            printf("Sexo: %c\n", alumnos[i].sexo);
            printf("Edad: %d\n",  alumnos[i].edad);
            printf("Fecha de nacimiento: %d/%d/%d\n", alumnos[i].nacimiento.dia, alumnos[i].nacimiento.mes, alumnos[i].nacimiento.anio);
            printf("Promedio: %.2f\n", alumnos[i].promedio);
        }else{
            printf("Error al apilar estructuras\n");
        }
        i++;
    }


    return 0;
}