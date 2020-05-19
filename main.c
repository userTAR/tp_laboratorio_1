#include <stdio.h>
#include <stdlib.h>
#include "ABM biblioteca.h"

void switchMenu(int opcion,sCliente estructura[],sMascota estructura2[],sRaza estructura3[],int tamEstructura1, int tamEstructura2,int tamEstructura3);

void main(void)
{
    int menu;
    sCliente clientes[10];
    sMascota mascotas[20];
    sRaza razas[8];
    initEstado_Cantidad_Cliente(clientes,10);
    inicializarEstadoMascota(mascotas,20);
    creadorDeIdCliente(clientes,10);
    creadorDeIdMascota(mascotas,20);
    hardcodearEstructuras(clientes,mascotas,razas,5,11,6);

    menu=menuOpciones();
    while(menu!=0)
    {
        switchMenu(menu,clientes,mascotas,razas,10,20,6);
        menu=reCall();
    }
}

void switchMenu(int opcion,sCliente estructura[],sMascota estructura2[],sRaza estructura3[],int tamEstructura1, int tamEstructura2,int tamEstructura3) //PARA EL MAIN
{
    switch(opcion)
    {
    case 1:
         printf("Listado Clientes \n:");
        imprimirArrayClientes_OCUPADOS(estructura,tamEstructura1);
        break;
    case 2:
         printf("Listado Mascotas \n:");
        imprimirArrayMascotas_OCUPADOS(estructura2,estructura3,tamEstructura2,tamEstructura3);
        break;
    case 3:
        printf("\nMascotas con sus duenios: \n");
        listarDueniosConSusMascotas(estructura,estructura2,estructura3,tamEstructura1,tamEstructura2,tamEstructura3);
        break;
    case 4:
        agregarMascota(estructura,estructura2,estructura3,tamEstructura1,tamEstructura2,tamEstructura3);
        break;
    case 5:
        eliminarMascota(estructura,estructura2,estructura3,tamEstructura1,tamEstructura2,tamEstructura3);
        break;
    case 6:
        modificarMascota(estructura2,estructura3,estructura,tamEstructura2,tamEstructura3,tamEstructura1);
        break;
    case 7:
        agregarCliente(estructura,tamEstructura1);
        break;
    case 8:
        eliminarClienteENCascada(estructura,estructura2,tamEstructura1,tamEstructura2);
        break;
    case 9:
     //   ImprMascotasOrdenadasPorTipo_ConDuenio(estructura2,tamEstructura2);
        break;
    case 10:
        modificarCliente(estructura,tamEstructura1);
        break;
    case 11:
        ImprclienteMasDeUnaMascota(estructura,estructura2,tamEstructura1,tamEstructura2);
        break;
    case 12:
      //  ImprMascotasMasDe3Anios(estructura2,tamEstructura2);
        break;
    case 13:
      //  imprMascotasPorTipoEnParticular(estructura2,tamEstructura2);
        break;
    case 14:
        imprClientesOrdenadosPorCantMascotas(estructura,estructura2,tamEstructura1,tamEstructura2);
        break;
    case 15:
        imprClientesOrdenadosPorCantMascotas_Nombre(estructura,estructura2,tamEstructura1,tamEstructura2);
        break;
    case 16:
       // promedioEdadMascotas(estructura2,tamEstructura2);
        break;
    case 17:
      //  promedioEdadMascotasPorTipo(estructura2,tamEstructura2);
        break;
    case 18:
        promedioVarones_Mujeres(estructura,tamEstructura1);
        break;
    }
}
