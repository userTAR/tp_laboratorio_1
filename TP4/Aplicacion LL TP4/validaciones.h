#include <stdio.h>
#include <stdlib.h>

/** \brief Se le ingresa un float: si es un numero NO decimal devuelve 1 si es decimal devuelve 0.
 *         Al terminar la funcion se debe preguntar si es el numero es 1 y en tal caso hacer el float, int.
 * \param float
 * \return int
 **/
int isInteger(float);


/** \brief Se le pasa una variable numerica, un maximo y un minimo. Si esta en rango devuelve el nuemro y si esta fuera de rango
 *          pide que se vuelva a ingresar un numero dentro del rango;
 * \param numero int
 * \param maximo int
 * \param minimo int
 * \return int
 **/
int validacionDeNumero(int numero,int maximo, int minimo);


/** \brief Se le pasa una variable de caracter con los caracteres maximos y minimos. Si esta en rango devuelve la letra y si esta
 *          fuera de rango, pide que se ingrese un caracter dentro del rango.
 * \param letra char
 * \param maximo char
 * \param minimo char
 * \return char
 **/
char validacionDeLetra(char letra, char maximo, char minimo);


/** \brief Se le pasa como parametro un mensaje predeterminado y la funcion pide ingresar un numero y devuelve el mismo
 *
 * \param char[]
 * \return int
 **/
int obtenerNumero(char[]);

float obtenerFlotante(char mensaje[]);

/** \brief Se le pasa como parametro un mensaje predeterminado y la funcion pide ingresar un caracter y devuelve el mismo
 *
 * \param char[]
 * \return char
 **/
char obtenerCaracter(char[]);



/** \brief Obtiene una cadena y verifica que no tenga numeros
 *
 * \param mensaje[] char-> mensaje predeterminado
 * \param cadena[] char-> cadena a la que se le pega el mensaje
 * \return int-> 0 si tiene numeros // 1 si no tiene numeros
 **/
int obtenerCadena(char mensaje[],char cadena[]);


int menuOpciones();

int reCall(void);


