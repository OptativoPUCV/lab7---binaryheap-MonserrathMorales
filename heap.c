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



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

/* 1. Implemente la función `Heap* createHeap()`. Esta función crea un nuevo dato de tipo Heap inicializando sus variables. Considere que la capacidad incial es de 3 casillas para el arreglo.
   > Recuerde reservar memoria para el Heap y también para el arreglo `heapArray`. */
Heap* createHeap(){
  Heap * newHeap = (Heap *) malloc(sizeof(Heap));
  newHeap->capac = 3;
  newHeap->size = 0;
  newHeap->heapArray = (heapElem *) malloc(sizeof(heapElem) * newHeap->capac);
    
  return newHeap;
}