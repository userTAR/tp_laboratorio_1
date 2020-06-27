#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "estructura-afines.h"
#include "guardado.h"

/*
La funcion lee el archivo de texto y lo guarda en un empleado y el empleado lo agrega a linked list.
*/
int parser_JuegoFromText(FILE* pFile, LinkedList* pArrayListJuegos)
{
    sJuego* juego;
    char id[21];
    char nombre[21];
    char horas[21];
    char precio[21];
    char stock[21];
    int idNum;
    int horasNum;
    float precioNum;
    int stockNum;
    //fseek(pFile,33,SEEK_SET); // REVISAR EL FSEEK DEBIDO A CABECERA DISTINTA
    while(!feof(pFile))
    {
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,precio,stock); //hay error
    idNum = atoi(id);
    horasNum = atoi(horas);
    precioNum = atof(precio);
    stockNum = atoi(stock);
    juego = videojuego_newParametros(&idNum,nombre,&horasNum,&precioNum,&stockNum);
    ll_add(pArrayListJuegos,juego);
    }
    return 1;
}
//lector de archivo binario
int parser_JuegoFromBinary(FILE* pFile, LinkedList* pArrayListJuegos)
{
    sJuego* juego;
    int devFread;

    //fseek(pFile,33,SEEK_SET); // REVISAR EL FSEEK DEBIDO A CABECERA DISTINTA
    while(!feof(pFile))
    {
        juego = videojuego_new();
        devFread = fread(juego,sizeof(juego),1,pFile);
        if(devFread != 1)
        {
            break;
        }
        ll_add(pArrayListJuegos,juego);

    }
    return 1;
}


//solo queda revisar tema cabecera a las 18:25.
