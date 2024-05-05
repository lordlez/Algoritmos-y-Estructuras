#include "ej_2_3.h"

int cargar_archivo_binario(const char *ruta){
    FILE *pf;
    tProducto productos[] = {
        {"C4", "Manteca", "Sancor", {12,1,2024}, {23,10,2024}, 10, 350, 500},
        {"A2", "Leche", "La Serenisima", {20,4,2024}, {6,9,2024}, 7, 800, 1050},
        {"A1", "Yogurt", "Monfrey", {11,3,2014}, {17,6,2024}, 5, 200, 430},
        {"D8", "Cereal", "Sancor", {30,1,2024}, {23,10,2024}, 2, 400, 560.20},
        {"B3", "Chocolate", "Bariloche", {27,3,2024}, {6,9,2024}, 1, 8000, 9999.99},
    };
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        return -1;
    }
    fwrite(productos, sizeof(productos), 1, pf);
    fclose(pf);
    return 1;
}


