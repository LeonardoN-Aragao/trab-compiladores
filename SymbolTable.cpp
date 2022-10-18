#include <iostream>
#include <string>
#include <cstdlib>
#include "SymbolTable.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>
using namespace std;
#define SIZE    39

LinkedList::LinkedList()
{
    cout << "Criando objeto LinkedList" << endl;
    first = NULL;
    last = NULL;
    n = 0;
}

LinkedList::~LinkedList()
{
    cout << "Destruindo objeto LinkedList" << endl;
    SymbEntry *p = first;
    while (p != NULL)
    {
        SymbEntry *t = p->getProx();
        delete p;
        p = t;
    }
}

void LinkedList::print()
{
    SymbEntry *p;
    for (p = first; p != NULL; p = p->getProx())
        cout << "-> "
             << "(" << (p->getToken()) << ", " << p->getKey() << ")";
}

int LinkedList::get(int k)
{
    SymbEntry *p = first;
    int i = 0;
    while (i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if (p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getToken();
}


void LinkedList::insereFinal(SymbEntry *p)
{
    if (last != NULL)
        last->setProx(p);

    last = p;

    n++;
    if (n == 1)
        first = p;
}

void LinkedList::removeInicio()
{
    SymbEntry *p;
    if (first != NULL)
    {
        p = first;
        first = p->getProx();
        delete p;

        n--;
        if (n == 0)
            last = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void LinkedList::removeFinal()
{
    SymbEntry *p;
    if (last != NULL)
    {
        if (first == last)
        {
            first = NULL;
            p = NULL;
        }
        else
        {
            p = first;
            while (p->getProx() != last)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete last;
        last = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

HashTable::HashTable()
{
    table = (LinkedList **)malloc(sizeof(LinkedList *) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = new LinkedList();
    }
}


int convertStringToInteger(string id)
{
    int soma = 0;
    for (int i = 0; i < id.length(); i++)
    {
        soma += id[i];
    }
    return soma;
}

int HashTable::hashFunction(string key)
{
    double C = 0.6180339887;
    int intKey = convertStringToInteger(key);
    int i = SIZE * fmod((C * intKey), 1);
    return i;
}

void ReservedWord::insert(string key)
{
    int index = hashFunction(key);
    cout << "indice: " << index << endl;
    SymbEntry *p = new SymbEntry(index, key, NULL);
    table[index]->insereFinal(p);
    cout << "inseriu" << endl;
}

void IdentifierOrLiteral::insert(string key)
{
    int index = hashFunction(key);
    cout << "indice: " << index << endl;
    SymbEntry *p = new SymbEntry(key, NULL);
    table[index]->insereFinal(p);
    cout << "inseriu" << endl;
}

void HashTable::print()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " ";
        table[i]->print();
        cout << endl;
    }
}