#include "ej_2_6.h"
#include "../Ej-2.2/pila.c"

void ordenar_archivo_con_pilas(const char *ruta, tPila *pp1, tPila *pp2){
    FILE *pf;
    tProducto prod, prod1, prod2;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        return;
    }
    fread(&prod, sizeof(tProducto), 1, pf);
    while(!feof(pf)){
        //verifico si las pilas estan vacias
        if (!pila_vacia(pp1)) {
            ver_tope(pp1, &prod1.codigo, sizeof(char));
        } else {
            prod1.codigo[0] = '\0'; //pongo como primer caracter \0 fin de cadena para inicializar
        }
        if (!pila_vacia(pp2)) {
            ver_tope(pp2, &prod2.codigo, sizeof(char));
        } else {
            prod2.codigo[0] = '\0'; //pongo como primer caracter \0 fin de cadena para inicializar
        }

        if( strcmp(prod.codigo, prod1.codigo) > 0){ //si lo del archivo es mas grande que lo de la pila1
            apilar(pp1, &prod, sizeof(tProducto));
        }else{
            if( strcmp(prod.codigo, prod2.codigo) > 0){ //si lo del archivo es mas grande que lo de la pila2
                apilar(pp2, &prod, sizeof(tProducto));
            }else{ //si lo del archivo no es mas grande que lo que hay en ambas pilas
                printf("Error");
                if( strcmp(prod1.codigo, prod2.codigo) > 0){ //lo de la pila1 es mas grande que lo de la pila2
                    desapilar(pp1, &prod1, sizeof(tProducto));
                    apilar(pp2, &prod1, sizeof(tProducto));
                }else{//lo de la pila2 es mas grande que lo de la pila1
                    desapilar(pp2, &prod2, sizeof(tProducto));
                    apilar(pp1, &prod2, sizeof(tProducto));
                }
                fseek(pf, -sizeof(tProducto), SEEK_CUR);//regreso al registro leido para no saltearme el registro que habia leido recientemente
                fseek(pf, 0L, SEEK_CUR);//sigo el flujo normal de lectura
            }
        }
        fread(&prod, sizeof(tProducto), 1, pf);
    }
    fclose(pf);
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        return;
    }
    while(!pila_vacia(pp1) && !pila_vacia(pp2)){
        ver_tope(pp1, &prod1.codigo, sizeof(int));
        ver_tope(pp2, &prod2.codigo, sizeof(int));
        if( strcmp(prod1.codigo, prod2.codigo) > 0 ){
            desapilar(pp1, &prod1, sizeof(tProducto));
            fwrite(&prod1, sizeof(tProducto), 1, pf);
        }else{
            desapilar(pp2, &prod2, sizeof(tProducto));
            fwrite(&prod2, sizeof(tProducto), 1, pf);
        }
    }
    while(!pila_vacia(pp1)){
        desapilar(pp1, &prod1, sizeof(tProducto));
        fwrite(&prod1, sizeof(tProducto), 1, pf);
    }
    while(!pila_vacia(pp2)){
        desapilar(pp2, &prod2, sizeof(tProducto));
        fwrite(&prod2, sizeof(tProducto), 1, pf);
    }
    fclose(pf);
}

void mostrar_archivo(const char *ruta){
    FILE *pf;
    tProducto prod;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        return;
    }
    fread(&prod, sizeof(tProducto),1, pf);
    while(!feof(pf)){
        mostrar_producto(&prod);
        fread(&prod, sizeof(tProducto),1, pf);
    }
    fclose(pf);
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





