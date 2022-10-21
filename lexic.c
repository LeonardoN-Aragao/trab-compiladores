#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.h"
#include "SymbolTable.h"
#include "errorManager.h"

#define RED "\e[0;31m"
#define NC "\e[0m"
#define BUFFERSIZE 512

int position = 0;
int qntReallocations = 1;
int wantShow = 0;

struct lexical
{                // actual definition of the struct, local to lexical.c
   char *lexeme; // private variable
   ReservedWord reservedWords;
   IdentifierOrLiteral identifiers;
   IdentifierOrLiteral literals;
   IdentifierOrLiteral intNumbers;
   IdentifierOrLiteral floatNumbers;
   char initialBuffer[BUFFERSIZE];
   FILE *pf;
};

lexical *lexical_construct(char *reservedWordsOflanguage[])
{
   lexical *obj;
   obj = (lexical *)malloc(sizeof(lexical));
   ReservedWord reserved;
   IdentifierOrLiteral id;
   IdentifierOrLiteral lit;
   IdentifierOrLiteral intNumbers;
   IdentifierOrLiteral floatNumbers;

   if (obj == NULL)
   {
      printf("Error creating lexical analyzer");
   }
   obj->lexeme = (char *)malloc(BUFFERSIZE * sizeof(char));
   obj->reservedWords = reserved;
   obj->identifiers = id;
   obj->literals = lit;
   obj->intNumbers = intNumbers;
   obj->floatNumbers = floatNumbers;

   // printf("INICIAL ALOCACAO %p \n", obj->lexeme);

   int i = 0;
   int j = 35;
   while (reservedWordsOflanguage[i])
   {
      obj->reservedWords.insert(reservedWordsOflanguage[i], j);
      i++;
      j++;
   };

   obj->pf = fopen("test1.txt", "r");
   if (NULL == obj->pf)
   {
      printf("file can't be opened \n");
   }

   return obj;
}

lexical *lexical_destruct(lexical *obj)
{
   free(obj);
   free(obj->lexeme);
   return NULL;
}

char *getLexeme(lexical *obj)
{
   return obj->lexeme;
}

void buildLexeme(lexical *obj, char str2)
{
   size_t const size = strlen(obj->lexeme);
   // printf("\nvoltou pra concatenar lexema: %d : %s\n", size,obj->lexeme );

   if (size == (qntReallocations * BUFFERSIZE) - 1)
   {
      obj->lexeme = (char *)realloc(obj->lexeme, (qntReallocations * BUFFERSIZE) + 512);
      qntReallocations++;
   }

   obj->lexeme[wantShow] = str2;
   wantShow++;
   // printf("size inserido %d %c \n", size, str2);

   //    if (wantShow)
   // {
   //    printf("lexema %s \n", obj->lexeme);
   //    wantShow = 0;
   // }

   // printf("lexema %s \n", obj->lexeme);

   // char* teste = obj->lexeme[size];
   // printf("retornou isso  %s \n", teste );
}

char nextChar(lexical *lex)
{
   int len = strlen(lex->initialBuffer);
   // printf("\n VEIO PARA RETORNAR NEXT CHAR position %d len %d \n", position, len);
   if (len == 0 || position == BUFFERSIZE || position == len - 1)
   {
      // printf("veio aq %d \n", position == BUFFERSIZE);
      // printf("antes de ler %s \n", lex->initialBuffer);
      // int q = 0;
      // while (lex->initialBuffer[q] != '\0')
      // {
      //    lex->initialBuffer[q] = '\0';
      //    q++;
      // }
      char testando[BUFFERSIZE];
      int qnt = fread(&lex->initialBuffer, sizeof(char), BUFFERSIZE, lex->pf);
      int bb = fread(&testando, sizeof(char), BUFFERSIZE, lex->pf);
      // printf("\n INITIAL BUFFER %s \n", lex->initialBuffer);
      // printf("\n TESTE BUFFER %s \n", testando);
      // printf("depois de ler %s \n", lex->initialBuffer);

      if (qnt == 0)
      {
         // printf("retornou EOF \n");
         // printf("lexema %s \n", lex->initialBuffer);
         return EOF;
      }
      else
      {
         position = 0;
         // printf("voltou pra posicao 0 %d \n", qnt);
      }
      // printf("CONTINUOU E N RETORNOU EOF \n");
   }
   // printf("POSITION  %d  LEN %d \n ", position, len);

   char c = lex->initialBuffer[position];

   position++;
   // printf("position final  %d e carac %c \n", position, c);
   return c;
}

