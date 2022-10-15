#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

typedef std::string string;
using namespace std;

class No
{
private:
    int token; /// valor armazenado no No
    string key;
    No *prox; /// ponteiro para o proximo No

public:
    No(int token, string key, No *prox)
    {
        this->token = token;
        this->key = key;
        this->prox = prox;
    };
    ~No(){};
    string getKey() { return key; };
    int getToken() { return token; };
    No *getProx() { return prox; };
    void setKey(string val) { key = val; };
    void setToken(int val) { token = val; };
    void setProx(No *p) { prox = p; };
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    int get(int k);           /// retorna o valor do k-�simo elemento
    void insereFinal(No *p);  /// insere um novo No contendo val no final da lista
    void removeInicio();      /// remove o first No da lista
    void removeFinal();       /// remove o �ltimo No da lista
    void print();

private:
    No *first; /// ponteiro para o first No da lista
    No *last;   /// ponteiro para o last No da lista
    int n;        /// numero de nos na lista
};

class HashTable
{
public:
    HashTable(int tam);
    void insert(string key);
    void print();

private:
    int tam;
    int hashFunction(string);
    LinkedList **table;
};

#endif // HASH_H_INCLUDED