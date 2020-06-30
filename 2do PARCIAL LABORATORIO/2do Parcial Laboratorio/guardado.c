#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "estructura-afines.h"
#include "guardado.h"

/*
La funcion lee el archivo de texto y lo guarda en un empleado y el empleado lo agrega a linked list.
*/
int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    sVuelo* pGenerico;
    char idVuelo[21];
    char idPiloto[21];
    char idAvion[21];
    char fecha[21];
    char destino[21];
    char cantPasajeros[21];
    char horaDespegue[21];
    char horaLlegada[21];
    int idVueloNum;
    int idAvionNum;
    int idPilotoNum;
    int cantPasajerosNum;
    int horaDespegueNum;
    int horaLlegadaNum;
    char cabecera[128];

    fscanf(pFile,"%[^\n]\n", cabecera);
    while(!feof(pFile))
    {
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada); //hay error
    idVueloNum = atoi(idVuelo);
    idAvionNum = atoi(idAvion);
    idPilotoNum= atoi(idPiloto);
    cantPasajerosNum= atoi(cantPasajeros);
    horaDespegueNum= atoi(horaDespegue);
    horaLlegadaNum= atoi(horaLlegada);
    pGenerico = generico_newParametros(&idVueloNum,&idAvionNum,&idPilotoNum,fecha,destino,&cantPasajerosNum,&horaDespegueNum,&horaLlegadaNum);
    ll_add(pArrayList,pGenerico);
    }
    return 1;
}
//lector de archivo binario
int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    sVuelo* pGenerico;
    int devFread;

    while(!feof(pFile))
    {
        pGenerico = generico_new();
        devFread = fread(pGenerico,sizeof(sVuelo),1,pFile);
        if(devFread != 1)
        {
            break;
        }
        ll_add(pArrayList,pGenerico);

    }
    return 1;
}


int parser_FromText_Pilotos(FILE* pFile, LinkedList* pArrayList)
{
    sPilotos* pGenerico;
    char cabecera[128];
    char idPiloto[21];
    char nombrePiloto[21];
    int idPilotoNum;


    fscanf(pFile,"%[^\n]\n",cabecera);
    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^\n]\n",idPiloto,nombrePiloto);
        idPilotoNum = atoi(idPiloto);
        pGenerico = generico_new2();
        generico_setIdPiloto_sPilotos(pGenerico,idPilotoNum);
        generico_setNombrePiloto_sPilotos(pGenerico,nombrePiloto);
        ll_add(pArrayList,pGenerico);
    }
    return 1;
}

//solo queda revisar tema cabecera a las 18:25.
