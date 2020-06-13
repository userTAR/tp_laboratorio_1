#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/*
La funcion lee el archivo de texto y lo guarda en un empleado y el empleado lo agrega a linked list.
*/
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* employee;
    char id[21];
    char nombre[21];
    char horas[21];
    char salario[21];
    int idNum;
    int horasNum;
    int salarioNum;
    fseek(pFile,33,SEEK_SET);
    while(!feof(pFile))
    {
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,salario); //hay error
    idNum = atoi(id);
    horasNum = atoi(horas);
    salarioNum = atoi(salario);
    employee = employee_newParametros(&idNum,nombre,&horasNum,&salarioNum);
    ll_add(pArrayListEmployee,employee);
    }
    return 1;
}
//lector de archivo binario
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int devFread;

    fseek(pFile,33,SEEK_SET);
    while(!feof(pFile))
    {
        employee = employee_new();
        devFread = fread(employee,sizeof(Employee),1,pFile);
        if(devFread != 1)
        {
            break;
        }
        ll_add(pArrayListEmployee,employee);

    }
    return 1;
}
