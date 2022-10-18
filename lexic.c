#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.h"
#include "SymbolTable.h"
// #include "errorManager.h"

#define RED "\e[0;31m"
#define NC "\e[0m"

struct lexical
{                // actual definition of the struct, local to lexical.c
   char *lexeme; // private variable
   ReservedWord reservedWords;
   IdentifierOrLiteral identifiers;
   IdentifierOrLiteral literals;
};

lexical *lexical_construct(char *reservedWordsOflanguage[])
{
   lexical *obj;
   obj = (lexical *)malloc(sizeof(lexical));
   ReservedWord reserved;
   IdentifierOrLiteral id;
   IdentifierOrLiteral lit;

   if (obj == NULL)
   {
      printf("Error creating lexical analyzer");
   }
   obj->lexeme = (char *)malloc(512 * sizeof(char));
   obj->reservedWords = reserved;
   obj->identifiers = id;
   obj->literals = lit;

   int i = 0;
   while (reservedWordsOflanguage[i])
   {
      printf("%s\n", reservedWordsOflanguage[i]);
      obj->reservedWords.insert(reservedWordsOflanguage[i]);
      i++;
   };

   return obj;
}

lexical *lexical_destruct(lexical *obj)
{
   free(obj);
   return NULL;
}

char *getLexeme(lexical *obj)
{
   return obj->lexeme;
}

