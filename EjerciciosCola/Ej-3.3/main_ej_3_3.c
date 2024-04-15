#include "ej_3_3.h"


int main(){

    tCola cola;
    char ruta[] = "../../EjerciciosPila/Ej-2.3/datos.dat";

    crear_cola(&cola);
    cargar_archivo_bin_en_colaE(ruta, &cola);
    menu(&cola);
    cargar_de_cola_a_archivo(ruta, &cola);

    return 0;
}