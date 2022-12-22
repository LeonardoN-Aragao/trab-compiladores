#ifndef AST_H
#define AST_H

typedef struct visitor {
    int info;
} visitor;

class Expr {
   // abstract
   virtual void accept (visitor * v) = 0;
   int tipo;
};

class Stmt {
   // abstract
   virtual void accept (visitor * v) = 0;
};

class PROGRAM {
   
};

class PROGRAML {

};

class TYPEDECL {

};

class TYPE {

};

class POINTER {

};

class FORMALIST {

};

class FORMALREST {

};

class ARRAY {

};

class IDLIST {

};

class IDLISTAUX {

};

class STMTL : Stmt {

};

class STMT : Stmt {

};

class ELSE : Stmt {

};

class FATID : Stmt {

};

class FATID1 : Stmt {

};

class CASEBLOCK : Stmt {

};

class EXPRLIST : Expr {

};

class EXPRLISTTAIL : Expr {

};

class EXPRLISTTAILAUX : Expr {

};

class F {

};

class EPSOLON;



// typedef struct AST{
//     enum type{
        // AST_PROGRAM,
        // AST_PROGRAML,
        // AST_TYPEDECL,
        // AST_TYPE,
        // AST_POINTER,
        // AST_FORMALIST,
        // AST_FORMALREST,
        // AST_ARRAY,
        // AST_IDLIST,
        // AST_IDLISTAUX,
        // AST_STMTL,
        // AST_STMT,
        // AST_ELSE,
        // AST_FATID,
        // AST_FATID1,
        // AST_CASEBLOCK,
        // AST_EXPRLIST,
        // AST_EXPRLISTTAIL,
        // AST_EXPRLISTTAILAUX,
        // AST_EXPR,
        // AST_F,
        // AST_EPSOLON
//     } type;

//     // AST_TYPE & AST_TOKEN & AST_POINTER & AST_F
//     char * token_value; // oi
//     int token_name; // ID 
//     int * token_nome; ( FormaList ) { STMT }
//     struct  AST * Formalist;
//     struct  AST * STMT;

//     // AST_EXPR
//     struct AST * AST_Token;
//     struct AST * AST_Expr;
//     struct AST * AST_ExprAux;

//     // AST_Array
//     struct AST * type;
//     struct Ast * Array;

//     // AST_Else
//     struct AST * stmt;

//     // AST_STMTLIST
//     struct AST * stmt;
//     struct AST * stmtList;

//     // AST_STMT
// 	struct AST * tokenAux;
//     struct AST * expr;
//     struct AST * elseStatement;

//     struct AST * stmt;
//     struct AST * stmtAux;

//     struct AST * type;
//     struct AST * fatId;

//     struct AST * stmtBlock; // catch stmt Block
//     struct ASTList * exprList; // print(ExprList);

//     unsigned int hasBracket_block; 
//     unsigned int hasParentheses_block;
//     unsigned int hasBraces_block; 
//     unsigned int hasSemicolon;    

//     // AST_FORMALIST
//     struct AST* Token 
//     struct ASt* identificador 
//     struct ASt* Array 
//     struct AST* FormalRest

//     // AST_PROGRAML
//     struct AST* Token 
//     struct AST* identificador 
//     struct AST* Array FormalRest

//     // AST_PROGRAM 
// 	struct AST * TypeDecl;
// 	struct AST * Program;
// 	struct AST * Pointer;
// 	struct AST * id;
// 	struct AST * ProgramL;
// } AST;

AST * init_ast(int type);

#endif // AST_H
