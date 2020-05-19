#include "cliente-mascotas.h"
#define LIBRE 0
#define OCUPADO 1

void hardcodearEstructuras(sCliente cliente[],sMascota mascota[],sRaza raza[],int tamEstructura1, int tamEstructura2,int tamEstructura3)
{
    char nombreCliente[5][20] = {"Stella","Pablo","Lucia","Tomas","Esteban"}; //nombre
    char apellidoCliente[5][20] = {"Galvan","Rivero","Zanchi","Rivero","Lopez"};    //apellido
    char lugarCliente[5][20] = {"Balvanera","Villa Caraza","Lanus","Constitucion","Palermo"};    //lugar
    char sexoCliente[5][20]={"FEMENINO","MASCULINO","FEMENINO","MASCULINO","MASCULINO"};
    int telefonoCliente[5]={111,222,333,444,555};  //un telefono/TIPO/MOTIVO o algo asi
    int edadCliente[5]={48,35,20,19,58}; //una edad
    int idPersonalCLiente[5]={1,11,21,31,41};      //un id personal
    int cantidadMascotas[5]={2,3,2,1,3};
    int estadoCliente[5]={1,1,1,1,1};    //un estado

    char nombreMascota[11][20] = {"LUZ","MANCHA","PACO","PLATURNO","GASTON","MALO","IGU","LADRA","MICHI","FUCHI","RONCO"}; //nombre
    //char string6[5][20] = {"Balvanera","Villa Caraza","Lanus","Constitucion","Palermo"};    //lugar
    char sexoMascota[11][20]={"FEMENINO","FEMENINO","MASCULINO","MASCULINO","MASCULINO","MASCULINO","MASCULINO","MASCULINO","MASCULINO","MASCULINO","MASCULINO"};  //sexo(1=masc'M' 2=fem 'F')
    char tipoMascota[11][10]={"GATO","GATO","PERRO","PERRO","GATO","PERRO","RARO","PERRO","GATO","GATO","PERRO"};  //un telefono/TIPO/MOTIVO o algo asi
    char NombreRazaMascota[11][20] = {"Bengala","British","Bull","Pitbull","Bengala","Pitbull","Camaleon","Bull","Bengala","British","Bull"};    //apellido u otra cosa
    char PaisRazaMascota[11][20] = {"Argentina","Inglaterra","Espania","Italia","Argentina","Italia","China","Espania","Argentina","Inglaterra","Espania"};    //apellido u otra cosa
    int tipoRaza[11]={2,2,1,1,2,1,3,1,2,2,1}; //una edad
    int idRazaMascota[11]={3,13,23,33,3,33,43,23,3,13,23}; //una edad
    int edadMascota[11]={1,3,5,7,4,5,11,4,2,3,4}; //una edad
    int pesoMascota[11]={25,63,45,8,6,8,4,1,5,22,31};
    int idMascota[11]={2,12,22,32,42,52,62,72,82,92,102};      //un id personal
    int idDuenio[11]={1,1,11,11,11,21,21,31,41,41,41};      //un id relacionador a la otra estructura
    char nombreDuenio[11][20] = {"Stella","Stella","Pablo","Pablo","Pablo","Lucia","Lucia","Tomas","Esteban","Esteban","Esteban"}; //nombre
    int estadoMascota[11]={1,1,1,1,1,1,1,1,1,1,1};    //un estado


    char razas[6][20] = {"Bengala","British","Bull","Pitbull","Camaleon","Anolis"};    //apellido u otra cosa
    char PaisRaza[6][20] = {"Argentina","Inglaterra","Espania","Italia","China","Japon"};    //apellido u otra cosa
    int razatipo[6]={2,2,1,1,3,3}; //una edad
    int idRaza[6]={3,13,23,33,43,53};
    int estadoRaza[6]={1,1,1,1,1,1};
  int i;

  for(i=0; i<tamEstructura1;i++) //cliente
  {
      strcpy(cliente[i].nombre, nombreCliente[i]);
      strcpy(cliente[i].apellido, apellidoCliente[i]);
      strcpy(cliente[i].localidad, lugarCliente[i]);
      strcpy(cliente[i].sexo, sexoCliente[i]);

      cliente[i].telefono= telefonoCliente[i];
      cliente[i].edad= edadCliente[i];
      cliente[i].idPersonal = idPersonalCLiente[i];
      cliente[i].cantMascotas = cantidadMascotas[i];
      cliente[i].estado = estadoCliente[i];
  }

  for(i=0; i<tamEstructura2;i++)
  {
      strcpy(mascota[i].nombreMascota, nombreMascota[i]);
      strcpy(mascota[i].raza.NombreRaza, NombreRazaMascota[i]);
      strcpy(mascota[i].raza.paisRaza, PaisRazaMascota[i]);
      strcpy(mascota[i].sexo, sexoMascota[i]);
      strcpy(mascota[i].tipo, tipoMascota[i]);
      strcpy(mascota[i].nombreDuenio, nombreDuenio[i]);

      mascota[i].raza.tipoRaza= tipoRaza[i];
      mascota[i].raza.IdRaza= idRazaMascota[i];
      mascota[i].edad = edadMascota[i];
      mascota[i].peso = pesoMascota[i];
      mascota[i].idMascota = idMascota[i];
      mascota[i].idDuenio = idDuenio[i];
      mascota[i].estado = estadoMascota[i];
  }
  for(i=0;i<tamEstructura3;i++)
  {
        strcpy(raza[i].NombreRaza, razas[i]);
        strcpy(raza[i].paisRaza, PaisRaza[i]);
        raza[i].tipoRaza = razatipo[i];
        raza[i].IdRaza = idRaza[i];
        raza[i].estado = estadoRaza[i];
  }
}



