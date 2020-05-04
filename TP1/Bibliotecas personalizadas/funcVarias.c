#include "funcVarias.h"

//-------------------------------------------FUNCIONES ESPECÍFICAS AL PROGRAMA REUTILIZABLES--------------------------------------
void agregarOrquesta(eOrquesta orquesta[],int indice)
{
    printf("Ingrese el nombre de la orquesta: ");
    fflush(stdin);
    gets(orquesta[indice].nombre);
    printf("Ingrese el lugar de la orquesta: ");
    fflush(stdin);
    gets(orquesta[indice].lugar);
    printf("Ingrese el número de tipo de orquesta:\n1.sinfonica");
    printf("\n2.Filarmonica\n3.Camara\nTipo de orquesta: ");
    fflush(stdin);
    scanf("%d",&orquesta[indice].tipo);
    orquesta[indice].estado=-1;
}

void eliminarOrquesta(eOrquesta orquesta[],eMusico musico[],int tamOrquesta,int tamMusico)
{
    int i,j;
    int eleccionID;
    //      imprimo todas los nombres e ID's de las orquestas;
    for(i=0;i<tamOrquesta;i++)
    {
        if(orquesta[i].estado!=0)
            printf("%d\t %s\n",orquesta[i].id,orquesta[i].nombre);

    }
    printf("Ingrese el ID de la orquesta que desea eliminar: ");
    scanf("%d", &eleccionID);
    //eliminación lógica de la orquesta. (se puede reescribir);
    for(i=0;i<tamOrquesta;i++)
    {
        if(orquesta[i].id == eleccionID)
            orquesta[i].estado = 0;
    }
    //eliminacion lógica de los músicos que tienen asociado el ID de la orquesta a eliminar;
    for(j=0;j<tamMusico;j++)
        {
            if(musico[j].idOrquesta == eleccionID)
                musico[j].estado = 0;
        }
}

void imprimirOrquestas(eOrquesta orquesta[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        if(orquesta[i].estado!=0)
        printf ("Nombre%8s Tipo:%8d ID:%8d\tLugar:%15s", orquesta[i].nombre,
                                    orquesta[i].tipo,
                                    orquesta[i].id,
                                    orquesta[i].lugar);
    }
}

void agregarMusico(eMusico musico[],int indice,eOrquesta orquesta[])
{
    int i;
    printf("Ingrese el nombre y apellido del musico: ");
    fflush(stdin);
    gets(musico[indice].nombreYapellido);
    printf("Ingrese la edad del musico: ");
    scanf("%d", &musico[indice].edad);
    for(i=0;i<50;i++)
    {
        if(orquesta[i].estado!=0)
            printf("%d\n",orquesta[i].id);
    }
    printf("Ingrese el ID de la orquesta en la que tocara:");
    scanf("%d",&musico[indice].idOrquesta);
    printf("Ingrese el ID del tipo de insturmento que tocara:\n1.Cuerdas");
    printf("\n2.Viento-Madera\n3.Viento-Metal\n4.Percusion\nTipo de instrumento: ");
    fflush(stdin);
    scanf("%d",&musico[indice].idInstrumento);
    musico[indice].estado = -1;
}

void eliminarMusico(eMusico musico[],int tamMusico)
{
    int i;
    int eleccionID;
    //      imprimo todas los nombres e ID's de las orquestas;
    for(i=0;i<tamMusico;i++)
    {
        if(musico[i].estado!=0)
            printf("ID Personal:%d\t Nombre y Apellido:%s\n",musico[i].idPersonal,musico[i].nombreYapellido);

    }
    printf("Ingrese el ID personal del músico que desea eliminar: ");
    scanf("%d", &eleccionID);
    //eliminacion lógica del musico con el id que el usuario ingreso;
    for(i=0;i<tamMusico;i++)
        {
            if(musico[i].idPersonal == eleccionID)
                musico[i].estado = 0;
        }

}
void imprimirMusicos(eMusico musico[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        if(musico[i].estado != 0)
        {
        printf("Nombre:%8s Edad:%8d IdInsturmento%8d ID Personal:%d  ID de Orquesta: %d", musico[i].nombreYapellido,
                                    musico[i].edad,
                                    musico[i].idInstrumento,
                                    musico[i].idPersonal,musico[i].idOrquesta);
        }
    }
}

