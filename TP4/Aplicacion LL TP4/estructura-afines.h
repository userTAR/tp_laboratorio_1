
typedef struct
{
    int idVideoJuego;
    char nombreVideoJuego[128];
    int horasJugables;
    float precioVideoJuego;
    int stock;
}sJuego;

/** \brief Crea un espacio en memoria dinámica para la estructura empleado
 *
 * \return Employee*
 **/
sJuego* videojuego_new();

/** \brief Crea un espacio en memoria dinámica para la estructura empleado con todos los parámetros ya guardados
 *
 * \param idStr int*
 * \param nombreStr char*
 * \param horasTrabajadasStr int*
 * \param sueldoStr int*
 * \return Employee*
 **/
sJuego* videojuego_newParametros(int* idStr,char* nombreStr,int* horasJugablesStr,int* precioStr,int*stockStr);

int videojuego_setStock(sJuego* juego,int stock);

/** \brief Setea la variable pasada como parámetro (ID) en el campo ID de la estructura empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 **/
int videojuego_setId(sJuego* this,int id);
int videojuego_getStock(sJuego* juego,int* stock);


/** \brief Toma el valor del campo ID de la estructura empleado y lo copia a la variable ID
 *
 * \param this Employee*
 * \param id int*
 * \return int
 **/
int videojuego_getId(sJuego* this,int* id);

/** \brief Setea la variable pasada como parámetro (NOMBRE) en el campo NOMBRE de la estructura empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 **/
int videojuego_setNombre(sJuego* this,char* nombre);


/** \brief Toma el valor del campo NOMBRE de la estructura empleado y lo copia a la variable NOMBRE
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 **/
int videojuego_getNombre(sJuego* this,char* nombre);

/** \brief Setea la variable pasada como parámetro (HORAS TRABAJADAS) en el campo HORAS TRABAJADAS de la estructura empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 **/
int videojuego_setHorasJugables(sJuego* this,int horasJugables);


/** \brief Toma el valor del campo HORAS TRABAJADAS de la estructura empleado y lo copia a la variable HORAS TRABAJADAS
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 **/
int videojuego_getHorasJugables(sJuego* this,int* horasJugables);

/** \brief Setea la variable pasada como parámetro (SUELDO) en el campo SUELDO de la estructura empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 **/
int videojuego_setPrecio(sJuego* this,float precioJuego);


/** \brief Toma el valor del campo SUELDO de la estructura empleado y lo copia a la variable SUELDO
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 **/
int videojuego_getPrecio(sJuego* this,float* precioJuego);

/** \brief Compara el campo NOMBRE de ambas estructuras empleado y devuelve el resultado del strcmp entre ambos campos
 *
 * \param e1 Employee*
 * \param e2 Employee*
 * \return int
 **/
int videojuego_CompareByName(sJuego* e1, sJuego* e2);


/** \brief Compara el campo ID
 *
 * \param e1 Employee*
 * \param e2 Employee*
 * \return int
 **/
int videojuego_CompareById(sJuego* e1, sJuego* e2);

