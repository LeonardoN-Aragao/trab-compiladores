#ifndef LEXIC_H
#define LEXIC_H

#define lbrackets 1
#define asterisk 2
#define lparent 3
#define comma 4
#define colon 5
#define rparent 6
#define rbraces 7
#define percent 8
#define lbraces 9
#define plusSign 10
#define rbrackets 11
#define backslash 12
#define arrow 13
#define equality 14
#define orSign 15
#define andSign 16
#define greaterOrEqual 17
#define notEqual 18
#define lessOrEqual 19
#define semicolon 20
#define exclamation 21
#define assing 22
#define ampersand 23
#define great 24
#define minusSign 25
#define verticalPipe 26
#define lessSign 27
#define slash 28
#define dot 29
#define ReservedWordOfLanguage 30
#define identifier 31
#define literal 32
#define numInt 33
#define numFloat 34

typedef struct lexical lexical; // forward declaration of incomplete type
extern int position;

lexical *lexical_construct(
    char *reservedWordsOflanguage[]);
lexical *lexical_destruct(lexical *obj);
int nextToken(lexical *obj, char text, char *buffer);
char *getLexeme(lexical *obj);
void buildLexeme(lexical *obj, char *str2);
char nextChar(lexical *lex, char *buffer);
char *searchAndGetString(lexical *lex, int token, char *lexeme);


#endif /* LEXIC_H */
