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
#define assignment 22
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


#define int_ 35
#define float_ 36
#define bool_ 37
#define char_ 38
#define double_ 39
#define long_ 40
#define if_ 41
#define else_ 42
#define while_ 43
#define switch_ 44
#define case_ 45
#define break_ 46
#define print_ 47
#define readln_ 48
#define return_ 49
#define throw_ 50
#define try_ 51
#define catch_ 52
#define true_ 53
#define false_ 54
#define typedef_ 55
#define struct_ 56

typedef struct lexical lexical; // forward declaration of incomplete type
extern int position;

lexical *lexical_construct(
    char *reservedWordsOflanguage[]);
lexical *lexical_destruct(lexical *obj);

int nextToken(lexical *obj, char text, char *buffer);
char nextChar(lexical *lex, char *buffer);

char *getLexeme(lexical *obj);
void buildLexeme(lexical *obj, char *str2);

char *searchAndGetString(lexical *lex, int token, char *lexeme);

#endif /* LEXIC_H */
