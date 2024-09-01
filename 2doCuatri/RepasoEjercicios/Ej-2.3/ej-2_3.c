#include "ej-2_3.h"

int cargar_archivo(const char *ruta){
    FILE *pf;
    tProducto productos[] = {
        {"A4", "Leche", "Sancor", {12,4,2001}, {25,7,2001}, 5, 8.99, 7.66 },
        {"B2", "Manteca", "La Paulina", {12,4,2001}, {25,7,2001}, 5, 8.99, 7.66 },
        {"C1", "Queso", "La Nata", {12,4,2001}, {25,7,2001}, 5, 8.99, 7.66 },
        {"B1", "Queso", "La Nata", {12,4,2001}, {25,7,2001}, 5, 8.99, 7.66 },
        {"A1", "Queso", "La Nata", {12,4,2001}, {25,7,2001}, 5, 8.99, 7.66 },
    };

    pf = fopen(ruta, "wb");
    if(pf == NULL){
        printf("Error al abrir el archivo\n");
        return -1;
    }
    fwrite(productos, sizeof(productos), 1, pf);
    fclose(pf);
    return 1;
}