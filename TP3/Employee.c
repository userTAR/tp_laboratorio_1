#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* pEmployee;
    pEmployee = malloc(sizeof(Employee));
    if(pEmployee==NULL)
    {
        printf("NO HAY ESPACIO EN MEMORIA PARA UN EMPLEADO");
        return 0;
    }
    return pEmployee;
}
Employee* employee_newParametros(int* idStr,char* nombreStr,int* horasTrabajadasStr,int* sueldoStr)
{
    Employee* pEmployee;
    pEmployee = employee_new();

//    pEmployee->id = *idStr;
    employee_setId(pEmployee, *idStr);
//    strcpy(pEmployee->nombre,nombreStr);
    employee_setNombre(pEmployee, nombreStr);
//    pEmployee->horasTrabajadas = *horasTrabajadasStr;
    employee_setHorasTrabajadas(pEmployee, *horasTrabajadasStr);
//    pEmployee->sueldo = *sueldoStr;
    employee_setSueldo(pEmployee, *sueldoStr);
    return pEmployee;
}

int employee_setNombre(Employee* employee,char* nombre)
{
    if(employee==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(employee->nombre, nombre);
    return 1;
}

int employee_getNombre(Employee* employee,char* nombre)
{
    if(employee==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    strcpy(nombre,employee->nombre);
    return 1;

}



int employee_setSueldo(Employee* employee,int sueldo)
{
    if(employee==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    employee->sueldo = sueldo;
    return 1;

}
int employee_getSueldo(Employee* employee,int* sueldo)
{
    if(employee==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *sueldo = employee->sueldo;
    return 1;
}

int employee_setId(Employee* employee,int id)
{
    if(employee==NULL)
    {
        return 0;
    }
    employee->id = id;
    return 1;

}
int employee_getId(Employee* employee,int* id)
{
    if(employee==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *id = employee->id;
    return 1;

}

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas)
{
    if(employee==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    employee->horasTrabajadas = horasTrabajadas;
    return 1;

}
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajdas)
{
    if(employee==NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE EL PUNTERO APUNTA A NULO");
        return 0;
    }
    *horasTrabajdas = employee->horasTrabajadas;
    return 1;
}


int employee_CompareByName(Employee* employee1, Employee* employee2)
{
    if(employee1 == NULL || employee2 == NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE ALGUNO DE LOS PUNTEROS APUNTA A NULO");
        return 0;
    }
    return strcmp(employee1->nombre, employee2->nombre);
}

int employee_CompareById(Employee* employee1, Employee* employee2)
{
    if(employee1 == NULL || employee2 == NULL)
    {
        printf("NO ES POSIBLE SETEAR EL NOMBRE DEBIDO A QUE ALGUNO DE LOS PUNTEROS APUNTA A NULO");
        return NULL;
    }
    if(employee1->id > employee2->id)
    {
        return 1;
    }
    else
    {
        if(employee1->id < employee2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}



