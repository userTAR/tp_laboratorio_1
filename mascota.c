#include "mascota.h"
#define LIBRE 0
#define OCUPADO 1

void inicializarEstadoMascota(sMascota estructura[],int tamEstructura)
{
    int i;
    for(i=0;i<tamEstructura;i++)
        estructura[i].estado = LIBRE;
}

void imprimirArrayMascotas_OCUPADOS(sMascota estructura[],int tamEstructura) //cambiarle el tipo de estructura
{
    int i;
    printf ("NombreMascota---------TipoMascota:------------RazaMascota:-------- SexoMascota:----- EdadMascota:---- PesoMascota:-----IdMascota:----NombreDuenio:---\n");
    for(i=0;i<tamEstructura;i++)
    {
       imprimirUnaSolaMascota_OCUPADOS(estructura[i]);
    }
}

void imprimirUnaSolaMascota_OCUPADOS(sMascota estructura) //cambiarle el tipo de estructura
{
    if(estructura.estado != LIBRE)
    {
        printf("%8s %20s %25s %12s   %20s   %15d   %16d  %10d  %18s \n", estructura.nombreMascota,estructura.tipo,estructura.raza.NombreRaza,estructura.raza.paisRaza,estructura.sexo,
                        estructura.edad,estructura.peso,estructura.idMascota,estructura.nombreDuenio); //completar printf
    }
}

int buscarIndiceDeMascotaPorId(sMascota estructura[],int tamEstructura)
{
    int eleccionID;
    int i;
    imprimirArrayMascotas_OCUPADOS(estructura,tamEstructura);
    eleccionID = obtenerNumero("Ingrese un id");
    for(i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado != LIBRE && estructura[i].idMascota == eleccionID)
            return i; //retorna el indice en el que se encuentra el ID para el ALTA y la BAJA
    }
    return -1;
}

int buscarLibreMascota(sMascota estructura[],int tamEstructura)
{
    int i;
    for (i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado == LIBRE)
            return i; //retorna el primer indice libre de la estructura
    }
    return -1; //devuelve -1 si no encontró espacio
}

void creadorDeIdMascota(sMascota estructura[],int tamEstructura)
{
    int i;
    int j=2;
    for(i=0;i<tamEstructura;i++)
    {
        estructura[i].idMascota = j;
       j = j + 10;
    }
}

void modificarMascota(sMascota estructura[],int tamEstructura) //cambiarle el tipo de estructura
{
    int i;
    int eleccionID;
    int eleccionModificacion;
    int nuevoNumero;
    char nuevaCadena[51];
    imprimirArrayMascotas_OCUPADOS(estructura,tamEstructura);
    eleccionID = obtenerNumero("Ingrese el id de la mascota"); // agregar mensaje
    printf("1.Modificar nombre\n2.Modificar tipo\n3.Modificar raza\n4.Modificar sexo\n5.Modificar edad\n"); //se ingresan las opciones
    printf("6.Modificar peso\n"); //se ingresan las opciones
    eleccionModificacion = obtenerNumero("Ingrese la opcion que desee: ");
    eleccionModificacion = validacionDeNumero(eleccionModificacion,1,6);
    switch(eleccionModificacion)
    {
    case 1:
        obtenerCadena("Ingrese nuevo nombre",nuevaCadena);
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idMascota== eleccionID) //completar condicion
                  strcpy(estructura[i].nombreMascota,nuevaCadena);        //completar igualdad
        }
        break;
    case 2:
        nuevoNumero = obtenerNumero("1.Perro//2.Gato//3.Raro");
        nuevoNumero = validacionDeNumero(nuevoNumero,1,3);
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idMascota == eleccionID && nuevoNumero == 1) //completar condicion
                strcpy(estructura[i].tipo,"PERRO");
            else if(estructura[i].idMascota == eleccionID && nuevoNumero == 2)
                strcpy(estructura[i].tipo,"GATO");
            else if(estructura[i].idMascota == eleccionID && nuevoNumero == 3)
                strcpy(estructura[i].tipo,"RARO");
        }
        break;
    case 3:
        obtenerCadena("Ingrese nueva raza",nuevaCadena);
        for(i=0;i<tamEstructura;i++)
        {
            //if(estructura[i].idMascota == eleccionID) //completar condicion
                // strcpy(estructura[i].raza ,nuevaCadena);        //completar igualdad
        }
        break;

    case 4:
        nuevoNumero = obtenerNumero("1.Masculino//2.Femenino\nIngrese el sexo");
        nuevoNumero = validacionDeNumero(nuevoNumero,1,2);
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idMascota == eleccionID && nuevoNumero == 1) //completar condicion
                strcpy(estructura[i].sexo,"MASCULINO");
            else if(estructura[i].idMascota == eleccionID && nuevoNumero == 2)
                strcpy(estructura[i].sexo,"FEMENINO");
        }
        break;

    case 5:
        nuevoNumero = obtenerNumero("Ingrese la nueva edad");
        validacionDeNumero(nuevoNumero,1,30);
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idMascota == eleccionID)    //completar condicion
               estructura[i].edad= nuevoNumero;    //completar igualdad
        }
        break;
    case 6:
        nuevoNumero = obtenerNumero("Ingrese el nuevo peso");
        validacionDeNumero(nuevoNumero,0,100);
        for(i=0;i<tamEstructura;i++)
        {
            if(estructura[i].idMascota == eleccionID)    //completar condicion
               estructura[i].peso = nuevoNumero;    //completar igualdad
        }
        break;

    }
}

