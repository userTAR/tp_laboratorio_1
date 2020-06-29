#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "estructura-afines.h"
#include "guardado.h"
#include "validaciones.h"
#include "controlador.h"



//codigo del id incrementado en 1 respecto del id mas grande de la lista de empleados.
int controller_setId(LinkedList* pArrayListJuegos)
{
    sJuego* pJuego;
    int size;
    int i;
    int mayor;
    int idObtenido;


    size = ll_len(pArrayListJuegos);
    if(size == 0)
    {
        return size;
    }
    for(i=0;i<size;i++)
    {
        pJuego = ll_get(pArrayListJuegos,i);
        videojuego_getId(pJuego,&idObtenido);
        if(i==0 || idObtenido>mayor)
        {
            mayor = idObtenido;
        }

    }
    return (mayor+1);
}

void controller_cargaActivos(LinkedList* pArrayListJuegos)
{
    int control;
    control = controller_loadFromText("juegos_activos.csv", pArrayListJuegos);
    if(control == 1)
    {
        printf("CARGA DE ARCHIVO PRINCIPAL DE JUEGOS ACTIVOS: OK...\n");
    }
    else
    {
        printf("ERROR EN LA CARGA DEL ARCHIVO PRINCIPAL DE JUEGOS ACTIVOS,SE INTETARA ABRIR EL BACKUP\n");
        control = controller_loadFromBinary("juegos_activos_back.bin",pArrayListJuegos);
        if(control == 1)
        {
            printf("CARGA DE DESDE BACKUP: OK...\n");
        }
        else
        {
            printf("ERROR EN LA CARGA DEL ARCHIVO BACKUP DE JUEGOS ACTIVOS\n\n");
        }
    }
}

void controller_cargaEliminados(LinkedList* pArrayListJuegos)
{
    int control;
    control = controller_loadFromText("juegos_eliminados.csv", pArrayListJuegos);
    if(control == 1)
    {
        printf("CARGA DE ARCHIVO DE JUEGOS ELIMINADOS: OK...\n\n");
    }
    else
    {
        printf("ERROR EN LA CARGA DEL ARCHIVO PRINCIPAL DE JUEGOS ELIMINADOS,SE INTETARA ABRIR EL BACKUP\n");
        control = controller_loadFromBinary("juegos_eliminados_back.bin",pArrayListJuegos);
        if(control == 1)
        {
            printf("CARGA DESDE BACKUP: OK...\n");
        }
        else
        {
            printf("ERROR EN LA CARGA DEL ARCHIVO BACKUP DE JUEGOS ELIMINADOS\n\n");
        }
    }
}
/*
Este archivo es el encargado de abrir el file y luego se llama a la funcion
parser text para guardar los datos en un empleado y luego en la linkedlist
*/
int controller_loadFromText(char* path, LinkedList* pArrayListJuegos)
{
    FILE* pFile;
    ll_clear(pArrayListJuegos);
    pFile = fopen(path,"r");

    if(pArrayListJuegos!= NULL)
    {
        if(pFile == NULL)
        {
            printf("EL ARCHIVO AUN NO EXISTE\n");
            return 0;
        }
        parser_JuegoFromText(pFile,pArrayListJuegos);
    }
    else
    {
        printf("EL PUNTERO A LINKEDLIST APUNTA A NULO, ERROR...");
        return 0;
    }
    fclose(pFile);
    return 1;
}

/*
Este archivo es el encargado de abrir el file y luego se llama a la funcion
parser binario para guardar los datos en un empleado y luego en la linkedlist
*/
int controller_loadFromBinary(char* path, LinkedList* pArrayListJuegos)
{
    FILE* pFile;
    ll_clear(pArrayListJuegos);
    pFile = fopen(path,"rb");

    if(pArrayListJuegos != NULL)
    {
        if(pFile == NULL)
        {
            printf("EL ARCHIVO AUN NO EXISTE\n");
            return 0;
        }
        parser_JuegoFromBinary(pFile,pArrayListJuegos);
        fclose(pFile);
        return 1;
    }
    else
    {
        printf("EL PUNTERO A LINKEDLIST APUNTA A NULO, ERROR...");
        return 0;
    }
}


