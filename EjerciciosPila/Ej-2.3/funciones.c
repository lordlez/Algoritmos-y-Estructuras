#include "header.h"

int crear_archivo(char *ruta){

    tProducto productos[] = {
        {"PROD1", "Leche", "Sancor", {20,2,2023}, {12,3,2023}, 20, 500, 850},
        {"PROD2", "Azucar", "Ledesma", {21,2,2023}, {14,4,2023}, 10, 200, 340},
        {"PROD3", "Yogurt", "La Serenisima", {8,3,2023}, {5,4,2023}, 7, 400, 560},
        {"PROD4", "Manteca", "La Paulina", {28,3,2023}, {13,5,2023}, 3, 150, 230},
        {"PROD5", "Carne", "Muu", {15,7,2023}, {23,9,2023}, 2, 670, 1240}
    };

    FILE *pf;
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        return -1;
    }
    fwrite(productos, sizeof(productos), 1, pf);
    fclose(pf);

    return 1;
}