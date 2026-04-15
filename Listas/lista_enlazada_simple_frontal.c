/** 
*   @file   lista_enlazada_simple_frontal.c
*   @brief  Implementación de la estructura de una lista enlazada simple frontalmente
*   @author Rafael Araujo
*   @date   2026-04-15
*/
#include <stdio.h>
#include "lista.h"

/**
*   @struct Nodo es la estructura interna que define una lista enlazada
*   @note   Esta consitutida por un puntero a su inforamcion y otro al nodo siguiente a él
*/
typedef struct _Nodo {
    void* info;          ///< Puntero del nodo que apunta a la info contenida
    struct _Nodo* next;  ///< Puntero al siguiente Nodo
} Nodo;

/**
*   @struct _Lista es la estructura que define, en este caso, una lista enlazada simple
*   @note Una lista enlazada simple frontalmente es una lista que apunta al primer nodo de la lista
*         siendo este seguido por otro nodo, y el ultimo nodo apunta a NULL.  Paritiendo todo desde el
*         el priemer nodo (first).

*             **(first)**
*         pl---->nodo1---->nodo2---->nodo3---->nodo4---->NULL
*/
struct _List{
    Nodo * first; ///< Primer Nodo de la lista (front)
};

/*====================== Metodos de la Sub-estructura Nodo ======================*/
/**
*   @brief Crea un nuevo nodo
*   @return Puntero al nuevo nodo
*/
Nodo*   nodo_new(){
    Nodo*   new_nodo = (Nodo*)malloc(sizeof(Nodo));
    if(!new_nodo) NULL;
    new_nodo->info = NULL;
    new_nodo->next = NULL;
    return new_nodo;
}
/**
*   @brief Libera el conteidno y el nodo en sí mismo. Evitando fugas de memorias
*/
void nodo_free(Nodo* pn) {free(pn);}

/*===============================================================================*/

/*===============(New/Free) Lista ===============*/

List* list_new(){
    List* new_list = (List*) malloc(sizeof(List));
    if(!new_list) return NULL;
    new_list->first = nodo_new();
    if(!(new_list->first)){
        free(new_list);
        return NULL;
    }
    return new_list;
}
void list_free(List* pl){
    if(pl){
        free(pl->first);
        free(pl);
    }
}


/*===============(push/pop) front of list ===============*/

Status list_push_front(List* pl, const void* element){
    if(!pl || !element) return ERROR;
    Nodo *pn = nodo_new();
    if(!pn) return ERROR;

    pn->info = element; 
    pn->next = pl->first; ///Aunque pl->first == NULL (lista vacia) se mantiene la funcionalidad

    /*actualizando el cabezal*/
    pl->first = pn;
    return OK; 
}
void* list_pop_front(List* pl){
    Nodo*   temp = NULL;
    void*   info = NULL;
    if(!pl || !pl->first)   return NULL;

    temp = pl->first; ///Usamos el nodo temporal para guardar el nodo que sacaremos 
    pl->first = temp->next; ///hacemos que el first apunte al rpximo nodo
    info = temp->info;///guardamos la info que tiene el nodo temporal
    nodo_free(temp);/// liberamos el nodo temporal
    return info;///devolvemos la info del nodo temporal
}

/*===============(push/pop) Back of list ===============*/

Status list_push_back(List* pl, const void* element);
void* list_pop_back(List* pl);

/*============== (is_Empty) ¿la lista está vacía?* ==============*/

Bool list_is_empty(List* pl);