char *nextToken(lexical *obj, char text)
{
   char c;
   char *token;
   int state = 0;
   int done = 0;
   // errorManager error;

   do
   {
      c = text;
      switch (state)
      {
      case 0:
         if (c == '-')
         {
            state = 1;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '=')
         {
            state = 2;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '|')
         {
            state = 3;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '&')
         {
            state = 4;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '>')
         {
            state = 5;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '[')
         {
            state = 6;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '*')
         {
            state = 7;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '(')
         {
            state = 9;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == ',')
         {
            state = 10;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '!')
         {
            state = 11;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == ':')
         {
            state = 12;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == ')')
         {
            state = 13;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '}')
         {
            state = 14;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '%')
         {
            state = 15;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '{')
         {
            state = 16;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '.')
         {
            state = 17;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '+')
         {
            state = 19;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == ']')
         {
            state = 20;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '\\')
         {
            state = 21;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '>')
         {
            state = 22;
            strncat(obj->lexeme, &c, 1);
         }
         else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
         {
            state = 23;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == ';')
         {
            state = 31;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c >= '0' && c <= '9')
         {
            state = 40;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '\"')
         {
            state = 50;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '/')
         {
            state = 51;
            strncat(obj->lexeme, &c, 1);
         }
         else if (c == '\'')
         {
            state = 55;
            strncat(obj->lexeme, &c, 1);
         }
         break;
      case 1:
         if (c == '>')
         {
            strncat(obj->lexeme, &c, 1);
            state = 24;
         }
         else
         {
            state = 36;
         }
         break;
      case 2:
         if (c == '=')
         {
            strncat(obj->lexeme, &c, 1);
            state = 25;
         }
         else
         {
            state = 33;
         }
         break;
      case 3:
         if (c == '|')
         {
            strncat(obj->lexeme, &c, 1);
            state = 26;
         }
         else
         {
            state = 37;
         }
      case 4:
         if (c == '&')
         {
            strncat(obj->lexeme, &c, 1);
            state = 27;
         }
         else
         {
            state = 34;
         }
         break;
      case 5:
         if (c == '=')
         {
            strncat(obj->lexeme, &c, 1);
            state = 28;
         }
         else
         {
            state = 35;
         }
         break;
      case 6:
         token = "lbrackets";
         done = 1;
         return token;
         break;
      case 7:
         token = "asterisk";
         done = 1;
         return token;
         break;
      case 9:
         token = "lparent";
         done = 1;
         return token;
         break;
      case 10:
         token = "comma";
         done = 1;
         return token;
         break;
      case 11:
         if (c == '=')
         {
            strncat(obj->lexeme, &c, 1);
            state = 29;
         }
         else
         {
            state = 32;
         }
         break;
      case 12:
         token = "colon";
         done = 1;
         return token;
         break;
      case 13:
         token = "rparent";
         done = 1;
         return token;
         break;
      case 14:
         token = "rbraces";
         done = 1;
         return token;
         break;
      case 15:
         token = "percent";
         done = 1;
         return token;
         break;
      case 16:
         token = "lbraces";
         done = 1;
         return token;
         break;
      case 17:
         if (c >= '0' && c <= '9')
         {
            strncat(obj->lexeme, &c, 1);
            state = 43;
         }
         else
         {
            state = 53;
         }
         break;
      case 18:
         if (c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?')
         {
            strncat(obj->lexeme, &c, 1);
            state = 50;
         }
         else
         {
            state = 48;
         }
      case 19:
         token = "plus";
         done = 1;
         return token;
         break;
      case 20:
         token = "rbrackets";
         done = 1;
         return token;
         break;
      case 21:
         token = "backslash";
         done = 1;
         return token;
         break;
      case 22:
         if (c == '=')
         {
            strncat(obj->lexeme, &c, 1);
            state = 30;
         }
         else
         {
            state = 38;
         }
         break;
      case 23:
         if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
         {
            strncat(obj->lexeme, &c, 1);
            state = 23;
         }
         else
         {
            state = 39;
         }
         break;
      case 24:
         token = "arrow";
         done = 1;
         return token;
         break;
      case 25:
         token = "equal";
         done = 1;
         return token;
         break;
      case 26:
         token = "or";
         done = 1;
         return token;
         break;
      case 27:
         token = "and";
         done = 1;
         return token;
         break;
      case 28:
         token = "greaterOrEqual";
         done = 1;
         return token;
         break;
      case 29:
         token = "notEqual";
         done = 1;
         return token;
         break;
      case 30:
         token = "lessOrEqual";
         done = 1;
         return token;
         break;
      case 31:
         token = "semicolon";
         done = 1;
         return token;
         break;
      case 32:
         token = "exclamation";
         done = 1;
         return token;
         break;
      case 33:
         token = "assing";
         done = 1;
         return token;
         break;
      case 34:
         token = "ampersand";
         done = 1;
         return token;
         break;
      case 35:
         token = "great";
         done = 1;
         return token;
         break;
      case 36:
         token = "minus";
         done = 1;
         return token;
         break;
      case 37:
         token = "verticalPipe";
         done = 1;
         return token;
         break;
      case 38:
         token = "less";
         done = 1;
         return token;
         break;
      case 39:
         token = "check SymbTable:";
         done = 1;
         return token;
         break;
      case 40:
         if (c >= '0' && c <= '9')
         {
            strncat(obj->lexeme, &c, 1);
            state = 40;
         }
         else if (c == 'e' || c == 'E')
         {
            strncat(obj->lexeme, &c, 1);
            state = 44;
         }
         else if (c == '.')
         {
            strncat(obj->lexeme, &c, 1);
            state = 43;
         }
         else
         {
            state = 41;
         }
         break;
      case 41:
         token = "numInt";
         done = 1;
         return token;
         break;
      case 43:
         if (c >= '0' && c <= '9')
         {
            strncat(obj->lexeme, &c, 1);
            state = 43;
         }
         else if (c == 'e' || c == 'E')
         {
            strncat(obj->lexeme, &c, 1);
            state = 44;
         }
         else
         {
            state = 52;
         }
         break;
      case 44:
         if (c >= '0' && c <= '9')
         {
            strncat(obj->lexeme, &c, 1);
            state = 47;
         }
         else if (c == '+' || c == '-')
         {
            strncat(obj->lexeme, &c, 1);
            state = 45;
         }
      case 45:
         if (c >= '0' && c <= '9')
         {
            strncat(obj->lexeme, &c, 1);
            state = 47;
         }
         else
         {
            state = 54;
         }
         break;
      case 46:
         // error = createError(1, "Unexpected end of file");
         printf("error 46");
         // insertLexicDataWithErro(token, lexeme, &val, i, 1);
         // return c;
         break;
      case 47:
         if (c >= '0' && c <= '9')
         {
            strncat(obj->lexeme, &c, 1);
            state = 47;
         }
         else
         {
            state = 52;
         }
      case 48:
         // error = createError(2, "Invalid escape character");
         printf("error 48");
         // insertLexicDataWithErro(token, lexeme, &val, i, 1);
         // return val;
         break;
      case 49:
         token = "LITERAL";
         done = 1;
         return token;
         break;
      case 50:
         if (c == '\"')
         {
            strncat(obj->lexeme, &c, 1);
            state = 49;
         }
         else if (c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?')
         {
            strncat(obj->lexeme, &c, 1);
            state = 18;
         }
         else if (c == EOF)
         {
            state = 58;
         }
         else
         {
            strncat(obj->lexeme, &c, 1);
            state = 50;
         }
         break;
      case 51:
         if (c == '*')
         {
            strncat(obj->lexeme, &c, 1);
            state = 60;
         }
         else if (c == '/')
         {
            strncat(obj->lexeme, &c, 1);
            state = 63;
         }
         else
         {
            strncat(obj->lexeme, &c, 1);
            state = 50;
         }
         break;
      case 52:
         token = "numFloat";
         done = 1;
         return token;
         break;
      case 53:
         // error = createError(3, "Invalid Number");
         printf("error 53");
         // insertLexicDataWithErro(token, lexeme, &val, i, 1);
         // return val;
         break;
      case 54:
         // error = createError(4, "Invalid Number");
         printf("error 54");
         // insertLexicDataWithErro(token, lexeme, &val, i, 1);
         // return val;
         break;
      case 55:
         if (c == '/')
         {
            strncat(obj->lexeme, &c, 1);
            state = 49;
         }
         else
         {
            strncat(obj->lexeme, &c, 1);
            state = 59;
         }
         break;
      case 56:
         if (c == '\'')
         {
            strncat(obj->lexeme, &c, 1);
            state = 49;
         }
         break;
      case 57:
         if (c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?')
         {
            strncat(obj->lexeme, &c, 1);
            state = 49;
         }
         else
         {
            // error = createError(5, "Invalid escape character");
            printf("error 57");
            // insertLexicDataWithErro(token, lexeme, &val, i, 1);
            // return val;
         }
      case 58:
         if (c == '/')
         {
            strncat(obj->lexeme, &c, 1);
            state = 49;
         }
         else if (c == EOF)
         {
            state = 61;
         }
      case 59:
         // error = createError(6, "Invalid escape character");
         printf("error 59");
         // insertLexicDataWithErro(token, lexeme, &val, i, 1);
         // return val;
         // continue;
         break;
      case 60:
         if (c == '*')
         {
            strncat(obj->lexeme, &c, 1);
            state = 58;
         }
         else if (c == EOF)
         {
            state = 61;
         }
         else
         {
            strncat(obj->lexeme, &c, 1);
            state = 60;
         }
      case 61:
         // error = createError(7, "Unexpected end of file in comment statement");
         printf("error 61");
         // insertLexicDataWithErro(token, lexeme, &val, i, 1);
         // return val;
         break;
      case 62:
         token = "Comment";
         done = 1;
         return token;
         break;
      case 63:
         if (c == '/')
         {
            strncat(obj->lexeme, &c, 1);
            state = 64;
         }
         else
         {
            strncat(obj->lexeme, &c, 1);
            state = 63;
         }
      case 64:
         if (c == '/')
         {
            strncat(obj->lexeme, &c, 1);
            state = 62;
         }
      case 65:
         token = "slash";
         done = 1;
         done = 1;
         return token;
         break;
      default:
         break;
      }
   } while (done != 1);
   return NULL;
}