void ImprMascotasOrdenadasPorTipo_ConDuenio(sMascota estructura[],int tamEstructura)
{
    int i,j;
    sMascota auxMascota;
    for(i=0;i<tamEstructura-1;i++)
    {
        for(j=i+1;j<tamEstructura;j++)
        {
            if(stricmp(estructura[i].tipo,estructura[j].tipo)>0)
            {
                auxMascota = estructura[i];
                estructura[i] = estructura[j];
                estructura[j] = auxMascota;
            }
        }
    }
    imprimirArrayMascotas_OCUPADOS(estructura,tamEstructura);
}

void ImprMascotasMasDe3Anios(sMascota estructura[],int tamEstructura)
{
    int i;
    int contador=0;
    printf ("NombreMascota---------TipoMascota-------------RazaMascota----------SexoMascota-------EdadMascota------PesoMascota------IdMascota-----NombreDuenio----\n");
    for(i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado != 0 && estructura[i].edad>3)
        {
            imprimirUnaSolaMascota_OCUPADOS(estructura[i]);
        }
    }
    if(contador==0)
        printf("No hay mascotas con mas de 3 anios");
}

void imprMascotasPorTipoEnParticular(sMascota estructura[], int tamEstructura)
{
    int i;
    int nuevoNumero;
    char nuevaCadena[10];
    int flag=0;
    nuevoNumero=obtenerNumero("1.Perros//2.Gatos//3.Raros");
    validacionDeNumero(nuevoNumero,1,3);
    switch(nuevoNumero)
    {
    case 1:
        strcpy(nuevaCadena,"PERRO");
        break;
    case 2:
        strcpy(nuevaCadena,"GATO");
        break;
    case 3:
        strcpy(nuevaCadena,"RARO");
        break;
    }
    printf ("NombreMascota---------TipoMascota-------------RazaMascota----------SexoMascota-------EdadMascota------PesoMascota------IdMascota-----NombreDuenio----\n");
    for(i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado != 0 && strcmp(estructura[i].tipo,nuevaCadena)==0)
        {
            imprimirUnaSolaMascota_OCUPADOS(estructura[i]);
            flag=1;
        }
    }
    if(flag==0)
        printf("No hay mascotas por ese tipo");
}

void promedioEdadMascotas(sMascota estructura[], int tamEstructura)
{
    int i;
    int contadorMascotas = 0;
    int acumuladorEdad = 0;
    float promedio;
    for(i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado != 0)
        {
            contadorMascotas++;
            acumuladorEdad = acumuladorEdad + estructura[i].edad;
        }
    }
    promedio = (float)acumuladorEdad / contadorMascotas;
    printf("El promedio de edad entre las mascotas es de: %.2f\n", promedio);
}

void promedioEdadMascotasPorTipo(sMascota estructura[], int tamEstructura)
{
    int contadorTipo[3];    //contador de cuantas mascotas hay por tipo. 0=gato 1=perro 2=raro
    int acumEdadTipo[3];    //acumulador de edad de mascotas por tipo. 0=gato 1=perro 2=raro
    float promedio[3];
    int i;
    for(i=0;i<3;i++)
    {
        contadorTipo[i]=0;
        acumEdadTipo[i]=0;
    }
    for(i=0;i<tamEstructura;i++)
    {
        if(strcmp(estructura[i].tipo,"GATO")==0)
        {
            contadorTipo[0]++;
            acumEdadTipo[0] = acumEdadTipo[0] + estructura[i].edad;
        }
        else if(strcmp(estructura[i].tipo,"PERRO")==0)
        {
            contadorTipo[1]++;
            acumEdadTipo[1] = acumEdadTipo[1] + estructura[i].edad;
        }
        else if(strcmp(estructura[i].tipo,"RARO")==0)
        {
            contadorTipo[2]++;
            acumEdadTipo[2] = acumEdadTipo[2] + estructura[i].edad;
        }
    }
    promedio[0]=(float)acumEdadTipo[0] / contadorTipo[0];
    promedio[1]=(float)acumEdadTipo[1] / contadorTipo[1];
    promedio[2]=(float)acumEdadTipo[2] / contadorTipo[2];

    printf("El promedio de edad de:\nGATOS: %.2f \nPERROS: %.2f\nRAROS: %.2f", promedio[0],promedio[1],promedio[2]);
}



