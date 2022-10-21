#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.h"

char *reservedWordsOflanguage[] = {"int", "float", "bool", "char", "double",
                                   "long", "if", "else", "while", "switch", "case", "break", "print",
                                   "readln", "return", "throw", "try", "catch", "true",
                                   "false", "typedef", "struct"};

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
      NAME(assignment)
      NAME(ampersand)
      NAME(great)
      NAME(minusSign)
      NAME(verticalPipe)
      NAME(lessSign)
      NAME(slash)
      NAME(dot)
      NAME(EOF)
      NAME(identifier)
      NAME(literal)
      NAME(numInt)
      NAME(numFloat)
      NAME(int_)
      NAME(float_)
      NAME(bool_)
      NAME(char_)
      NAME(double_)
      NAME(long_)
      NAME(if_)
      NAME(else_)
      NAME(while_)
      NAME(switch_)
      NAME(case_)
      NAME(break_)
      NAME(print_)
      NAME(readln_)
      NAME(return_)
      NAME(throw_)
      NAME(try_)
      NAME(catch_)
      NAME(true_)
      NAME(false_)
      NAME(typedef_)
      NAME(struct_)
   }
   return "unknown";
#undef NAME
}

int main()
{
   // // Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'

   lexical *lex = lexical_construct(reservedWordsOflanguage);

   int token = 0;
   while (token != EOF)
   {

      // printf("next char main \n");
      token = nextToken(lex);
      // printf("next token %d \n", token);
      if (token != NULL)
      {
         const char *tName = getTokenName(token);
         if (token == 31 || token == 32 || token == 33 || token == 34)
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

   // fclose(pf);

   return 0;
}
