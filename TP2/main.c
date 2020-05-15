#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#define tamEmployee 5 // puede ser que haya que eliminarlo por estar definido en employee.c


void switchOpciones(int,sEmployee[],int);
int reCall(void);
void pedidoDeDatos(char name[],char lastName[],float salary,int sector);
void subMenu(sEmployee employee[],int len);
void switchSubmenu(int opcion,sEmployee[],int len);

//----------------------------------MAIN----------------------------------------------------------
void main(void)
{
    int opciones;
    int init;
    sEmployee employee[tamEmployee];
    init = initEmployees(employee,tamEmployee);
    hardcodearEmployee(employee,tamEmployee);
    if(init == -1)
        printf("Error en inicialización");
    else
        printf("Inicializacion ok...\n");
    system("pause");
    system("cls");
    opciones = menuOpciones();
    while (opciones != 0)
    {
        switchOpciones(opciones, employee, tamEmployee);
        opciones = reCall();
    }
}

//-----------------------------------------------------------------------------------------------------

void switchOpciones(int opciones,sEmployee employee[],int len)
{

    int id;
    char name[51];
    char lastName[51];
    float salary = 0;
    int sector = 0;
    int devAddEmployee, devModifyEmployee, devRemoveEmployee, devFindEmployeeById;

    switch (opciones)
    {
    case 1:
        //Funcion que pide los datos para pasarselos a la funcion addEmployee
        printf("Ingrese el nombre del empleado: ");
        fflush(stdin);
        gets(name);
        printf("Ingrese el apellido del empleado: ");
        fflush(stdin);
        gets(lastName);
        printf("Ingrese el salario: ");
        fflush(stdin);
        scanf("%f",&salary);
        printf("Ingrese el sector: ");
        fflush(stdin);
        scanf("%d",&sector);
        //pedidoDeDatos(name,lastName,salary,sector);
        //se iguala la funcion a la variable dev para evaluar si dio error o no.
        devAddEmployee = addEmployee(employee,tamEmployee,name,lastName,salary,sector);
        //si dio error devuelve -1
        if(devAddEmployee == -1)
            printf("No se pudo ingresar el empleado por falta de espacio");
        //si esta ok devuelve 0
        else
            printf("Ingreso correcto");
        break;
    case 2:
        //Imprime empleados
        printEmployees(employee,tamEmployee);
        //pide el id y busca el indice del empleado con ese id
        id = obtenerNumero("Ingrese el id del empleado que desea modificar");
        //se iguala la funcion a la variable dev para evaluar si dio error o no.
        devModifyEmployee = modifyEmployee(employee,tamEmployee,id);
        //si da error devuelve -1
        if(devModifyEmployee == -1)
            printf("Error en la modificación");
        //si esta todo ok devuelve 0
        else
            printf("Modificacion OK...");
        break;
    case 3:
        //Imprime empleados
        printEmployees(employee,tamEmployee);
        //pide el id del empleado deseado y lo guarda en id
        id = obtenerNumero("Ingrese el id del empleado que busca:");
        //busca el indice por el id ingresado. y devuelve--> 1.el indice//2.-1 si error
        devFindEmployeeById = findEmployeeById(employee,tamEmployee,id);
        //si la devolucion es -1 el id no fue encontrado
        if(devFindEmployeeById == -1)
            printf("Error en la busqueda");
        /*
        se iguala la funcion remover empleado pasandole la estructura,el tamanio de la misma
        y el indice del empleado que queremos eliminar
        */
        devRemoveEmployee = removeEmployee(employee,len,devFindEmployeeById);
        //Si devuelve -1 hay error
        if(devRemoveEmployee == -1)
            printf("Error en la eliminacion");
        //Si devuelve 0, eliminacion ok.
        else
            printf("Eliminacion OK...");
        break;
    case 4:
        subMenu(employee,len);
        break;
    }
}

int reCall(void)
{
    int i;
     printf("\n");
    system("pause");
    system("cls");
    i = menuOpciones();
    return i;
}

void pedidoDeDatos(char name[],char lastName[],float salary,int sector)
{
    printf("Ingrese el nombre del empleado: ");
    fflush(stdin);
    gets(name);
    printf("Ingrese el apellido del empleado: ");
    fflush(stdin);
    gets(lastName);
    printf("Ingrese el salario: ");
    fflush(stdin);
    scanf("%f",&salary);
    printf("Ingrese el sector: ");
    fflush(stdin);
    scanf("%d",&sector);

}
void subMenu(sEmployee employee[],int len)
{
    int opcion;
    printf("---BIENVENIDO AL MENU DE OPCIONES---\n");
    printf("1.Ordenar empleados\n");
    printf("2.Mostrar salarios total, promedio y cuantos superan el promedio\n");
    printf("Ingrese Una Opcion: ");
    scanf("%d",&opcion);
    opcion = validacionDeNumero(opcion,1,2);
    switchSubmenu(opcion,employee,len);

}
void switchSubmenu(int opcion,sEmployee employee[],int len)
{
    int order;
    if(opcion == 1)
    {
        order = obtenerNumero("Ingrese el orden: 1 (UP) 0(DOWN)");
        order = validacionDeNumero(order,0,1);
    }
    switch(opcion)
    {
    case 1:
        sortEmployees(employee,tamEmployee,order);
        break;
    case 2:
        salaryEmployees(employee,tamEmployee);
        break;
    }
}
