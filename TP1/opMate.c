#include "opMate.h"
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

int factorial(float A)
{
    int X;
    int t=1;
    X=A;
    //si el numero NO TIENE COMA hace esto:
    if(A-X==0)
    {
    // si es igual a 0 (su factorial es 1);
    if(X==0)
        return 1;
    //si es menor a 0 (no existe factorial);
    else if(X<0)
        return 0;
    //si es mayor a 0 (devuelve el factorial correspondiente)
    else
    {
    for(;A>0;A--){
        t*=A;
    }
    return t;
    }
    }
    //si el numero TIENE COMA
    else
        return 0;
}
