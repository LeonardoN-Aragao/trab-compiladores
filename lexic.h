#ifndef LEXIC_H
#define LEXIC_H

typedef struct lexicData {
   int pos;
   char* lexeme;
   char* token;
} lexicData;

void insertLexicData(char* token, char* lexeme, lexicData* val, int i);

void clearLexeme(char* lexeme);
lexicData lexicalAnalyzer(char *text, lexicData val);

#endif /* LEXIC_H */
