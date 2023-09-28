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

/* La función retorna el dato con mayor prioridad del montículo, el cual se encuentra en la primera casilla del arreglo (raíz del montículo), siempre y cuando el montículo no esté vacío y el tamaño sea mayor que cero. */
void* heap_top(Heap* pq){
  if(pq == NULL || pq->size == 0) return NULL;
  return pq->heapArray[0].data;
}

/* La función inserta un nuevo dato con prioridad y valor en el montículo, siempre que haya espacio disponible en el arreglo. Si no hay suficiente espacio, se duplica la capacidad + 1 utilizando realloc. Luego, se realiza un intercambio con el padre si el nuevo dato no cumple con la propiedad del montículo, que exige que el padre sea siempre mayor. Este proceso se repite hasta llegar a la raíz o hasta que no sea necesario realizar más intercambios.
*/
void heap_push(Heap* pq, void* data, int priority){
  // Inicializar datos para el nuevo elemento
  heapElem nuevoDato;
  nuevoDato.data = data;
  nuevoDato.priority = priority;

  // Verificar si el arreglo esta lleno. Si lo esta, se aumenta la capacidad al doble + 1.
  if(pq->size == pq->capac) {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    if(pq->heapArray == NULL) exit(EXIT_FAILURE);
  }
  
  // Insercion en la siguiente casilla
  int i = pq->size;
  pq->heapArray[i] = nuevoDato;
  pq->size++;

  // Intercambio de valores cumpliendo la prioridad del orden del monticulo (padres mayores que los hijos)
  while(i != 0 && (pq->heapArray[(i-1)/2].priority < pq->heapArray[i].priority)) {
    heapElem temp = pq->heapArray[i];
    pq->heapArray[i] = pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = temp;
    i = (i-1)/2;
  }
}

/* La función elimina el mayor elemento del montículo (la raíz). Para hacerlo, se inicia el recorrido desde los últimos hijos en el montículo, reemplazando cada valor en la raíz y eliminando el valor reemplazado, ajustando el respectivo tamaño. Si la raíz es menor que alguno de sus hijos, se intercambian, repitiendo este proceso con el nodo desplazado hacia abajo, hasta que todos los hijos sean menores que el nodo o hasta que se llegue a un nodo hoja. */
void heap_pop(Heap* pq){
  // intercambio del ultimo valor en la raiz.
  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  // Reajuste para mantener la prioridad del monticulo (que la raiz sea mayor a sus hijos)
  int i = 0; // rastreo de la posición del nodo actual (en un principio raiz)
  int izquierda, derecha;
  
  while(1) {
    int mayor = i; // rastreo temporal de la posición del elemento más grande
    izquierda = 2 * i + 1; // calculo de posicion hijo izq.
    derecha = 2 * i + 2; // calculo de posicion hijo der.

    // Si el hijo izquierdo es mayor que la raiz
    if(izquierda < pq->size && (pq->heapArray[izquierda].priority > pq->heapArray[mayor].priority)) {
      mayor = izquierda;
    }
    
    // Si el hijo derecho es mayor que la raiz
    if(derecha < pq->size && (pq->heapArray[derecha].priority > pq->heapArray[mayor].priority)) {
      mayor = derecha;
    }

    // Si no se requieren más intercambios en el montículo, se termina el proceso. (la raíz del montículo es mayor igual que sus hijos)
    if(mayor == i) break;
    
    // Se intercambia la raiz con el hijo mayor y se actualiza i
    heapElem nuevoValor = pq->heapArray[i];
    pq->heapArray[i] = pq->heapArray[mayor];
    pq->heapArray[mayor] = nuevoValor;
    
    i = mayor;
  }
}

/* La función crea un nuevo dato de tipo Heap, inicializa sus variables con los valores correspondientes, estableciendo una capacidad inicial de 3 casillas para el arreglo y reserva memoria tanto para el montículo como para el arreglo. */
Heap* createHeap(){
  Heap * nuevoHeap = (Heap *) malloc(sizeof(Heap));
  nuevoHeap->capac = 3;
  nuevoHeap->size = 0;
  nuevoHeap->heapArray = (heapElem *) malloc(sizeof(heapElem) * nuevoHeap->capac);
    
  return nuevoHeap;
}