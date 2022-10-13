#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.c"


int main()
{
   char *text = "a+b= 2if(x == 2E-a)";

   lexicData value;
   value.pos = 0;
   value.erro = 0;
   value.lexeme = (char*)malloc(512*sizeof(char));
   value.token = (char*)malloc(512*sizeof(char));

   while(text[value.pos] != '\0') {
      value = lexicalAnalyzer(text, value);
      if(value.erro == 1) break;
      printf("token: %s || lexeme: %s\n", value.token, value.lexeme);
   }
   // free(text);
   return 0;
}
