#ifndef ERRORMANAGER_H
#define ERRORMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\e[0;31m"
#define NC "\e[0m"

typedef struct errorManager {
   const char* message;
   int code;
} errorManager;

errorManager createError(int code, const char* message) {
   errorManager error;
   error.code = code;
   error.message = message;
   return error;
}

void printError(errorManager error) {
   int i = 0;
   fprintf(stderr, RED "[ERROR %d]: " NC "%s\n", error.code, error.message);
}


#endif /* ERRORMANAGER_H */
