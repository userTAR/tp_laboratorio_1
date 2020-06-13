#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un espacio en memoria dinámica para la estructura empleado
 *
 * \return Employee*
 **/
Employee* employee_new();

/** \brief Crea un espacio en memoria dinámica para la estructura empleado con todos los parámetros ya guardados
 *
 * \param idStr int*
 * \param nombreStr char*
 * \param horasTrabajadasStr int*
 * \param sueldoStr int*
 * \return Employee*
 **/
Employee* employee_newParametros(int* idStr,char* nombreStr,int* horasTrabajadasStr,int* sueldoStr);


/** \brief Setea la variable pasada como parámetro (ID) en el campo ID de la estructura empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 **/
int employee_setId(Employee* this,int id);


/** \brief Toma el valor del campo ID de la estructura empleado y lo copia a la variable ID
 *
 * \param this Employee*
 * \param id int*
 * \return int
 **/
int employee_getId(Employee* this,int* id);

/** \brief Setea la variable pasada como parámetro (NOMBRE) en el campo NOMBRE de la estructura empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 **/
int employee_setNombre(Employee* this,char* nombre);


/** \brief Toma el valor del campo NOMBRE de la estructura empleado y lo copia a la variable NOMBRE
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 **/
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setea la variable pasada como parámetro (HORAS TRABAJADAS) en el campo HORAS TRABAJADAS de la estructura empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 **/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Toma el valor del campo HORAS TRABAJADAS de la estructura empleado y lo copia a la variable HORAS TRABAJADAS
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 **/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Setea la variable pasada como parámetro (SUELDO) en el campo SUELDO de la estructura empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 **/
int employee_setSueldo(Employee* this,int sueldo);


/** \brief Toma el valor del campo SUELDO de la estructura empleado y lo copia a la variable SUELDO
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 **/
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara el campo NOMBRE de ambas estructuras empleado y devuelve el resultado del strcmp entre ambos campos
 *
 * \param e1 Employee*
 * \param e2 Employee*
 * \return int
 **/
int employee_CompareByName(Employee* e1, Employee* e2);


/** \brief Compara el campo ID
 *
 * \param e1 Employee*
 * \param e2 Employee*
 * \return int
 **/
int employee_CompareById(Employee* e1, Employee* e2);

#endif // employee_H_INCLUDED
