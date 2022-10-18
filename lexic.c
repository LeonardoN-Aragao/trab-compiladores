#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.h"
#include "SymbolTable.h"
// #include "errorManager.h"

#define RED "\e[0;31m"
#define NC "\e[0m"

int tam = 0;
int bufferSize = 512;

struct lexical
{                // actual definition of the struct, local to lexical.c
   char *lexeme; // private variable
   ReservedWord reservedWords;
   IdentifierOrLiteral identifiers;
   IdentifierOrLiteral literals;
   char initialBuffer[512];
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

void buildLexeme(lexical *obj, char *str2)
{
   // printf("CONSTRUIBO LEXEMA \n");
   // printf("como veio %s \n", obj->lexeme);
   char *str3 = (char *)malloc(512 * sizeof(char));
   strcpy(str3, obj->lexeme);
   strcat(str3, str2);
   obj->lexeme = str3;
   // printf("str3 %s \n", str3);
}
char *nextChar(lexical *lex)
{
   char *a[4];
   a[0] = "i";
   a[1] = "f";
   a[2] = ")";
   a[3] = "(";

   // char *myfile[] = {"i", "f", ")", "("};
   printf("tam %d \n", tam);
   char *t = a[tam];
   if (tam < 3)
   {
      tam++;
   }

   return t;
   // char* buf = (char *)malloc(512 * sizeof(char));
   // buf = lex->initialBuffer;
   // printf("BUF %s", &buf[0]);
   // if (buf != '\0')
   // {

   // char t = lex->initialBuffer[tam];
   // char *entry = &t;
   // char *teste = &lex->initialBuffer[0];
   // printf("retunnnnnnnnn %s \n", &teste[0]);
   // return entry;
   //   }
}

void readFile(lexical *lex)
{
   FILE *pf;
   pf = fopen("test.txt", "r");
   if (NULL == pf)
   {
      printf("file can't be opened \n");
   }
   printf("antes while\n");
   while (fread(&lex->initialBuffer, sizeof *lex->initialBuffer, bufferSize, pf) > 1)
   {
      char *token;
      char *c, *t;
      t = nextChar(lex);
      printf("QUEM E VC %s \n", t);
      token = nextToken(lex, t);
      printf("IMPRIMINDO TOKEN ENCONTRADO %s \n", token);
   }
   fclose(pf);
}

char *nextToken(lexical *obj, char *text)
{
   char *c;
   char *token;
   int state = 0;
   int done = 0;
   // errorManager error;
   c = text;
   do
   {
      switch (state)
      {
      case 0:
         if (*c == '-')
         {
            state = 1;
            buildLexeme(obj, c);
         }
         else if (*c == '=')
         {
            state = 2;
            buildLexeme(obj, c);
         }
         else if (*c == '|')
         {
            state = 3;
            buildLexeme(obj, c);
         }
         else if (*c == '&')
         {
            state = 4;
            buildLexeme(obj, c);
         }
         else if (*c == '>')
         {
            state = 5;
            buildLexeme(obj, c);
         }
         else if (*c == '[')
         {
            state = 6;
            buildLexeme(obj, c);
         }
         else if (*c == '*')
         {
            state = 7;
            buildLexeme(obj, c);
         }
         else if (*c == '(')
         {
            state = 9;
            buildLexeme(obj, c);
         }
         else if (*c == ',')
         {
            state = 10;
            buildLexeme(obj, c);
         }
         else if (*c == '!')
         {
            state = 11;
            buildLexeme(obj, c);
         }
         else if (*c == ':')
         {
            state = 12;
            buildLexeme(obj, c);
         }
         else if (*c == ')')
         {
            state = 13;
            buildLexeme(obj, c);
         }
         else if (*c == '}')
         {
            state = 14;
            buildLexeme(obj, c);
         }
         else if (*c == '%')
         {
            state = 15;
            buildLexeme(obj, c);
         }
         else if (*c == '{')
         {
            state = 16;
            buildLexeme(obj, c);
         }
         else if (*c == '.')
         {
            state = 17;
            buildLexeme(obj, c);
         }
         else if (*c == '+')
         {
            state = 19;
            buildLexeme(obj, c);
         }
         else if (*c == ']')
         {
            state = 20;
            buildLexeme(obj, c);
         }
         else if (*c == '\\')
         {
            state = 21;
            buildLexeme(obj, c);
         }
         else if (*c == '>')
         {
            state = 22;
            buildLexeme(obj, c);
         }
         else if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
         {
            state = 23;
            buildLexeme(obj, c);
            c = nextChar(obj);
            break;
         }
         else if (*c == ';')
         {
            state = 31;
            buildLexeme(obj, c);
         }
         else if (*c >= '0' && *c <= '9')
         {
            state = 40;
            buildLexeme(obj, c);
         }
         else if (*c == '\"')
         {
            state = 50;
            buildLexeme(obj, c);
         }
         else if (*c == '/')
         {
            state = 51;
            buildLexeme(obj, c);
         }
         else if (*c == '\'')
         {
            state = 55;
            buildLexeme(obj, c);
         }
         break;
      case 1:
         if (*c == '>')
         {
            buildLexeme(obj, c);
            state = 24;
         }
         else
         {
            state = 36;
         }
         break;
      case 2:
         if (*c == '=')
         {
            buildLexeme(obj, c);
            state = 25;
         }
         else
         {
            state = 33;
         }
         break;
      case 3:
         if (*c == '|')
         {
            buildLexeme(obj, c);
            state = 26;
         }
         else
         {
            state = 37;
         }
      case 4:
         if (*c == '&')
         {
            buildLexeme(obj, c);
            state = 27;
         }
         else
         {
            state = 34;
         }
         break;
      case 5:
         if (*c == '=')
         {
            buildLexeme(obj, c);
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
         if (*c == '=')
         {
            buildLexeme(obj, c);
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
         if (*c >= '0' && *c <= '9')
         {
            buildLexeme(obj, c);
            state = 43;
         }
         else
         {
            state = 53;
         }
         break;
      case 18:
         if (*c == 'a' || *c == 'b' || *c == 'f' || *c == 'n' || *c == 'v' || *c == 't' || *c == '\\' || *c == '\'' || *c == '\"' || *c == '\0' || *c == '\?')
         {
            buildLexeme(obj, c);
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
         if (*c == '=')
         {
            buildLexeme(obj, c);
            state = 30;
         }
         else
         {
            state = 38;
         }
         break;
      case 23:
         printf("=============== \n");
         printf("CASE 23 %s \n", c);

         if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
         {
            printf("QUAL ERA O CARACTER? %s \n", c);
            buildLexeme(obj, c);
            printf("CONTRUI O lexeme %s \n", obj->lexeme);
            // c = "(";
            c = nextChar(obj);
            printf("qual o next: %s \n", c);
            state = 23;
            break;
         }
         else
         {
            printf("prox estado \n");
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
         if (obj->reservedWords.search(obj->lexeme) != "")
         {
            token = obj->reservedWords.search(obj->lexeme);
            printf("achou nas reservadas %s \n", token);
            free(obj->lexeme);
         }
         else
         {
            if (obj->identifiers.search(obj->lexeme) != "")
            {
               token = obj->identifiers.insert(obj->lexeme);
               printf("inseriu na de IDS \n");
            }
            else
            {
               token = obj->identifiers.search(obj->lexeme);
            }
         }
         done = 1;
         return token;
         break;
      case 40:
         if (*c >= '0' && *c <= '9')
         {
            buildLexeme(obj, c);
            state = 40;
         }
         else if (*c == 'e' || *c == 'E')
         {
            buildLexeme(obj, c);
            state = 44;
         }
         else if (*c == '.')
         {
            buildLexeme(obj, c);
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
         if (*c >= '0' && *c <= '9')
         {
            buildLexeme(obj, c);
            state = 43;
         }
         else if (*c == 'e' || *c == 'E')
         {
            buildLexeme(obj, c);
            state = 44;
         }
         else
         {
            state = 52;
         }
         break;
      case 44:
         if (*c >= '0' && *c <= '9')
         {
            buildLexeme(obj, c);
            state = 47;
         }
         else if (*c == '+' || *c == '-')
         {
            buildLexeme(obj, c);
            state = 45;
         }
      case 45:
         if (*c >= '0' && *c <= '9')
         {
            buildLexeme(obj, c);
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
         if (*c >= '0' && *c <= '9')
         {
            buildLexeme(obj, c);
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
         if (*c == '\"')
         {
            buildLexeme(obj, c);
            state = 49;
         }
         else if (*c == 'a' || *c == 'b' || *c == 'f' || *c == 'n' || *c == 'v' || *c == 't' || *c == '\\' || *c == '\'' || *c == '\"' || *c == '\0' || *c == '\?')
         {
            buildLexeme(obj, c);
            state = 18;
         }
         else if (*c == EOF)
         {
            state = 58;
         }
         else
         {
            buildLexeme(obj, c);
            state = 50;
         }
         break;
      case 51:
         if (*c == '*')
         {
            buildLexeme(obj, c);
            state = 60;
         }
         else if (*c == '/')
         {
            buildLexeme(obj, c);
            state = 63;
         }
         else
         {
            buildLexeme(obj, c);
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
         if (*c == '/')
         {
            buildLexeme(obj, c);
            state = 49;
         }
         else
         {
            buildLexeme(obj, c);
            state = 59;
         }
         break;
      case 56:
         if (*c == '\'')
         {
            buildLexeme(obj, c);
            state = 49;
         }
         break;
      case 57:
         if (*c == 'a' || *c == 'b' || *c == 'f' || *c == 'n' || *c == 'v' || *c == 't' || *c == '\\' || *c == '\'' || *c == '\"' || *c == '\0' || *c == '\?')
         {
            buildLexeme(obj, c);
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
         if (*c == '/')
         {
            buildLexeme(obj, c);
            state = 49;
         }
         else if (*c == EOF)
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
         if (*c == '*')
         {
            buildLexeme(obj, c);
            state = 58;
         }
         else if (*c == EOF)
         {
            state = 61;
         }
         else
         {
            buildLexeme(obj, c);
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
         if (*c == '/')
         {
            buildLexeme(obj, c);
            state = 64;
         }
         else
         {
            buildLexeme(obj, c);
            state = 63;
         }
      case 64:
         if (*c == '/')
         {
            buildLexeme(obj, c);
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
