//-----------------------FUNCIONES AGREGADAS--------------
/** \brief Identifica todos los ID'S de los empleados dentro de LL y al ID mas grande le suma uno y lo devuelve
 *
 * \param pArrayListEmployee LinkedList*
 * \return int-> retorna el id
 **/
int controller_setId(LinkedList* pArrayListEmployee);
/** \brief Busca el id de un empleado dentro de la LL y devuelve el indice del empleado que tenga ese ID.
 *
 * \param pArrayListEmployee LinkedList*
 * \param idBuscado int-> Se le pasa el ID que se está buscando
 * \return int-> Devuelve el indice del empleado que tiene el ID buscado
 **/
int controller_getIndexById(LinkedList* pArrayListEmployee,int idBuscado);
//-------------------------FUNCIONES BASES-----------------------------------------------
/** \brief Abre el archivo correspondiente, pregunta si el archivo esta es nulo y luego llama
 *          a la funcion parserfromtext
 * \param path char*-> el nombre del archivo
 * \param pArrayListEmployee LinkedList*-> puntero a linkedlist
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Abre el archivo binario, pregunta si el archivo es nulo y luego llama a la funcion
 *          parserfrombinary
 * \param path char*-> el nombre del archivo
 * \param pArrayListEmployee LinkedList*-> puntero a linkedlist
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Adhiere un empleado
 *
 * \param pArrayListEmployee LinkedList*-> puntero a linkedlist
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Se edita un empleado existente, imprimiendo la LL y eligiendo el ID.
 *
 * \param pArrayListEmployee LinkedList*-> puntero a linkedlist
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Se imprime la lista, se elige el ID y se elimina el ID elegido
 *
 * \param pArrayListEmployee LinkedList*-> puntero a linkedlist
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Se listan todos los empleados de la LL
 *
 * \param pArrayListEmployee LinkedList*-> puntero a linkedlist
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Se ordenan los empleados utilizando las funciones comparedByID y comparedByName.
 *
 * \param pArrayListEmployee LinkedList*-> puntero a linkedlist
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Se guarda la LL que esta en memoria dinamica en el archivo csv *
 *
 * \param path char*-> nombre del archivo de texto
 * \param pArrayListEmployee LinkedList*
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Se guarda la LL que esta en memoria dinamica en el archivo binario
 *
 * \param path char*-> nombre del archivo binario
 * \param pArrayListEmployee LinkedList*
 * \return int-> devuelve 1 si fue completado // 0 si no se pudo
 **/
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


