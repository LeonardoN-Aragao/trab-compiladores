#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.c"

int main(int argc, char **argv)
{
   char *text = "a+b= 2if(x == 2E-a)";

   // Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'
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

      // Imprime o conteúdo, se existir, do arquivo informado
      printf("\nO CONTEÚDO DO ARQUIVO É:\n %s \n", initialBuffer);
   }

   fclose(pf);

   lexicData value;
   value.pos = 0;
   value.erro = 0;
   value.lexeme = (char *)malloc(bufferSize * sizeof(char));
   value.token = (char *)malloc(bufferSize * sizeof(char));

   while (text[value.pos] != '\0')
   {
      value = lexicalAnalyzer(text, value);
      if (value.erro == 1)
         break;
      printf("token: %s || lexeme: %s\n", value.token, value.lexeme);
   }
   // free(text);
   return 0;
}
