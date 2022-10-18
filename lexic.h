#ifndef LEXIC_H
#define LEXIC_H

extern int tam;
extern int bufferSize;



typedef struct lexical lexical; // forward declaration of incomplete type

lexical *lexical_construct(
    char *reservedWordsOflanguage[]);
lexical *lexical_destruct(lexical *obj);
char *nextToken(lexical *obj, char *text);
char *getLexeme(lexical *obj);
void buildLexeme(lexical *obj, char *str2);
char *nextChar(lexical *lex);
void readFile(lexical *lex);

#endif /* LEXIC_H */
