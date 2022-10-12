#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "NoTab.h"
#include "ListaEncad.h"

typedef std::string string;
class TabelaHash
{
public:
    TabelaHash(int tam);
    int getTam() { return tam; }
    void insere(No* n);
    void print();
    void insereArtists(int tam, string arq4, int M, int op);

private:
    int tam;
    int ocupacao;
    int funct(string, int);
    ListaEncad** tabela;
};



#endif // HASH_H_INCLUDED