void modificarMusico(eMusico musico[],eOrquesta orquesta[], int tamMusico, int tamOrquesta)
{
    int i , j , p;
    int eleccionID;
    int eleccionModificacion;
    int nuevaEdad;
    int nuevoIdOrquesta;
    //  Se imprime el nombre y edad de todas las orquestas;
    for (i=0;i<tamOrquesta;i++)
    {
        if(musico[i].estado != 0)
            printf("%8s \t%d\n", musico[i].nombreYapellido,musico[i].idPersonal);
    }
    printf("Ingrese el ID personal del músico que quiera modificar: ");
    //  Se ingresa el ID de la orquesta a modificar;
    scanf("%d", &eleccionID);
    printf("1.Modificar edad del musico\n2.Modificar ID de la orquesta que toca\n");
    printf("Ingrese la opcion que desee: ");
    //  Se ingresa la opcion 1 o 2.
    scanf("%d", &eleccionModificacion);
    eleccionModificacion = validacionDeNumero(eleccionModificacion,1,2);
    if(eleccionModificacion == 1)
    {
        printf("Ingrese la nueva edad: ");
        scanf("%d", &nuevaEdad);
        for(i=0;i<tamMusico;i++)
        {
            if(musico[i].idPersonal == eleccionID)
                musico[i].edad = nuevaEdad;
        }
    }
    else if(eleccionModificacion == 2)
    {
        for (j=0;j<tamMusico;j++)
        {
            printf ("%8s %8d", orquesta[j].nombre,orquesta[j].id);
        }
        printf("Ingrese el nuevo ID de la orquesta en la que tocara");
        scanf("%d", &nuevoIdOrquesta);
        for(p=0;p<tamMusico;p++)
        {
            if(musico[p].idOrquesta == eleccionID)
                musico[p].idOrquesta = nuevoIdOrquesta;
        }
    }
}

void agregarInstrumento(eInstrumento instrumento[], int indice)
{
    printf("Ingrese el nombre del instrumento: ");
    fflush(stdin);
    gets(instrumento[indice].nombreInstrumento);
    printf("Ingrese el ID del tipo de insturmento:\n1.Cuerdas");
    printf("\n2.Viento-Madera\n3.Viento-Metal\n4.Percusion\nTipo de instrumento: ");
    fflush(stdin);
    scanf("%d",&instrumento[indice].tipo);
    instrumento[indice].estado = -1;
}

