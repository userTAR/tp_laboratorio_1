#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    LinkedList* miLista = ll_newLinkedList();

    int choise;
    int control;
    choise = menuOpciones();
    for(;;)
    {

        if(choise==10)
        {
            choise = obtenerNumero("ESTA SEGURO QUE DESEA SALIR DEL PROGRAMA?\n1.SI // 2. NO");
            if(choise==1) break;
        }
    switch(choise)
    {
    case 1:
        control = controller_loadFromText("data.csv", miLista);
        if(control == 1) printf("CARGA DE ARCHIVO DE TEXTO: OK...");
        else printf("ERROR EN LA CARGA DE ARCHIVO DE TEXTO");
        break;
    case 2:
        control = controller_loadFromBinary("dataBIN.bin",miLista);
        if(control == 1) printf("CARGA DE ARCHIVOS BINARIO: OK...");
        else printf("ERROR EN LA CARGA DE ARCHIVO BINARIO");
        break;
    case 3:
        control = controller_addEmployee(miLista);
        if(control == 1) printf("ADICION DE EMPLEADO: OK...");
        else printf("ADICION DE EMPLEADO FALLIDA");
        break;
    case 4:
        control = controller_editEmployee(miLista);
        if(control == 1) printf("EDICION DE EMPLEADO: OK...");
        else printf("EDICION DE EMPLEADO FALLIDA");
        break;
    case 5:
        control = controller_removeEmployee(miLista);
        if(control == 1) printf("REMOCION DE EMPLEADO: OK...");
        else printf("REMOCION DE EMPLEADO FALLIDA");
        break;
    case 6:
        control = controller_ListEmployee(miLista);
        if(control == 1) printf("LISTADO DE EMPLEADOS: OK...");
        else printf("LISTADO DE EMPLEADOS FALLIDO");
        break;
    case 7:
        control = controller_sortEmployee(miLista);
        if(control == 1) printf("ORDENAMIENTO DE EMPLEADOS: OK...");
        else printf("ORDENAMIENTO DE EMPLEADOS FALLIDO");
        break;
    case 8:
        control = controller_saveAsText("data.csv",miLista);
        if(control == 1) printf ("GUARDADO EN FORMA DE ARCHIVO DE TEXTO: OK...");
        else printf("GUARDADO EN FORMA DE ARCHIVO DE TEXTO FALLIDO");
        break;
    case 9:
        control = controller_saveAsBinary("dataBIN.bin",miLista);
        if(control == 1) printf("GUARDADO EN FORMA DE ARCHIVO BINARIO: OK...");
        else printf("GUARDADO EN FORMA DE ARCHIVO BINARIO FALLIDO");
        break;
    }
    choise = reCall();
    }
}



    /*Employee* e1 = (Employee*) malloc(sizeof(Employee));
    Employee* e2 = (Employee*) malloc(sizeof(Employee));
    Employee* e3 = (Employee*) malloc(sizeof(Employee));

    e1->id = 5;
    e1->horasTrabajadas = 10;
    strcpy(e1->nombre,"Juan");
    e1->sueldo = 10000;

    e2->id = 1;
    e2->horasTrabajadas = 15;
    strcpy(e2->nombre,"Martin");
    e2->sueldo = 15000;

    e3->id = 3;
    e3->horasTrabajadas = 10;
    strcpy(e3->nombre,"Aria");
    e3->sueldo = 20000;

    ll_add(miLista, e1);
    ll_add(miLista, e2);
    ll_add(miLista, e3);



    size = ll_len(miLista);


    ll_sort(miLista,employee_CompareById,0);

    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

    printf("Remuevo 1\n");

    ll_remove(miLista, 1);

    size = ll_len(miLista);
    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }
    printf("El indice de e2 es: %d\n", ll_indexOf(miLista,e3));
    return 0;
    */








