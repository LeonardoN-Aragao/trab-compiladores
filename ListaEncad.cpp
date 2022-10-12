#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"
#include <string>

using namespace std;

ListaEncad::ListaEncad()
{
    cout << "Criando objeto ListaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad()
{
    cout << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while (p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}



void ListaEncad::print()
{
    No *p;
    for (p = primeiro; p != NULL; p = p->getProx())
        cout << "-> "
             << "(" << (p->getToken()) << ", " << p->getKey() << ")";
}

int ListaEncad::get(int k)
{
    No *p = primeiro;
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

void ListaEncad::set(int k, int val)
{
    No *p = primeiro;
    int i = 0;
    while (i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if (p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setToken(val);
}

void ListaEncad::insereFinal(No *p)
{
    if (ultimo != NULL)
        ultimo->setProx(p);

    ultimo = p;

    n++;
    if (n == 1)
        primeiro = p;
}

void ListaEncad::removeInicio()
{
    No *p;
    if (primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if (n == 0)
            ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
    No *p;
    if (ultimo != NULL)
    {
        if (primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while (p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}
