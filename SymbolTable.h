#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "No.h"
#include "ListaEncad.h"

typedef std::string string;
class TabelaHash
{
public:
    TabelaHash(int tam);
    void insere(string key);
    void print();

private:
    int tam;
    int ocupacao;
    int hashFunction(string);
    ListaEncad **tabela;
};



#endif // HASH_H_INCLUDED