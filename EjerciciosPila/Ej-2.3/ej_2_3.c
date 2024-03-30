#include "ej_2_3.h"

int cargar_archivo_binario(const char *ruta){
    FILE *pf;
    tProducto productos[] = {
        {"A1", "Manteca", "Sancor", {12,1,2024}, {3,8,2024}, 10, 350, 500},
        {"D5", "Leche", "La Serenisima", {20,4,2024}, {6,9,2024}, 7, 800, 1050},
        {"B3", "Yogurt", "Monfrey", {11,3,2014}, {17,6,2024}, 5, 200, 430},
        {"B5", "Cereal", "FelFort", {30,1,2024}, {23,10,2024}, 2, 400, 560.20},
        {"C13", "Chocolate", "Bariloche", {27,3,2024}, {10,4,2025}, 1, 8000, 9999.99},
    };
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        return -1;
    }
    fwrite(productos, sizeof(productos), 1, pf);
    fclose(pf);
    return 1;
}


