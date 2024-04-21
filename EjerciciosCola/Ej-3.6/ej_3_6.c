#include "ej_3_6.h"

#include "../../PilaDinamica/pilaDinamica.c"


int generar_archivos(const char *ruta, const char *ruta2, const char *ruta3, tPila *pp){

    FILE *datos, *datos1, *datos2;
    tProducto prod;
    int caracter;

    datos = fopen(ruta, "rb");
    if(datos == NULL){
        return -1;
    }
    datos1 = fopen(ruta2, "wb");
    if(datos1 == NULL){
        fclose(datos);
        return -1;
    }
    datos2 = fopen(ruta3, "wb");
    if(datos2 == NULL){
        fclose(datos);
        fclose(datos1);
        return -1;
    }

    fread(&prod, sizeof(tProducto), 1, datos); 
    while(!feof(datos)){
        printf("Leo producto: \n");
        mostrar_producto(&prod);
        printf("\n");
        caracter = ver_caracter(&prod);
        if( caracter == 1){
            if(!pila_llena(pp, sizeof(tProducto))){
                apilar(pp, &prod, sizeof(tProducto));
            }
            fwrite(&prod, sizeof(tProducto), 1, datos2);
            printf("Meti en el archivo datos2: \n");
            mostrar_producto(&prod);
        }else{
            printf("No entre\n");
        }
        fread(&prod, sizeof(tProducto), 1, datos);
        printf("\n");
    }

    fclose(datos);
    fclose(datos2);

    while(!pila_vacia(pp)){
        desapilar(pp, &prod, sizeof(tProducto));
        printf("Meti en el archivo datos1: \n");
        mostrar_producto(&prod);
        fwrite(&prod, sizeof(tProducto), 1, datos1);
    }

    fclose(datos1);

    return 1;
}


int ver_caracter(tProducto *prod){
    int i = 0;
    char cod[5];
    strcpy(cod, prod->codigo);
    while((cod[i] != '1' && cod[i] != '2' && cod[i] != '3' && cod[i] != '4' && cod[i] != '5' && cod[i] != '6' && cod[i] != '7' && cod[i] != '8' && cod[i] != '9' && cod[i] != '0') && (i < 5)){
        i++;
    }
    if(i == 5){
        return 0; //no encontro
    }
    return 1;// encontro
}


void mostrar_producto(tProducto *prod){
    printf("Codigo: %s\n", prod->codigo);
    printf("Descripcion: %s\n", prod->descripcion);
    printf("Proveedor: %s\n", prod->proveedor);
    printf("Fecha de compra: %d/%d/%d\n", prod->fCompra.dia, prod->fCompra.mes, prod->fCompra.anio);
    printf("Fecha de vencimiento: %d/%d/%d\n", prod->fVencimiento.dia, prod->fVencimiento.mes, prod->fVencimiento.anio);
    printf("Cantidad: %d\n", prod->cantidad);
    printf("Precio de compra: %.2f\n", prod->pCompra);
    printf("Precio de venta: %.2f\n", prod->pVenta);
}