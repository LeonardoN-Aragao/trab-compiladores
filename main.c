#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.h"

char *reservedWordsOflanguage[] = {"if", "else", "try", NULL};

const char *getTokenName(int value)
{
#define NAME(ERR) \
   case ERR:      \
      return #ERR;
   switch (value)
   {
      NAME(lbrackets)
      NAME(asterisk)
      NAME(lparent)
      NAME(comma)
      NAME(colon)
      NAME(rparent)
      NAME(rbraces)
      NAME(percent)
      NAME(lbraces)
      NAME(plusSign)
      NAME(rbrackets)
      NAME(backslash)
      NAME(arrow)
      NAME(equality)
      NAME(orSign)
      NAME(andSign)
      NAME(greaterOrEqual)
      NAME(notEqual)
      NAME(lessOrEqual)
      NAME(semicolon)
      NAME(exclamation)
      NAME(assing)
      NAME(ampersand)
      NAME(great)
      NAME(minusSign)
      NAME(verticalPipe)
      NAME(lessSign)
      NAME(slash)
      NAME(dot)
      NAME(EOF)
      NAME(ReservedWordOfLanguage)
      NAME(identifier)
      NAME(literal)
      NAME(numInt)
      NAME(numFloat)
   }
   return "unknown";
#undef NAME
}

int main()
{
   // // Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'
   FILE *pf;
   int bufferSize = 512;
   char initialBuffer[bufferSize];

   lexical *lex = lexical_construct(reservedWordsOflanguage);

   pf = fopen("test.txt", "r");
   if (NULL == pf)
   {
      printf("file can't be opened \n");
   }

   while (fread(&initialBuffer, sizeof *initialBuffer, bufferSize, pf) > 1)
   {
      // char *token = "";
      int token = 0;
      char t;
      char *teste;

      teste = &initialBuffer[0];


      while (token != EOF)
      {  
         t = nextChar(lex, teste);
         // printf("next char main %c \n", t);
         token = nextToken(lex, t, teste);
         // printf("next token %d \n", token);
         if (token != NULL)
         {
            const char *tName = getTokenName(token);
            if (token == 30 || token == 31 || token == 32 || token == 33 || token == 34)
            {
               char *s = searchAndGetString(lex, token, getLexeme(lex));
               printf("%s.%s \n", tName, s);
            }
            else
            {
               printf("%s \n", tName);
            }
         }
      }
   }

   fclose(pf);

   return 0;
}
