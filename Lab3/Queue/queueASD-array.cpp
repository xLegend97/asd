#include "queueASD-array.h"

using namespace queue;


/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/
/*--Ausiliarie--*/
Queue copy(const Queue& q){         // Funzione pr la copia profonda di tutti gli elementi presenti nella queue.
    Elem* aux = new Elem[q.maxsize];
    for(int i = 0; i<q.size; ++i){
        aux[i] = q.queue[i];
    }
    Queue nQ;
    nQ.queue = aux;
    nQ.maxsize = q.maxsize;
    nQ.size = q.size;
    return nQ;
}

Queue resize(const Queue& q){
    Elem* aux = new Elem[q.maxsize + BLOCKDIM];
}

/****************************************************************/
Queue queue::createEmpty()
{
    Queue q;
    q.size = 0;
    q.maxsize = BLOCKDIM;
    Elem* aux = new Elem[BLOCKDIM];
    q.queue = aux;
    return q;
}

/****************************************************************/
void queue::enqueue(Elem e, Queue& l) // aggiunge e in coda
{
    if(l.size >= l.maxsize){
        int oMaxsize = l.maxsize;
        l.maxsize = l.maxsize + BLOCKDIM;
        Elem* aux = l.queue;
        l.queue = new Elem[l.maxsize];
        for(int i = 0; i < oMaxsize; ++i){
            l.queue[i] = aux[i];
        }
        delete [] aux;
    }else{
        l.queue[l.size] = e;
        l.size++;
    }
}


/****************************************************************/
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
    if(isEmpty(l)) return EMPTYELEM;
    else{
        l.size = l.size - 1;

        Elem e = l.queue[0];
        for(int i = 0; i < l.size; ++i){
            l.queue[i] = l.queue[i + 1];
        }
        if(l.size < (l.maxsize - BLOCKDIM)){
            l.maxsize = l.maxsize - BLOCKDIM;
            Elem* aux = l.queue;
            l.queue = new Elem[l.maxsize];
            for(int i = 0; i < l.maxsize; ++i){
                l.queue[i] = aux[i];
            }
            delete [] aux;
        }
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
   return (l.size == 0);
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
