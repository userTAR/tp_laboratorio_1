//BIBLIOTECA MAS PRIMITIVA

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "validaciones Biblioteca.h"

typedef struct
{
    char NombreRaza[21];
    char paisRaza[21];
    int tipoRaza;
    int IdRaza;
    int estado;
}sRaza;

typedef struct
{
    char nombreMascota[21];
    char tipo[21];
    sRaza raza;
    char sexo[21];
    char nombreDuenio[21];
    int idDuenio;
    int idMascota;
    int edad;
    int peso;
    int estado;
}sMascota;

/** \brief Inicializa el estado de las mascotas en libre
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return void
 *
 */
void inicializarEstadoMascota(sMascota estructura[],int tamEstructura);

/** \brief Imprime una sola mascota
 *
 * \param estructura sMascota
 * \return void
 *
 */
void imprimirUnaSolaMascota_OCUPADOS(sMascota estructura);

/** \brief Imprime todo el array de la estructura mascota
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return void
 *
 */
void imprimirArrayMascotas_OCUPADOS(sMascota estructura[],int tamEstructura);

/** \brief Se imprimen las mascotas, se ingresa un id y se devuelve el codigo de la mascota seleccionada
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return int
 *
 */
int buscarIndiceDeMascotaPorId(sMascota estructura[],int tamEstructura);

/** \brief Busca la primer mascota con el estado libre dentro del array de estructura mascota y devuelve el indice
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return int
 *
 */
int buscarLibreMascota(sMascota estructura[],int tamEstructura);

/** \brief Crea, para toda la longitud del array de mascota, un id y se lo asigna al miembro id
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return void
 *
 */
void creadorDeIdMascota(sMascota estructura[],int tamEstructura);



/** \brief Se ordenan las mascotas por tipo y se imprimen junto al nombre de su dueño
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return void
 *
 */
void ImprMascotasOrdenadasPorTipo_ConDuenio(sMascota estructura[],int tamEstructura);

/** \brief Se imprimen las mascotas que tengan mas de 3 años exclusivamente
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return void
 *
 */
void ImprMascotasMasDe3Anios(sMascota estructura[],int tamEstructura);

/** \brief Se ingresa un tipo dentro de los disponibles y se imprimen todas las mascotas pertenecientes a ese tipo
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return void
 *
 */
void imprMascotasPorTipoEnParticular(sMascota estructura[], int tamEstructura);

/** \brief Se calcula y se imprime el promedio de edad de todas las mascotas
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return void
 *
 */
void promedioEdadMascotas(sMascota estructura[], int tamEstructura);

/** \brief Se calcula y se imprime el promedio de edad de las mascotas discriminado por tipo.
 *
 * \param estructura[] sMascota
 * \param tamEstructura int
 * \return void
 *
 */
void promedioEdadMascotasPorTipo(sMascota estructura[], int tamEstructura);


