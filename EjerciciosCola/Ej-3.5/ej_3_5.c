#include "ej_3_5.h"
#include "../../ColaDinamica/colaDinamica.c"

int simulacion_cajero(tCola *pc){
    srand(time(NULL));//genero una semilla aleatoria
    //rango = (FIN + 1) - INICIO
    //int rango = 6 - 1;
    //printf("%d", rand() % 6); //numeros random desde el cero al 5
    //printf("%d", rand() % rango + 1); //numeros random entre 1 y 5

    int demoraCajero = 0; //tiempo que tardo en el cajero
    int llegoCola = 0; // tiempo que tardo en llegar a la cola
    int demoraCola = 0; //tiempo de espera en la cola
    int vecesVacias = 0; //no hay clientes en la cola
    int clientesAtendidos = 0;

    while(vecesVacias < 5){

        llegoCola = rand() % 9 + 1; // va de (0 a 8) + 1 va de 1 a 9
        demoraCajero = rand() % 5 + 1; // va de (0 a 4) + 1 va de 1 a 5

        if(!cola_llena(pc, sizeof(int))){
            encolar(pc, &llegoCola, sizeof(int));
        }
        
        if(cola_vacia(pc)){
            demoraCola = 0;
            printf("Cliente atendido en %d minutos\n", demoraCajero);
            clientesAtendidos++;
        }else{
            desencolar(pc, &llegoCola, sizeof(int));

        }





    }

    return 1;
}
