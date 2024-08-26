#include "parcial.h"
// 38929303_Lezcano_Lorenzo

/**
Justificacion:
Utilizo una pila porque me piden que inserte unos datos en prod_a_vencer.txt pero en un orden inverso al que vienen en el arch de stock,
al usar LIFO obtengo esa secuencia de datos inverso
*/

void crear_pila(tPila *pp){
    *pp = NULL;
}

void vaciar_pila(tPila *pp){
    tNodo *elim;
    while(*pp){
        elim = *pp;
        *pp = elim->sig;
        free(elim->info);
        free(elim);
    }
}

int poner_en_pila(tPila *pp, const void *pd, unsigned tam){
    tNodo *nuevo;
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->sig = *pp;
    *pp = nuevo;
    return 1;
}

int sacar_de_pila(tPila *pp, void *pd, unsigned tam){
    tNodo *elim;
    if(*pp == NULL){
        return 0;
    }
    elim = *pp;
    *pp = elim->sig;
    memcpy(pd, elim->info, MIN(tam, elim->tamInfo));
    free(elim->info);
    free(elim);
    return 1;
}

int pila_vacia(const tPila *pp){
    if(*pp == NULL){
        return 1;
    }
    return 0;
}


int cargar_archivo_stock(const char *rutaStock){
    FILE *archivoStock;
    tProducto productos[] = {
        {"ABC100", "Tomate", 1, {25,04,2020}, 10},
        {"ABC100", "Tomate", 2, {12,07.2023}, 15},
        {"ABC100", "Tomate", 3, {15,06,2022}, 7},
        {"ABC100", "Tomate", 3, {26,06,2022}, 10},
        {"ABC200", "Arroz", 4, {20,01,2022}, 6},
        {"ABC200", "Arroz", 5, {04,02,2024}, 5},
        {"ABC300", "Manteca", 6, {14,02,2024}, 5},
    };

    archivoStock = fopen(rutaStock, "wb");
    if(archivoStock == NULL){
        printf("Error al abrir el archivo de stock\n");
        return -1;
    }

    fwrite(productos, sizeof(tProducto), 1, archivoStock);
    fclose(archivoStock);
    return 1;
}


void menu(const char *rutaStock, int mes, const char *rutaProdAVencer, const char *rutaProdOk, tPila *pp){
    printf("La Gran Oferta\n");
    printf("-----Menu----\n");
    int opcion;
    do{
        printf("1 - Generar archivos prod_ok y prod_a_vencer\n");
        printf("2 - Mostrar prod_ok\n");
        printf("3 - Mostrar prod_a_vencer\n");
        printf("4 - Ver el archivo de txt\n");
        printf("5 - Mostrar producto mas proximo a vencer\n");
        printf("6 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Opcion 1 - Generando archivos ...\n");
                vencimiento_n_meses(rutaStock, mes, rutaProdAVencer, rutaProdOk, pp);
                break;
            case 2:
                printf("Opcion 2 - Mostrando archivo stock.dat ...\n");
                mostrar_archivo(rutaStock, mostrar_producto);
                break;
            case 3:
                printf("Opcion 3 - Mostrando el archivo prodOk.dat ...\n");
                mostrar_archivo(rutaProdOk, mostrar_producto);
                break;
            case 4:
                printf("Opcion 4 - Abriendo el archivo de texto ...\n");
                mostrar_archivo_txt(rutaProdAVencer);
                break;
            case 5:
                printf("Opcion 5 - Producto mas proximo a vencer ...\n");
                // mostrar el prod
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion ingresada no valida, vuelva a elegir: ");
        }

    }while(opcion != 6);
}



