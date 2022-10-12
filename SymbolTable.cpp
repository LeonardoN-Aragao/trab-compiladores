#include <iostream>
#include <string>
#include <cstdlib>
#include "SymbolTable.h"
#include <sstream>
#include <fstream>
#include <vector>
#include "ListaEncad.h"

using namespace std;

TabelaHash::TabelaHash(int tam){
    this->tam = tam;
    tabela = (ListaEncad**) malloc(sizeof(ListaEncad*)*tam);
    for(int i=0;i<tam;i++)
    {
        tabela[i] = new ListaEncad();
    }
}

int TabelaHash::hashFunction(string id,int j){
    int intId = converteId(id);
    long long k = (intId + j*j);
    int key = k % tam;

        return key;
}

void TabelaHash::insere(string key){
    int i = hashFunction(key);
    No *novoArtista = new No(key, i, NULL);
    tabela[i]->insereFinal(novoArtista)
}

