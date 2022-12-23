#include "lexic.h"
#include "AST.h"


Program * parser(lexical * l);
Program* Parser_Program();
Stmt * Parser_Stmt();
Stmtl * Parser_Stmtl();
Expr * Parser_Expr9();
ExprList * Parser_ExprList();
ExprListTail * Parser_ExprListTail();
FormalRest * Parser_FormalRest();
FormaList * Parser_FormaList();
Array * Parser_Array();
IdList * Parser_IdList();
IdListAux * Parser_IdListAux();
CaseBlock * Parser_CaseBlock();
Expr * Parser_Expr();
Expr * Expr9();
ProgramL * Parser_ProgramL();