void listarDueniosConSusMascotas(sCliente cliente[],sMascota mascota[],int tamEstructura1,int tamEstructura2)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        printf("Las mascotas del cliente: \n");
        imprimirUnSoloCliente_OCUPADOS(cliente[i]);
        printf ("NombreMascota---------TipoMascota:------------RazaMascota:-------- SexoMascota:----- EdadMascota:---- PesoMascota:-----IdMascota:----IdDuenio:---\n");
        for(j=0;j<11;j++)
        {
            if(cliente[i].idPersonal == mascota[j].idDuenio && cliente[i].estado != 0)
            {
               imprimirUnaSolaMascota_OCUPADOS(mascota[j]);
            }
        }
    }
}



void agregarMascota(sCliente cliente[],sMascota estructura[],sRaza estructura2[],int tamCliente,int tamMascota,int tamEstructura2) //cambiarle el tipo de estructura
{
    int i,j;
    int indice;
    int tipo;
    int sexo;
    int peso;
    int edad;
    int idDuenio;
    int idRaza;
    imprimirArrayClientes_OCUPADOS(cliente,tamCliente);
    idDuenio=obtenerNumero("\nIngrese el id del cliente al que pertenece el perro");
    indice = buscarLibreMascota(estructura,tamMascota);
    obtenerCadena("Ingrese el nombre de la mascota",estructura[indice].nombreMascota);
    tipo = obtenerNumero("1.perro\n2.gato\n3.raro\nIngrese el tipo de mascota");
    tipo = validacionDeNumero(tipo,1,3);
    switch(tipo)
    {
    case 1:
        strcpy(estructura[indice].tipo, "PERRO");
        for(i=0;i<6;i++)
        {
            if(estructura2[i].tipoRaza == tipo && estructura2[i].estado!=0)
            {
                printf("Raza:%8s PaisRaza: %8s Id:Raza:%5d \n",estructura2[i].NombreRaza,estructura2[i].paisRaza,estructura2[i].IdRaza);
            }
        }
        idRaza= obtenerNumero("Ingrese el ID de la raza que quiera:");
        for(j=0;j<tamEstructura2;j++)
        {
           if(estructura2[j].IdRaza == idRaza)
            {
                strcpy(estructura[indice].raza.NombreRaza,estructura2[j].NombreRaza);
                strcpy(estructura[indice].raza.paisRaza,estructura2[j].paisRaza);
                estructura[indice].raza.tipoRaza = estructura2[j].tipoRaza;

            }
        }
        break;
    case 2:
        strcpy(estructura[indice].tipo, "GATO");
        for(i=0;i<6;i++)
        {
            if(estructura2[i].tipoRaza == tipo && estructura2[i].estado!=0)
            {
                printf("Raza:%8s PaisRaza: %8s Id:Raza:%5d \n",estructura2[i].NombreRaza,estructura2[i].paisRaza,estructura2[i].IdRaza);
            }
        }
        idRaza= obtenerNumero("Ingrese el ID de la raza que quiera:");
        for(j=0;j<tamMascota;j++)
        {
           if(estructura2[j].IdRaza == idRaza)
            {
                strcpy(estructura[indice].raza.NombreRaza,estructura2[j].NombreRaza);
                strcpy(estructura[indice].raza.paisRaza,estructura2[j].paisRaza);
                estructura[indice].raza.tipoRaza = estructura2[j].tipoRaza;

            }
        }
        break;
    case 3:
        strcpy(estructura[indice].tipo, "RARO");
        for(i=0;i<6;i++)
        {
            if(estructura2[i].tipoRaza == tipo && estructura2[i].estado!=0)
            {
                printf("Raza:%8s PaisRaza: %8s Id:Raza:%5d \n",estructura2[i].NombreRaza,estructura2[i].paisRaza,estructura2[i].IdRaza);
            }
        }
        idRaza= obtenerNumero("Ingrese el ID de la raza que quiera:");
        for(j=0;j<tamEstructura2;j++)
        {
           if(estructura2[j].IdRaza == idRaza)
            {
                strcpy(estructura[indice].raza.NombreRaza,estructura2[j].NombreRaza);
                strcpy(estructura[indice].raza.paisRaza,estructura2[j].paisRaza);
                estructura[indice].raza.tipoRaza = estructura2[j].tipoRaza;

            }
        }
        break;
    }
    //obtenerCadena("Ingrese la raza del animal",estructura[indice].raza);
    sexo = obtenerNumero("1.Masculino\n2.Femenino\nIngrese el sexo");
    validacionDeNumero(sexo,1,2);
    switch(sexo)
    {
    case 1:
        strcpy(estructura[indice].sexo, "MASCULINO");
        break;
    case 2:
        strcpy(estructura[indice].sexo, "FEMENINO");
        break;
    }
    peso=obtenerNumero("Ingrese el peso");
    edad=obtenerNumero("Ingrese la edad");
    estructura[indice].idDuenio=idDuenio;
    estructura[indice].peso = peso;
    estructura[indice].edad = edad;
    for(i=0;i<tamCliente;i++)
    {
        if(cliente[i].idPersonal == idDuenio)
        {
            strcpy(estructura[indice].nombreDuenio,cliente[i].nombre);
            cliente[i].cantMascotas++;
        }

    }
    estructura[indice].estado = OCUPADO;
}

