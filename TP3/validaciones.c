#include "validaciones.h"
#include "string.h"

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
        printf("Numero fuera de rango, Ingreselo nuevamente: ");
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

     for(i=0;i<30;i++)
        {
            if((string[i]== '0'||string[i]== '1'||string[i]== '2'||string[i]== '3'||string[i]== '4'||string[i]== '5'||string[i]== '6'
               ||string[i]== '7'||string[i]== '8'||string[i]== '9')&& string[i]!= '\n')
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
    printf("---BIENVENIDO AL MENU DE OPCIONES---\n");
    printf("1.CARGAR LOS EMPLEADOS GUARDADOS EN EL ARCHIVO EN MODO TEXTO\n");
    printf("2.CARGAR LOS EMPLEADOS GUARDADOS EN EL ARCHIVO EN MODO BINARIO\n");
    printf("3.DAR DE ALTA UN EMPLEADO\n");
    printf("4.MODIFICAR A UN EMPLEADO\n");
    printf("5.DAR DE BAJA A UN EMPLEADO\n");
    printf("6.LISTAR A TODOS LOS EMPLEADOS GUARDADOS Y ACTIVOS\n");
    printf("7.ORDENAR A TODOS LOS EMPLEADOS GUARDADOS Y ACTIVOS\n");
    printf("8.GUARDAR LOS DATOS EN EL ARCHIVO DATA.CSV EN MODO DE TEXTO\n");
    printf("9.GUARDAR LOS DATOS EN EL ARCHIVO DATA.BIN EN MODO BINARIO");
    printf("\nINGRESE 10 PARA SALIR DE LA CONSOLA");
    printf("\nIngrese Una Opcion: ");
    scanf("%d",&opcion);
    opcion = validacionDeNumero(opcion,1,10);
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


