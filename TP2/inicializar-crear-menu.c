#include "inicializar-crear-menu.h"

int menuOpciones()
{
    int opcion;
    printf("---BIENVENIDO AL MENU DE OPCIONES---\n");
    printf("1.Dar de alta un empleado\n");
    printf("2.Modificar un empleado\n3.Dar de baja un empleado\n");
    prinf("\4.Informes(SUBMENU)\nINGRESE 0 PARA SALIR DE LA CONSOLA");
    printf("\nIngrese Una Opcion: ");
    scanf("%d",&opcion);
    opcion = validacionDeNumero(opcion,0,10);
    return opcion;
}

/*
Se le pasa por parametro la opcion elegida en menu, las estructuras en las que va a buscar libre y los tamaños de los arrays
de las estructuras. ----> devuelve el indice libre (cuando esta en 0)
*/
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


void creadorDeId(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[],int tamOrquesta,int tamMusico, int tamInstrumento)
{
    int i;
    int j=1;
    int q=2;
    int p=3;
    for(i=0;i<tamOrquesta;i++)
    {
       orquesta[i].id = j;
       j = j + 10;
    }
    for(i=0;i<tamMusico;i++)
    {
        musico[i].idPersonal = q;
        q = q + 10;
    }
    for(i=0;i<tamInstrumento;i++)
    {
        instrumento[i].id = p;
        p = p + 10;
    }

}