void eliminarMascota(sCliente estructura[],sMascota estructura2[],int tamEstructura,int tamEstructura2) //cambiarle el tipo de estructura
{
   int indice;
   int i;
   indice = buscarIndiceDeMascotaPorId(estructura2,tamEstructura2);
   estructura2[indice].estado = LIBRE;
   for(i=0;i<tamEstructura;i++)
    {
        if(estructura[i].idPersonal == estructura2[indice].idDuenio)
            estructura[i].cantMascotas--;
    }
}

void eliminarClienteENCascada(sCliente estructura[],sMascota estructura2[],int tamEstructura1, int tamEstructura2) //cambiarle el tipo de estructura
{
   int indice;
   int i;
   indice = buscarIndiceDeClientePorId(estructura,tamEstructura1);
   estructura[indice].estado = LIBRE;
   for(i=0;i<tamEstructura2;i++)
   {
       if(estructura[indice].idPersonal == estructura2[i].idDuenio)
            estructura2[i].estado = 0;
   }
}



void ImprclienteMasDeUnaMascota(sCliente estructura[],sMascota estructura2[], int tamEstructura, int tamEstructura2)
{
    int i;
    int j;
    int contador;
    printf("NOMBRE-----------------APELLIDO----------LOCALIDAD----TELEFONO--------EDAD--------SEXO-------IDPERSONAL\n");
    for(i=0;i<tamEstructura;i++)
    {
        if(estructura[i].estado != 0)
        {
        contador=0;
        for(j=0;j<tamEstructura2;j++)
        {
            if(estructura[i].idPersonal == estructura2[j].idDuenio)
                contador++;
        }
        }
    if(contador>1)
        imprimirUnSoloCliente_OCUPADOS(estructura[i]);
    }
    if(contador == 0)
        printf("No hay clientes con mas de una mascota");
}



