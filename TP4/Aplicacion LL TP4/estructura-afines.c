#include <stdlib.h>
#include <stdio.h>
#include "estructura-afines.h"
#include <string.h>

sJuego* videojuego_new()
{
    sJuego* pJuego;
    pJuego = malloc(sizeof(sJuego));
    if(pJuego==NULL)
    {
        printf("NO HAY ESPACIO EN MEMORIA PARA UN JUEGO");
        return 0;
    }
    return pJuego;
}
sJuego* videojuego_newParametros(int* idStr,char* nombreStr,int* horasJugablesStr,float* precioStr, int* stockStr)
{
    sJuego* pJuego;
    pJuego = videojuego_new();

    videojuego_setId(pJuego, *idStr);
    videojuego_setNombre(pJuego, nombreStr);
    videojuego_setHorasJugables(pJuego, *horasJugablesStr);
    videojuego_setPrecio(pJuego, *precioStr);
    videojuego_setStock(pJuego,*stockStr);
    return pJuego;
}

int videojuego_setStock(sJuego* juego,int stock)
{
    if(juego==NULL)
    {
        return 0;
    }
    juego->stock = stock;
    return 1;

}
int videojuego_getStock(sJuego* juego,int* stock)
{
    if(juego==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *stock = juego->stock;
    return 1;

}

int videojuego_setNombre(sJuego* juego,char* nombre)
{
    if(juego==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(juego->nombreVideoJuego, nombre);
    return 1;
}

int videojuego_getNombre(sJuego* juego,char* nombre)
{
    if(juego==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(nombre,juego->nombreVideoJuego);
    return 1;

}



int videojuego_setPrecio(sJuego* juego,float precio)
{
    if(juego==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    juego->precioVideoJuego = precio;
    return 1;

}
int videojuego_getPrecio(sJuego* juego,float* precio)
{
    if(juego==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *precio = juego->precioVideoJuego;
    return 1;
}

int videojuego_setId(sJuego* juego,int id)
{
    if(juego==NULL)
    {
        return 0;
    }
    juego->idVideoJuego = id;
    return 1;

}
int videojuego_getId(sJuego* juego,int* id)
{
    if(juego==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *id = juego->idVideoJuego;
    return 1;

}

int videojuego_setHorasJugables(sJuego* juego,int horasJugables)
{
    if(juego==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    juego->horasJugables = horasJugables;
    return 1;

}
int videojuego_getHorasJugables(sJuego* juego,int* horasJugables)
{
    if(juego==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *horasJugables = juego->horasJugables;
    return 1;
}


int videojuego_CompareByName(sJuego* juego1, sJuego* juego2)
{
    if(juego1== NULL || juego2 == NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE ALGUNO DE LOS PUNTEROS APUNTA A NULO");
        return 0;
    }
    return strcmp(juego1->nombreVideoJuego,juego2->nombreVideoJuego);
}

int videojuego_CompareById(sJuego* juego1, sJuego* juego2)
{
    if(juego1== NULL || juego2 == NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE ALGUNO DE LOS PUNTEROS APUNTA A NULO");
        return NULL;
    }
    if(juego1->idVideoJuego > juego2->idVideoJuego)
    {
        return 1;
    }
    else
    {
        if(juego1->idVideoJuego < juego2->idVideoJuego)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}



