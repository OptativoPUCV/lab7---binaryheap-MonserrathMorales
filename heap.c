#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

/* Implemente la función `void* heap_top(Heap* pq)`. Esta función retorna el dato con mayor prioridad del montículo. 
    > Recuerde que este dato se encuentra en la raíz el montículo, es decir, en la primera casilla del arreglo. */
void* heap_top(Heap* pq){
  if(pq == NULL || pq->size == 0) return NULL;
  return pq->heapArray[0].data;
}

/* Implemente la función `void heap_push(Heap* pq, void* data, int p)`. Esta función inserta un nuevo dato con prioridad `p` en el montículo. 
    > Si el arreglo está lleno aumente la capacidad al **doble + 1** usando la función `realloc` así:
    > `arreglo = realloc(arreglo, nueva_capacidad)`*/
void heap_push(Heap* pq, void* data, int priority){
  if(pq == NULL) return;
  // Inicializar datos para el nuevo elemento
  heapElem nuevoElem;
  nuevoElem.data = data;
  nuevoElem.priority = priority;

  // Verificar si el arreglo esta lleno. Si lo esta, se aumenta la capacidad al doble + 1.
  if(pq->size == pq->capac) {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    if(pq->heapArray == NULL) exit(EXIT_FAILURE);
  }
  
  // Insercion en el siguiente nodo
  int i = pq->size;
  pq->heapArray[i] = nuevoElem;
  pq->size++;

  // Intercambio de valores
  while(i != 0 && (pq->heapArray[(i-1)/2].priority < pq->heapArray[i].priority)) {
    heapElem temp = pq->heapArray[i];
    pq->heapArray[i] = pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = temp;
    i = (i-1)/2;
  }
}

/* Implemente la función `void heap_pop(Heap* pq)`. Esta función elimina el mayor elemento del montículo (la raíz). */
void heap_pop(Heap* pq){
  if(pq == NULL || pq->size == 0) return;

  // Eliminacion
  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  // reajuste
  int i = 0;
  int i_MayorValor = i;
  int izquierda = 2 * i + 1;
  int derecha = 2 * i + 2;

  if (izquierda < pq->size && (pq->heapArray[izquierda]->priority > pq->heapArray[i_MayorValor]->priority)) {
        i_MayorValor = izquierda;
    }


}

/* 1. Implemente la función `Heap* createHeap()`. Esta función crea un nuevo dato de tipo Heap inicializando sus variables. Considere que la capacidad incial es de 3 casillas para el arreglo.
   > Recuerde reservar memoria para el Heap y también para el arreglo `heapArray`. */
Heap* createHeap(){
  Heap * nuevoHeap = (Heap *) malloc(sizeof(Heap));
  nuevoHeap->capac = 3;
  nuevoHeap->size = 0;
  nuevoHeap->heapArray = (heapElem *) malloc(sizeof(heapElem) * nuevoHeap->capac);
    
  return nuevoHeap;
}