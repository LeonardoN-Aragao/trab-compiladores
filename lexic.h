#ifndef LEXIC_H
#define LEXIC_H

typedef struct lexical lexical; // forward declaration of incomplete type

lexical *lexical_construct();
lexical *lexical_destruct(lexical *obj);
char *nextToken(lexical *obj, char text);
char *getLexeme(lexical *obj);

#endif /* LEXIC_H */
