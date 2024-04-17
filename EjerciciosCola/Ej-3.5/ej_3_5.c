#include "ej_3_5.h"
#include "../Ej-3.2/colaD.c"

int numero_aleatorio(int min, int max){
    return min + rand() % (max - min + 1);
}

void cajero(tCola *pc){
    int clientes_vacios = 0;
    int intervalo_llegada, tiempo_atencion, tiempo_espera ,tiempo_espera_siguiente;

    srand(time(NULL)); //inicializo la semilla para numeros aleatorios

    while(clientes_vacios < 5){
        intervalo_llegada = numero_aleatorio(1,3);
        sleep(intervalo_llegada);//esperar el intervalo de llegada
        tiempo_atencion = numero_aleatorio(1, 5);

        if(cola_vacia(pc)){
            printf("Cliente atendido en %d minutos\n", tiempo_atencion);
        }else{
            desencolar(pc, &tiempo_espera, sizeof(int));
            tiempo_atencion += tiempo_espera;//tiempo que espere en la cola mas el tiempo de atencion en el cajero
            printf("Cliente atendido en %d minutos(espero %d minutos en la cola)\n", tiempo_atencion, tiempo_espera);
        }

        //genero el tiempo de espera del siguiente cliente
        tiempo_espera_siguiente = numero_aleatorio(1, 5);

        if(cola_llena(pc, sizeof(int))){
            //si la cola esta llena se descarta el tiempo de espera del siguiente cliente
            printf("Cola llena, no se puede atender al cliente\n");
        }else{
            //si hay espacio se encola el tiempo de espera del siguiente
            encolar(pc, &tiempo_espera_siguiente, sizeof(int));
        }

        if(cola_vacia(pc)){
            clientes_vacios++;
            printf("Cola vacia por %d vez", clientes_vacios);
        }
    }

    //vacio la cola al finalizar
    vaciar_cola(pc);

}