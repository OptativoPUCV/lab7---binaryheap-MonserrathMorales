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
  heapElem nuevoElem;
  nuevoElem.data = data;
  nuevoElem.priority = priority;

  if(pq->capac == 3) {
    pq = realloc(pq, pq->capac * 2 + 1);
  }
  
}


void heap_pop(Heap* pq){

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