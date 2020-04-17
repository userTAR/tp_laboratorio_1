#include <stdio.h>
#include <stdlib.h>
#include "opMate.h"
#include "funcVarias.h"
int menu();
void casos(int);
float ingreso(char[],int);
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
    //variable para el switch
    int opcion;
    opcion=menu();
    casos(opcion);
}

int menu(void)
{
    int opcion;
    //Imprimo el munu de opciones y la eleccion de la opcion
    printf("Opciones \n1.Ingresar 1\247 operando\n2.Ingresar 2\247 operando");
    printf("\n3.Calcular todas las operaciones\n4.Informe de resultados");
    printf("\n5.Salida");
    printf("\nIngrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
float ingreso(char operando[], int numero)
{
    float i;
    printf("Ingresar el %s operando: ", operando);
    scanf("%f",&i);
    printf("El %d\247 operando ingresado es: %.2f",numero,i);
    printf("\nAVISO:Si el operando supera el numero 12, el factorial no sera el correcto");
    return i;
}
void casos(int opcion)
{
    //ingreso dos variables
    float A;
    float B;
    //variables para el flag
    int flagOperando1=0;
    int flagOperando2=0;
    int flagOpcion3=0;
    //variables para las operaciones
    float sum,rest,multplic,div;
    unsigned long int factA,factB;
    //variables para la comparacion de decimal o no decimal
    int compSum,compRest,compDiv,compMultplic;
   //si la opcion es 5 salgo directamente de la consola
    while(opcion!=5)
    {
  switch(opcion)
    {
    //escaneo el primer numero en caso de que el usuario ingrese esta opcion
    case 1:
    flagOperando1=1;
    A=ingreso("primer",1);
    break;

    //escaneo el segundo numero en caso de que el usuario ingrese esta opcion
    case 2:
    flagOperando2=1;
    B=ingreso("segundo",2);
    break;


    case 3:
    flagOpcion3=1;
    //LINEA 80 A 94: chequeo que ya se hayan ingresado los operandos
    if(flagOperando1==0&&flagOperando2==0)
    {
        printf("No ingreso ningun operando");
        break;
    }
    else if(flagOperando1==0&&flagOperando2==1)
    {
        printf("No ingreso el primer operando");
        break;
    }
    else if(flagOperando1==1&&flagOperando2==0)
    {
        printf("No ingreso el segundo operando");
        break;
    }
    else{
    sum = suma(A,B);
    compSum=isInteger(sum);
    rest = resta(A,B);
    compRest=isInteger(rest);
    div = division(A,B);
    compDiv=isInteger(div);
    multplic = multpl(A,B);
    compMultplic=isInteger(multplic);
    factA = factorial(A);
    factB = factorial(B);
    break;
    }

    case 4:
    //LINEA 111 A 115: chequeo que se hayan ingresado la opcion 3
    if(flagOpcion3==0)
    {
    printf("Debe ingresar primero la opcion 3");
    break;
    }
    else{
    //imprimo todos los resultados que se me pide
    if(compSum==0)
        //si el numero tiene coma
        printf("El resultado A+B es: %.2f",sum);
    else
        //si el numero no tiene coma
        printf("El resultado A+B es: %d",(int)sum);
    if(compRest==0)
        //si el numero tiene coma
        printf("\nEl resultado A-B es: %.2f",rest);
    else
        //si el numero no tiene coma
        printf("\nEl resultado A-B es: %d",(int)rest);
    //en el caso de que el divisor sea 0, se imprime que no es posible
    if(B!=0)
    {
        if(compDiv==0)
            //si el numero tiene coma
            printf("\nEl resultado A/B es: %.2f",div);
        else
            //si el numero no tiene coma
            printf("\nEl resultado A/B es: %d",(int)div);
    }
    else
        printf("\nNo es posible dividir por cero");
    if(compMultplic==0)
        //si el numero tiene coma
        printf("\nEl resultado A*B es: %.2f",multplic);
    else
        //si el numero no tiene coma
        printf("\nEl resultado A*B es: %d",(int)multplic);
    //si el numero ingresado es menor a 0 se imprime que no existe el factorial de tal numero
    if(factA!=0){
        printf("\nEl factorial de A es: %lu",factA);
    }
    else
        printf("\nPor regla matematica el primer operando no tiene factorial");
    // si el numero ingresado es menor a 0 se imprime que no existe el factorial de tal numero
    if(factB!=0){
    printf("\nEl factorial de B es: %lu",factB);
    }
    else
    {
        printf("\nPor regla matematica el segundo operando no tiene factorial");
    }
    break;
    }
    //en caso de que se oprima cualquier otra opcion que no sea del 1 al 5


    default:
    printf("No es una opcion valida");
    break;
    }

    //se vuelve a preguntar que otra opcion quiere ingresar para seguir con la opcion que se elija
    printf("\nIngrese otra opcion: ");
    scanf("%d",&opcion);
    }
}
