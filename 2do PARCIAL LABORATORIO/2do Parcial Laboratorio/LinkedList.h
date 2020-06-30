/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Privadas
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);


//Publicas

/** \brief Funcion que sirve de constructor por defecto de la estructura linkedList.
 *
 * \param void
 * \return LinkedList*-> puntero de la estructura en memoria dinamica
 *
 */
LinkedList* ll_newLinkedList(void);

/** \brief Funcion que retorna el valor de la variable size de la estructura LL, la cual contiene la cantidad de elementos guardados
 *
 * \param this LinkedList*-> LL
 * \return int-> valor de la variable size
 *
 */
int ll_len(LinkedList* this);

/** \brief Funcion que agrega un elemento al final de la lista.
 *
 * \param this LinkedList*-> LL
 * \param pElement void*-> Elemento a agregar
 * \return int-> (0)= si se pudo agregar de forma correcta el elemento
                 (-1)= si la LL es un puntero a nulo
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief Funcion que obtiene un elemento de la lista.
 *
 * \param this LinkedList*-> LL
 * \param index int-> indice de donde quiero sacar el elemento.
 * \return void*-> elemento
 *
 */
void* ll_get(LinkedList* this, int index);

/** \brief Funcion que setea un elemento al nodo existente en el indice
 *
 * \param this LinkedList*-> LL
 * \param index int-> indice de donde se quiere setear el elemento
 * \param pElement void*-> elemento a setar
 * \return int-> (0)= si fue seteado correctamente
                    (-1)= si la lista es null o el indice esta fuera de rango..
 *
 */
int ll_set(LinkedList* this, int index,void* pElement);

/** \brief Funcion que remueve un elemento de la lista.
 *
 * \param this LinkedList*-> LL
 * \param index int-> indice donde está el elemento
 * \return int-> (0)= si fue removido correctamente
                    (-1)= si el puntero a lista es nulo o el indice esta fuera de campo
 *
 */
int ll_remove(LinkedList* this,int index);

/** \brief Funcion que elimina todos los elementos de la lista
 *
 * \param this LinkedList*-> LL
 * \return int-> (0)= si los elementos se eliminaron correctamente
                    (-1)= si el puntero a la lista es nulo
 *
 */
int ll_clear(LinkedList* this);

/** \brief Funcion que elimina la lista de memoria.
 *
 * \param this LinkedList*
 * \return int
 *
 */
int ll_deleteLinkedList(LinkedList* this);

int ll_indexOf(LinkedList* this, void* pElement);

int ll_isEmpty(LinkedList* this);

int ll_push(LinkedList* this, int index, void* pElement);

void* ll_pop(LinkedList* this,int index);

int ll_contains(LinkedList* this, void* pElement);

int ll_containsAll(LinkedList* this,LinkedList* this2);

LinkedList* ll_subList(LinkedList* this,int from,int to);

LinkedList* ll_clone(LinkedList* this);

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

int ll_count(LinkedList* this, int (*fn)(void* element));

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element));

LinkedList* ll_filter_Parametro(LinkedList* this, int (*fn)(void* element,char* cadena),char* stringCadena);


