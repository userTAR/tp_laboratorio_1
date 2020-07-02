#include <stdio.h>
#include <stdlib.h>
/** \brief Se reciben 2 numeros y se devuelve la suma entre el primero y el segundo consecutivamente
 *
 * \param float
 * \param float
 * \return float
 *
 */
float suma(float, float);

/** \brief Se reciben 2 numeros y se devuelve la resta entre el primero y el segundo consecutivamente
 *
 * \param float
 * \param float
 * \return float
 *
 */
float resta(float, float);

/** \brief Se reciben 2 numeros y se devuelve la division entre el primero y el segundo consecutivamente
 *
 * \param float
 * \param float
 * \return int
 *
 */
float division(float, float);

/** \brief Se reciben 2 numeros y se devuelve la multiplicacion entre el primero y el segundo consecutivamente
 *
 * \param float
 * \param float
 * \return int
 *
 */
float multpl(float, float);

/** \brief Recibe un numero y calcula su factorial
 *
 * \param int
 * \return int
 *
 */
double factorial(float);


int switching(int opcion);

float ingreso(char operando[], int numero);

void print_suma(int comparacion, float suma);

void print_resta(int comparacion, float resta);

void print_multiplc(int comparacion, float multiplc);

void print_div(int comparacion, float division, float B);

void print_factorial(double factorialA, double factorialB);
