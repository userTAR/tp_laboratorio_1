#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "estructura-afines.h"
#include "guardado.h"
#include "validaciones.h"
#include "controlador.h"



//codigo del id incrementado en 1 respecto del id mas grande de la lista de empleados.
int controller_setId(LinkedList* pArrayListJuegos)
{
    sJuego* pJuego;
    int size;
    int i;
    int mayor;
    int idObtenido;


    size = ll_len(pArrayListJuegos);
    if(size == 0)
    {
        return size;
    }
    for(i=0;i<size;i++)
    {
        pJuego = ll_get(pArrayListJuegos,i);
        videojuego_getId(pJuego,&idObtenido);
        if(i==0 || idObtenido>mayor)
        {
            mayor = idObtenido;
        }

    }
    return (mayor+1);
}
/*
Este archivo es el encargado de abrir el file y luego se llama a la funcion
parser text para guardar los datos en un empleado y luego en la linkedlist
*/
int controller_loadFromText(char* path, LinkedList* pArrayListJuegos)
{
    FILE* pFile;
    ll_clear(pArrayListJuegos);
    pFile = fopen(path,"r");

    if(pArrayListJuegos!= NULL)
    {
        if(pFile == NULL)
        {
            printf("EL ARCHIVO AUN NO EXISTE\n");
            return 0;
        }
        parser_JuegoFromText(pFile,pArrayListJuegos);
    }
    else
    {
        printf("EL PUNTERO A LINKEDLIST APUNTA A NULO, ERROR...");
        return 0;
    }
    fclose(pFile);
    return 1;
}

/*
Este archivo es el encargado de abrir el file y luego se llama a la funcion
parser binario para guardar los datos en un empleado y luego en la linkedlist
*/
int controller_loadFromBinary(char* path, LinkedList* pArrayListJuegos)
{
    FILE* pFile;
    ll_clear(pArrayListJuegos);
    pFile = fopen(path,"rb");

    if(pArrayListJuegos != NULL)
    {
        if(pFile == NULL)
        {
            printf("EL ARCHIVO AUN NO EXISTE\n");
            return 0;
        }
        parser_JuegoFromBinary(pFile,pArrayListJuegos);
        fclose(pFile);
        return 1;
    }
    else
    {
        printf("EL PUNTERO A LINKEDLIST APUNTA A NULO, ERROR...");
        return 0;
    }
}


int controller_addGame(LinkedList* pArrayListJuegos)
{
    sJuego* pJuego;
    char nombre[20];
    int horasJugables;
    float precio;
    int stock;
    int id;
    int dev;

    pJuego = videojuego_new();
    if(pJuego == NULL)
    {
        printf("NO EXISTE ESPACIO EN MEMORIA PARA ALMACENAR UN JUEGO");
    }
    else
    {
        do
        {
            dev = obtenerCadena("INGRESE EL NOMBRE DEL NUEVO JUEGO", nombre);
        }while(dev==0);
        horasJugables = obtenerNumero("INGRESE LA CANTIDAD DE HORAS DE JUGABILIDAD DEL VIDEOJUEGO");
        horasJugables= validacionDeNumero(horasJugables,1,1000000);
        precio = obtenerNumero("INGRESE EL PRECIO DEL JUEGO");
        precio = validacionDeNumero(precio,1,10000);
        stock = obtenerNumero("INGRESE EL STOCK TOTAL DEL JUEGO");
        stock = validacionDeNumero(stock,1,1000);
        id = controller_setId(pArrayListJuegos);
        videojuego_setNombre(pJuego,nombre);
        videojuego_setHorasJugables(pJuego,horasJugables);
        videojuego_setPrecio(pJuego,precio);
        videojuego_setStock(pJuego,stock);
        videojuego_setId(pJuego,id);
        ll_add(pArrayListJuegos,pJuego);
    }
    return 1;
}

