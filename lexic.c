#include "lexic.h"

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

void clearLexeme(char* lexeme) {
   for(int i = 0; lexeme[i]; i++) {
      lexeme[i] = '\0';
   }
}
// void lexicalAnalyzer(char *text){
lexicData lexicalAnalyzer(char *text, lexicData val) {
   char *lexeme = (char*)malloc(512*sizeof(char));
   char c;
   char *token;
   int state = 0;
   int i = val.pos;
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
         // printf("lbrackets: %s\n", lexeme);
         token = "lbrackets";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 7:
         // printf("asterisk: %s\n", lexeme);
         token = "asterisk";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 9:
         // printf("lparent: %s\n", lexeme);
         token = "lparent";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 10:
         // printf("comma: %s\n", lexeme);
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
         // printf("colon: %s\n", lexeme);
         token = "colon";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 13:
         // printf("rparent: %s\n", lexeme);
         token = "rparent";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 14:
         // printf("rbraces: %s\n", lexeme);
         token = "rbraces";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 15:
         // printf("percent: %s\n", lexeme);
         token = "percent";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 16:
         // printf("lbraces: %s\n", lexeme);
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
         // printf("plus: %s\n", lexeme);
         token = "plus";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 20:
         // printf("rbrackets: %s\n", lexeme);
         token = "rbrackets";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 21:
         // printf("backslash: %s\n", lexeme);
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
         // printf("arrow: %s\n", lexeme);
         token = "arrow";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 25:
         // printf("equal: %s\n", lexeme);
         token = "equal";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 26:
         // printf("or: %s\n", lexeme);
         token = "or";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 27:
         // printf("and: %s\n", lexeme);
         token = "and";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 28:
         // printf("greaterOrEqual: %s\n", lexeme);
         token = "greaterOrEqual";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 29:
         // printf("notEqual: %s\n", lexeme);
         token = "notEqual";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 30:
         // printf("lessOrEqual: %s\n", lexeme);
         token = "lessOrEqual";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 31:
         // printf("semicolon: %s\n", lexeme);
         token = "semicolon";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 32:
         // printf("exclamation: %s\n", lexeme);
         token = "exclamation";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 33:
         // printf("assing: %s\n", lexeme);
         token = "assing";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 34:
         // printf("ampersand: %s\n", lexeme);
         token = "ampersand";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 35:
         // printf("great: %s\n", lexeme);
         token = "great";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 36:
         // printf("minus: %s\n", lexeme);
         token = "minus";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 37:
         // printf("verticalPipe: %s\n", lexeme);
         token = "verticalPipe";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 38:
         // printf("less: %s\n", lexeme);
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
         // printf("numInt: %s\n", lexeme);
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
         break;
      case 49:
         // printf("Literal: %s\n", lexeme);
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
         // printf("numFloat: %s\n", lexeme);
         token = "numFloat";
         insertLexicData(token, lexeme, &val, i);
         return val;
         break;
      case 53:
         printf("Erro Invalid Number");
         break;
      case 54:
         printf("Erro Invalid Number");
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
            printf("Erro Invalid escape character");
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
         // fprintf(stderr, RED "[ERROR]"
         //       NC  ": No string argument provided! \n"
         //           "You must provide a program path as argument\n");
         // return val;
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
         printf("Erro Unexpected end of file in comment statement");
         break;
      case 62:
         // printf("Comment: %s\n", lexeme);
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
         // printf("slash: %s\n", lexeme);
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
