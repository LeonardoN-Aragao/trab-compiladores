#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.h"

char *reservedWordsOflanguage[] = {"if", "else", "try", NULL};

int main()
{
   // char *text = "a+b= 2if(x == 2E-a)";

   // // Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'
   FILE *pf;
   int bufferSize = 512;
   char initialBuffer[bufferSize];

   // Opening file in reading mode
   pf = fopen("test.txt", "r");

   if (NULL == pf)
   {
      printf("file can't be opened \n");
   }
   // ode would stop reading as soon as fread extracts anything other than 1 element.
   // Le em initialBuffer o valor da variável armazenada anteriormente pf

   while (fread(&initialBuffer, sizeof *initialBuffer, bufferSize, pf) > 1)
   {
      lexical *x = lexical_construct(reservedWordsOflanguage);
      char *token;
      int tam = 0;

      while (initialBuffer[tam] != '\0')
      {
         printf("char %c \n", initialBuffer[tam]);
         char teste = initialBuffer[tam];
         token = nextToken(x, teste);
         tam++;

         if (token)
         {
            printf("O TOKEN: %s \n", token);
            // printf("lexema %s \n", lexeme);
         }
         else
            continue;
      }

      // Imprime o conteúdo, se existir, do arquivo informado
      printf("\nO CONTEÚDO DO ARQUIVO É:\n %s \n", initialBuffer);
   }

   fclose(pf);

   return 0;
}
