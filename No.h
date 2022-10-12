#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include <string>
#include <iostream>
#include <cstdlib>
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
#endif // NO_H_INCLUDED
