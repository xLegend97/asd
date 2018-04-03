/////////////////////////////////////////////////////////////////////
//
// Laboratorio 3: calcolo di semplici espressioni numeriche 
//                mediante pile e code
//
// vengono accettati dall'esterno solo numeri positivi.
// Per trattare anche numeri negativi occorre modificare
// l'analizzatore lessicale.
//
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "token.h"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

/////////////////////////////////////////////////////////////////////
// Funzioni ausiliarie su tipi di dato semplici
/////////////////////////////////////////////////////////////////////

// da stringa a numero
int str2int(const string &s) {
  // DA IMPLEMENTARE
  //return 0;
  int n;
  istringstream itmp(s);
  itmp >> n;
  return n;
}

// da numero a stringa
string int2str(int n) {
  // DA IMPLEMENTARE
  //return "";
  ostringstream otmp;
  otmp << n;
  string s = otmp.str();
  return s;
}

// ritorna false se e solo se token di tipo sconosciuto o se stringa vuota.
// se stringa non vuota, la stringa perde il pezzo iniziale,
// che diventa token.

bool prossimoToken(string &s, token &t) {
  // DA IMPLEMENTARE
  //return false;
  if(!s.empty()){
    int count = 0;
    for(unsigned int i = 0; i < s.find(' ',0); ++i){
      count++;
    }
    string substring = s.substr(0,count);
    t.val = substring;
    char c;
    int n;
    if(substring.find(n,0) == string::npos){
      switch( substring.find(c, 0) ){
        case '(':{
          t.k = PARENTESI_APERTA;
          break;
        }
        case ')':{
          t.k = PARENTESI_CHIUSA;
          break;
        }
        case '+':{
          t.k = OP_SOMMA;
          break;
        }
        case '-':{
          t.k = OP_SOTTRAZIONE;
          break;
        }
        case '*':{
          t.k = OP_MOLTIPLICAZIONE; 
          break;
        }
        default: t.k = SCONOSCIUTO;
      }
    }else{
      t.k = NUMERO;
    }
    return true;
  }else{
    return false;
  }
}

