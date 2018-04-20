#include "dictionary.h"

#include <math.h> // sqrt()

using namespace dict;

struct dict::BSTnode {
    dictionaryElem  elem;
	BSTnode* leftChild;
    BSTnode* rightChild;
};

Key normalize(Key k){
    removeBlanksAndLower(k);
    return k;
}

Error dict::deleteElem(const Key k, Dictionary& s)
{
    return FAIL;
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Value dict::search(const Key k, const Dictionary& s)
{	
  return emptyValue;  	
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error insertElem(const Key k, const Value v, Dictionary& s)
{
    Key k1 = normalize(k);
    if(s == EMPTYNODE){
        BSTnode* aux = new BSTnode;
        aux->elem.key = k1;
        aux->elem.value = v;
        aux->leftChild = EMPTYNODE;
        aux->rightChild = EMPTYNODE;
        s = aux;
        return OK;
    }
    if(k < s->elem.key){
        return insertElem(k, v, s->leftChild);
    }
    if(k > s->elem.key){
        return insertElem(k, v, s->rightChild);
    }else return FAIL;
}


/****************************************************************/
Dictionary dict::createEmptyDict()
{
   Bucket* d = new Bucket[tableDim];
   for (int i=0; i < tableDim; ++i)
      d[i]=EMPTYNODE;
   return d;
}


/****************************************************************/
/*Dictionary readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmptyDict();}  
    return readFromStream(ifs);
}*/


/****************************************************************/
/*Dictionary readFromStdin()
{
    cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
    return readFromStream((std::cin));
}*/


/****************************************************************/
/*Dictionary readFromStream(istream& str)
{
    Dictionary d = createEmptyDict();     
    string key, kcopy;
    string value;
    getline (str, key, ':'); 
    getline (str, value); 
    while (!str.eof())  
        {     
        kcopy = key;
        removeBlanksAndLower(kcopy);   
        insertElem(kcopy, value, d); // FINCHE' NON IMPLEMENTATE LA INSERTELEM, NON PUO' FUNZIONARE CORRETTAMENTE: la insertElem e' la prima funzione che dovete implementare
        getline (str, key, ':'); 
        getline (str, value); 
        }
str.clear();
return d;
}*/


/****************************************************************/
//int printBucket(Bucket b) // stampa il contenuto di un bucket e restituisce il numero di elementi contenuti nel bucket stesso
//{  
//   int counter = 0;
//   while(b!=emptyBucket) {
//        counter++;
//       cout << (b->elem).key << ": " << (b->elem).value << "\n"; 
//	b=b->next;
//	}
//   return counter;	
//}


/****************************************************************/
void print(const Dictionary& s)         // ricorsiva e simmetrica
// stampa il contenuto del dizionario ed anche informazioni su come sono stati organizzati gli elementi
{
    if(s == EMPTYNODE) return;
    print(s->leftChild);
    cout << " " <<s->elem.value;
    print(s->rightChild);
}