void  imprClientesOrdenadosPorCantMascotas(sCliente estructura[],sMascota estructura2[],int tamEstructura,int tamEstructura2)
{
    int i;
    int j;
    sCliente auxCliente;

    for(i=0;i<tamEstructura-1;i++)
    {
        for(j=i+1;j<tamEstructura;j++)
        {
            if(estructura[i].cantMascotas<estructura[j].cantMascotas)
            {
                auxCliente = estructura[i];
                estructura[i] = estructura[j];
                estructura[j] = auxCliente;
            }
        }
     }
    imprimirArrayClientes_OCUPADOS(estructura,tamEstructura);
}

void imprClientesOrdenadosPorCantMascotas_Nombre(sCliente estructura[],sMascota estructura2[],int tamEstructura,int tamEstructura2)
{
    int i;
    int j;
    sCliente auxCliente;

    for(i=0;i<tamEstructura-1;i++)
    {
        for(j=i+1;j<tamEstructura;j++)
        {
            if(estructura[i].cantMascotas<estructura[j].cantMascotas)
            {
                auxCliente = estructura[i];
                estructura[i] = estructura[j];
                estructura[j] = auxCliente;
            }
            else if(estructura[i].cantMascotas == estructura[j].cantMascotas)
            {
                if(strcmp(estructura[i].nombre,estructura[j].nombre)>0)
                {
                auxCliente = estructura[i];
                estructura[i] = estructura[j];
                estructura[j] = auxCliente;
                }
            }
        }
     }
    imprimirArrayClientes_OCUPADOS(estructura,tamEstructura);
}

void promedioVarones_Mujeres(sCliente estructura[],int tamEstructura)
{
    int contador=0; // 0==hombre / 1==mujeres
    int acumulador[2]={0,0}; // 0==hombre / 1==mujeres
    float promedio[2];
    int i;
    for(i=0;i<tamEstructura;i++)
    {
        if(strcmp(estructura[i].sexo, "FEMENINO") == 0)
        {
            contador++;
            acumulador[0]++;
        }
        else if(strcmp(estructura[i].sexo, "MASCULINO") == 0)
        {
            contador++;
            acumulador[1]++;
        }
    }
    promedio[0] = (float)acumulador[0] / contador;
    promedio[1] = (float)acumulador[1] / contador;
    printf("El porcentaje de mujeres es: %.1f \nEl porcentaje de hombres es: %.1f \n",(promedio[0])*100,(promedio[1])*100);
}

void promedioEdadVarones_Mujeres(sCliente estructura[],int tamEstructura)
{
    int contador[2]={0,0}; // 0==hombre / 1==mujeres
    int acumulador[2]={0,0}; // 0==hombre / 1==mujeres
    float promedio[2];
    int i;
    for(i=0;i<tamEstructura;i++)
    {
        if(strcmp(estructura[i].sexo, "FEMENINO") == 0)
        {
            contador[0]++;
            acumulador[0] = estructura[i].edad + acumulador[0];
        }
        else if(strcmp(estructura[i].sexo, "MASCULINO") == 0)
        {
            contador[1]++;
            acumulador[1] = estructura[i].edad + acumulador[1];
        }
    }
    promedio[0] = (float)acumulador[0] / contador[0];
    promedio[1] = (float)acumulador[1] / contador[1];
    printf("El promedio de edad de las mujeres es: %.1f \nEl promedio de edad de los hombres es: %.1f \n",promedio[0],promedio[1]);
}


