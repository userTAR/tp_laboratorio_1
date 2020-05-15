#include "employee.h"
#define LIBRE 1
#define OCUPADO 0
#define tamEmployee 5


void hardcodearEmployee(sEmployee employee[],int len)
{
    int id[tamEmployee]={3,13,23,33,43};
    char nombre[tamEmployee][51]={"Juan","Maria","Ana","Pedro","Luisa"};
    char apellido[tamEmployee][51]={"a","b","c","d","e"};
    float salario[tamEmployee]={50000,15600,35000,80000,64500};
    int sectores[tamEmployee]={1,2,3,1,3}; //tipo de insturmento;
    int estado[tamEmployee]={0,0,0,0,0};

  int i;
  for(i=0; i<tamEmployee; i++)
  {
      employee[i].id = id[i];
      employee[i].sector = sectores[i];
      employee[i].salary = salario[i];
      employee[i].isEmpty = estado[i];
      strcpy(employee[i].name, nombre[i]);
      strcpy(employee[i].lastName, apellido[i]);
  }
}

int menuOpciones()
{
    int eleccion;
    printf("---BIENVENIDO AL MENU DE OPCIONES---\n");
    printf("1.Dar de alta un empleado\n");
    printf("2.Modificar un empleado\n3.Dar de baja un empleado\n");
    printf("4.Informes(SUBMENU)\nINGRESE 0 PARA SALIR DE LA CONSOLA");
    printf("\nIngrese Una Opcion: ");
    scanf("%d",&eleccion);
    eleccion = validacionDeNumero(eleccion,0,10);
    return eleccion;
}

void creadorDeId(sEmployee employee[],int len)
{
    int i;
    int j=1;
    for(i=0;i<len;i++)
    {
       employee[i].id = j;
       j = j + 10;
    }
}
int initEmployees(sEmployee employee[],int tam)
{
    int i;
    //pone todas las posiciones en libre;
    for(i=0;i<tam;i++)
       employee[i].isEmpty = LIBRE;
    for(i=0;i<tam;i++)
    {
        //si alguna posicion no esta en libre (1), devuelve -1.
        if(employee[i].isEmpty != LIBRE)
            return -1;
    }
    //si no, devuelve 0;
    return 0;
}
//addEmployee sirve para la parte de alta
int addEmployee(sEmployee employee[],int len,char name[],char lastName[],float salary,int sector)
{
    int i;
    //con el for recorre el array de empleados buscando un lugar libre;
    for(i=0;i<len;i++)
    {
        if(employee[i].isEmpty == 1)
        {
            strcpy(employee[i].name, name);
            strcpy(employee[i].lastName , lastName);
            employee[i].salary = salary;
            employee[i].sector = sector;
            employee[i].isEmpty = 0;
            return 0;
        }
    }
    return -1;
}
//removeEmployee sirve para la parte de bajas.
int removeEmployee(sEmployee employee[], int len, int id)
{
        employee[id].isEmpty = LIBRE;
        if(employee[id].isEmpty == LIBRE)
            return 0;
        else
            return -1;
}
int modifyEmployee(sEmployee employee[],int len, int id)
{
    int eleccionSubmenu;
        printf("1.Modificar Nombre\n2.Modificar Apellido\n3.Modificar salario");
        printf("\n4.Modificar sector");
        printf("Ingrese que desea cambiar del empleado: ");
        scanf("%d",&eleccionSubmenu);
        // se valida que el numero ingresado este entre los del menu
        validacionDeNumero(eleccionSubmenu,1,4);
        switch(eleccionSubmenu)
        {
        case 1:     //se le cambia el nombre usando el indice de la variable devFindEmployeeById
            printf("Ingrese el nuevo nombre");
            fflush(stdin);
            gets(employee[id].name);
            break;
        case 2:     //se le cambia el apellido usando el indice de la variable devFindEmployeeById
            printf("Ingrese el nuevo apellido");
            fflush(stdin);
            gets(employee[id].lastName);
            break;
        case 3:     // se le cambia el salario usando el indice de la variable devFindEmployeeById
            employee[id].salary = obtenerNumero("Ingrese el nuevo salario del empleado");
            break;
        case 4:     //se le cambia el sector usando el indice de la variable deFindEmployeeById
            employee[id].sector = obtenerNumero("Ingrese el nuevo sector del empleado");
            break;
        }
    return 0;
}
//findEmployeeById sirve para la parte de modificacion
int findEmployeeById(sEmployee employee[],int len,int id)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(employee[i].id == id)
            return i;
    }
    return -1;

}

int printEmployees(sEmployee employee[], int tam)
{
    int i;
    printf("Nombre--------Apellido--------ID--------Salario--------Sector\n");
    for (i=0;i<tam;i++)
    {
        if(employee[i].isEmpty != LIBRE)
        printOneEmployee(employee[i]);
    }
    return 0;
}

void printOneEmployee(sEmployee employee)
{
    if(employee.isEmpty!=LIBRE)
        printf("%8s  %9s  %10d \t %.2f  %8d\n", employee.name, employee.lastName, employee.id, employee.salary, employee.sector);
}
//--------------------------------------------------------INFORMES--------------------------------------------------------------------------

int sortEmployees(sEmployee employee[],int len, int order)
{
    int devPrintEmployee;
    //1 ORDENAN UP
    if(order == 1)
    {
        sEmployee auxEmployee;
        int p,j;
        for(p=0;p<len-1;p++)
        {
            for(j=p+1;j<len;j++)
            {
                if(stricmp(employee[p].lastName,employee[j].lastName)>0)
                {
                    auxEmployee= employee[p];
                    employee[p] = employee[j];
                    employee[j] = auxEmployee;
                }
            }
        }
       devPrintEmployee = printEmployees(employee,len);
       if(devPrintEmployee == 0)
            printf("Impresion ok...");
    }
    // 0 ORDENA DOWN
    else
    {
     sEmployee auxEmployee;
        int p,j;
        for(p=0;p<len-1;p++)
        {
            for(j=p+1;j<len;j++)
            {
                if(stricmp(employee[p].lastName,employee[j].lastName)<0)
                {
                    auxEmployee= employee[p];
                    employee[p] = employee[j];
                    employee[j] = auxEmployee;
                }
            }
        }
        devPrintEmployee = printEmployees(employee,len);
        if(devPrintEmployee == 0)
            printf("Impresion ok...");
    }
    return 0;
}

void salaryEmployees(sEmployee employee[],int len)
{
    int i;
    int contadorEmployee=0;
    int employeeOverSalary=0;
    float promedio;
    float acumuladorSalario=0;
    for(i=0;i<len;i++)
    {
        if(employee[i].isEmpty == OCUPADO)
        {
            acumuladorSalario = acumuladorSalario + employee[i].salary;
            contadorEmployee++;
        }
    }
    promedio = acumuladorSalario/contadorEmployee;
    for(i=0;i<len;i++)
    {
        if(employee[i].isEmpty == OCUPADO && employee[i].salary > promedio)
        {
            employeeOverSalary++;
        }
    }
    printf("El salario total sumado es: %.2f \t El promedio de los salarios es: %.2f \n", acumuladorSalario, promedio );
    printf("La cantidad de empleados que superan el promedio de salario es: %d", employeeOverSalary);
}
