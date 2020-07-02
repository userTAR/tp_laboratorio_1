#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[21];
    char lugar[21];
    int tipo;
    int id;
    int estado;
}eOrquesta;

typedef struct
{
    char nombreYapellido[31];
    int edad;
    int idPersonal;
    int idOrquesta;     // id de la orquesta a la que pertenece;
    int idInstrumento;      //id del instrumento que toca el músico;
    int estado;
}eMusico;

typedef struct
{
    int id; //se debe generar el id automaticamente;
    char nombreInstrumento[16];
    int tipo; //tipo de insturmento;
    int estado;
}eInstrumento;

/*typedef struct
{
    eOrquesta orquesta;
    eMusico musico;
    eInstrumento instrumento;
}eGeneral;
*/

//-------------------------------FUNCIONES GENERALES REUTILIZABLES SIN MODIFICARLAS TANTO-----------------------------
int buscarLibre(int opcion,eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]
                       ,int tamOrquesta, int tamMusico, int tamInstrumento);
/** \brief Se le ingresa un float: si es un numero NO decimal devuelve 1 si es decimal devuelve 0.
 *         Al terminar la funcion se debe preguntar si es el numero es 1 y en tal caso hacer el float, int.
 * \param float
 * \return int
 *
 */
int isInteger(float);
/** \brief Se despliega un menú de opciones y se devuelve la eleccion que se haya selecionado;
 *
 * \return int
 *
 */
int menuOpciones();
/** \brief Se le pasa una variable numerica, un maximo y un minimo. Si esta en rango devuelve el nuemro y si esta fuera de rango
 *          pide que se vuelva a ingresar un numero dentro del rango;
 * \param numero int
 * \param maximo int
 * \param minimo int
 * \return int
 *
 */
int validacionDeNumero(int numero,int maximo, int minimo);
/** \brief Se le pasa una variable de caracter con los caracteres maximos y minimos. Si esta en rango devuelve la letra y si esta
 *          fuera de rango, pide que se ingrese un caracter dentro del rango.
 * \param letra char
 * \param maximo char
 * \param minimo char
 * \return char
 *
 */
char validacionDeLetra(char letra, char maximo, char minimo);
/** \brief Pone a la variable estado de una estructura en 0. Sea una estructura unica o un array de estructuras;
 *
 * \return void
 *
 */
void inicializarEstado(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]
                       ,int tamOrquesta, int tamMusico, int tamInstrumento);     //REVISAR SABADO
void inicializadorDeId(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]
                       ,int tamOrquesta, int tamMusico, int tamInstrumento);
void creadorDeId(eOrquesta orquesta[],eMusico musico[],eInstrumento instrumento[]);
//-----------------------------------------------------------------------------------------------------------------
//----------------------------------FUNCIONES QUE DEPENDERAN DEL PROGRAMA A REALIZAR-------------------------------
void agregarOrquesta(eOrquesta orquesta[],int indice);
void eliminarOrquesta(eOrquesta orquesta[],eMusico musico[],int tamOrquesta,int tamMusico);
void imprimirOrquestas(eOrquesta orquesta[], int tam);

void agregarMusico(eMusico musico[],int indice,eOrquesta orquesta[]);
void modificarMusico(eMusico musico[],eOrquesta orquesta[], int tamMusico, int tamOrquesta);
void eliminarMusico(eMusico musico[],int tamMusico);
void imprimirMusicos(eMusico musico[], int tam);

void agregarInstrumento(eInstrumento instrumento[],int indice);
void imprimirInstrumentos(eInstrumento instrumento[], int tam);
//--------------------------------------------------------------------------------------------------------------------
//-------------------------------------FUNCIONES DE LISTADO-----------------------------------------------------------
void orquestasMasDe5Musicos(eOrquesta orquesta[],eMusico musico[],int tamOrquesta,int tamMusico);

void musicosMasDe30(eMusico musico[],int tamMusico);

void orquestasLugarParticular(eOrquesta orquesta[], int tamOrquesta);

void orquestasCompletas(); //Completa: 5 o +  instr. a cuerda, 3 o + instr. de viento, 2 o + instr. de percusion;

void musicosDeOrquestaDeterminada(); // musicos de una orquesta la cual el usuario ingresa el ID.

void orquestaConMasMusicos();

void musicosInstrumentosCuerdas(); // nombre, apellido, edad, nombre y tipo de instrumento que toca ordenado por apellido;

void promedioMusicosPorOrquesta();