void imprimirInstrumentos(eInstrumento instrumento[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        if(instrumento[i].estado != 0)
        {
        printf("%8s %8d %5d", instrumento[i].nombreInstrumento,
                                instrumento[i].tipo,
                                instrumento[i].id);
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------FUNCIONES DE LISTADO QUE PUEDEN SER REUTILIZABLES--------------------------------------
void orquestasMasDe5Musicos(eOrquesta orquesta[],eMusico musico[],int tamOrquesta,int tamMusico)
{
    int i,j,contador;
    for(i=0;i<tamOrquesta;i++)
        {
            contador=0;
            for(j=0;j<tamMusico;j++)
            {
                if(orquesta[i].id == musico[j].idOrquesta && musico[j].estado != 0)
                {
                    contador++;
                    if(contador>5)
                    {
                        printf ("Nombre%8s Tipo:%8d ID:%8d\tLugar:%15s", orquesta[i].nombre,
                                    orquesta[i].tipo,
                                    orquesta[i].id,
                                    orquesta[i].lugar);
                        break;
                    }
                }
            }

        }
}

void musicosMasDe30(eMusico musico[],int tamMusico)
{
    int i;
    for(i=0;i<tamMusico;i++)
    {
        if(musico[i].estado != 0 && musico[i].edad > 30)
            printf("Nombre:%8s Edad:%8d IdInsturmento%8d ID Personal:%d  ID de Orquesta: %d", musico[i].nombreYapellido,
                                                                            musico[i].edad,
                                                                            musico[i].idInstrumento,
                                                                            musico[i].idPersonal,musico[i].idOrquesta);
    }
}

void orquestasLugarParticular(eOrquesta orquesta[], int tamOrquesta)
{
    char lugar[21];
    int i,comparacion;
    imprimirOrquestas(orquesta,tamOrquesta);
    printf("Ingrese un lugar: ");
    gets(lugar);
    for(i=0;i<tamOrquesta;i++)
    {
        comparacion = strcmp(strlwr(orquesta[i].lugar), strlwr(lugar));
        if(comparacion == 0 && orquesta[i].estado != 0)
            printf ("Nombre%8s Tipo:%8d ID:%8d\tLugar:%15s", orquesta[i].nombre,
                                    orquesta[i].tipo,
                                    orquesta[i].id,
                                    orquesta[i].lugar);

    }
}

void orquestasCompletas(eOrquesta orquesta[],eMusico musico[], int tamOrquesta, int tamMusico)
{
    int i,j;
    int contCuerda,contViento,contPercusion;
    for(i=0;i<tamOrquesta;i++)
    {
        if(orquesta[i].estado != 0)
        {
            contCuerda = 0;
            contViento = 0;
            contPercusion = 0;
            for(j=0;j<tamMusico;j++)
            {
                 if(orquesta[i].id == musico[j].idOrquesta && musico[j].estado != 0)
                 {
                     if(musico[j].idInstrumento == 1)
                        contCuerda++;
                     else if(musico[j].idInstrumento == 2 || musico[j].idInstrumento == 3)
                        contViento++;
                     else
                        contPercusion++;

                 }
            }
        }
            if(contCuerda > 4 && contViento > 2 && contPercusion > 1)
                printf ("Nombre%8s Tipo:%8d ID:%8d\tLugar:%15s", orquesta[i].nombre,
                                                                    orquesta[i].tipo,
                                                                    orquesta[i].id,
                                                                    orquesta[i].lugar);
    }
}

void musicosDeOrquestaDeterminada(eOrquesta orquesta[], eMusico musico[], int tamOrquesta, int tamMusico)
{

}


//---------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------FUNCIONES DE FUNCIONALIDAD GENERAL-----------------------------------------------------
int buscarLibre(int opcion,eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[],int tamOrquesta, int tamMusico, int tamInstrumento)
{
    int i;
    //si la opcion es 1(AGREGAR ORQUESTA);
    if(opcion==1)
    {
    for (i=0;i<tamOrquesta;i++)
    {
        if(orquesta[i].estado==0)
            //retorna el primer valor libre de miembro estado de la estrutura orquesta;
            return i;
    }
    }
    //si la opcion es 4(AGREGAR MUSICO);
    else if(opcion==4)
    {
     for (i=0;i<tamMusico;i++)
    {
        if(musico[i].estado==0)
            //retorna el primer valor libre de miembro estado de la estrutura musico;
            return i;
    }
    }
    else if(opcion==8)
    {
     for (i=0;i<tamInstrumento;i++)
    {
        if(instrumento[i].estado==0)
            //retorna el primer valor libre de miembro estado de la estrutura instrumento;
            return i;
    }
    }
    return 0;
}


void inicializarEstado(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]
                       ,int tamOrquesta, int tamMusico, int tamInstrumento)  //REVISAR SABADO
{
    int i;
    for(i=0;i<tamOrquesta;i++)
       orquesta[i].estado = 0;
    for(i=0;i<tamMusico;i++)
       musico[i].estado = 0;
    for(i=0;i<tamInstrumento;i++)
       instrumento[i].estado = 0;
}

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
int menuOpciones()
{
    int opcion;
    printf("---BIENVENIDO AL MENU---\n");
    printf("1.Agregar Orquesta\n");
    printf("2.Eliminar Orquesta\n3.Imprimir Orquestas\n4.Agregar Musico");
    printf("\n5.Modificar Musico\n6.Eliminar Musico\n7.Imprimir Musicos");
    printf("\n8.Agregar Instrumento\n9.Imprimir Instrumentos\n10.Informes(SUBMENU)\nINGRESE 0 PARA SALIR DE LA CONSOLA");
    printf("\nIngrese Una Opcion: ");
    scanf("%d",&opcion);
    opcion = validacionDeNumero(opcion,0,10);
    return opcion;
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
void inicializadorDeId(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]
                       ,int tamOrquesta, int tamMusico, int tamInstrumento)  //REVISAR SABADO
{
    int i;
    for(i=0;i<tamOrquesta;i++)
       orquesta[i].id = -1;
    for(i=0;i<tamMusico;i++)
       musico[i].idPersonal = 0;
    for(i=0;i<tamInstrumento;i++)
       instrumento[i].id= 0;
}

void creadorDeId(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[])
{
    int i;
    int j=1;
    int q=2;
    int p=3;
    for(i=0;i<50;i++)
    {
       orquesta[i].id = j;
       j = j + 10;
    }
    for(i=0;i<1000;i++)
    {
        musico[i].idPersonal = q;
        q = q + 10;
    }
    for(i=0;i<20;i++)
    {
        instrumento[i].id = p;
        p = p + 10;
    }

}
