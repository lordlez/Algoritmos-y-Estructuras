#include "header_p1.h"

int main(){
    tLista lista;
    char ruta[] = "archivo.txt";

    crear_lista(&lista);
    leer_archivo(ruta, &lista);
    printf("Contenido de la lista:\n");
    recorrer(&lista, mostrar);
    vaciar_lista(&lista);

    return 0;
}