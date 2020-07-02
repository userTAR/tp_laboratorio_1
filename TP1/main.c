#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


/* CONSIGNAS:
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)          4. Informar resultados
2. Ingresar 2do operando (B=y)          a) “El resultado de A+B es: r”
3. Calcular todas las operaciones       b) “El resultado de A-B es: r”
a) Calcular la suma (A+B)               c) “El resultado de A/B es: r”o“No es posible dividir por cero”
b) Calcular la resta (A-B)              d) “El resultado de A*B es: r”
c) Calcular la division (A/B)           e) “El factorial de A es: r1 y El factorial de B es: r2”
d) Calcular la multiplicacion (A*B)     5. Salir
e) Calcular el factorial (A!)
*/
int main(void)
{
    int control;
    //variable para el switch
    int opcion;
    opcion=menu();
    control = controlador_casos(opcion);
    if(control == 1) printf("ACCION: OK...");
}

