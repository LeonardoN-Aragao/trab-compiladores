#include <iostream>
#include <string>
#include <cstdlib>
#include "SymbolTable.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <string.h>
using namespace std;
#define SIZE 97

LinkedList::LinkedList()
{
    first = NULL;
    last = NULL;
    n = 0;
}

void LinkedList::destructLinkedList()
{
    SymbEntry *p = first;
    while (p != NULL)
    {
        SymbEntry *t = p->getNext();
        delete p;
        p = t;
    }
}

void LinkedList::printWithToken(int i)
{
    SymbEntry *p = first;
    if (p != NULL)
    {
        cout << i << ") ";
    }
    for (; p != NULL; p = p->getNext())
        cout << " -> "
             << "(" << (p->getToken()) << ", " << p->getKey() << ")";
    p = first;
    if (p != NULL)
    {
        cout << endl;
    }
}

void LinkedList::print(int i)
{
    SymbEntry *p = first;
    if (p != NULL)
    {
        cout << i << ") ";
    }
    for (; p != NULL; p = p->getNext())
        cout << " -> " << p->getKey();
    p = first;
    if (p != NULL)
    {
        cout << endl;
    }
}

void LinkedList::insertEnd(SymbEntry *p)
{
    if (last != NULL)
        last->setNext(p);

    last = p;

    n++;
    if (n == 1)
        first = p;
}

bool is_equal(const char *str1, const char *str2)
{
    while (true)
    {
        if (*str1 != *str2)
            return false;
        if (!*str1 && !*str2)
            return true;
        str1++;
        str2++;
    }
}

char *LinkedList::search(char *val)
{
    SymbEntry *p;
    for (p = first; p != NULL; p = p->getNext())
    {

        if (is_equal(p->getKey(), val))
        {
            return p->getKey();
        }
    }

    return NULL;
}

int LinkedList::searchAndReturnToken(char *val)
{
    SymbEntry *p;
    for (p = first; p != NULL; p = p->getNext())
    {

        if (is_equal(p->getKey(), val))
        {
            return p->getToken();
        }
    }

    return -100;
}






HashTable::HashTable()
{
    table = (LinkedList **)malloc(sizeof(LinkedList *) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = new LinkedList();
    }
}

void HashTable::destructHashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i]->destructLinkedList();
    }
    table = NULL;
    free(table);
}

int convertStringToInteger(char *key)
{
    int sum = 0;
    int index = 0;
    while (key[index] != '\0')
    {
        sum += key[index];
        index++;
    }
    return sum;
}

int HashTable::hashFunction(char *key)
{
    double C = 0.6180339887;
    int intKey = convertStringToInteger(key);
    int i = SIZE * fmod((C * intKey), 1);
    return i;
}

int ReservedWord::insert(char *key, int token)
{
    int index = hashFunction(key);
    SymbEntry *p = new SymbEntry(token, key, NULL);
    table[index]->insertEnd(p);
    return p->getToken();
}

int IdentifierOrLiteral::insert(char *key)
{
    int index = hashFunction(key);
    SymbEntry *p = new SymbEntry(key, NULL);
    table[index]->insertEnd(p);
    return index;
}

void HashTable::print()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i]->printWithToken(i);
    }
}

char *IdentifierOrLiteral::search(char *key)
{
    int index = hashFunction(key);
    char *ret;
    ret = table[index]->search(key);
    if (ret == "")
    {
        return NULL;
    }
    return table[index]->search(key);
}



int ReservedWord::search(char *key)
{
    int index = hashFunction(key);
    char *ret;
    ret = table[index]->search(key);
    if (ret == "")
    {
        return -100;
    }
    return table[index]->searchAndReturnToken(key);
}
void IdentifierOrLiteral::print()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i]->print(i);
    }
}

void ReservedWord::print()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i]->printWithToken(i);
    }
}