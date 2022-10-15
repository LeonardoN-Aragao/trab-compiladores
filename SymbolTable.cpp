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
    No *p = first;
    while (p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

void LinkedList::print()
{
    No *p;
    for (p = first; p != NULL; p = p->getProx())
        cout << "-> "
             << "(" << (p->getToken()) << ", " << p->getKey() << ")";
}

int LinkedList::get(int k)
{
    No *p = first;
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


void LinkedList::insereFinal(No *p)
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
    No *p;
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
    No *p;
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

HashTable::HashTable(int tam)
{
    this->tam = tam;
    table = (LinkedList **)malloc(sizeof(LinkedList *) * tam);
    for (int i = 0; i < tam; i++)
    {
        table[i] = new LinkedList();
    }
}

// int HashTable::hashFunction(string key)
// {
//     int result = 0;
//     for (size_t i = 0; i < key.length(); ++i)
//     {
//         result += key[i] * pow(13, i);
//     }
//     cout << "o result: " << fabs(result) << endl;
//     return 30;
//     return 3;
// }

int converteId(string id)
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
    int intId = converteId(key);
    int k = intId % tam;
    return k;
}

void HashTable::insert(string key)
{
    int index;
    index = hashFunction(key);
    cout << "indice: " << index << endl;
    No *p = new No(index, key, NULL);
    table[index]->insereFinal(p);
    cout << "inseriu" << endl;
}

void HashTable::print()
{
    for (int i = 0; i < tam; i++)
    {
        cout << i << " ";
        table[i]->print();
        cout << endl;
    }
}