#include <iostream>
#include <string>
#include <cstdlib>
#include "SymbolTable.h"
#include <sstream>
#include <fstream>
#include <vector>
#include "ListaEncad.h"
#include <math.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

TabelaHash::TabelaHash(int tam)
{
    this->tam = tam;
    tabela = (ListaEncad **)malloc(sizeof(ListaEncad *) * tam);
    for (int i = 0; i < tam; i++)
    {
        tabela[i] = new ListaEncad();
    }
}

// int TabelaHash::hashFunction(string key)
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

int TabelaHash::hashFunction(string key)
{
    int intId = converteId(key);
    int k = intId % tam;
    return k;
}

void TabelaHash::insere(string key)
{
    int index;
    index = hashFunction(key);
    cout << "indice: " << index << endl;
    No *p = new No(index, key, NULL);
    tabela[index]->insereFinal(p);
    cout << "inseriu" << endl;
}

void TabelaHash::print()
{
    for (int i = 0; i < tam; i++)
    {
        cout << i << " ";
        tabela[i]->print();
        cout << endl;
    }
}