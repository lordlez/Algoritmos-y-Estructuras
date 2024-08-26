#include "header.h"

/**
Ejercicio de practica: Crear un archivo binario de productos, generar un indice de ese archivo implementando un arbol
binario de busqueda. Buscar en el indice el codigo de producto nro 10 y cambiarle el proveedor a "Frutitas  Lulu" en
el archivo de productos.
Nota: mostrar el archivo de productos antes de realizar cuaquier cambio
Nota: mostrar el archivo de productos luego de realizar cualquier cambio para corroborar que funcione todo bien
*/

int main()
{
    char rutaBin[] = "productos.dat";
    char rutaIdx[] = "productos.idx";
    tArbol ar;

    cargar_archivo(rutaBin); // cargo mi archivo de productos
    printf("Archivo de productos\n");
    mostrar_archivo(rutaBin); // imprimo el archivo de productos
    printf("\n------------------------------------\n\n");
    cargar_indice(rutaBin, rutaIdx); // cargo mi archivo de indice desde mi archivo de productos
    crear_arbol(&ar); // creo mi arbol
    cargar_de_indice_a_arbol(rutaIdx, &ar); // cargo mi arbol desde mi archivo de indice desordenado
    cargar_de_arbol_a_indiceOrd(&ar, rutaIdx); // cargo mi indice ya ordenado desde mi arbol
    cargar_arbol_desde_archivo_ordenado(&ar, rutaIdx, sizeof(tIndice));// cargo desde mi indice ordenado a mi arbol para que este balanceado
    modificar_proveedor(rutaBin, &ar, 75, "Frutitas Lulu"); // modifico el proveedor del producto 10
    printf("Archivo de productos luego de modificar el proveedor del producto 75\n");
    mostrar_archivo(rutaBin); // imprimo el archivo de productos
    vaciar_arbol(&ar); // vacio el arbol al finalizar el programa


    return 0;
}