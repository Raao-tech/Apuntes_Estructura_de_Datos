#ifndef TYPES_H
#define TYPES_H

/**
*   @enum Status define el estado de un proceso/funcion
*/
typedef enum{
    ERROR,  ///< Algo Horrible!! ¡¿Qué has hecho?! 
    OK      ///< Todo perfecto mi Rey
}Status;
/**
*   @enum Bool define si es verdadero o falso
*/
typedef enum{
    False,  ///< La expresión es Falsa == 0
    True    ///< La expresión es Verdadera == 1
}Bool;

#endif