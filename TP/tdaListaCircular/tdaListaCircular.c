#include "tdaListaCircular.h"


void crearLista(tLista *pl)
{
    *pl = NULL;
}

int Insertar(tLista *pl, const void *pd, unsigned cantBytes)
{
    tNodo *nue;
    nue =  malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;
  
    nue->info = malloc(cantBytes);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info,pd,cantBytes);
    nue->tamInfo = cantBytes;


    if(*pl == NULL)
        *pl = nue;
    else
        nue->ste = (*pl)->ste;

    (*pl)->ste = nue;

    return OK;

}

int Sacar(tLista* pl, void *pd, unsigned cantBytes)
{
    tNodo *elim;
    if(!*pl)
        return VACIA; 

    elim = *pl;
    *pl = elim->ste;
    if(*pl == elim)
        *pl = NULL;

    memcpy(pd,elim->info,MIN(cantBytes,elim->tamInfo));
    free(elim->info);
    free(elim);

    return OK;


}

int VerPrimero(const tLista* pl, void *pd, unsigned cantBytes)
{
    if(!*pl)
        return VACIA; ///Vacia

    memcpy(pd,(*pl)->info,MIN(cantBytes,(*pl)->tamInfo));

    return OK;


}

int listaVacia(const tLista* pl, void *pd, unsigned cantBytes)
{
    if(!*pl)
        return 1;
  
    return 0;
}

int listaLlena(const tLista* pl, void *pd, unsigned cantBytes)
{
    return 0; //no me acuerdo si era asi la mas simple
}

void Map(tLista *pl,void (*accion)(const void*))
{
    tNodo *inicio;
    if(!*pl)
        return;
    inicio = *pl;
    do
    {
        accion((*pl)->info);
        pl = &(*pl)->ste;
    }while(*pl != inicio);

    return;
}


int InsertarLuegodeN(tLista *pl, const void *pd, unsigned cantBytes,int n)
{
    tNodo *nue;
    if(!*pl)
        return Insertar(pl,pd,cantBytes);

    while(*pl && --n)
        pl = &(*pl)->ste;

    nue =  malloc(sizeof(tNodo));

    if(!nue)
        return SIN_MEM;

    nue->info = malloc(cantBytes);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEM;
    }
    memcpy(nue->info,pd,cantBytes);
    nue->tamInfo = cantBytes;
    nue->ste = (*pl)->ste;

    (*pl)->ste = nue;

    return OK;

}



void vaciarLista(tLista *pl)
{
    tNodo *elim;
    while(*pl)
    {
        elim = (*pl)->ste;
        if(elim == *pl)
            *pl = NULL;
        else
            (*pl)->ste = elim->ste;
        free(elim->info);
        free(elim);
    }
}

