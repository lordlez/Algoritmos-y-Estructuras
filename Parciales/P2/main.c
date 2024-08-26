#include "p2.h"

int main(){
    
    tArbol arbol;
    char ruta[] = "quijote-es.txt";

    crear_arbol(&arbol);
    leer_archivo(ruta, &arbol);
    menu(&arbol);

    vaciar_arbol(&arbol);
    return 0;
}