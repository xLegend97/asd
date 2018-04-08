/////////////////////////////////////////////////////////////////////
//
// Laboratorio 3: calcolo di semplici espressioni numeriche 
//                mediante pile e code
//
// vengono accettati dall'esterno solo numeri positivi.
// Per trattare anche numeri negativi occorre modificare
// l'analizzatore lessicale.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "token.h"
#include "queue.h"
#include "stack.h"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

/////////////////////////////////////////////////////////////////////
// Funzioni principali: leggi() e calcola()
/////////////////////////////////////////////////////////////////////

// Estrae uno dopo l'altro i token dalla stringa "str", inserendoli via via nella coda "codaToken"
bool leggi(const string &str, queue::Queue &codaToken) {
  bool result = false;
  for(unsigned int i = 0; i < str.size(); ++i){
    token t;
    result = prossimoToken(str, t);
    if(result){
      queue::enqueue(t,codaToken);
    }else{
      throw("Unknown char!");
    }
  }
  return result;
}

// Estrae uno dopo l'altro i token dalla coda, inserendoli via via sullo stack.
// Appena si incontra un token PARENTESI CHIUSA, quello segnala la fine
// di una sottoespressione; allora tiriamo giu' dallo stack gli ultimi cinque token inseriti.
// I token estratti dovrebbero essere esattamente, nell'ordine:
// un ")", un numero, un operatore aritmetico, un altro
// numero, e un "("; se non è così, allora si segnala
// errore sintattico e l'algoritmo termina.
// A questo punto la funzione deve convertire i token di tipo NUMERO in numeri interi, 
// eseguire l'operazione aritmetica opportuna, e trasformare il risultato da numero a
// token e inserire quest'ultimo sullo stack.
// Alla fine se non ci sono errori sintattici la funzione deve mettere nella variabile
// risultato il vaore dell'espressione
bool calcola(queue::Queue codaToken, int &risultato) {
  bool result = false;
  token t;
  stack::Stack stackToken;
  while((t.k) != PARENTESI_CHIUSA){
    if(t.k != PARENTESI_CHIUSA){
      t = queue::dequeue(codaToken);
      stack::push(t, stackToken);
    }else{
      token t1, t2, op;
      int num1, num2, r;
      stack::pop(stackToken);   // essendo la parentesi la ignoro
      t1 = stack::pop(stackToken);
      op = stack::pop(stackToken);
      t2 = stack::pop(stackToken);
      stack::pop(stackToken);   // essendo la parentesi la ignoro
      num1 = str2int(t1.val);
      num2 = str2int(t2.val);
      switch(op.k){
        case 4:{
          r = num1 + num2;
          break;
        }
        case 5:{
          r = num1 - num2;
          break;
        }
        case 6:{
          r = num1 * num2;
          break;
        }
        default: throw ("syntactic error");
      }
      t1.k = NUMERO;
      t1.val = int2str(r);
      stack::push(t1, stackToken);
      result = true;
    }
  }
  return result;
}

/////////////////////////////////////////////////////////////////////
//                               MAIN
/////////////////////////////////////////////////////////////////////

int main() {

  string s;
  queue::Queue q;
  int r;

  cout << "Inserisci l'espressione che vuoi valutare:" << endl;
  getline(cin,s);

  if (!leggi(s,q)) {
    cout << "errore lessicale\n";
    exit(1);
  }

  if (!calcola(q,r)) {
    cout << "errore sintattico\n";
    exit(1);
  }

  cout << "risultato: " << r << "\n";
  exit(0);
}
