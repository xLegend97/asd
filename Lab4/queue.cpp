#include "queue.h"

using namespace queue;

/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/
void queue::enqueue(Elem e, Queue& l){// aggiunge e in coda
  // rendo inefficente la enqueue per avere la dequeue più efficente
  cell* aux = new cell;
  cell* cur = l;
  aux->info = e;
  aux->next = EMPTYQUEUE;
  while(cur != EMPTYQUEUE){
    if(cur->next == EMPTYQUEUE){
      cur->next = aux;
    }else{
      cur = cur->next;
    }
  }
}


/****************************************************************/
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
  cell* tmp = l->next;
  Elem result = l->info;
  delete l;
  l = tmp;
  return result; 
}

/****************************************************************/
bool queue::isEmpty(const Queue& l){
  return (l == EMPTYQUEUE);
}

/****************************************************************/
