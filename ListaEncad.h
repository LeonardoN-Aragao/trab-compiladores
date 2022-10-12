#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"
#include <string>

class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();
    int get(int k);           /// retorna o valor do k-�simo elemento
    void set(int k, int val); /// altera o valor do k-�simo elemento
    void insereFinal(No *p); /// insere um novo No contendo val no final da lista
    void removeInicio(); /// remove o primeiro No da lista
    void removeFinal();  /// remove o �ltimo No da lista
    void print();

private:
    No *primeiro; /// ponteiro para o primeiro No da lista
    No *ultimo;   /// ponteiro para o ultimo No da lista
    int n;        /// numero de nos na lista
};
#endif
