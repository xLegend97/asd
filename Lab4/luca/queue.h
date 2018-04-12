#include <iostream>
#include <stdexcept>

#include "token.h"
	
using namespace std;

// Implementa QUEUE 
namespace queue{

// Gli elementi della QUEUE sono token
typedef token Elem;       

//typedef int Queue; // Definizione di Queue fasulla. MODIFICARE!
struct cell{
  Elem info;
  cell* next;
};
typedef cell* Queue;
const Queue EMPTYQUEUE = NULL;

bool isEmpty(const Queue&);
void enqueue(Elem, Queue&);  /* inserisce l'elemento alla fine della lista */
Elem dequeue(Queue&);        /* cancella l'elemento in prima posizione (se esiste) e lo restituisce */
}
