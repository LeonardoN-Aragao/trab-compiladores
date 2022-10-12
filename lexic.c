#include "lexic.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearLexeme(char* lexeme) {
   for(int i = 0; lexeme[i]; i++) {
      lexeme[i] = '\0';
   }
}

void lexicalAnalyzer(char *text){
   char *lexeme = (char*)malloc(512*sizeof(char));
   char c;
   int state = 0;
   int i = 0;
   int done = 0;
   while(text[i] != EOF) {
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
            // i++;
         }
      case 4:
         if(c == '&') {
            strncat(lexeme, &c, 1);
            state = 27;
            i++;
         } else {
            state = 34;
            // i++;
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
         printf("lbrackets: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 7:
         printf("asterisk: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 9:
         printf("lparent: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 10:
         printf("comma: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
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
         printf("colon: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 13:
         printf("rparent: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 14:
         printf("rbraces: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 15:
         printf("percent: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 16:
         printf("lbraces: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
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
         // escape charater - state 50
         // else - erro
      case 19:
         printf("plus: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 20:
         printf("rbrackets: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 21:
         printf("backslash: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
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
         printf("arrow: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 25:
         printf("equal: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 26:
         printf("or: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 27:
         printf("and: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 28:
         printf("greaterOrEqual: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 29:
         printf("notEqual: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 30:
         printf("lessOrEqual: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 31:
         printf("semicolon: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 32:
         printf("exclamation: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 33:
         printf("assing: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 34:
         printf("ampersand: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 35:
         printf("great: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 36:
         printf("minus: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 37:
         printf("verticalPipe: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 38:
         printf("less: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 39:
         printf("check SymbTable: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
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
         printf("numInt: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
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
         break;
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
         printf("Error Unexpected end of file");
         clearLexeme(lexeme);
         state = 0;
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
         printf("Error Invalid escape character");
         clearLexeme(lexeme);
         state = 0;
         break;
      case 49:
         printf("Literal: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
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
         printf("numFloat: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      case 53:
         printf("Erro Invalid Number");
         clearLexeme(lexeme);
         state = 0;
         break;
      case 54:
         printf("Erro Invalid Number");
         clearLexeme(lexeme);
         state = 0;
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
         } else {
            printf("Erro");
            clearLexeme(lexeme);
            state = 0;
         }
         break;
      case 57:
         if(c == 'a' || c == 'b' || c == 'f' || c == 'n' || c == 'v' || c == 't' || c == '\\' || c == '\'' || c == '\"' || c == '\0' || c == '\?') {
            strncat(lexeme, &c, 1);
            state = 49;
            i++;
         } else {
            printf("Erro Invalid escape character");
            clearLexeme(lexeme);
            state = 0;
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
         printf("Erro Invalid escape character");
         clearLexeme(lexeme);
         state = 0;
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
         printf("Erro Unexpected end of file in comment statement");
         clearLexeme(lexeme);
         state = 0;
         break;
      case 62:
         printf("Comment: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
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
         printf("slash: %s\n", lexeme);
         clearLexeme(lexeme);
         state = 0;
         break;
      default:
         break;
      }
   }
}
