#include "queueASD-array.h"

using namespace queue;


/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/
Queue queue::createEmpty()
{
/* ricordati che per accedere all'array devi mettere il punto*/
   Queue q; //  Queue q; lo inizializzo per poi accedere 		all'array ( e come le liste che crei un nuovo puntatore 	//	es.
    // list Q  = new list;
   q.size = 0; //piglia size di q ;
   q.maxsize = BLOCKDIM;
   //dichiaro la dim(max)= block(1000)
   
   /* q.queue  = new elem[BD] e' la inilizzazione della di Elem cioe' creamo la dimensione di 1000 elementi grazie a BD  */
   q.queue = new Elem[BLOCKDIM]; 
   
   return q;
}

/****************************************************************/
void queue::enqueue(Elem e, Queue& l) // aggiunge e in coda
{
	if(l.size >= l.maxsize)
	{
 /* inseriamo un crontrolla per verificare se non superi la dimensione dell'array di fatti andiamo a ampliare la dimensione di l.maxsize + Block */
	
		int oldSize = l.maxsize;
		l.maxsize = l.maxsize + BLOCKDIM;
		
/* creiamo un nuovo puntatore  che prende il vecchio array e lo copia tutto su essa dato che abbiamo ampliato di dim MAX */

		Elem* els = l.queue;
		l.queue = new Elem[l.maxsize];
		for(int i=0; i<oldSize; i++)
			l.queue[i] = els[i];
		delete[] els;
	}
	
	l.queue[l.size] = e;
	l.size ++;
}


/****************************************************************/
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
/* se è vuoto mettiamo stop e riporta vuoto */

	if(isEmpty(l)) return EMPTYELEM;
	l.size = l.size -1;
	
	
/* andiamo a salvare l'elemento di l.queue[0] in E  */
/* qui compiamo ma dato che dobbiamo cancellare  */
	Elem e = l.queue[0];
	for(int i = 0; i<l.size;i++)
	{
		l.queue[i] = l.queue[i+1];
	}
/* qui controlliamo se la s.size e' minore di MAX - BKD cioe verifichiamo se e minore di 1000 per poi ridimensionare tutto l'array , copiandolo grazie un puntatore + un ciclo e delete puntatore els che punta al vecchio array */
	if(l.size < l.maxsize-BLOCKDIM)
	{
		l.maxsize = l.maxsize - BLOCKDIM;
		
		Elem* els = l.queue;
		l.queue = new Elem[l.maxsize];
		for(int i=0; i<l.maxsize; i++)
			l.queue[i] = els[i];
		delete[] els;
	}
	
	return e;
}


/****************************************************************/
Elem queue::first(Queue& l) // restituisce il primo elemento
{
	if(isEmpty(l)) return EMPTYELEM;
	return l.queue[0];
}


/****************************************************************/
bool queue::isEmpty(const Queue& l)
{
   return l.size == 0;
}



/****************************************************************/
Queue readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    return readFromStream(ifs);
}


/****************************************************************/
Queue readFromStdin()
{
    cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
    return readFromStream((std::cin));
}


/****************************************************************/
Queue readFromStream(istream& str)
{
    Queue l = createEmpty();        
    int dato;
    str>>dato;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (dato!= FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {     
        enqueue(dato, l);   // aggiunge l'elemento alla fine della coda
        str>>dato;
        if (!str) throw runtime_error("Errore inserimento dati\n");
        }
return l;
}

/****************************************************************/
void print(const Queue& l)
{
cout << endl;
for (int i=0; i<l.size; ++i)
   cout << l.queue[i] << "; "; 
cout << endl;
}
