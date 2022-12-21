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
    enum type {
        TYPE_DECLARATION,
        VARIABLE_DECLARATION,
        EXPR,
        STMT,
        FUNCTION_DECLARATION,
        FUNCTION_CALL,
    } type;

    struct SCOPE* scope;

    /* AST_VARIABLE_DEFINITION */
    char* variable_definition_variable_name;
    struct AST* variable_definition_value;

    /* AST_FUNCTION_DEFINITION */
    struct AST* function_definition_body;
    char* function_definition_name;
    struct AST** function_definition_args;
    size_t function_definition_args_size;

    /* AST_VARIABLE */
    char* variable_name;

    /* AST_FUNCTION_CALL */
    char* function_call_name;
    struct AST** function_call_arguments;
    size_t function_call_arguments_size;

    /* AST_STRING */
    char* string_value;

    /* AST_COMPOUND */
    struct AST** compound_value;
    size_t compound_size;
}AST;

AST * init_ast(int type);

#endif // AST_H