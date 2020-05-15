#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

/** \brief hardecode de employee
 *
 * \param sEmployee[]
 * \param len int
 * \return void
 **/
void hardcodearEmployee(sEmployee[], int len);


/** \brief Se despliega un menú de opciones y se retorna la eleccion que se haya selecionado;
 *
 * \return int
 *
 */
int menuOpciones();

/** \brief Creates a unique ID and put it in the id member of the struct array employee
 *
 * \param sEmployee [] array of the struct employee
 * \param tamEmployee int size of the array
 * \return void
 *
 */
void creadorDeId(sEmployee [],int );


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int initEmployees(sEmployee[],int);

/** \brief add in a existing list of employees the values received as parameters
*     in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
**/
int addEmployee(sEmployee [], int len, char name[],char lastName[],float salary,int sector);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1) *
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
**/
int removeEmployee(sEmployee[], int len, int id);

/** \brief Modify a employee: name, last name, age or sector
 *
 * \param sEmployee[]
 * \param len int length of the array
 * \param id int the id of the employee that we want to modify
 * \return int  return 0 if the modify is OK or -1 if there is an error
 *
 */
int modifyEmployee(sEmployee[],int len,int id);
/** \brief find an Employee by Id en returns the index position in array. *
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
**/
int findEmployeeById(sEmployee[], int len,int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order *
* \param list Employee*
* \param len int
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int sortEmployees(sEmployee[], int len, int order);

/** \brief Print the total and avarage salary of all the employees and print how many of them receive more than the avarege.
 * \param sEmployee[] array of the struct employee
 * \param len int   length of the struct array
 * \return void
 **/
void salaryEmployees(sEmployee[], int len);

/** \brief print the content of employees array *
* \param list Employee*
* \param length int
* \return int
**/
int printEmployees(sEmployee[], int tam);

/** \brief print only one employee (must specify the index)
 *
 * \param employee sEmployee
 * \return void
 **/
void printOneEmployee(sEmployee employee);