int controller_addGame(LinkedList* pArrayListJuegos)
{
    sJuego* pJuego;
    char nombre[20];
    int horasJugables;
    float precio;
    int stock;
    int id;
    int dev;

    pJuego = videojuego_new();
    if(pJuego == NULL)
    {
        printf("NO EXISTE ESPACIO EN MEMORIA PARA ALMACENAR UN JUEGO");
    }
    else
    {
        do
        {
            dev = obtenerCadena("INGRESE EL NOMBRE DEL NUEVO JUEGO", nombre);
        }while(dev==0);
        horasJugables = obtenerNumero("INGRESE LA CANTIDAD DE HORAS DE JUGABILIDAD DEL VIDEOJUEGO");
        horasJugables= validacionDeNumero(horasJugables,1,1000000);
        precio = obtenerFlotante("INGRESE EL PRECIO DEL JUEGO");
        stock = obtenerNumero("INGRESE EL STOCK TOTAL DEL JUEGO");
        stock = validacionDeNumero(stock,1,1000);
        id = controller_setId(pArrayListJuegos);
        videojuego_setNombre(pJuego,nombre);
        videojuego_setHorasJugables(pJuego,horasJugables);
        videojuego_setPrecio(pJuego,precio);
        videojuego_setStock(pJuego,stock);
        videojuego_setId(pJuego,id);
        ll_add(pArrayListJuegos,pJuego);
    }
    return 1;
}

int controller_sellGame(LinkedList*pArrayListJuegos)
{
    int idBuscado;
    int returnAux = -1;
    int stock;
    sJuego* pJuego;
    if(pArrayListJuegos != NULL)
    {
        returnAux = 0;
        controller_ListGame(pArrayListJuegos);
        idBuscado = obtenerNumero("INGRESE EL ID DEL JUEGO QUE QUIERE VENDER");
        controller_getIndexById(pArrayListJuegos,idBuscado);
        pJuego = (sJuego*)ll_get(pArrayListJuegos,idBuscado);
        videojuego_getStock(pJuego,&stock);
        stock--;
        videojuego_setStock(pJuego,stock);
    }
    return returnAux;
}

int controller_getIndexById(LinkedList* pArrayListJuegos,int idBuscado)
{
    sJuego* pJuego;
    int size;
    int i;
    int idObtenido;

    size = ll_len(pArrayListJuegos);
    for(i=0;i<size;i++)
    {
        pJuego = ll_get(pArrayListJuegos,i);
        videojuego_getId(pJuego,&idObtenido);
        if(idObtenido == idBuscado)
        {
            return i;
        }

    }
    return -1;
}

int controller_editGame(LinkedList* pArrayListJuegos)
{
    sJuego* pJuego;
    int id;
    int index = -1;
    int keepEditting = 1;
    int choise;
    int nuevoNumero;
    char nuevaCadena[21];

    controller_ListGame(pArrayListJuegos);
    while(index == -1)
    {
        id = obtenerNumero("\nINGRESE EL ID DEL JUEGO QUE QUIERA MODIFICAR");
        index = controller_getIndexById(pArrayListJuegos,id);
        if(index == -1)
        {
            printf("EL ID INGRESADO NO EXISTE\n");
            index = -1;
        }
        else
            break;
    }
    pJuego = ll_get(pArrayListJuegos,index);
    while(keepEditting == 1)
    {
        choise = obtenerNumero("MODIFICAR\n1.NOMBRE\n2.HORAS DE JUGABILIDAD\n3.PRECIO\n4.STOCK\n ELECCION");
        switch(choise)
        {
            case 1:
                obtenerCadena("INGRESE EL NUEVO NOMBRE DEL JUEGO", nuevaCadena);
                videojuego_setNombre(pJuego,nuevaCadena);
                break;
            case 2:
                nuevoNumero = obtenerNumero("INGRESE LA NUEVA CANTIDAD DE HORAS TRABAJADAS POR EL EMPLEADO");
                videojuego_setHorasJugables(pJuego,nuevoNumero);
                break;
            case 3:
                nuevoNumero = obtenerNumero("INGRESE EL PRECIO DEL JUEGO");
                nuevoNumero = validacionDeNumero(nuevoNumero,1,8000);
                videojuego_setPrecio(pJuego,nuevoNumero);
                break;
            case 4:
                nuevoNumero = obtenerNumero("INGRESE EL NUEVO STOCK DEL JUEGO");
                nuevoNumero = validacionDeNumero(nuevoNumero,1,10000);
                videojuego_setStock(pJuego,nuevoNumero);
                break;
        }
        keepEditting = obtenerNumero("DESEA MODIFICAR OTRA CAMPO DEL JUEGO?\n1.SI//2.NO");
    }
    return 1;
}


