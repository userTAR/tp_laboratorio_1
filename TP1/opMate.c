#include "opMate.h"
#include "validaciones.h"
#include "menu.h"

float suma(float A, float B)
{
    float resultado=A+B;
    return resultado;
}

float resta(float A, float B)
{
    float resultado=A-B;
    return resultado;
}

float division(float A, float B)
{
    float resultado;
    if(B==0)
       resultado=0;
    else
    resultado=A/B;
    return resultado;
}

float multpl(float A, float B)
{
    float resultado=A*B;
    return resultado;
}

double factorial(float A)
{
    int X;
    int returnAux = -1;
    int t=1;
    X=A;
    //si el numero NO TIENE COMA hace esto:
    if(A-X==0)
    {
        // si es igual a 0 (su factorial es 1);
        if(X==0)
            returnAux = 1;
        //si es menor a 0 (no existe factorial);
        else if(X<0)
            returnAux = 0;
        //si es mayor a 0 (devuelve el factorial correspondiente)
        else
        {
            for(X=A;X>0;X--)
            {
                t = t * X;
            }
            returnAux = t;
        }
    }
   return returnAux;
}


float ingreso(char operando[], int numero)
{
    float i;
    printf("Ingresar el %s operando: ", operando);
    scanf("%f",&i);
    printf("El %d\247 operando ingresado es: %.2f",numero,i);
    return i;
}

int switching(int opcion)
{
    int returnAux = -1;
    float A;
    float B;
    //variables para el flag
    int flagOperando1=0;
    int flagOperando2=0;
    int flagOpcion3=0;
    //variables para las operaciones
    float sum;
    float rest;
    float multplic;
    float div;
    double factA;
    double factB;
    //variables para la comparacion de decimal o no decimal
    int compSum;
    int compRest;
    int compDiv;
    int compMultplic;
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
                else
                {
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
                    printf("Calculos realizados");
                    break;
                }
            case 4:
                if(flagOpcion3==0)
                {
                    printf("Debe ingresar primero la opcion 3");
                    break;
                }
                else
                {
                    returnAux = 1;
                //impresion de resultados
                    print_suma(compSum,sum);
                    print_resta(compRest,rest);
                    print_multiplc(compMultplic,multplic);
                    print_div(compDiv,div,B);
                    print_factorial(factA,factB);
                }
                break;
            default:
                printf("NUMERO FUERA DE RANGO");
        }
        printf("\n");
        system("pause");
        printf("PRESIONE ENTER PARA CONTINUAR");
        system("cls");
        opcion = menu();
    }
    return returnAux;
}

void print_suma(int comparacion, float suma)
{
    if(comparacion==0)
    //si el numero tiene coma
        printf("El resultado A+B es: %.2f",suma);
    else
    //si el numero no tiene coma
        printf("El resultado A+B es: %d",(int)suma);
}

void print_resta(int comparacion, float resta)
{
    if(comparacion==0)
    //si el numero tiene coma
        printf("\nEl resultado A-B es: %.2f",resta);
    else
    //si el numero no tiene coma
        printf("\nEl resultado A-B es: %d",(int)resta);
}

void print_multiplc(int comparacion, float multiplc)
{
    if(comparacion==0)
    //si el numero tiene coma
        printf("\nEl resultado A*B es: %.2f",multiplc);
    else
    //si el numero no tiene coma
        printf("\nEl resultado A*B es: %d",(int)multiplc);
}

void print_div(int comparacion, float division, float B)
{
    //en el caso de que el divisor sea 0, se imprime que no es posible
    if(B!=0)
    {
        if(comparacion==0)
        //si el numero tiene coma
            printf("\nEl resultado A/B es: %.2f",division);
        else
        //si el numero no tiene coma
            printf("\nEl resultado A/B es: %d",(int)division);
    }
    else
        printf("\nNo es posible dividir por cero");
}

void print_factorial(double factorialA, double factorialB)
{
 //si el numero ingresado es menor a 0 se imprime que no existe el factorial de tal numero
    if(factorialA!=0 && factorialA != -1)
        printf("\nEl factorial de A es: %.0lf",factorialA);
    else
        printf("\nPor regla matematica el primer operando no tiene factorial");
    // si el numero ingresado es menor a 0 se imprime que no existe el factorial de tal numero
    if(factorialB!=0 && factorialB!= -1)
        printf("\nEl factorial de B es: %.0lf",factorialB);
    else
        printf("\nPor regla matematica el segundo operando no tiene factorial");
}


