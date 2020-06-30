#include <stdlib.h>
#include <stdio.h>
#include "estructura-afines.h"
#include <string.h>

//-----------------------------------CONSTRUCTORES-------------------------------------
sVuelo* generico_new()
{
    sVuelo* pGenerico;
    pGenerico = malloc(sizeof(sVuelo));
    if(pGenerico==NULL)
    {
        printf("NO HAY ESPACIO EN MEMORIA PARA UN JUEGO");
        return 0;
    }
    return pGenerico;
}

sPilotos* generico_new2()
{
    sPilotos* pGenerico;
    pGenerico = malloc(sizeof(sPilotos));
    if(pGenerico==NULL)
    {
        printf("NO HAY ESPACIO EN MEMORIA PARA UN JUEGO");
        return 0;
    }
    return pGenerico;
}

sVuelo* generico_newParametros(int* integro,int* integro2,int* integro3,char* cadena, char* cadena2,int* integro4,int* integro5,int* integro6)
{
    sVuelo* pGenerico;
    pGenerico = generico_new();

    generico_setIdVuelo(pGenerico, *integro);
    generico_setIdAvion(pGenerico, *integro2);
    generico_setIdPiloto(pGenerico, *integro3);
    generico_setFecha(pGenerico, cadena);
    generico_setDestino(pGenerico,cadena2);
    generico_setCantPasajeros(pGenerico,*integro4);
    generico_setHoraDespegue(pGenerico,*integro5);
    generico_setHoraLlegada(pGenerico,*integro6);
    return pGenerico;
}

sPilotos* generico_newParametros2(int integro,char* cadena)
{
    sPilotos* pGenerico;
    pGenerico = generico_new2();

    generico_setIdPiloto_sPilotos(pGenerico,integro);
    generico_setNombrePiloto_sPilotos(pGenerico, cadena);

    return pGenerico;
}

//_----------------------------------------------------------------------------

//---------------------SETTERS Y GETTERS------------------------------

/*

GETTERS Y SETTERS DE ESTRUCTURA SPILOTOS

*/

int generico_setNombrePiloto_sPilotos(sPilotos* Generico,char* cadena)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(Generico->nombrePiloto, cadena);
    return 1;
}

int generico_getNombrePiloto_sPilotos(sPilotos* Generico,char* cadena)
{
    if(Generico!=NULL)
    {
    strcpy(cadena,Generico->nombrePiloto);
    }
    return 1;

}

int generico_setIdPiloto_sPilotos(sPilotos* Generico,int integro)
{
    if(Generico!=NULL)
    {
         Generico->idPiloto = integro;
    }
    Generico->idPiloto = integro;
    return 1;

}
int generico_getIdPiloto_sPilotos(sPilotos* Generico,int* integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *integro = Generico->idPiloto;
    return 1;
}



/*

GETTERS Y SETTERS DE ESTRUCTURA SVUELO

*/
int generico_setIdVuelo(sVuelo* Generico,int integro)
{
    if(Generico==NULL)
    {
        return 0;
    }
    Generico->idVuelo = integro;
    return 1;

}
int generico_getIdVuelo(sVuelo* Generico,int* integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *integro= Generico->idVuelo;
    return 1;

}

int generico_setIdAvion(sVuelo* Generico,int integro)
{
    if(Generico==NULL)
    {
        return 0;
    }
    Generico->idAvion = integro;
    return 1;

}
int generico_getIdAvion(sVuelo* Generico,int* integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *integro= Generico->idAvion;
    return 1;

}



int generico_setIdPiloto(sVuelo* Generico,int integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    Generico->idPiloto= integro;
    return 1;

}
int generico_getIdPiloto(sVuelo* Generico,int* integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *integro = Generico->idPiloto;
    return 1;
}

int generico_setFecha(sVuelo* Generico,char* cadena)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(Generico->fecha,cadena);
    return 1;
}

