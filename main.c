#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.h"

char *reservedWordsOflanguage[] = {"if", "else", "try", NULL};

int main()
{
   // // Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'
   // FILE *pf;
   // int bufferSize = 512;
   // char initialBuffer[bufferSize];

   // // Opening file in reading mode
   // pf = fopen("test.txt", "r");

   // if (NULL == pf)
   // {
   //    printf("file can't be opened \n");
   // }
   // // ode would stop reading as soon as fread extracts anything other than 1 element.
   // // Le em initialBuffer o valor da variável armazenada anteriormente pf

   // while (fread(&initialBuffer, sizeof *initialBuffer, bufferSize, pf) > 1)
   // {
   //    lexical *lex = lexical_construct(reservedWordsOflanguage);
   //    char *token;
   //    int tam = 0;

   //    while (initialBuffer[tam] != '\0')
   //    {
   //       // printf("char %s \n", &initialBuffer[tam]);
   //       char t = initialBuffer[tam];
   //       printf("INITIAL BUYC %c \n", t);
   //       char *entry = &t;
   //       printf("entry %s", entry);
   //       token = nextToken(lex, entry);
   //       tam++;

   //       if (token != NULL)
   //       {
   //          printf("O TOKEN: %s \n", token);
   //          // printf("lexema %s \n", lexeme);
   //       }
   //       else
   //          continue;
   //    }

   //    // Imprime o conteúdo, se existir, do arquivo informado
   //    printf("\nO CONTEÚDO DO ARQUIVO É:\n %s \n", initialBuffer);
   // }

   // fclose(pf);

   lexical *lex = lexical_construct(reservedWordsOflanguage);
   readFile(lex);
   return 0;
}
