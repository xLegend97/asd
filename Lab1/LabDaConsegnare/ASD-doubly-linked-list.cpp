// Implementa le funzioni sulle liste realizzate con strutture doppiamente collegate, circolari, con sentinella, senza ordinamento

#include "ASD-doubly-linked-list.h"


using namespace list;

struct list::node {  // descrivo qui, fuori dal namespace, come e' fatta la struttura node: i dettagli interni non saranno visibili dal main
Elem info;
node *prev;
node *next;
};

/***********************************************/
/* Implementazione delle operazioni di utilità */
/***********************************************/

void readFromStream(istream& str, List& l)
{
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e != FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {     
        addRear(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
        }
}

void readFromFile(string nome_file, List& l)  /* legge il contenuto di una lista da file */
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    readFromStream(ifs, l);
}



void readFromStdin(List& l)         /* legge il contenuto di una lista da standard input */
{
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   readFromStream((std::cin), l);
}


void print(const List& l)           /* stampa la lista */
{
   List q = l->next;  // q "salta la sentinella" e va alla testa della lista
   while (q != l)     // avanza finche' non finisce la lista
     {
      cout << q->info << "; ";
      q = q->next; 
      }
}





/**************************************************/
/* Implementazione delle operazioni nel namespace */
/**************************************************/
void clear_rec(List& cur){
    if(cur->info != EMPTYELEM){
        clear(cur->next);
        delete cur;
    }else{
        cur->next = cur;
        cur->prev = cur;
    }
}

void list::clear(const List& l)                 /* "smantella" la lista svuotandola */
{
    node *cur = l->next;    // salto la sentinella
    clear_rec(cur);
}


Elem list::get(int pos, const List& l)        /* restituisce l'elemento in posizione pos se presente; restituisce un elemento che per convenzione si decide che rappresenta l'elemento vuoto altrimenti*/
{
    if(!isEmpty(l)){
        node *cur = l->next;    // Salto la sentinella
        int count = 0;
        while(cur->info != EMPTYELEM){
            if(count == pos){
                return (cur->info);
            }else{
                cur = cur->next;
                count++;
            }
        }
        return EMPTYELEM;
    }else{
        return EMPTYELEM;
    }
}


void list::set(int pos, Elem e, const List& l)        /* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
{
    if(!isEmpty(l)){
        node *cur = l->next;    // Salto la sentinella
        int count = 0;
        while((cur->info != EMPTYELEM) && (count != pos)){
            cur = cur->next;
            count++;
        }
        if((count == pos) && (cur->info != EMPTYELEM)){
            cur->info = e;
        }
    }
}


void list::add(int pos, Elem e, const List& l)        /* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
{   
    node *aux = new node;
    aux->info = e;                                 
    if(!isEmpty(l)){
        if(pos == 0){addFront(e,l);}
        node *cur = l->next;    // Salto la sentinella
        int count = 0;
        while(cur->info != EMPTYELEM){
            if(count == pos){
                aux->next = cur;
                aux->prev = cur->prev;
                cur->prev->next = aux;
                cur->prev = aux;
            }else{
                count++;
                cur = cur->next;
            }
        }
    }
}


void list::addRear(Elem e,  const List& l)        /* inserisce l'elemento alla fine della lista */
{
    node *aux = new node;
    aux->info = e;
    aux->next = l;
    aux->prev = l->prev;
    l->prev->next = aux;
    l->prev = aux;
}


void list::addFront(Elem e, const List& l)        /* inserisce l'elemento all'inizio della lista */
{
    node *aux = new node;
    aux->info = e;
    aux->next = l->next;
    aux->prev = l;
    l->next->prev = aux;
    l->next = aux;
}


void list::removePos(int pos, const List& l)           /* cancella l'elemento in posizione pos dalla lista */
{
    if(!isEmpty(l)){
        node *cur = l->next;
        int count = 0;
        while((cur->info != EMPTYELEM) && (count <= pos)){
            if((count == pos) && (cur->info != EMPTYELEM)){
                cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
                delete cur;
                break;
            }else{
                count++;
                cur = cur->next;
            }
        }
    }
}


void list::removeEl(Elem e, const List& l)          /* cancella l'elemento elem, se presente, dalla lista */
{
    if(!isEmpty(l)){
        node *cur = l->next;
        while(cur->info != EMPTYELEM){
            if(cur->info == e){
                cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
                delete cur;
                break;
            }else{
                cur = cur->next;
            }
        }
    }
}


bool list::isEmpty(const List& l)         /* restituisce true se la lista e' vuota (ed e' vuota se il next di l, e' l stessa */
{
    return (l->next->info == EMPTYELEM);
}


int list::size(const List& l)           /* restituisce la dimensione della lista */
{
    // creo il counter
    int count = 0;
    // salto la sentinella
    node *cur = l->next;
    while(cur->info != EMPTYELEM){
        count++;
        cur = cur->next;
    }
    return count;
}


void list::createEmpty(List& l)           /* crea la lista vuota */
{
    // sentinella
    l = new node;   
    l->info = EMPTYELEM;
    l->next = l;
    l->prev = l;
}