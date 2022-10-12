#include <stdio.h>
#include <string.h>

void lexicalAnalyzer(char *text){
   char *lexeme;
   char c;
   int state = 0;
   int done = 0;
   int i = 0;
   while(text[i] != '\0') {
      c = text[i];
      switch (state)
      {
      case 0:
         /* code */
         strncat(lexeme, &c, 1);
         if(c == '-') {
            state = 1;

i++;         } else if(c == '=') {
            state = 2;

i++;         } else if(c == '|') {
            state = 3;

i++;         } else if(c == '&') {
            state = 4;

i++;         } else if(c == '>') {
            state = 5;

i++;         } else if(c == '[') {
            state = 6;

i++;         } else if(c == '*') {
            state = 7;

i++;         } else if(c == '(') {
            state = 9;

i++;         } else if(c == ',') {
            state = 10;
            i++;
         } else if(c == '!') {
            state = 11;
            i++;
         } else if(c == ':') {
            state = 12;
            i++;
         } else if(c == ')') {
            state = 13;
            i++;
         } else if(c == '}') {
            state = 14;
            i++;
         } else if(c == '%') {
            state = 15;
            i++;
         } else if(c == '{') {
            state = 16;
            i++;
         } else if(c == '.') {
            state = 17;
            i++;
         } else if(c == '+') {
            state = 19;
            i++;
         } else if(c == ']') {
            state = 20;
            i++;
         } else if(c == '\\') {
            state = 21;
            i++;
         } else if(c == '>') {
            state = 22;
            i++;
         } else if((c >= 'a' && c <='z') || (c >= 'A' && c <='Z')) {
            state =23;

i++;         } else if(c == ';') {
            state = 31;
            i++;
         } else if(c >= '0' && c <= '9') {
            state = 40;
            i++;
         } else if(c == '\"') {
            state = 50;
            i++;
         } else if(c == '/') {
            state = 51;
            i++;
         } else if(c == '\'') {
            state = 55;
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
            // i++;
         }
         break;
      case 2:
         if(c == '=') {
            strncat(lexeme, &c, 1);
            state = 25;
            i++;
         } else {
            state = 33;
            // i++;
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
         printf("lbrackets: %s", lexeme);
         break;
      case 7:
         printf("asterisk: %s", lexeme);
         break;
      case 9:
         printf("lparent: %s", lexeme);
         break;
      case 10:
         printf("comma: %s", lexeme);
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
         printf("colon: %s", lexeme);
         break;
      case 13:
         printf("rparent: %s", lexeme);
         break;
      case 14:
         printf("rbraces: %s", lexeme);
         break;
      case 15:
         printf("percent: %s", lexeme);
         break;
      case 16:
         printf("lbraces: %s", lexeme);
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
         printf("plus: %s", lexeme);
         break;
      case 20:
         printf("rbrackets: %s", lexeme);
         break;
      case 21:
         printf("backslash: %s", lexeme);
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
            state = 39;
            i++;
         }
         break;
      case 24:
         printf("arrow: %s", lexeme);
         break;
      case 25:
         printf("equal: %s", lexeme);
         break;
      case 26:
         printf("or: %s", lexeme);
         break;
      case 27:
         printf("and: %s", lexeme);
         break;
      case 28:
         printf("greaterOrEqual: %s", lexeme);
         break;
      case 29:
         printf("notEqual: %s", lexeme);
         break;
      case 30:
         printf("lessOrEqual: %s", lexeme);
         break;
      case 31:
         printf("semicolon: %s", lexeme);
         break;
      case 32:
         printf("exclamation: %s", lexeme);
         break;
      case 33:
         printf("assing: %s", lexeme);
         break;
      case 34:
         printf("ampersand: %s", lexeme);
         break;
      case 35:
         printf("great: %s", lexeme);
         break;
      case 36:
         printf("minus: %s", lexeme);
         break;
      case 37:
         printf("verticalPipe: %s", lexeme);
         break;
      case 38:
         printf("less: %s", lexeme);
         break;
      case 39:
         printf("check SymbTable: %s", lexeme);
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
         pintf("numInt: %s", lexeme);
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
      default:
         break;
      }
   }
}