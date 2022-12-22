#include "lexic.h"
//#include "AST.h"

typedef struct AST {
    int info;
    AST * FunctionDecl;
}AST;

AST * parser(lexical * l);
AST * Stmt();
AST * StmtList();
AST * Expr9();
AST * ExprList();
AST * ExprListTail();
AST * FormalRest();
AST * FormaList();
AST * Array();
AST * IdList();
AST * IdListAux();
AST * CaseBlock();