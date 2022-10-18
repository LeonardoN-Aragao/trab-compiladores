#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

typedef std::string string;
using namespace std;

class SymbEntry
{
private:
    int token; /// valor armazenado SymbEntry SymbEntry
    string key;
    SymbEntry *prox; /// ponteiro para o proximo SymbEntry

public:
    SymbEntry(int token, string key, SymbEntry *prox)
    {
        this->token = token;
        this->key = key;
        this->prox = prox;
    };
    ~SymbEntry(){};
    string getKey() { return key; };
    int getToken() { return token; };
    SymbEntry *getProx() { return prox; };
    void setKey(string val) { key = val; };
    void setToken(int val) { token = val; };
    void setProx(SymbEntry *p) { prox = p; };
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    int get(int k);           /// retorna o valor do k-�simo elemento
    void insereFinal(SymbEntry *p);  /// insere um SymbEntryvo SymbEntry contendo val SymbEntry final da lista
    void removeInicio();      /// remove o first SymbEntry da lista
    void removeFinal();       /// remove o �ltimo SymbEntry da lista
    void print();

private:
    SymbEntry *first; /// ponteiro para o first SymbEntry da lista
    SymbEntry *last;   /// ponteiro para o last SymbEntry da lista
    int n;        /// numero de SymbEntrys na lista
};

class HashTable
{
public:
    HashTable(int tam);
    SymbEntry* insert(char* key, int token);
    void insert(char* key, SymbEntry* info);
    void insert(string key); // jeito que ele reclamou
    void print();

private:
    int tam;
    int hashFunction(string);
    LinkedList **table;
};

#endif // HASH_H_INCLUDED