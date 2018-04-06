#include "queue.h"

using namespace queue;

struct cell{
  Elem info;
  cell* next;
};

/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/
void queue::enqueue(Elem e, Queue& l) // aggiunge e in coda
{
   // DA IMPLEMENTARE
}


/****************************************************************/
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
   // DA IMPLEMENTARE
   Elem e;
   return e;
}

/****************************************************************/
bool queue::isEmpty(const Queue& l){
  return (l == EMPTYQUEUE);
}

/****************************************************************/
