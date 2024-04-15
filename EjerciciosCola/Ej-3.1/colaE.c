#include "colaE.h"



void crear_cola(tCola *pc){
    pc->pri = 0;
    pc->ult = 0;
    pc->tamDisp = TAMCOLA;
}

void vaciar_cola(tCola *pc){
    pc->ult = pc->pri;
    pc->tamDisp = TAMCOLA;
}

int encolar(tCola *pc, const void *pd, unsigned tam){
    unsigned ini, fin;
    if(pc->tamDisp < tam + sizeof(unsigned)){
        return 0;//sin espacio
    }
    pc->tamDisp -= sizeof(unsigned) + tam;
    if((ini = MIN(sizeof(unsigned), TAMCOLA - pc->ult))!=0){
        memcpy(pc->cola + pc->ult, &tam, ini);
    }
    if((fin = sizeof(unsigned) - ini) !=0){
        memcpy(pc->cola, ((char*)&tam)+ini, fin);
    }
    pc->ult = fin ? fin : pc->ult + ini;
    if((ini = MIN(tam, TAMCOLA - pc->ult))!=0){
        memcpy(pc->cola + pc->ult, pd, ini);
    }
    if((fin = tam - ini)!=0){
        memcpy(pc->cola, ((char*)pd)+ini, fin);
    }
    pc->ult = fin ? fin : pc->ult + ini;
    return 1;
}

int desencolar(tCola *pc, void *pd, unsigned tam){
    unsigned tamInfo, ini, fin;
    if(pc->tamDisp == TAMCOLA){
        return 0;//cola vacia
    }
    if((ini = MIN(sizeof(unsigned), TAMCOLA - pc->pri))!=0){
        memcpy(&tamInfo, pc->cola + pc->pri, ini);
    }
    if((fin = sizeof(unsigned) - ini)!=0){
        memcpy(((char*)&tamInfo)+ini, pc->cola, fin);
    }
    pc->pri = fin ? fin : pc->pri + ini;
    pc->tamDisp += sizeof(unsigned) + tamInfo;
    tamInfo = MIN(tamInfo, tam);
    if((ini = MIN(tamInfo, TAMCOLA - pc->pri))!=0){
        memcpy(pd, pc->cola + pc->pri, ini);
    }
    if((fin = tamInfo - ini)!=0){
        memcpy(((char*)pd)+ini, pc->cola, fin);
    }
    pc->pri = fin ? fin : pc->pri + ini;
    return 1;
}

int ver_primero(const tCola *pc, void *pd, unsigned tam){
    unsigned tamInfo, ini, fin, pos = pc->pri;
    if(pc->tamDisp == TAMCOLA){
        return 0;//cola vacia
    }
    if((ini = MIN(sizeof(unsigned), TAMCOLA - pos))!=0){
        memcpy(&tamInfo, pc->cola + pos, ini);
    }
    if((fin = sizeof(unsigned)-ini)!=0){
        memcpy(((char*)&tamInfo)+ini, pc->cola, fin);
    }
    pos = fin ? fin : pos + ini;
    tamInfo = MIN(tamInfo, tam);
    if((ini = MIN(tamInfo, TAMCOLA - pos))!=0){
        memcpy(pd, pc->cola + pos, ini);
    }
    if((fin = tamInfo - ini)!=0){
        memcpy(((char*)pd) + ini, pc->cola, fin);
    }
    return 1;
}


int cola_vacia(const tCola *pc){
    if(pc->tamDisp == TAMCOLA){
        return 1;//cola vacia
    }
    return 0;//cola no vacia
}

int cola_llena(const tCola *pc, unsigned tam){
    if(pc->tamDisp < tam + sizeof(unsigned)){
        return 1;//cola llena
    }
    return 0;//cola no llena
}


