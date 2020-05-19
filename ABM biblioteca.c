#include "ABM biblioteca.h"


int reCall(void)
{
    int i;
     printf("\n");
    system("pause");
    system("cls");
    i = menuOpciones();
    return i;
}

int menuOpciones()
{
    int opcion;
    printf("---BIENVENIDO AL MENU---\n");
    printf("1.Listado de Clientes\n");
    printf("2.Listado de Mascotas\n3.Listado de Cliente con mascotas\n4.Alta Mascota");
    printf("\n5.Baja Mascota\n6.Modificar Mascota\n7.Alta Duenio\n8.Borrar de duenio en cascada");
    printf("\n9.Ordenar Las mascotas por tipo y listarlas\n10.Modificar Duenio");
    printf("\n11.Listar los clientes con mas de una mascota\n12.Listar las mascotas con mas de 3 anios de edad");
    printf("\n13.Listar las mascotas por un tipo en particular");
    printf("\n14.Ordenar duenios por cantidad de mascotas y mostrarlos");
    printf("\n15.Ordenar duenios por cantidad de mascotas y por orden alfabético");
    printf("\n16.El promedio de edad entre las mascotas \n17.Promedio de edad entre mascotas por tipo");
    printf("\n18.Promedio entre varones y mujeres de los clientes\nINGRESE 0 PARA SALIR DE LA CONSOLA");
    printf("\nIngrese Una Opcion: ");
    scanf("%d",&opcion);
    opcion = validacionDeNumero(opcion,0,18); //MODIFICAR SEGUN MENU
    return opcion;
}
/*
void switchMenu(int opcion,sEstructura estructura[],sEstructura2 estructura2[],int tamEstructura1, int tamEstructura2) //PARA EL MAIN
{
    switch(opcion)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    case 10:

        break;
    }
}


*/

