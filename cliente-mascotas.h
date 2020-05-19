#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"




/** \brief Se le ingresan a ambas estructuras, datos predeterminados para poder probar las funciones
 *
 * \param cliente[] sCliente
 * \param mascota[] sMascota
 * \param tamEstructura1 int
 * \param tamEstructura2 int
 * \return void
 *
 */
void hardcodearEstructuras(sCliente cliente[],sMascota mascota[],sRaza raza[],int tamEstructura1, int tamEstructura2,int tamEstructura3);

/** \brief Se listar los clientes con sus respectivas mascotas
 *
 * \param estructura1[] sCliente
 * \param estructura2[] sMascota
 * \param tamEstructura1 int
 * \param tamEstructura2 int
 * \return void
 *
 */
void listarDueniosConSusMascotas(sCliente estructura1[],sMascota estructura2[],int tamEstructura1,int tamEstructura2);

/** \brief Se agrega una nueva mascota, ingresando todos los datos en los campos correspondientes
 *
 * \param cliente[] sCliente
 * \param estructura[] sMascota
 * \param tamCliente int
 * \param tamEstructura int
 * \return void
 *
 */
void agregarMascota(sCliente cliente[],sMascota estructura[],sRaza estructura2[],int tamCliente,int tamMascota,int tamEstructura2);

/** \brief Se elimina logicamente a una mascota (su estado pasa a ser libre y puede ser reescrita bajo el mismo id)
 *
 * \param estructura[] sCliente
 * \param estructura2[] sMascota
 * \param tamEstructura int
 * \param tamEstructura2 int
 * \return void
 *
 */
void eliminarMascota(sCliente estructura[],sMascota estructura2[],int tamEstructura,int tamEstructura2);

/** \brief Se elimina logicamente a un cliente elegido por id y a todas las mascotas asociadas a ese cliente elegido
 *
 * \param estructura[] sCliente
 * \param estructura2[] sMascota
 * \param tamEstructura1 int
 * \param tamEstructura2 int
 * \return void
 *
 */
void eliminarClienteENCascada(sCliente estructura[],sMascota estructura2[],int tamEstructura1, int tamEstructura2);

/** \brief Se imprimen los clientes que tienen mas de una mascota bajo su dominio
 *
 * \param estructura[] sCliente
 * \param estructura2[] sMascota
 * \param tamEstructura int
 * \param tamEstructura2 int
 * \return void
 *
 */
void ImprclienteMasDeUnaMascota(sCliente estructura[],sMascota estructura2[], int tamEstructura, int tamEstructura2);

/** \brief Se ordenan los clientes de mayor a menor cantidad de mascotas y se imprimen en tal orden
 *
 * \param estructura[] sCliente
 * \param estructura2[] sMascota
 * \param tamEstructura int
 * \param tamEstructura2 int
 * \return void
 *
 */
void imprClientesOrdenadosPorCantMascotas(sCliente estructura[],sMascota estructura2[],int tamEstructura,int tamEstructura2);

/** \brief Se ordenan los clientes de mayor a menor cantidad de mascotas y si el numero es igual se ordenan por orden alfabetico. Luego de
 *          ordenarlas, se imprimen
 * \param estructura[] sCliente
 * \param estructura2[] sMascota
 * \param tamEstructura int
 * \param tamEstructura2 int
 * \return void
 *
 */
void imprClientesOrdenadosPorCantMascotas_Nombre(sCliente estructura[],sMascota estructura2[],int tamEstructura,int tamEstructura2);

/** \brief Se calcula el porcentaje de varones y muj
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return void
 *
 */
void promedioVarones_Mujeres(sCliente estructura[],int tamEstructura);

/** \brief Se calcula el promedio de edad de las mujeres y el de los hombres por separado
 *
 * \param estructura[] sCliente
 * \param tamEstructura int
 * \return void
 *
 */
void promedioEdadVarones_Mujeres(sCliente estructura[],int tamEstructura);







