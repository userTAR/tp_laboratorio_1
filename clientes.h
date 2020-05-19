#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"

typedef struct
{
    char nombre[21];
    char apellido[21];
    char localidad[21];
    char sexo[21];
    int telefono;
    int edad;
    int idPersonal;
    int cantMascotas;
    int estado;
}sCliente;

/** \brief Inicializa el estado y la cantidad de mascotas de los clientes
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return void
 **/
void initEstado_Cantidad_Cliente(sCliente estructura[],int tamEstructura);

/** \brief Imprime un solo cliente.
 *
 * \param estructura sCliente
 * \return void
 *
 */
void imprimirUnSoloCliente_OCUPADOS(sCliente estructura);

/** \brief Imprime todo el vector de estructura
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return void
 *
 */
void imprimirArrayClientes_OCUPADOS(sCliente estructura[],int tamEstructura);

/** \brief Busca la posicion libre del cliente y devuelve el indice
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return int
 *
 */
int buscarLibreCliente(sCliente estructura[],int tamEstructura);

/** \brief Se imprime la lista de clientes, se ingresa el id y a partir del id se busca el indice correspondiente
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return int
 *
 */
int buscarIndiceDeClientePorId(sCliente estructura[],int tamEstructura);

/** \brief Se inicializa un ID para cada cliente del array
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return void
 *
 */
void creadorDeIdCliente(sCliente estructura[],int tamEstructura);

/** \brief Se piden distintos datos para agregar un cliente nuevo
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return void
 *
 */
void agregarCliente(sCliente estructura[],int tamEstructura);

/** \brief Se elije que usuario modificar y luego se elije que modificar de los distintos miembros de la estructura
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return void
 *
 */
void modificarCliente(sCliente estructura[],int tamEstructura);



