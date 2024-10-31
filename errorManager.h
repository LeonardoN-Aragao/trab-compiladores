#ifndef ERRORMANAGER_H
#define ERRORMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\e[0;31m"
#define NC "\e[0m"

typedef struct errorManager
{
   const char *message;
   int code;
} errorManager;
errorManager createError(int code, const char *message);
void printError(errorManager error);

#endif /* ERRORMANAGER_H */
