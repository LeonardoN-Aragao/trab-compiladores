#ifndef AST_H
#define AST_H

#include <stdlib.h>

typedef struct AST_Token {
    int token_value; 
}AST_Token;

typedef struct AST_Expr{
    struct AST_Token* token;
    struct AST_Expr* expr;
    struct AST_Expr* exprAux;
}AST_Expr;

typedef struct AST_StmtList {
  struct AST_Stmt * stmt;
  struct AST_StmtList * stmtList;
}AST_StmtList;

typedef struct AST_Stmt{
    struct AST_Token * token;
	struct AST_Token * tokenAux;
    struct AST_Expr * expr;
    struct AST_Else * elseStatement;

    struct AST_Stmt * stmt;
    struct AST_Stmt * stmtAux;

    struct AST_Type * type;
    struct AST_FatId * fatId;

    struct AST_Stmt * stmtBlock; // catch stmt Block
    struct AST_ExprList * exprList; // print(ExprList);

    unsigned int hasParentheses_block;
    unsigned int hasBraces_block; 
    unsigned int hasSemicolon;
}AST_Stmt;

typedef struct AST_Else {
    struct AST_Token * token;
    struct AST_Stmt * stmt;
}AST_Else;

typedef struct {
    
};

typedef struct AST_Program { 
	struct AST_Type * Type;
	struct AST_TypeDecl * TypeDecl;
	struct AST_Program * Program;
	struct AST_Pointer * Pointer;
	struct AST * id;
	struct AST_ProgramL * ProgramL;
}AST_Program;


typedef struct AST
{
    struct AST_Program * program;
}AST;

AST * init_ast(int type);

#endif // AST_H