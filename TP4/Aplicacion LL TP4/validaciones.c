#include "validaciones.h"
#include "string.h"
#include <ctype.h>

int isInteger(float A)
{
int X;
X=A;
if(A-X==0)
    //si NO TIENE COMA devuelve 1
    return 1;
else
    // si TIENE COMA devuelve 0
    return 0;
}

int validacionDeNumero(int numero,int minimo, int maximo)
{
    //creo la variable por si el numero está dentro del rango,devolver
    //el mismo numero que se paso como parametro inicialmente;
    int i;
    i=numero;
    // si el numero es menor que el minimo Ó mayor que el maximo;
    while(minimo>numero||numero>maximo)
    {
        //Si está fuera de rango lo reingreso hasta que este dentro del rango;
        printf("NUMERO FUERA DE RANGO, INGRESELO NUEVAMENTE: ");
        scanf("%d",&i);
        numero = i;
    }
    //si el numero esta dentro del rango devuelvo el numero;
    return i;
}



char validacionDeLetra(char letra, char maximo, char minimo)
{
    int auxLetra,auxMaximo,auxMinimo;
    auxLetra = letra;
    auxMaximo = maximo;
    auxMinimo = minimo;
    // si el numero es menor que el minimo Ó mayor que el maximo;
    while(auxMinimo>auxLetra||auxLetra>auxMaximo)
    {
        //Si está fuera de rango lo reingreso hasta que este dentro del rango;
        printf("La letra no es la correcta, Ingresela nuevamente: ");
        fflush(stdin);
        scanf("%c",&letra);
        auxLetra = letra;
    }
    //si el numero esta dentro del rango devuelvo el numero;
    return auxLetra;
}

int obtenerNumero(char mensaje[])
{
    int numero;
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

char obtenerCaracter(char mensaje[])
{
    char caracter;
    printf("%s", mensaje);
    scanf("%c",&caracter);
    return caracter;
}

int obtenerCadena(char mensaje[],char cadena[])
{
    char string[30];
    int i;

    printf("%s: ",mensaje);
    fflush(stdin);
    fgets(string,30,stdin);
    strtok(string,"\n");
    fflush(stdin);
     for(i=0;i<30;i++)
        {
            if((string[i]== '0'||string[i]== '1'||string[i]== '2'||string[i]== '3'||string[i]== '4'||string[i]== '5'||string[i]== '6'
               ||string[i]== '7'||string[i]== '8'||string[i]== '9') && string[i]!= '\n')
            {
                printf("EL NOMBRE CONTIENE NUMEROS\n");
                return 0;
            }
        }
    strcpy(cadena,string);
    return 1;
}


int menuOpciones()
{
    int opcion;
    printf("1.AGREGAR UN NUEVO JUEGO\n");
    printf("2.MODIFICAR UN JUEGO EXISTENTE\n");
    printf("3.DAR DE BAJA UN JUEGO\n");
    printf("4.VENDER UN JUEGO\n");
    printf("5.LISTAR LOS JUEGOS ACTIVOS.\n");
    printf("6.LISTAR LOS JUEGOS DADOS DE BAJA\n");
    printf("7.REORDENAR LA LISTA DE JUEGOS ACTIVOS\n");
    printf("INGRESE 0 PARA SALIR DE LA CONSOLA");
    printf("\nIngrese Una Opcion: ");
    scanf("%d",&opcion);
    opcion = validacionDeNumero(opcion,0,7);
    return opcion;
}

int reCall(void)
{
    int i;
    printf("\n");
    system("pause");
    printf("PRESIONE ENTER PARA CONTINUAR");
    system("cls");
    i = menuOpciones();
    return i;
}


