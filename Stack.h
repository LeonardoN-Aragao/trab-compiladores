#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

struct modificar {
    int info;
};

class Node {
    public:
        Node() { next == NULL; }
        ~Node();

        void setInfo(modificar i) { info = i; }
        modificar getInfo() { return info; }
        void setNext(Node * n) { next = n; }
        Node * getNext() { return next; }

    private:
        modificar info;
        Node * next;
}

class Stack {
    public:
        Stack();
        ~Stack();

        int empty();
        int size();
        Node * get_Back();
        void push_back(Node * n);
        Node * pop_back();
        void print();

    private:
        Node * top;
        int size;
};

#endif // STACK_H