#include "Stack.h"

Stack::Stack(){
    top = NULL;
    size = 0;
}
Stack::~Stack(){
    Node * p;
    while(!empty()){
        p = pop_back();
        delete p;
    }
}

int Stack::empty(){
    if(top == NULL)
        return 1;
    else 
        return 0;
}

int Stack::size(){
    return size;
}

Node * Stack::get_Back(){
    return top;
}

void Stack::push_back(Node * n){
    if(empty())
        top = n;
    else {
        n->setNext(top);
        top = n;
    }
    size++;
}

Node * Stack::pop_back(){
    if(empty())
        return NULL;
    else{
        Node * n = top;
        top = n->getNext();
        
        n->setNext(NULL);
        size--;
        return n;
    }
}

void Stack::print(){
    Node * p = top;

    while(p != NULL){
        printf(stdout,p->info.info);
        p = p->getNext();
    }
}

