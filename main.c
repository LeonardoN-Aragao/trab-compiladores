#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexic.c"


int main()
{
   char *text = "a+b= 2if(x == 2){return false}";
   lexicalAnalyzer(text);
   return 0;
}
