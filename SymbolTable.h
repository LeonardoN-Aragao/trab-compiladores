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
    SymbEntry *next; /// ponteiro para o nextimo SymbEntry

public:
    SymbEntry(int token, char *key, SymbEntry *next)
    {
        this->token = token;
        this->key = key;
        this->next = next;
    };
    SymbEntry(char *key, SymbEntry *next)
    {
        this->key = key;
        this->next = next;
    };
    ~SymbEntry(){};
    char *getKey() { return key; };
    int getToken() { return token; };
    SymbEntry *getNext() { return next; };
    void setKey(char *val) { key = val; };
    void setToken(int val) { token = val; };
    void setNext(SymbEntry *p) { next = p; };
};

class LinkedList
{
public:
    LinkedList();
    void destructLinkedList();
    char *search(char *val);      /// retorna o valor do k-�simo elemento
    void insertEnd(SymbEntry *p); /// insere um SymbEntryvo SymbEntry contendo val SymbEntry final da lista
    void print(int i);
    void printWithToken(int i);
    int searchAndReturnToken(char *val);

    int searchIsPresent(char *val);

private:
    SymbEntry *first; /// ponteiro para o first SymbEntry da lista
    SymbEntry *last;  /// ponteiro para o last SymbEntry da lista
    int n;            /// numero de SymbEntrys na lista
};

class HashTable
{
public:
    HashTable();
    void destructHashTable();
    virtual void print() = 0;

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
    void print();
};

class IdentifierOrLiteral : public HashTable
{
public:
    // The implementation for insert is specific to identifier or literal.
    int insert(char *key);
    char *search(char *key);
    void print();
    int isPresent(char *key);
};

#endif // HASH_H_INCLUDED