int setDone(char c)
{
   int result = isspace(c);

   if (result == 0 && c != EOF)
      position--;
   return 1;
}

int nextToken(lexical *obj)
{
   char c;
   int token;
   int state = 0;
   int result;
   obj->lexeme[0] = '\0';
   wantShow = 0;
   int done = 0;
   errorManager error;
   c = nextChar(obj);
   // printf("novo char %c ", c);
   if (c == EOF)
   {
      printf("CHEHHHHHHHHHHHHHHHHHHHHH \n");
      token = EOF;
      return token;
   }

   int t = 1;
   while (obj->lexeme[t] != '\0')
   {
      obj->lexeme[t] = '\0';
      t++;
   }

   result = isspace(c);

   if (result != 0)
   {
      return NULL;
   }
   // printf("novo next token %c \n", c);
   // printf("lexema inicial %s \n", obj->lexeme);
   // printf("=============");
   do
   {

      // printf("state %d \n ", state);

      switch (state)
      {
      case 0:
         if (c == EOF)
         {
            printf("eof no swithc \n");
         }
         if (c == '-')
         {
            state = 1;
            buildLexeme(obj, c);
            c = nextChar(obj);
         }
         else if (c == '=')
         {
            state = 2;
            buildLexeme(obj, c);
            c = nextChar(obj);
         }
         else if (c == '|')
         {
            state = 3;
            buildLexeme(obj, c);
            c = nextChar(obj);
         }
         else if (c == '&')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 4;
         }
         else if (c == '>')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 5;
         }
         else if (c == '<')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 22;
         }
         else if (c == '[')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 6;
         }
         else if (c == '*')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 7;
         }
         else if (c == '(')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 9;
         }
         else if (c == ',')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 10;
         }
         else if (c == '!')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 11;
         }
         else if (c == ':')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 12;
         }
         else if (c == ')')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 13;
         }
         else if (c == '}')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 14;
         }
         else if (c == '%')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 15;
         }
         else if (c == '{')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 16;
         }
         else if (c == '.')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 17;
         }
         else if (c == '+')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 19;
         }
         else if (c == ']')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 20;
         }
         else if (c == '\\')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 21;
         }
         else if (c == '>')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 22;
         }
         else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 23;
            break;
         }
         else if (c == ';')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 31;
         }
         else if (c >= '0' && c <= '9')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 40;
         }
         else if (c == '\"')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 50;
         }
         else if (c == '/')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 51;
         }
         else if (c == '\'')
         {

            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 55;
         }
         break;
      case 1:
         if (c == '>')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
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
            buildLexeme(obj, c);
            c = nextChar(obj);
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
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 26;
         }
         else
         {
            state = 37;
         }
      case 4:
         if (c == '&')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
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
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 28;
         }
         else
         {
            state = 35;
         }
         break;
      case 6:
         token = lbrackets;
         done = setDone(c);
         return token;
         break;
      case 7:
         token = asterisk;
         done = setDone(c);
         return token;
         break;
      case 9:
         // printf("CASE 9 RECONHECENDO %c  ", c);
         token = lparent;
         done = setDone(c);
         return token;
         break;
      case 10:
         token = comma;
         done = setDone(c);
         return token;
         break;
      case 11:
         if (c == '=')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 29;
         }
         else
         {
            state = 32;
         }
         break;
      case 12:
         token = colon;
         done = setDone(c);
         return token;
         break;
      case 13:
         token = rparent;
         done = setDone(c);
         return token;
         break;
      case 14:
         token = rbraces;
         done = setDone(c);
         return token;
         break;
      case 15:
         token = percent;
         done = setDone(c);
         return token;
         break;
      case 16:
         token = lbraces;
         done = setDone(c);
         return token;
         break;
      case 17:
         if (c >= '0' && c <= '9')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
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
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 50;
         }
         else
         {
            state = 48;
         }
      case 19:
         token = plusSign;
         done = setDone(c);
         return token;
         break;
      case 20:
         token = rbrackets;
         done = setDone(c);
         return token;
         break;
      case 21:
         token = backslash;
         done = setDone(c);
         return token;
         break;
      case 22:
         if (c == '=')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 30;
         }
         else
         {
            state = 38;
         }
         break;
      case 23:

         if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
         {
            // printf("veio no 23 %c \n", c);
            buildLexeme(obj, c);
            // printf("contruindo lexema %s \n", obj->lexeme);
            c = nextChar(obj);
            // printf("montando str %c \n", c);
            // printf("POSITIONS %d \n", position);

            state = 23;
         }
         else
         {
            // printf("veio pra 39 \n");

            state = 39;
         }
         break;
      case 24:
         token = arrow;
         done = setDone(c);
         return token;
         break;
      case 25:
         token = equality;
         done = setDone(c);
         return token;
         break;
      case 26:
         token = orSign;
         done = setDone(c);
         return token;
         break;
      case 27:
         token = ampersand;
         done = setDone(c);
         return token;
         break;
      case 28:
         token = greaterOrEqual;
         done = setDone(c);
         return token;
         break;
      case 29:
         token = notEqual;
         done = setDone(c);
         return token;
         break;
      case 30:
         token = lessOrEqual;
         done = setDone(c);
         return token;
         break;
      case 31:
         token = semicolon;
         done = setDone(c);
         return token;
         break;
      case 32:
         token = exclamation;
         done = setDone(c);
         return token;
         break;
      case 33:
         token = assignment;
         done = setDone(c);
         return token;
         break;
      case 34:
         token = andSign;
         done = setDone(c);
         return token;
         break;
      case 35:
         token = great;
         done = setDone(c);
         return token;
         break;
      case 36:
         token = minusSign;
         done = setDone(c);
         return token;
         break;
      case 37:
         token = verticalPipe;
         done = setDone(c);
         return token;
         break;
      case 38:
         token = lessSign;
         done = setDone(c);
         return token;
         break;
      case 39:
         // printf("o que vou reconhecer %s \n", obj->lexeme);
         int tokenId;
         tokenId = obj->reservedWords.search(obj->lexeme);

         if (tokenId != -100)
         {
            token = tokenId;
         }
         else
         {
            char *isIdentifier;
            isIdentifier = obj->identifiers.search(obj->lexeme);
            if (isIdentifier == NULL)
            {
               obj->identifiers.insert(obj->lexeme);
               token = identifier;
            }
            else
            {
               token = identifier;
            }
         }
         // position--;

         done = setDone(c);
         // printf("setou na tab %d \n", position);
         return token;
         break;
      case 40:
         if (c >= '0' && c <= '9')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 40;
         }
         else if (c == 'e' || c == 'E')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            printf("go to state 44 %c \n", c);
            state = 44;
         }
         else if (c == '.')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 43;
         }
         else
         {
            state = 41;
         }
         break;
      case 41:

         char *isAlreadyIntTable;
         isAlreadyIntTable = obj->intNumbers.search(obj->lexeme);
         if (isAlreadyIntTable != NULL)
         {
            token = numInt;
         }
         else
         {
            obj->intNumbers.insert(obj->lexeme);
            token = numInt;
         }

         done = setDone(c);
         return token;
         break;
      case 43:
         if (c >= '0' && c <= '9')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 43;
         }
         else if (c == 'e' || c == 'E')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
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
            printf("aaaaa vai pro 47 %c \n ", c);
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 47;
         }
         else if (c == '+' || c == '-')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 45;
         }
         break;
      case 45:
         if (c >= '0' && c <= '9')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 47;
         }
         else
         {
            printf("case 45 %c \n", c);
            state = 54;
         }
         break;
      case 46:
         error = createError(1, "Unexpected end of file");
         printError(error);
         state = 0;
         c = nextChar(obj);
         break;
      case 47:
         if (c >= '0' && c <= '9')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 47;
         }
         else
         {
            state = 52;
         }
         break;
      case 48:
         error = createError(2, "Invalid escape character");
         printError(error);
         c = nextChar(obj);
         state = 0;

         break;
      case 49:
         char *isAlreadyInLiteralsTable;
         isAlreadyInLiteralsTable = obj->literals.search(obj->lexeme);

         if (isAlreadyInLiteralsTable != NULL)
         {
            token = literal;
         }
         else
         {
            obj->literals.insert(obj->lexeme);
            token = literal;
         }
         done = setDone(c);
         return token;
         break;
      case 50:
         if (c == '\"')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 49;
         }
         else if (c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 18;
         }
         else if (c == EOF)
         {
            state = 58;
         }
         else
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 50;
         }
         break;
      case 51:
         if (c == '*')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 60;
         }
         else if (c == '/')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 63;
         }
         else
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 50;
         }
         break;
      case 52:
         char *isAlreadyInFloatTable;
         isAlreadyInFloatTable = obj->floatNumbers.search(obj->lexeme);
         if (isAlreadyInFloatTable != NULL)
         {
            token = numFloat;
         }
         else
         {
            obj->floatNumbers.insert(obj->lexeme);
            token = numFloat;
         }

         done = setDone(c);
         return token;
         break;
      case 53:
         token = dot;
         done = setDone(c);
         return token;

         break;
      case 54:
         error = createError(4, "Invalid Number");
         printError(error);
         c = nextChar(obj);
         state = 0;

         break;
      case 55:
         if (c == '/')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 49;
         }
         else
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 59;
         }
         break;
      case 56:
         if (c == '\'')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 49;
         }
         break;
      case 57:
         if (c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 49;
         }
         else
         {
            error = createError(5, "Invalid escape character");
            printError(error);
            c = nextChar(obj);
            state = 0;
         }
         break;
      case 58:
         if (c == '/')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 49;
         }
         else if (c == EOF)
         {
            state = 61;
         }
         break;
      case 59:
         error = createError(6, "Invalid escape character");
         printError(error);
         c = nextChar(obj);
         state = 0;

         break;
      case 60:
         if (c == '*')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 58;
         }
         else if (c == EOF)
         {
            state = 61;
         }
         else
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 60;
         }
         break;
      case 61:
         error = createError(7, "Unexpected end of file in comment statement");
         printError(error);
         c = nextChar(obj);
         break;
      case 62:
         // token = "Comment";
         done = setDone(c);
         return token;
         break;
      case 63:
         if (c == '/')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 64;
         }
         else
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 63;
         }
         break;
      case 64:
         if (c == '/')
         {
            buildLexeme(obj, c);
            c = nextChar(obj);
            state = 62;
         }
         break;
      case 65:
         token = slash;
         done = setDone(c);
         return token;
         break;
      default:
         break;
      }

   } while (done != 1);

   return NULL;
};

char *searchAndGetString(lexical *lex, int token, char *lexeme)
{

   char *b;
   switch (token)
   {
   case 31:
      b = lex->identifiers.search(lexeme);
      return b;
      break;
   case 32:
      b = lex->literals.search(lexeme);
      return b;
      break;
   case 33:
      b = lex->intNumbers.search(lexeme);
      return b;
      break;
   case 34:
      b = lex->floatNumbers.search(lexeme);
      return b;
      break;

   default:
      break;
   }
};
