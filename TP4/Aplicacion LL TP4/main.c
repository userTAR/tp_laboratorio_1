#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controlador.h"
#include "estructura-afines.h"
#include "validaciones.h"
int main()
{
    LinkedList* juegosActivos = ll_newLinkedList();
    LinkedList* juegosEliminados = ll_newLinkedList();
    int choise;
    int control;
// LECTURA DE ARCHIVO DE JUEGOS ACTIVOS
    controller_cargaActivos(juegosActivos);
// LECTURA DE ARCHIVO DE JUEGOS ELIMINADOS
    controller_cargaEliminados(juegosEliminados);

    choise = menuOpciones();
    for(;;)
    {

        if(choise==0)
        {
            choise = obtenerNumero("ESTA SEGURO QUE DESEA SALIR DEL PROGRAMA?\n1.SI // 2. NO");
            if(choise==1) break;
        }
    switch(choise)
    {
    case 1:
        control = controller_addGame(juegosActivos);
        if(control == 1) printf("ADICION DE JUEGO: OK...");
        else printf("ADICION DEL JUEGO: FALLIDA");
        break;
    case 2:
        control = controller_editGame(juegosActivos);
        if(control == 1) printf("EDICION DEL JUEGO: OK...");
        else printf("EDICION DEL JUEGO: FALLIDA");
        break;
    case 3:
        control = controller_removeGame(juegosActivos);
        if(control == 1) printf("REMOCION DEL JUEGO: OK...");
        else printf("REMOCION DEL JUEGO: FALLIDA");
        break;
    case 4:
        control = controller_sellGame(juegosActivos);
        if(control == 1) printf("VENTA DEL JUEGO: OK...");
        else printf("VENTA DEL JUEGO: FALLIDA");
        break;
    case 5:
        // LISTADO DE ACTIVOS
        control = controller_ListGame(juegosActivos);
        if(control == 1) printf("LISTADO DE JUEGOS: OK...");
        else printf("LISTADO DE JUEGOS: FALLIDO");
        break;
    case 6:
        // LISTADO DE ELIMINADOS
        control = controller_ListGame(juegosEliminados);
        if(control == 1) printf("LISTADO DE JUEGOS: OK...");
        else printf("LISTADO DE JUEGOS: FALLIDO");
        break;
    case 7:
        control = controller_sortGame(juegosActivos);
        if(control == 1) printf("ORDENAMIENTO DE JUEGOS: OK...");
        else printf("ORDENAMIENTO DE JUEGOS: FALLIDO");
        break;
    }
    choise = reCall();
    }
//TERMINA LA ITERACION

//GUARDADO DE LISTA DE JUEGOS ACTIVOS EN PRINCIPAL Y BACKUP
    control = controller_saveAsText("juegos_activos.csv",juegosActivos);
    if(control == 1)
    {
        printf ("GUARDADO DE LISTA DE JUEGOS ACTIVOS: OK...\n");
    }
    else
    {
        printf("GUARDADO DE LISTA DE JUEGOS ACTIVOS, FALLIDO\n");
    }
    control = controller_saveAsBinary("juegos_activos_back.bin",juegosActivos);
    if(control == 1)
    {
        printf("GUARDADO DE LISTA DE JUEGOS ACTIVOS EN BACKUP: OK...\n");
    }
    else
    {
        printf("GUARDADO DE LISTA DE JUEGOS ACTIVOS EN BACKUP, FALLIDO\n");
    }
// GUARDADO DE LISTA DE JUEGOS ELIMINADOS EN PRINCIPAL Y BACKUP
    control = controller_saveAsBinary("juegos_eliminados.csv",juegosEliminados);
    if(control == 1)
    {
        printf ("GUARDADO DE LISTA DE JUEGOS ACTIVOS: OK...\n");
    }
    else
    {
        printf("GUARDADO DE LISTA DE JUEGOS ACTIVOS, FALLIDO\n");
    }
    control = controller_saveAsBinary("juegos_eliminados_back.bin",juegosEliminados);
    if(control == 1)
    {
        printf("GUARDADO DE LISTA DE JUEGOS ACTIVOS EN BACKUP: OK...\n");
    }
    else
    {
        printf("GUARDADO DE LISTA DE JUEGOS ACTIVOS EN BACKUP, FALLIDO\n");
    }

//ELIMINA LAS LL ANTES DE CERRAR EL PROGRAMA.
    ll_deleteLinkedList(juegosActivos);
    ll_deleteLinkedList(juegosEliminados);
}




















// AGUANTE GARDEL.