int generico_getFecha(sVuelo* Generico,char* cadena)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(cadena,Generico->fecha);
    return 1;

}

int generico_setDestino(sVuelo* Generico,char* cadena)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(Generico->destino,cadena);
    return 1;
}

int generico_getDestino(sVuelo* Generico,char* cadena)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(cadena,Generico->destino);
    return 1;

}

int generico_setCantPasajeros(sVuelo* Generico,int integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    Generico->cantPasajeros= integro;
    return 1;

}
int generico_getCantPasajeros(sVuelo* Generico,int* integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *integro= Generico->cantPasajeros;
    return 1;
}

int generico_setHoraDespegue(sVuelo* Generico,int integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    Generico->horaDespegue= integro;
    return 1;

}
int generico_getHoraDespegue(sVuelo* Generico,int* integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *integro= Generico->horaDespegue;
    return 1;
}

int generico_getHoraLlegada(sVuelo* Generico,int* integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *integro= Generico->horaLlegada;
    return 1;
}

int generico_setHoraLlegada(sVuelo* Generico,int integro)
{
    if(Generico==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    Generico->horaLlegada= integro;
    return 1;

}

//-----------------------------------------------------------------------

//---------------------------FUNCIONES CRITERIO---------------------------------


int generico_CompareByName(void* e1, void* e2)
{
    sPilotos* Generico1 = (sPilotos*)e1;
    sPilotos* Generico2 = (sPilotos*)e2;
    if(Generico1== NULL || Generico2 == NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE ALGUNO DE LOS PUNTEROS APUNTA A NULO");
        return 0;
    }
    return strcmp(Generico1->nombrePiloto,Generico2->nombrePiloto);
}

int generico_CompareById(void* e1, void* e2)
{
    sVuelo* Generico1 = (sVuelo*)e1;
    sVuelo* Generico2 = (sVuelo*)e2;
    if(Generico1== NULL || Generico2 == NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE ALGUNO DE LOS PUNTEROS APUNTA A NULO");
        return NULL;
    }
    if(Generico1->idPiloto > Generico2->idPiloto)
    {
        return 1;
    }
    else
    {
        if(Generico1->idPiloto < Generico2->idPiloto)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int generico_countTotales(void* e1)
{
    sVuelo* vuelo;
    if(e1 != NULL)
    {
        vuelo = (void*)e1;
    }
    return vuelo->cantPasajeros;
}

int generico_countEspecifico(void* e1)
{
    sVuelo* vuelo;
    int acum=0;
    if(e1 != NULL)
    {
        vuelo = (void*)e1;
        if(strcmpi(vuelo->destino,"Irlanda")==0)
        {
            acum = vuelo->cantPasajeros;
        }
    }
    return acum;
}

int generico_filtroMenorATres(void*e1)
{
    int returnAux = 0;
    sVuelo* vuelo;
    int tiempoVuelo;
    if(e1 != NULL)
    {
        vuelo = (void*)e1;
        tiempoVuelo = vuelo->horaLlegada - vuelo->horaDespegue;
        if(tiempoVuelo < 3)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int generico_filtroAUnLugar(void* e1)
{
    int returnAux = 0;  // RETURN 0 ES PARA INCLUIR
    sVuelo* vuelo;
    if(e1 != NULL)
    {
        vuelo = (void*)e1;
        if(strcmpi(vuelo->destino,"Portugal")==0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int generico_filtroPorNombre(void* e1)
{
    int returnAux = 0;
    sVuelo* vuelo = (void*)e1;
    if(e1 != NULL)
    {
        if(vuelo->idPiloto != 1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int generico_filtroPorNombreElegido(void* e1,char* cadena)
{
    int returnAux = 0;
    char cadenaCopiada[50];
    sPilotos* piloto= (void*)e1;
    if(e1 != NULL)
    {
        generico_getNombrePiloto_sPilotos(piloto,cadenaCopiada);
        if(strcmp(cadenaCopiada,cadena)==0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

//------------------------------------------------------------------------------
