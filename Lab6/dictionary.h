#include <iostream>
#include <stdexcept>
#include <vector> 
#include <fstream> 
#include <chrono>          // necessario compilare con -std=c++11
#include <stdlib.h>        // srand, rand
#include <string>          // std::string
#include "string-utility.h"


using namespace std::chrono; 
using namespace std; 

namespace dict {

enum Error {OK, FAIL};

typedef string Key; 
typedef string Value;

const Key emptyKey = "###RESERVED KEYWORD### EMPTY KEY";
const Value emptyValue = "###RESERVED KEYWORD### EMPTY VALUE";

struct dictionaryElem {
    Key    key;
    Value value;
};
typedef dictionaryElem Elem;

Error insertElem(const Key, const Value, Dictionary&);
Error deleteElem(const Key, Dictionary&);
Value search(const Key, const Dictionary&);
Dictionary createEmptyDict();

#ifdef USE_HASH_TABLE
// Implementazione basata su tabella hash

struct cell;
typedef cell* Bucket;
const Bucket emptyBucket = NULL;
typedef Bucket* Dictionary; // un Dictionary è un array di dimensione tableDim (che viene fissata in fase di inizializzazione), di puntatori a cell (che abbiamo chiamato "Bucket"); come già fatto in altre occasioni, la struttura di cell è definita nel file ausiliario per incapsulare il più possibile l'informazione

#endif


#ifdef USE_ORDERED_LIST
// Implementazione basata su lista ordinata

struct nodo;
typedef nodo* Dictionary;

#endif


#ifdef USE_ORDERED_VECTOR
// Implementazione basata su vettore ordinato

typedef vector<Elem> Dictionary;

#endif


#if !defined(USE_HASH_TABLE) && !defined(USE_ORDERED_LIST) && !defined(USE_ORDERED_VECTOR)
    #error "Must specify USE_HASH_TABLE or USE_ORDERED_LIST or USE_ORDERED_VECTOR"
#endif


Error insertElem(const Key, const Value, Dictionary&);
Error deleteElem(const Key, Dictionary&);
Value search(const Key, const Dictionary&);
Dictionary createEmptyDict();


}  // end namespace Dict


dict::Dictionary readFromFile(string);
dict::Dictionary readFromStdin();
dict::Dictionary readFromStream(istream&);
void print(const dict::Dictionary&);
