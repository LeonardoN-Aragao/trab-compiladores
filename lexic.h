#ifndef LEXIC_H
#define LEXIC_H


typedef struct lexicData {
        char* lexeme;

} lexicData;

char* nextToken(char text, char* lexeme);

#endif /* LEXIC_H */