int controller_removeGame(LinkedList* pArrayListJuegos)
{
    int id;
    int index = -1;
    int keepErasing = 1;

    controller_ListGame(pArrayListJuegos);
    while(keepErasing == 1)
    {
        while(index == -1)
        {
            id = obtenerNumero("INGRESE EL ID DEL JUEGO QUE QUIERA BORRAR");
            index = controller_getIndexById(pArrayListJuegos,id);
            if(index == -1)
            {
                printf("EL ID INGRESADO NO EXISTE\n");
            }
            else
                continue;
        }
        ll_remove(pArrayListJuegos,index);
        keepErasing = obtenerNumero("DESEA ELIMINAR OTRO EMPLEADO?\n1.SI//2.NO");
        if(keepErasing==1)
        {
            index = -1;
        }
        else
            break;
    }
    return 1;
}


int controller_ListGame(LinkedList* pArrayListJuegos)
{
    sJuego* pJuego;
    int i;
    int size;
    int id;
    char nombre[21];
    int horas;
    float precio;
    int stock;

    printf("ID-------NOMBRE-------HORAS JUGABLES--------PRECIO-------STOCK\n");
    size=ll_len(pArrayListJuegos);
    for(i=0;i<size;i++)
    {
        pJuego = ll_get(pArrayListJuegos,i);
        videojuego_getId(pJuego,&id);
        videojuego_getNombre(pJuego,nombre);
        videojuego_getHorasJugables(pJuego,&horas);
        videojuego_getPrecio(pJuego,&precio);
        videojuego_getStock(pJuego,&stock);
        printf("%d %12s %8d %10f %8d\n",id,nombre,horas,precio,stock);
    }
    return 1;
}


int controller_sortGame(LinkedList* pArrayListJuegos)
{
    int choise;
    int upOrDown;
    choise = obtenerNumero("-MENU DE ORDENAMIENTO-\n1.ORDENAR POR NOMBRE//2.ORDENAR POR ID\n ELECCION");
    choise = validacionDeNumero(choise,1,2);
    upOrDown = obtenerNumero("0.ORDENAR DE FORMA DESCENDENTE//1.ORDENAR DE FORMA ASCENDENTE\n ELECCION");
    upOrDown = validacionDeNumero(upOrDown,0,1);
    switch(choise)
    {
        case 1:
            ll_sort(pArrayListJuegos,videojuego_CompareByName,upOrDown);
            break;
        case 2:
            ll_sort(pArrayListJuegos,videojuego_CompareById,upOrDown);
            break;
    }
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayListJuegos)
{
    FILE* pFile;
    sJuego* auxJuego;
    int i;
    int size;
    char nombre[21];
    int id;
    int horas;
    float precio;
    int stock;

    if(pArrayListJuegos != NULL)
    {
    pFile = fopen(path,"w");
    if(pFile == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        return 0;
    }
    else
    {
        size = ll_len(pArrayListJuegos);
        fprintf(pFile,"id,nombre,horasjugables,precio,stock\n");
        for(i=0;i<size;i++)
        {
                auxJuego = (sJuego*)ll_get(pArrayListJuegos,i);
                videojuego_getId(auxJuego, &id);
                videojuego_getNombre(auxJuego,nombre);
                videojuego_getHorasJugables(auxJuego,&horas);
                videojuego_getPrecio(auxJuego, &precio);
                videojuego_getStock(auxJuego, &stock);
                fprintf(pFile,"%d,%s,%d,%f,%d\n",id,nombre,horas,precio,stock);
        }
    }
    fclose(pFile);
    return 1;
    }
    else printf("DIRECCION DE MEMORIA DE LINKEDLIST INCORRECTA");
    return 0;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListJuegos)
{
    FILE* pFile;
    sJuego* pJuego;
    int size;
    int i;

    if(pArrayListJuegos != NULL)
    {
    pFile = fopen(path,"wb");
    if(pFile == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        return 0;
    }
    else
    {
        size = ll_len(pArrayListJuegos);
        for(i=0;i<size;i++)
        {
                pJuego= (sJuego*)ll_get(pArrayListJuegos,i);
                fwrite(pJuego,sizeof(sJuego),1,pFile);
        }
    }
    fclose(pFile);
    return 1;
    }
    else printf("DIRECCION DE MEMORIA DE LINKEDLIST INCORRECTA");
    return 0;

}

