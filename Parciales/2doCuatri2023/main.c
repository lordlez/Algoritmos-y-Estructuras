#include "header.h"

int main()
{
    char rutaBin[] = "alumnos.dat";
    char rutaIdx[] = "alumnos.idx";
    tArbol ar;
    int dniBorrar = 11;

    cargar_archivo_bin(rutaBin); // tengo mi archivo de alumnos cargado con los registros
    printf("Lista de alumnos sin modificar\n");
    mostrar_archivo(rutaBin);
    cargar_indice_alumnos(rutaBin, rutaIdx); // tengo mi archivo indice cargado desordenado
    crear_arbol(&ar); // creo mi arbol binario
    cargar_desde_archivoDes_a_arbol(rutaIdx, &ar); // cargo mi arbol con los registros del indice
    cargar_desde_arbol_a_archivo(rutaIdx, &ar); // cargo datos a mi indice desde el arbol asi me quedara ordenado
    cargar_arbol_desde_archivo_ordenado(&ar, rutaIdx, sizeof(tIndice)); // algoritmo para ontener el arbol balanceado desde mi archivo de indice
    menu(&ar, &dniBorrar, rutaBin, rutaIdx);
    printf("Lista de alumnos modificados\n");
    printf("-*-*--*-*-*-*--*--***-*-*--*-*-\n");
    mostrar_archivo(rutaBin);

    return 0;
}