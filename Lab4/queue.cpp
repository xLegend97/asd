#include "queue.h"

using namespace queue;

/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/
void queue::enqueue(Elem e, Queue& l){// aggiunge e in coda
  // rendo inefficente la enqueue per avere la dequeue più efficiente
  cell* aux = new cell;
  cerr << "\nDEBUG: " << "--ENQUEUE: creo aux.";
  cerr << "\nDEBUG: " << "--ENQUEUE: assegno a aux --> e = (  '" << e.val << "'  ).";
  aux->info = e;
  aux->next = EMPTYQUEUE;
  if(!isEmpty(l)){  
    cerr << "\nDEBUG: " << "--ENQUEUE: la queue non è vuota.";
    cell* cur = l;
    cerr << "\nDEBUG: " << "--ENQUEUE: creo cur.";
    while(cur != EMPTYQUEUE){
      if(cur->next != EMPTYQUEUE){
          cur = cur->next;
          cerr << "\nDEBUG: " << "--ENQUEUE: scorro la queue.";
      }else{
        cur->next = aux;
        cerr << "\nDEBUG: " << "--ENQUEUE: inserisco aux nella queue.";
        cerr << "\nDEBUG: " << "--ENQUEUE: cur->next->info: " << cur->next->info.val << ".";
      }
    }
  }else{
    cerr << "\nDEBUG: " << "--ENQUEUE: la queue è vuota.";
    l = aux;
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
