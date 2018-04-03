
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "token.h"
//#include "queue.h"
//#include "stack.h"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

// AUSILIARIE

void printToken(token& t){
    cout << "\nTOKEN: \n\tValue: " << t.val << ".";
    switch(t.k){
        case 1:
            cout << "\n\tKind: Parentesi aperta.";
            break;
        case 2:
            cout << "\n\tKind: Parentesi chiusa.";
            break;
        case 3:
            cout << "\n\tKind: Numero.";
            break;
        case 4:
            cout << "\n\tKind: Op. somma.";
            break;
        case 5:
            cout << "\n\tKind: Op. sottrazione.";
            break;
        case 6:
            cout << "\n\tKind: Op. moltiplicazione.";
            break;
        default: cout << "\n\tKind: Sconosciuto.";
    }
    count << std::endl; 
}

// MAIN

int main(){
    string s;
    //queue::Queue q;

    cout << "Inserisci l'espressione che vuoi valutare:" << std::endl;
    getline(cin,s);

    token t;
    
    while(s.size() != 0){
        prossimoToken(s,t);
        printToken(t);
    }
    
    return 0;
}