int controller_getIndexById(LinkedList* pArrayListEmployee,int idBuscado)
{
    Employee* employee;
    int size;
    int i;
    int idObtenido;

    size = ll_len(pArrayListEmployee);
    for(i=0;i<size;i++)
    {
        employee = ll_get(pArrayListEmployee,i);
        employee_getId(employee,&idObtenido);
        if(idObtenido == idBuscado)
        {
            return i;
        }

    }
    return -1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int id;
    int index = -1;
    int keepEditting = 1;
    int choise;
    int nuevoNumero;
    char nuevaCadena[21];

    controller_ListEmployee(pArrayListEmployee);
    while(index == -1)
    {
        id = obtenerNumero("\nINGRESE EL ID DEL EMPLEADO QUE QUIERA MODIFICAR");
        index = controller_getIndexById(pArrayListEmployee,id);
        if(index == -1)
        {
            printf("EL ID INGRESADO NO EXISTE\n");
            index = -1;
        }
        else
            break;
    }
    pEmployee = ll_get(pArrayListEmployee,index);
    while(keepEditting == 1)
    {
        choise = obtenerNumero("1.MODIFICAR NOMBRE\n2.HORAS TRABAJADAS\n3.SUELDO\n ELECCION");
        switch(choise)
        {
            case 1:
                obtenerCadena("INGRESE EL NUEVO NOMBRE DEL EMPLEADO", nuevaCadena);
                employee_setNombre(pEmployee,nuevaCadena);
                break;
            case 2:
                nuevoNumero = obtenerNumero("INGRESE LA NUEVA CANTIDAD DE HORAS TRABAJADAS POR EL EMPLEADO");
                employee_setHorasTrabajadas(pEmployee,nuevoNumero);
                break;
            case 3:
                nuevoNumero = obtenerNumero("INGRESE EL NUEVO SUELDO DEL EMPLEADO");
                employee_setSueldo(pEmployee,nuevoNumero);
                break;
        }
        keepEditting = obtenerNumero("DESEA MODIFICAR OTRA CAMPO DEL EMPLEADO?\n1.SI//2.NO");
    }
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index = -1;
    int keepErasing = 1;

    controller_ListEmployee(pArrayListEmployee);
    while(keepErasing == 1)
    {
        while(index == -1)
        {
            id = obtenerNumero("INGRESE EL ID DEL EMPLEADO QUE QUIERA MODIFICAR");
            index = controller_getIndexById(pArrayListEmployee,id);
            if(index == -1)
            {
                printf("EL ID INGRESADO NO EXISTE\n");
            }
            else
                continue;
        }
        ll_remove(pArrayListEmployee,index);
        keepErasing = obtenerNumero("DESEA ELIMINAR OTRO EMPLEADO?\n1.SI//2.NO");
        if(keepErasing==1)
        {
            index = -1;
        }
        else
            break;
    }
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int size;
    int id;
    char nombre[21];
    int horas;
    int sueldo;

    printf("ID-------NOMBRE-------HORAS TRABAJADAS--------SUELDO\n");
    size=ll_len(pArrayListEmployee);
    for(i=0;i<size;i++)
    {
        auxEmployee = ll_get(pArrayListEmployee,i);
        employee_getId(auxEmployee,&id);
        employee_getNombre(auxEmployee,nombre);
        employee_getHorasTrabajadas(auxEmployee,&horas);
        employee_getSueldo(auxEmployee,&sueldo);
        printf("%d %12s %8d %10d\n",id,nombre,horas,sueldo);
    }
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int choise;
    int upOrDown;
    choise = obtenerNumero("-MENU DE ORDENAMIENTO-\n1.ORDENAR POR NOMBRE//2.ORDENAR POR ID\n ELECCION");
    choise = validacionDeNumero(choise,1,2);
    upOrDown = obtenerNumero("0.ORDENAR DE FORMA DESCENDENTE//1.ORDENAR DE FORMA ASCENDENTE\n ELECCION");
    upOrDown = validacionDeNumero(upOrDown,0,1);
    switch(choise)
    {
    case 1:
        ll_sort(pArrayListEmployee,employee_CompareByName,upOrDown);
        break;
    case 2:
        ll_sort(pArrayListEmployee,employee_CompareById,upOrDown);
        break;
    }
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* employeeAux;
    int i;
    int size;
    char nombre[21];
    int id;
    int horas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
    pFile = fopen(path,"w");
    if(pFile == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        return 0;
    }
    else
    {
        size = ll_len(pArrayListEmployee);
        fprintf(pFile,"id,nombre,horastrabajadas,sueldo\n");
        for(i=0;i<size;i++)
        {
                employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(employeeAux, &id);
                employee_getNombre(employeeAux,nombre);
                employee_getHorasTrabajadas(employeeAux,&horas);
                employee_getSueldo(employeeAux, &sueldo);
                fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
        }
    }
    fclose(pFile);
    return 1;
    }
    else printf("DIRECCION DE MEMORIA DE LINKEDLIST INCORRECTA");
    return 0;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* employee;
    int size;
    int i;
    char cabecera[33]={"id,nombre,horastrabajadas,sueldo\n"};

    if(pArrayListEmployee != NULL)
    {
    pFile = fopen(path,"wb");
    if(pFile == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        return 0;
    }
    else
    {
        fwrite(cabecera,sizeof(char[33]),1,pFile);
        size = ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
                employee = (Employee*)ll_get(pArrayListEmployee,i);
                fwrite(employee,sizeof(Employee),1,pFile);
        }
    }
    fclose(pFile);
    return 1;
    }
    else printf("DIRECCION DE MEMORIA DE LINKEDLIST INCORRECTA");
    return 0;

}

