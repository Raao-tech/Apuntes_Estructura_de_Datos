/** 
*   @file   lista.h
*   @brief  Cabecera de la estructura de una lista enlazada simple
*   @author Rafael Araujo
*   @date   2026-04-15
*/
#ifndef LISTA_H
#define LISTA_H

#include "../types.h"

/** 
 * @brief Estructura de una lista básica.
 */
typedef struct _List List;

/*Métodos de una Lista*/

/*===============(New/Free) Lista ===============*/
/**
*   @brief  Crea una lista vacía y devuelve un puntero a la nueva lista
*   @return Un **puntero** a la nueva lista vacía.
*/
List*  list_new();
/**
*   @brief  Elimina una lista vacía
*   @param  pl es un puntero a la lista a liberar
*/
void list_free(List* pl);


/*===============(push/pop) front of list ===============*/
/**
*   @brief  Pushea un elemento desde el front de la lista 
*   @param  pl puntero a la lista
*   @param  element elemento a pushear
*   @return OK si todo perfecto, ERROR si algo fue mal
*/
Status list_push_front(List* pl, const void* element);
/**
*   @brief  Popea un elemento desde el front de la lista 
*   @param  pl puntero a la lista
*   @return puntero a gneerico del elemeneto popeado
*/
void* list_pop_front(List* pl);

/*===============(push/pop) Back of list ===============*/
/**
*   @brief  Pushea un elemento desde el back de la lista 
*   @param  pl puntero a la lista
*   @param  element elemento a pushear
*   @return OK si todo perfecto, ERROR si algo fue mal
*/
Status list_push_back(List* pl, const void* element);
/**
*   @brief  Popea un elemento desde el front de la lista 
*   @param  pl puntero a la lista
*   @return puntero gnerico al elemeneto popeado
*/
void* list_pop_back(List* pl);

/*============== (is_Empty) ¿la lista está vacía?* ==============*/

/**
*   @brief  Verifica si una lista está vacía o no
*   @param  pl puntero a la lista
*   @note   Una lista esta vacia si y sólo si su primer nodo es NULL (pl--->nodo==NULL)
*   @return TRUE si está vacía o (pl==NULL), y FALSE si no está vacía
*/
Bool list_is_empty(List* pl);




/*==============================================================================================*/
/*============================== Otros Métodos útiles para listas ==============================*/

#endif
