#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "estructura-afines.h"
#include "guardado.h"
#include "validaciones.h"
#include "controlador.h"



//----------------------------LECTURA------------------------
int controller_Rivero_loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    int returnAux = 0;
    ll_clear(pArrayList);
    pFile = fopen(path,"r");

    if(pArrayList!= NULL)
    {
        if(pFile != NULL)
        {
            returnAux =1;
            parser_FromText(pFile,pArrayList);
        }

    }
    fclose(pFile);
    return returnAux;
}

int controller_Rivero_loadFromText_Pilotos(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    int returnAux = 0;
    ll_clear(pArrayList);
    pFile = fopen(path,"r");

    if(pArrayList!= NULL)
    {
        if(pFile != NULL)
        {
            returnAux =1;
            parser_FromText_Pilotos(pFile,pArrayList);
        }

    }
    fclose(pFile);
    return returnAux;
}

int controller_Rivero_loadFromBinary(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    ll_clear(pArrayList);

    if(pArrayList != NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile != NULL)
        {
            parser_FromBinary(pFile,pArrayList);
            fclose(pFile);
            return 1;
        }
    }
        printf("EL PUNTERO A LINKEDLIST APUNTA A NULO, ERROR...");
        return 0;
}

//----------------------------------------------------------------------
int controller_Rivero_ListGenerico(LinkedList* pArrayList, LinkedList* this)
{
    sVuelo* pGenerico;
    sPilotos* piloto;
    int i;
    int j;
    int size1;
    int size2;
    int idVuelo;
    int idAvion;
    char nombrePiloto[21];
    char fecha[21];
    char destino[21];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    if(pArrayList != NULL && this!=NULL)
    {
        printf("IDVUELO-------IDAVION----NOMBREPILOTO-------FECHA--------DESTINO-------CANTPASAJEROS-------HORADESPEGUE------HORALLEGADA\n");
        size1=ll_len(pArrayList);
        size2=ll_len(this);
        for(i=0;i<size1;i++)
        {
            pGenerico = ll_get(pArrayList,i);
            generico_getIdVuelo(pGenerico,&idVuelo);
            generico_getIdAvion(pGenerico,&idAvion);
            for(j=0;j<size2;j++)
            {
                piloto = (sPilotos*)ll_get(this,j);
                if(pGenerico->idPiloto == piloto->idPiloto)
                {
                    generico_getNombrePiloto_sPilotos(piloto,nombrePiloto);
                }
            }
            generico_getFecha(pGenerico,fecha);
            generico_getDestino(pGenerico,destino);
            generico_getCantPasajeros(pGenerico,&cantPasajeros);
            generico_getHoraDespegue(pGenerico,&horaDespegue);
            generico_getHoraLlegada(pGenerico,&horaLlegada);
            printf("%5d %12d %18s %14s %16s %12d %15d %16d\n",idVuelo,idAvion,nombrePiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        }
    }
    return 1;
}

int controller_Rivero_ListPilotos(LinkedList* LLpilotos)
{
    sPilotos* auxPilotos;
    int returnAux = -1;
    int idPiloto;
    char nombrePiloto[21];
    int size;
    int i;

    if(LLpilotos != NULL)
    {
        returnAux = 0;
        printf("IDPILOTO-------NOMBREPILOTO\n");
        size=ll_len(LLpilotos);
        for(i=0;i<size;i++)
        {
            auxPilotos = generico_new2();
            auxPilotos == (sPilotos*)ll_get(LLpilotos,i);
            generico_getIdPiloto_sPilotos(auxPilotos,&idPiloto);
            generico_getNombrePiloto_sPilotos(auxPilotos,nombrePiloto);
            printf("%d %s \n",idPiloto,nombrePiloto);
        }
    }
    return returnAux;
}

LinkedList* Controller_Rivero_crear_hardCodeoPilotos()
{
    LinkedList* llHardcodeada;
    sPilotos* pilotos;

    llHardcodeada = ll_newLinkedList();
    pilotos= generico_newParametros2(1,"Tomas Rivero");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(2,"Lionel Messi");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(3,"Cristiano Ronaldo");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(4,"Carlos Gardel");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(5,"Carlos Sainz");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(6,"Muhhamed Ali");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(7,"Juan Antonio");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(8,"Lala Pou");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(9,"Pocoyo Altamiro");
    ll_add(llHardcodeada,pilotos);
    pilotos= generico_newParametros2(10,"Juan Ruso");
    ll_add(llHardcodeada,pilotos);

    return llHardcodeada;
}

//-------------------------GUARDADO-------------------------------------------
int controller_Rivero_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    sVuelo* pGenerico;
    int i;
    int size;
    int idVuelo;
    int idPiloto;
    char fecha[21];
    char destino[30];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

    if(pArrayList != NULL)
    {
    pFile = fopen(path,"w");
    if(pFile == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        return 0;
    }
    else
    {
        size = ll_len(pArrayList);
        fprintf(pFile,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
        for(i=0;i<size;i++)
        {
            pGenerico = ll_get(pArrayList,i);
            generico_getIdVuelo(pGenerico,&idVuelo);
            generico_getIdPiloto(pGenerico,&idPiloto);
            generico_getFecha(pGenerico,fecha);
            generico_getDestino(pGenerico,destino);
            generico_getCantPasajeros(pGenerico,&cantPasajeros);
            generico_getHoraDespegue(pGenerico,&horaDespegue);
            generico_getHoraLlegada(pGenerico,&horaLlegada);
            fprintf(pFile,"%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        }
    }
    fclose(pFile);
    return 1;
    }
    else printf("DIRECCION DE MEMORIA DE LINKEDLIST INCORRECTA");
    return 0;
}


int controller_Rivero_saveAsBinary(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    sVuelo* pGenerico;
    int size;
    int i;

    if(pArrayList != NULL)
    {
    pFile = fopen(path,"wb");
    if(pFile == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        return 0;
    }
    else
    {
        size = ll_len(pArrayList);
        for(i=0;i<size;i++)
        {
                pGenerico= (sVuelo*)ll_get(pArrayList,i);
                fwrite(pGenerico,sizeof(sVuelo),1,pFile);
        }
    }
    fclose(pFile);
    return 1;
    }
    else printf("DIRECCION DE MEMORIA DE LINKEDLIST INCORRECTA");
    return 0;

}
//--------------------------------------------------------------------------------------------------
int controller_Rivero_PasajerosTotales(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = 0;
        returnAux = ll_count(this,generico_countTotales);
    }
    return returnAux;
}

int controller_Rivero_PasajerosIrlanda(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = 0;
        returnAux = ll_count(this,generico_countEspecifico);

    }
    return returnAux;
}

int controller_Rivero_VuelosCortos(LinkedList* this)
{
    int returnAux = -1;
   LinkedList* vuelosCortos;

    if(this!=NULL)
    {
        vuelosCortos = ll_newLinkedList();
        returnAux = 1;
        vuelosCortos = ll_filter(this,generico_filtroMenorATres);
        controller_Rivero_saveAsText("vuelos_Cortos.csv",vuelosCortos);

    }
    return returnAux;
}

int controller_Rivero_VuelosPortugal(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    LinkedList* vuelosPortugal;

    if(this!=NULL&& this2 != NULL)
    {
        vuelosPortugal = ll_newLinkedList();
        returnAux = 0;
        vuelosPortugal = ll_filter(this,generico_filtroAUnLugar);
        controller_Rivero_ListGenerico(vuelosPortugal,this2);
    }
    return returnAux;
}

int controller_Rivero_FiltrarLifeson(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    LinkedList* vuelosSinLifeson;

    if(this!=NULL && this2 != NULL)
    {
        vuelosSinLifeson = ll_newLinkedList();
        returnAux = 0;
        vuelosSinLifeson = ll_filter(this,generico_filtroPorNombre);
        controller_Rivero_ListGenerico(vuelosSinLifeson,this2);
    }
    return returnAux;
}

int controller_Rivero_FiltrarPorNombreElegido(LinkedList* this, LinkedList* this2)
{
    int returAux = -1;
    LinkedList* vuelosPorNombre;
    char nombreBuscado[50];

    if(this!=NULL && this2 != NULL)
    {
        returAux= 0;
        vuelosPorNombre = ll_newLinkedList();
        controller_Rivero_ListPilotos(this2);
        obtenerCadena("INGRESE EL NOMBRE DEL PILOTO QUE BUSCA",nombreBuscado);
        vuelosPorNombre = ll_filter_Parametro(this2,generico_filtroPorNombreElegido,nombreBuscado);
        controller_Rivero_ListPilotos(vuelosPorNombre);
        controller_Rivero_saveAsText("vuelo_por_nombre.csv",vuelosPorNombre);
    }
    return returAux;
}
