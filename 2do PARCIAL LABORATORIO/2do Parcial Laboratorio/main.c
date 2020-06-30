#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "controlador.h"
#include "estructura-afines.h"
#include "validaciones.h"


/*
1	Cargar archivo: Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del mismo.
2	Imprimir vuelos: Se imprimirá por pantalla la tabla con los datos de los vuelos indicando el nombre del piloto (no el número)
3	Cantidad de pasajeros: Cantidad de pasajeros totales
4	Cantidad de pasajeros  a Irlanda: cantidad de pasajeros a irlanda.
5	Filtrar vuelos cortos: Generar un archivo de iguales características que el original, con los datos de los vuelos cuya duración sea inferior a 3 horas.
6	Listar vuelos a Portugal: Generar un listado que solo incluya los vuelos con destino a Portugal.
7	Filtrar a Alex Lifeson: Necesitamos un listado de vuelos que no incluya al chofer Alex Lifeson
Salir.
*/

int main()
{
    LinkedList* pilotos;
    LinkedList* vuelos;
    int choise;
    int control;
   /*char path[128];
   printf("INGRESE EL NOMBRE DEL ARCHIVO");
   gets(path);
   */
    pilotos = ll_newLinkedList();
    vuelos = ll_newLinkedList();

    //vuelos = Controller_Rivero_crear_hardCodeoPilotos();



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
        control = controller_Rivero_loadFromText("vuelos.csv",vuelos); //debería ir path
        if(control==1) printf("ACCION: OK...");
        control = controller_Rivero_loadFromText_Pilotos("pilotos.csv",pilotos);
        if(control==1) printf("ACCION: OK...");
        break;
    case 2:
        control = controller_Rivero_ListGenerico(vuelos,pilotos);
        if(control==1) printf("ACCION: OK...");
        control = controller_Rivero_ListPilotos(pilotos);
        if(control==1) printf("ACCION: OK...");
        break;
    case 3:
        control = controller_Rivero_PasajerosTotales(vuelos);
        if(control!=0) printf("ACCION: OK...\nPASAJEROS: %d",control);
        break;
    case 4:
        control = controller_Rivero_PasajerosIrlanda(vuelos);
       if(control!=0) printf("ACCION: OK...\nPASAJEROS A IRLANDA: %d",control);
        break;
    case 5:
        control = controller_Rivero_VuelosCortos(vuelos);
        if(control==1) printf("ACCION: OK...");
        break;
    case 6:
        control = controller_Rivero_VuelosPortugal(vuelos,pilotos);
        if(control==1) printf("ACCION: OK...");
        break;
    case 7:
        control = controller_Rivero_FiltrarLifeson(vuelos,pilotos);
        if(control==1) printf("ACCION: OK...");
        break;
    case 8:
        control = controller_Rivero_FiltrarPorNombreElegido(vuelos,pilotos);
        break;
    }
    choise = reCall();
    }
//TERMINA LA ITERACION

    ll_deleteLinkedList(pilotos);
    ll_deleteLinkedList(vuelos);
}

