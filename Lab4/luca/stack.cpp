#include "stack.h"

using namespace stack;

/****************************************************************/
bool stack::isEmpty(const Stack& s){
    return (s == EMPTYSTACK);
}

/****************************************************************/
void stack::push(const Elem x, Stack& s){
    cell* aux = new cell;
    aux->info = x;
    if(!isEmpty(s)){
        aux->next = s;
        s = aux;
    }else{
        aux->next = EMPTYSTACK;
        s = aux;
    }
}

/****************************************************************/
Elem stack::pop(Stack& s){
    if(!isEmpty(s)){
        Elem result = s->info;
        cell* cur = s;
        s = s->next;
        delete cur;
        return result;
    }else{
        throw("The Stack is empty!");
    }
}

/****************************************************************/

