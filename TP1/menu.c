#include "menu.h"
#include "validaciones.h"
#include "opMate.h"

int menu(void)
{
    int opcion;
    //Imprimo el munu de opciones y la eleccion de la opcion
    printf("Opciones \n1.Ingresar 1\247 operando\n2.Ingresar 2\247 operando");
    printf("\n3.Calcular todas las operaciones\n4.Informe de resultados");
    printf("\n5.Salida\n");
    opcion = obtenerNumero("Ingrese la eleccion");
    return opcion;
}


int controlador_casos(int opcion)
{
    int returnAux = -1;
    int control;
    //si la opcion es 5 salgo directamente de la consola
    control = switching(opcion);
    if(control == 1) returnAux=1;
    return returnAux;
}
