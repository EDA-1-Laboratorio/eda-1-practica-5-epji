/* * Objetivo: Utilizar el comportamiento LIFO para invertir cadenas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definición de tipos básicos
typedef char DATA;
typedef struct elemento {
    DATA d;
    struct elemento *siguiente;
} ELEMENTO;

typedef struct {
    int cnt;
    ELEMENTO *tope;
} PILA;

// Funciones de Pila (Completadas)
void inicializar(PILA *s) {
    s->cnt = 0;
    s->tope = NULL;
}

void push(PILA *s, DATA x) {
    ELEMENTO *nuevo = (ELEMENTO*)malloc(sizeof(ELEMENTO)); 
    nuevo->d = x;
    nuevo->siguiente = s->tope;
    s->tope = nuevo;
    s->cnt++;
}

DATA pop(PILA *s) {
    if (s->tope == NULL) return '\0';
    ELEMENTO *aux = s->tope;
    DATA dato = aux->d;
    s->tope = aux->siguiente;
    free(aux);
    s->cnt--;
    return dato;
}

int estavacia(PILA *s) {
    return s->tope == NULL;
}

/**
 * TAREA PRINCIPAL: Determinar si la cadena es palíndromo.
 */
int esPalindromo(char cadena[]) {
    PILA original, invertida;
    inicializar(&original);
    inicializar(&invertida);

    int i, longitud = strlen(cadena);

    // 1. Filtrar y llenar la pila original
    for (i = 0; i < longitud; i++) {
        if (isalpha(cadena[i])) { 
            push(&original, tolower(cadena[i]));
        }
    }

    // 2. Crear la versión invertida
    // Clonamos la original a la invertida usando una cadena temporal
    // para no perder el orden de la original.
    char temp[100]; // Buffer temporal para guardar los caracteres
    int n = 0;
    
    while (!estavacia(&original)) {
        temp[n++] = pop(&original);
    }
    
   
    for (i = 0; i < n; i++) {
        push(&original, temp[i]);
    }
    for (i = n - 1; i >= 0; i--) {
        push(&invertida, temp[i]);
    }

    
    while (!estavacia(&original)) {
        if (pop(&original) != pop(&invertida)) {
            return 0; // No es palíndromo
        }
    }

    return 1; 
}

int main() {
    char prueba1[] = "Anita lava la tina";
    char prueba2[] = "Estructuras de Datos";

    printf("--- TEST DE PALINDROMOS ---\n");
    
    printf("Prueba 1: '%s' -> %s\n", prueba1, 
           esPalindromo(prueba1) ? "ES PALINDROMO" : "NO ES PALINDROMO");
           
    printf("Prueba 2: '%s' -> %s\n", prueba2, 
           esPalindromo(prueba2) ? "ES PALINDROMO" : "NO ES PALINDROMO");

    return 0;
}
