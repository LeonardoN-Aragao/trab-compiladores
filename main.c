#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lexic.h"
#include "AST.h"
#include "parser.h"


char *reservedWordsOflanguage[] = {"int", "float", "bool", "char", "double",
                                   "long", "if", "else", "while", "switch", "case", "break", "print",
                                   "readln", "return", "throw", "try", "catch", "true",
                                   "false", "typedef", "struct"};


int main(int argc, char **argv)
{

   double time_spent = 0.0;

   clock_t begin = clock();

   char *fileName;
   int readFromFile;
   if (argc > 1)
   {
      fileName = argv[1];
      size_t const size = strlen(fileName);
      if (fileName[size - 1] != 'm' && fileName[size - 2] != 'm' && fileName[size - 3] != 'c')
      {
         char *con = (char *)malloc(size + 4);
         strcpy(con, fileName);
         strcat(con, ".cmm");
         fileName = con;
      }
      readFromFile = 1;
   }
   else
   {
      char *text = (char *)calloc(1, 1), buffer[BUFFERSIZE];
      printf("You need to press enter twice to exit \n");
      printf("Enter with your text: \n");
      while (*(fgets(buffer, BUFFERSIZE, stdin)) != '\n') /* break with ^\n */
      {
         text = (char *)realloc(text, strlen(text) + 1 + strlen(buffer));
         strcat(text, buffer); /* note a '\n' is appended here everytime */
      }
      printf("\nyour input:\n%s", text);
      fileName = text;
      readFromFile = 0;
   }
   lexical *lex = lexical_construct(reservedWordsOflanguage, fileName, readFromFile);

   Program * a = parser(lex);
   //  int x, y;
   // FunctionOrVarDecl *c = (new IntType(), NULL, new Identifier("xx"), new ProgramL(NULL, NULL),NULL));
   // Program * b = new Program(c);
   // Visitor *v;
   // v->visit(a);

   // int token = 0;
   // while (token != EOF)
   // {
   //    token = nextToken(lex);
   //    if (token != -100)
   //    {
   //       const char *tName = getTokenName(token);
   //       if (token == 31 || token == 32 || token == 33 || token == 34)
   //       {
   //          char *s = searchAndGetString(lex, token, getLexeme(lex));
   //          printf("%s.%s \n", tName, s);
   //       }

   //       else
   //       {
   //          printf("%s \n", tName);
   //       }
   //    }
   // }
   // printf("\n");
   clock_t end = clock();
   time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

   // printAllTables(lex);
   // lexical_destruct(lex);
   printf("The elapsed time is %f seconds \n", time_spent);

   return 0;
}
