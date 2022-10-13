#include "lexic.h"
#include "errorManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\e[0;31m"
#define NC "\e[0m"

void insertLexicData(char* token, char* lexeme, lexicData* val, int i) {
   val->pos = i;
   val->lexeme = lexeme;
   val->token = token;
}

void insertLexicDataWithErro(char* token, char* lexeme, lexicData* val, int i, int error) {
   val->pos = i;
   val->lexeme = lexeme;
   val->token = token;
   val->erro = error;
}


void clearLexeme(char* lexeme) {
   for(int i = 0; lexeme[i]; i++) {
      lexeme[i] = '\0';
   }
}

lexicData lexicalAnalyzer(char *text, lexicData val) {
   char *lexeme = (char*)malloc(512*sizeof(char));
   char c;
   char *token;
   int state = 0;
   errorManager error;
   int i = val.pos;

   int done = 0;
   while(done == 0) {
      c = text[i];
      switch (state) {
      case 0:
         /* code */

         if(c == '-') {
            state = 1;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '=') {
            state = 2;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '|') {
            state = 3;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '&') {
            state = 4;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '>') {
            state = 5;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '[') {
            state = 6;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '*') {
            state = 7;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '(') {
            state = 9;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == ',') {
            state = 10;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '!') {
            state = 11;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == ':') {
            state = 12;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == ')') {
            state = 13;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '}') {
            state = 14;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '%') {
            state = 15;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '{') {
            state = 16;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '.') {
            state = 17;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '+') {
            state = 19;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == ']') {
            state = 20;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '\\') {
            state = 21;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '>') {
            state = 22;
            strncat(lexeme, &c, 1);
            i++;
         } else if((c >= 'a' && c <='z') || (c >= 'A' && c <='Z')) {
            state =23;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == ';') {
            state = 31;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c >= '0' && c <= '9') {
            state = 40;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '\"') {
            state = 50;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '/') {
            state = 51;
            strncat(lexeme, &c, 1);
            i++;
         } else if(c == '\'') {
            state = 55;
            strncat(lexeme, &c, 1);
            i++;
         } else {
            i++;
         }
         break;
      case 1:
         if(c == '>') {
            strncat(lexeme, &c, 1);
            state = 24;
            i++;
         } else {
            state = 36;
         }
         break;
      case 2:
         if(c == '=') {
            strncat(lexeme, &c, 1);
            state = 25;
            i++;
         } else {
            state = 33;
         }
         break;
      case 3:
         if(c == '|') {
            strncat(lexeme, &c, 1);
            state = 26;
            i++;
         } else {
            state = 37;
         }
      case 4:
         if(c == '&') {
            strncat(lexeme, &c, 1);
            state = 27;
            i++;
         } else {
            state = 34;
         }
         break;
      case 5:
         if(c == '=') {
            strncat(lexeme, &c, 1);
            state = 28;
            i++;
         } else {
            state = 35;
         }
         break;
      case 6:
         token = "lbrackets";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 7:
         token = "asterisk";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 9:
         token = "lparent";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 10:
         token = "comma";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 11:
         if(c == '=') {
            strncat(lexeme, &c, 1);
            state = 29;
            i++;
         } else {
            state = 32;
         }
         break;
      case 12:
         token = "colon";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 13:
         token = "rparent";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 14:
         token = "rbraces";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 15:
         token = "percent";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 16:
         token = "lbraces";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 17:
         if(c >= '0' && c <= '9') {
            strncat(lexeme, &c, 1);
            state = 43;
            i++;
         } else {
            state = 53;
         }
         break;
      case 18:
         if(c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?') {
            strncat(lexeme, &c, 1);
            state = 50;
            i++;
         } else {
            state = 48;
         }
      case 19:
         token = "plus";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 20:
         token = "rbrackets";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 21:
         token = "backslash";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 22:
         if(c == '=') {
            strncat(lexeme, &c, 1);
            state = 30;
            i++;
         } else {
            state = 38;
         }
         break;
      case 23:
         if((c >= 'a' && c <='z') || (c >= 'A' && c <='Z')) {
            strncat(lexeme, &c, 1);
            state = 23;
            i++;
         } else {
            state = 39;
         }
         break;
      case 24:
         token = "arrow";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 25:
         token = "equal";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 26:
         token = "or";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 27:
         token = "and";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 28:
         token = "greaterOrEqual";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 29:
         token = "notEqual";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 30:
         token = "lessOrEqual";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 31:
         token = "semicolon";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 32:
         token = "exclamation";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 33:
         token = "assing";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 34:
         token = "ampersand";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 35:
         token = "great";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 36:
         token = "minus";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 37:
         token = "verticalPipe";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 38:
         token = "less";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 39:
         token = "check SymbTable:";;
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 40:
         if(c >= '0' && c <= '9') {
            strncat(lexeme, &c, 1);
            state = 40;
            i++;
         } else if(c == 'e' || c == 'E') {
            strncat(lexeme, &c, 1);
            state = 44;
            i++;
         } else if(c == '.') {
            strncat(lexeme, &c, 1);
            state = 43;
            i++;
         } else {
            state = 41;
         }
         break;
      case 41:
         token = "numInt";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 43:
         if(c >= '0' && c <= '9') {
            strncat(lexeme, &c, 1);
            state = 43;
            i++;
         } else if(c == 'e' || c == 'E') {
            strncat(lexeme, &c, 1);
            state = 44;
            i++;
         } else {
            state = 52;
         }
         break;
      case 44:
         if(c >= '0' && c <= '9') {
            strncat(lexeme, &c, 1);
            state = 47;
            i++;
         } else if(c == '+' || c == '-') {
            strncat(lexeme, &c, 1);
            state = 45;
            i++;
         }
      case 45:
         if(c >= '0' && c <= '9') {
            strncat(lexeme, &c, 1);
            state = 47;
            i++;
         } else {
            state = 54;
         }
         break;
      case 46:
         error = createError(1, "Unexpected end of file");
         printError(error);
         insertLexicDataWithErro(token, lexeme, &val, i, 1);
         return val;
         break;
      case 47:
         if(c >= '0' && c <= '9') {
            strncat(lexeme, &c, 1);
            state = 47;
            i++;
         } else {
            state = 52;
         }
      case 48:
         error = createError(2, "Invalid escape character");
         printError(error);
         insertLexicDataWithErro(token, lexeme, &val, i, 1);
         return val;
         break;
      case 49:
         token = "LITERAL";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 50:
         if(c == '\"') {
            strncat(lexeme, &c, 1);
            state = 49;
            i++;
         } else if(c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?') {
            strncat(lexeme, &c, 1);
            state = 18;
            i++;
         } else if(c == EOF) {
            state = 58;
         } else {
            strncat(lexeme, &c, 1);
            state = 50;
            i++;
         }
         break;
      case 51:
         if(c == '*') {
            strncat(lexeme, &c, 1);
            state = 60;
            i++;
         } else if(c == '/') {
            strncat(lexeme, &c, 1);
            state = 63;
            i++;
         } else {
            strncat(lexeme, &c, 1);
            state = 50;
         }
         break;
      case 52:
         token = "numFloat";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 53:
         error = createError(3, "Invalid Number");
         printError(error);
         insertLexicDataWithErro(token, lexeme, &val, i, 1);
         return val;
         break;
      case 54:
         error = createError(4, "Invalid Number");
         printError(error);
         insertLexicDataWithErro(token, lexeme, &val, i, 1);
         return val;
         break;
      case 55:
         if(c == '/') {
            strncat(lexeme, &c, 1);
            state = 49;
            i++;
         } else {
            strncat(lexeme, &c, 1);
            state = 59;
         }
         break;
      case 56:
         if(c == '\'') {
            strncat(lexeme, &c, 1);
            state = 49;
            i++;
         }
         break;
      case 57:
         if(c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?') {
            strncat(lexeme, &c, 1);
            state = 49;
            i++;
         } else {

            error = createError(5, "Invalid escape character");
         printError(error);
         insertLexicDataWithErro(token, lexeme, &val, i, 1);
         return val;
         }
      case 58:
         if(c == '/') {
            strncat(lexeme, &c, 1);
            state = 49;
            i++;
         } else if (c == EOF) {
            state = 61;
         }
      case 59:
         error = createError(6, "Invalid escape character");
         printError(error);
         insertLexicDataWithErro(token, lexeme, &val, i, 1);
         return val;
         continue;
         break;
      case 60:
         if(c == '*') {
            strncat(lexeme, &c, 1);
            state = 58;
            i++;
         } else if (c == EOF) {
            state = 61;
         } else {
            strncat(lexeme, &c, 1);
            state = 60;
            i++;
         }
      case 61:
         error = createError(7, "Unexpected end of file in comment statement");
         printError(error);
         insertLexicDataWithErro(token, lexeme, &val, i, 1);
         return val;
         break;
      case 62:
         token = "Comment";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 63:
         if(c == '/') {
            strncat(lexeme, &c, 1);
            state = 64;
            i++;
         } else {
            strncat(lexeme, &c, 1);
            state = 63;
            i++;
         }
      case 64:
         if(c == '/') {
            strncat(lexeme, &c, 1);
            state = 62;
            i++;
         }
      case 65:
         token = "slash";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      default:
         break;
      }
   }
   return val;
}
