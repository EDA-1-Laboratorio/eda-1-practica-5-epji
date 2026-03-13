/* 
 * Objetivo: Completar las primitivas de la pila para evaluación de RPN.
 */

#include "pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

// =========================================================
// SECCIÓN 1: PRIMITIVAS DE LA PILA (A IMPLEMENTAR)
// =========================================================

// Funcion inicializar
void inicializar(PILA *stk) {
    /* TODO: 
       1. Inicializar el contador de elementos (cnt) a 0.
       2. Inicializar el puntero al tope a NULL. 
    */
    stk -> cnt = 0;
    stk -> tope = NULL;
}

// Funcion push
void push(PILA *stk, DATO x) {
    /* TODO: 
       1. Declarar un puntero a ELEMENTO y asignar memoria con malloc.
       2. Asignar el dato 'x' al nuevo elemento.
       3. Hacer que el nuevo elemento apunte al actual tope de la pila.
       4. Actualizar el tope de la pila para que sea el nuevo elemento.
       5. Incrementar el contador (cnt).
    */
    ELEMENTO *nuevo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    if(nuevo == NULL){
        printf("ERROR: No hay memoria disponible");
        exit(1);
        
}

nuevo -> d = x;
nuevo -> siguiente = stk->tope;
stk -> tope = nuevo;
stk -> cnt++;
}

// Funcion pop
DATO pop(PILA *stk) {
    if (estavacia(stk)) {
        printf("ERROR: Intento de POP en pila vacia (Stack Underflow)\n");
        exit(1); 
    }
    
    /* TODO: 
       1. Declarar una variable DATO para el valor de retorno.
       2. Declarar un puntero ELEMENTO temporal para el nodo a eliminar.
       3. Guardar el dato del tope en la variable DATO.
       4. Hacer que el tope de la pila apunte al siguiente elemento.
       5. Decrementar el contador (cnt).
       6. Liberar la memoria (free) del nodo temporal.
       7. Retornar el dato.
    */
    
    DATO valor;
    ELEMENTO *temp;
    temp = stk -> tope;
    valor = temp -> d;
    stk -> tope = temp -> siguiente;
    stk -> cnt--;
    free(temp);
    return valor;
    
    

    
}
