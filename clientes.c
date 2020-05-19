#include "clientes.h"
#define LIBRE 0
#define OCUPADO 1

void initEstado_Cantidad_Cliente(sCliente estructura[],int tamEstructura)
{
    int i;
    for(i=0;i<tamEstructura;i++)
    {
        estructura[i].estado = LIBRE;
        estructura[i].cantMascotas = LIBRE;
    }
}

void imprimirArrayClientes_OCUPADOS(sCliente estructura[],int tamEstructura) //cambiarle el tipo de estructura
{
    int i;
    printf("NOMBRE-----------------APELLIDO----------LOCALIDAD----TELEFONO--------EDAD--------SEXO-------IDPERSONAL\n");
    for(i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado)
            imprimirUnSoloCliente_OCUPADOS(estructura[i]);
    }
}

void imprimirUnSoloCliente_OCUPADOS(sCliente estructura) //cambiarle el tipo de estructura
{
    if(estructura.estado != LIBRE)
        printf("%8s %18s %20s %8d %15d %18s %12d \n", estructura.nombre,estructura.apellido,estructura.localidad,estructura.telefono,estructura.edad,estructura.sexo,estructura.idPersonal); //completar printf
}

void agregarCliente(sCliente estructura[],int tamEstructura) //cambiarle el tipo de estructura
{
    int indice;
    int sexo;
    indice = buscarLibreCliente(estructura,tamEstructura);
    obtenerCadena("Ingrese el nombre",estructura[indice].nombre);
    obtenerCadena("Ingrese el apellido",estructura[indice].apellido);
    obtenerCadena("Ingrese la localidad",estructura[indice].localidad);
    sexo = obtenerNumero("1.Masculino//2.Femenino\nIngrese el sexo");
    if(sexo==1)
        strcpy(estructura[indice].sexo,"MASCULINO");
    else
        strcpy(estructura[indice].sexo,"FEMENINO");
    estructura[indice].telefono = obtenerNumero("Ingrese el telefono");
    estructura[indice].edad = obtenerNumero("Ingrese la edad");
    estructura[indice].estado = OCUPADO;
}



void modificarCliente(sCliente estructura[],int tamEstructura)
{
    int i;
    int eleccionID;
    int eleccionModificacion;
    int nuevoNumero;
    char nuevaCadena[51];
    imprimirArrayClientes_OCUPADOS(estructura,tamEstructura);
    eleccionID = obtenerNumero("Ingrese el id del cliente que quiere modificar"); // agregar mensaje
    printf("1.Modificar nombre\n2.Modificar apellido\n3.Modificar Localidad\n4.Modificar telefono\n5.Modificar edad\n"); //se ingresan las opciones
    printf("6.Modificar sexo\n"); //se ingresan las opciones
    eleccionModificacion = obtenerNumero("Ingrese la opcion que desee: ");
    eleccionModificacion = validacionDeNumero(eleccionModificacion,1,6);
    switch(eleccionModificacion)
    {
    case 1:
        obtenerCadena("Ingrese nuevo nombre",nuevaCadena);
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idPersonal== eleccionID) //completar condicion
                  strcpy(estructura[i].nombre,nuevaCadena);        //completar igualdad
        }
        break;
    case 2:
        obtenerCadena("Ingrese nuevo apellido",nuevaCadena);
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idPersonal == eleccionID) //completar condicion
                  strcpy(estructura[i].apellido,nuevaCadena);        //completar igualdad
        }
        break;
    case 3:
        obtenerCadena("Ingrese nueva localidad",nuevaCadena);
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idPersonal == eleccionID) //completar condicion
                 strcpy(estructura[i].localidad,nuevaCadena);        //completar igualdad
        }
        break;

    case 4:
        nuevoNumero = obtenerNumero("Ingrese nuevo telefono");
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idPersonal == eleccionID) //completar condicion
                  estructura[i].telefono = nuevoNumero;        //completar igualdad
        }
        break;

    case 5:
        nuevoNumero = obtenerNumero("Ingrese la nueva edad");        //completar mensaje de obtener numero
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idPersonal== eleccionID)    //completar condicion
               estructura[i].edad = nuevoNumero;    //completar igualdad
        }
        break;
    case 6:
        nuevoNumero = obtenerNumero("1.Masculino//2.Femenino\nIngrese el nuevo sexo");        //completar mensaje de obtener numero
        nuevoNumero = validacionDeNumero(nuevoNumero,1,2);
        if(nuevoNumero == 1)
            strcpy(nuevaCadena,"MASCULINO");
        else if(nuevoNumero == 2)
            strcpy(nuevaCadena,"FEMENINO");
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idPersonal == eleccionID)    //completar condicion
               strcpy(estructura[i].sexo ,nuevaCadena);       //completar igualdad
        }
        break;
    }
}

int buscarIndiceDeClientePorId(sCliente estructura[],int tamEstructura)
{
    int eleccionID;
    int i;
    imprimirArrayClientes_OCUPADOS(estructura,tamEstructura);
    eleccionID = obtenerNumero("Ingrese un id");
    for(i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado != LIBRE && estructura[i].idPersonal == eleccionID)
            return i; //retorna el indice en el que se encuentra el ID para el ALTA y la BAJA
    }
    return -1;
}

int buscarLibreCliente(sCliente estructura[],int tamEstructura)
{
    int i;
    for (i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado == LIBRE)
            return i; //retorna el primer indice libre de la estructura
    }
    return -1; //devuelve -1 si no encontró espacio
}

void creadorDeIdCliente(sCliente estructura[],int tamEstructura)
{
    int i;
    int j=1;
    for(i=0;i<tamEstructura;i++)
    {
        estructura[i].idPersonal = j;
       j = j + 10;
    }
}