int vencimiento_n_meses(const char *rutaStock, int mes, const char *rutaProdAVencer, const char *rutaProdOk, tPila *pp){
    tProducto prod;
    FILE *archivoStock;
    FILE *archivoProdAVencer;
    FILE *archivoProdOk;
    char codigoVen[6];
    char codigo[6];
    int nroLote;
    int vencimiento = 0;

    archivoStock = fopen(rutaStock, "rb");
    if(archivoStock == NULL){
        printf("Error al abrir el archivo de stock\n");
        return -1; // error de arch
    }

    archivoProdAVencer = fopen(rutaProdAVencer, "wt");
    if(archivoProdAVencer == NULL){
        printf("Error al abrir el archivo ProdAVencer\n");
        fclose(archivoStock);
        return -2; // error de arch
    }

    archivoProdOk = fopen(rutaProdOk, "wb");
    if(archivoProdOk == NULL){
        printf("Error al abrir el archivo de ProdOk\n");
        fclose(archivoStock);
        fclose(archivoProdAVencer);
        return -3; // error de arch
    }

    fread(&prod, sizeof(tProducto), 1, archivoStock);
    while(!feof(archivoStock)){
        strcpy(codigo, prod.codProd); // guardo el codigo para verificar dsp si ningun lote de ese cod vencio
        if(prod.fechaVencimiento.mes <= mes){ // si el producto esta a vencer
            strcpy(codigoVen, prod.codProd); // con esto se que productos estan x vencer
            nroLote = prod.lote;
            poner_en_pila(pp, &prod, sizeof(tProducto)); // meto en la pila el producto
            vencimiento = 1; // si esta en 1 no debe ir en el arch de prodOk
        }else{
            if(prod.codProd == codigoVen && nroLote != prod.lote){ // si el producto es el mismo, pero de distinto lote lo debo meter, si es el mismo lote no lo debo meter
                poner_en_pila(pp, &prod, sizeof(tProducto));// el producto es el mismo, debo meterlo
            }
        }
        fread(&prod, sizeof(tProducto), 1, archivoStock); //leo el sig registro de stock
        if(prod.codProd != codigo){ // aca me fijo si cambie de producto
            if(vencimiento == 0){ // con esto se si los lotes del producto estan o no vencidos
                fseek(archivoStock, -sizeof(tProducto), SEEK_CUR); // vuelvo al registro anterior para copiar los datos
                fread(&prod, sizeof(tProducto), 1, archivoStock); // leo el registro
                fwrite(&prod, sizeof(tProducto), 1, archivoProdOk); // guardo el registro en el archivo OK
                fseek(archivoStock, 0L, SEEK_CUR); // vuelvo al sentido de lectura original
                fread(&prod, sizeof(tProducto), 1, archivoStock); // leo el sig registro
            }
        }
    }

    while(!pila_vacia(pp)){
        sacar_de_pila(pp, &prod, sizeof(tProducto)); // saco de la pila para meterlo en el txt
        fprintf(archivoProdAVencer, "%s|%s|%d|%d/%d/%d|%d\n", prod.codProd, prod.descripcion, prod.lote, prod.fechaVencimiento.dia, prod.fechaVencimiento.mes, prod.fechaVencimiento.anio, prod.cantidad);
    }


    fclose(archivoStock);
    fclose(archivoProdAVencer);
    fclose(archivoProdOk);
    return 1;
}


int mostrar_archivo(const char *ruta, void(*mostrar)(void*)){
    FILE *pf;
    tProducto prod;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        printf("Error al mostrar el archivo!\n");
        return -1; // error de arch
    }

    fread(&prod, sizeof(tProducto), 1, pf);
    while(!feof(pf)){
        mostrar(&prod);
        fread(&prod, sizeof(tProducto), 1, pf);
    }

    fclose(pf);
    return 1;
}


void mostrar_producto(void *el){
    tProducto *prod = (tProducto*)el;
    printf("Codigo de Producto: %s\n", prod->codProd);
    printf("Descripcion: %s\n", prod->descripcion);
    printf("Numero de Lote: %d\n", prod->lote);
    printf("Fecha de vencimiento: %d/%d/%d\n", prod->fechaVencimiento.dia, prod->fechaVencimiento.mes, prod->fechaVencimiento.anio);
    printf("Cantidad en stock: %d\n", prod->cantidad);
    printf("\n\n");
}


int mostrar_archivo_txt(const char *rutaProdAVencer){
    FILE *pf;
    tProducto prod;

    pf = fopen(rutaProdAVencer, "rt");
    if(pf == NULL){
        printf("Error al abrir el archivo de txt!\n");
        return -1; // error de archivo
    }

    while(fscanf(pf, "%[^|\n]|%[^|\n]|%d|%d/%d/%d|%d\n", prod.codProd, prod.descripcion, &prod.lote, &prod.fechaVencimiento.dia, &prod.fechaVencimiento.mes, &prod.fechaVencimiento.anio, &prod.cantidad)!=EOF){
        printf("Codigo: %s\n", prod.codProd);
        printf("Descripcion: %s\n", prod.descripcion);
        printf("Numero de Lote: %d\n", prod.lote);
        printf("Fecha de vencimiento: %d%d%d\n", prod.fechaVencimiento.dia, prod.fechaVencimiento.mes, prod.fechaVencimiento.anio);
        printf("Cantidad de stock: %d\n", prod.cantidad);
        printf("\n");
    }

    fclose(pf);
    return 1;
}

