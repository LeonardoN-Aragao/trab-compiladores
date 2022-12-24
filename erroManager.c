#include "errorManager.h"

errorManager createError(int code, const char *message)
{
    errorManager error;
    error.code = code;
    error.message = message;
    return error;
}

void printError(errorManager error)
{
    int i = 0;
    fprintf(stderr, RED "[ERROR %d]: " NC "%s\n", error.code, error.message);
}