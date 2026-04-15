/** 
*   @file   lista_enlazada_simple_posterior.c
*   @brief  Implementación de la estructura de una lista enlazada simple posteriormente
*   @author Rafael Araujo
*   @date   2026-04-15
*/
#include <stdio.h>
#include "lista.h"

/**
*   @struct Nodo es la estructura interna que define una lista enlazada posteriormente
*   @note   Esta consitutida por un puntero a su inforamcion y otro al nodo siguiente a él
*/
typedef struct _Nodo {
    void* info;         ///< Puntero del nodo que apunta a la info contenida
    struct _Nodo next;  ///< Puntero al siguiente Nodo
}Nodo;

/**
*   @struct _Lista es la estructura que define, en este caso, una lista enlazada posterioremete
*   @note Una lista enlazada simple posteriormetne es una lista que tiene:
*         Nodo(first) apuntando al primer nodo de la lista.
*         Nodo(last) que aputna al ultimo nodo de la lista.
*         
*         Siendo el primer nodo seugio del segundo nodo asi hasta el ultimo Nodo este seguido por otro nodo
*         y éste apunta a NULL y es apuntado por el last de la lista.

*             **(first)**                     **(last)**
*         pl---->nodo1---->nodo2---->nodo3---->nodo4---->NULL
*          |                                    / \ 
*          |                                     |
*          |_____________________________________|
*/
struct _Lista{
    Nodo* first;    ///< Primer Nodo de la lista (front)
    Nodo* last;     ///< Último Nodo de la lista (last)
}

