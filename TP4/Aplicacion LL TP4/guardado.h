/** \brief Parsea el archivo de texto, guardando los fragmentos en variables, asignandole los valores
 *          de esas variables a un nuevo empleado y por ultimo lo agrega a la LL.
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int-> Devuelve 1 si el proceso fue completado o 0 si no fue completado
 *
 */
int parser_JuegoFromText(FILE* pFile , LinkedList* pArrayListJuegos);
/** \brief Lee los datos del archivo binario, guardandolos en una variable de tipo empleado.
 *          asigna los valores del empleado a variables y con esas variables se crea un nuevo empleado
 *          para guardarlo en la LL
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int-> Devuelve 1 si el proceso fue completado o si no fue completado
 *
 */
int parser_JuegoFromBinary(FILE* pFile , LinkedList* pArrayListJuegos);


//solo queda revisar tema cabecera a las 18:25.
