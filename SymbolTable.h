#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class SymbEntry
{
private:
    int token; /// valor armazenado SymbEntry SymbEntry
    char *key;
    SymbEntry *prox; /// ponteiro para o proximo SymbEntry

public:
    SymbEntry(int token, char *key, SymbEntry *prox)
    {
        this->token = token;
        this->key = key;
        this->prox = prox;
    };
    SymbEntry(char *key, SymbEntry *prox)
    {
        this->key = key;
        this->prox = prox;
    };
    ~SymbEntry(){};
    char *getKey() { return key; };
    int getToken() { return token; };
    SymbEntry *getProx() { return prox; };
    void setKey(char *val) { key = val; };
    void setToken(int val) { token = val; };
    void setProx(SymbEntry *p) { prox = p; };
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    int get(int k);
    char *search(char *val);        /// retorna o valor do k-�simo elemento
    void insereFinal(SymbEntry *p); /// insere um SymbEntryvo SymbEntry contendo val SymbEntry final da lista
    void removeInicio();            /// remove o first SymbEntry da lista
    void removeFinal();             /// remove o �ltimo SymbEntry da lista
    void print();
    int searchAndReturnToken(char *val);

private:
    SymbEntry *first; /// ponteiro para o first SymbEntry da lista
    SymbEntry *last;  /// ponteiro para o last SymbEntry da lista
    int n;            /// numero de SymbEntrys na lista
};

class HashTable
{
public:
    HashTable();

    void print();

protected:
    int hashFunction(char *);
    LinkedList **table;
};

class ReservedWord : public HashTable
{
public:
    // The implementation for insert is specific to reserved word.
    int insert(char *key, int token);
     int search(char *key);
};

class IdentifierOrLiteral : public HashTable
{
public:
    // The implementation for insert is specific to identifier or literal.
    int insert(char *key);
    char *search(char *key);
};

#endif // HASH_H_INCLUDED