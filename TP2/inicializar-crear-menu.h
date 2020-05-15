#include <stdio.h>
#include <stdlib.h>

/** \brief Se despliega un menú de opciones y se retorna la eleccion que se haya selecionado;
 *
 * \return int
 *
 */
int menuOpciones();

/** \brief Se le pasa la opcion elegida en menu junto a estructuras y dependiendo de la opcion devuelve
 *          el indice de la estructura correspondiente.
 * \param opcion, estructuras, tamaño de los arrays de estructuras
 * \return indice (int)
 *
 */
int buscarLibre(int opcion,eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]
                       ,int tamOrquesta, int tamMusico, int tamInstrumento);



/** \brief Pone a la variable estado de una estructura en 0. Sea una estructura unica o un array de estructuras;
 *
 * \return void
 *
 */
void inicializarEstado(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]
                       ,int tamOrquesta, int tamMusico, int tamInstrumento);

/** \brief Pone la variable ID de las estructuras en 0.
 *
 * \param estructuras a las que se les va a poner el id en 0
 * \param
 * \return void
 *
 */
void inicializadorDeId(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]
                       ,int tamOrquesta, int tamMusico, int tamInstrumento);

/** \brief Le asiga 1 valor decreciente a cada uno de los arrays de estructuras que se le pase como parametro.
 *
 * \param orquesta[] eOrquesta
 * \param musico[] eMusico
 * \param instrumento[] eInstrumento
 * \return void
 *
 */
void creadorDeId(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[],int tamOrquesta, int tamMusico, int tamInstrumento);

