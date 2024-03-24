#include "header.h"


/*NO FUNCIONA, ARREGLAR*/

int main(){

    tCola cola;
    int opcion;
    char ruta[] = "../Ej-2.3/datos.dat";

    archivo_a_cola(ruta, &cola);

    menu(&cola);

    comprobar_cola(ruta, &cola);

    leer_archivo(ruta);

    return 0;
}
