#include <stdio.h>
#include "parser.h"
#include "lexic.h"
//#include "errorManager.h"

// ------------ REMOVER ??? ---------------

lexical * lex;
int token = 0;

// ----------------------------------------

// Errors ------------------------------------------------
void error() {
  printf("Error!!!\n");
}

int inFollow(int token, int *follow) {
    for(int i=0; i<sizeof(follow); i++) {
        if(follow[i] == token)
            return 0;
    }
    return 1;
}

int inFirst(int token, int *first) {
    for(int i=0; i<sizeof(first); i++) {
        if(first[i] == token)
            return 0;
    }
    return 1;
}
// Isso para o eat
void erro_eat(int token, int t, int *follow) {
    if(inFollow(token, follow)) {
        // Add t at ASA
        // Do not consume token and continue
        printf("If");
    } else {
        printf("Unexpected Token!!!");
    }
}

void erro(int token) {
    // STMT -> make the token an id/num and continue
    // FatId -> verify token == +,-,... and continue
    // Type -> add to SymbTable and continue
}
// -------------------------------------------------------

void advance() { token = nextToken(lex); }
void eat(int t) {if (token == t) advance(); else error();}

int isType() {
    if(token == int_ || token == float_ || token == bool_ || token == char_ || 
        token == double_ || token == long_ || token == identifier)
        return 1;

    return 0;
}

int isStmt(){
    if(token == if_ || token == while_ || token == switch_ || token == lbraces ||
        token == print_ || token == readln_ || token == return_ || token == throw_ ||
        token == try_ || token == identifier || token == break_)
        return 1;
    return 0;
}

//Num -> numInt
//Num -> numFloat
AST * Num(){
    switch (token){
        case numInt:
            eat(numInt);
            break;
        case numFloat:
            eat(numFloat);
            break;
        
        default:
            error();
            break;
    }
}

// Type -> long
// Type -> int
// Type -> float
// Type -> bool
// Type -> ID
// Type -> char
// Type -> double
AST * Type(){
    if(token == int_ || token == float_ || token == bool_ || token == char_ || token == double_ || token == long_)
        advance();
    else if(1) //verificar tabela de simbolos
        return;
    else
        error();
}

AST * F(){

}

// Expr9Aux -> plusUnary Expr9
// Expr9Aux -> minusUnary Expr9
// Expr9Aux -> notUnary Expr9
// Expr9Aux -> ''
AST * Expr9Aux() {
    switch(token){
        case plusSign:
            eat(plusSign);
            Expr9();
            break;

        case minusSign:
            eat(minusSign);
            Expr9();
            break;

        case exclamation:
            eat(exclamation);
            Expr9();
            break;

        default:    
            return;
    }
}

// Expr9 -> F Expr9Aux
AST * Expr9() {
    F(); Expr9Aux();
}

// Expr8Aux -> * Expr9 Expr8Aux
// Expr8Aux -> / Expr9 Expr8Aux
// Expr8Aux -> % Expr9 Expr8Aux
// Expr8Aux -> ''
AST * Expr8Aux() {
     switch(token){
        case asterisk:
            eat(asterisk);
            Expr9();
            Expr8Aux();
            break;

        case slash:
            eat(slash);
            Expr9();
            Expr8Aux();
            break;

        case percent:
            eat(percent);
            Expr9();
            Expr8Aux();
            break;

        default:    
            return;
    }
}

// Expr8 -> Expr9 Expr8Aux
AST * Expr8() {
    Expr9(); Expr8Aux();
}

// Expr7Aux -> + Expr8 Expr7Aux
// Expr7Aux -> - Expr8 Expr7Aux
// Expr7Aux -> ''
AST * Expr7Aux() {
    switch(token){
        case plusSign:
            eat(plusSign);
            Expr8();
            Expr7Aux();
            break;

        case minusSign:
            eat(minusSign);
            Expr8();
            Expr7Aux();
            break;

        default:    
            return;
    }
}

// Expr7 -> Expr8 Expr7Aux
AST * Expr7() {
    Expr8(); Expr7Aux();
}

// Expr6Aux -> < Expr7 Expr6Aux
// Expr6Aux -> > Expr7 Expr6Aux
// Expr6Aux -> <= Expr7 Expr6Aux
// Expr6Aux -> >= Expr7 Expr6Aux
// Expr6Aux -> ''
AST * Expr6Aux() {
    switch(token){
        case lessSign:
            eat(lessSign);
            Expr7();
            Expr6Aux();
            break;

        case great:
            eat(great);
            Expr7();
            Expr6Aux();
            break;
        
        case lessOrEqual:
            eat(lessOrEqual);
            Expr7();
            Expr6Aux();
            break;

        case greaterOrEqual:
            eat(greaterOrEqual);
            Expr7();
            Expr6Aux();
            break;

        default:    
            return;
    }
}

// Expr6 -> Expr7 Expr6Aux
AST * Expr6() {
    Expr7(); Expr6Aux();
}

// Expr5Aux -> == Expr6 Expr5Aux
// Expr5Aux -> != Expr6 Expr5Aux
// Expr5Aux -> ''
AST * Expr5Aux() {
    switch(token){
        case equality:
            eat(equality);
            Expr6();
            Expr5Aux();
            break;

        case notEqual:
            eat(notEqual);
            Expr6();
            Expr5Aux();
            break;

        default:    
            return;
    }
}

// Expr5 -> Expr6 Expr5Aux
AST * Expr5() {
    Expr6(); Expr5Aux();
}

// Expr4Aux -> & Expr5 Expr4Aux
// Expr4Aux -> ''
AST * Expr4Aux() {
    if(token == ampersand){
        Expr5(); 
        Expr4Aux();
    }
    else return;
}

// Expr4 -> Expr5 Expr4Aux
AST * Expr4() {
    Expr5(); Expr4Aux();
}

// Expr3Aux -> | Expr4 Expr3Aux
// Expr3Aux -> ''
AST * Expr3Aux() {
    if(token == verticalPipe){
        Expr4(); 
        Expr3Aux();
    }
    else return;
}

// Expr3 -> Expr4 Expr3Aux
AST * Expr3() {
    Expr4(); Expr3Aux();
}

// Expr2Aux -> && Expr3 Expr2Aux
// Expr2Aux -> ''
AST * Expr2Aux() {
    if(token == andSign){
        Expr3(); 
        Expr2Aux();
    }
    else return;
}

// Expr2 -> Expr3 Expr2Aux
AST * Expr2() {
    Expr3(); Expr2Aux();
}

// ExprAux -> || Expr2 ExprAux
// ExprAux -> ''
AST * ExprAux(){
    if(token == orSign){
        Expr2(); 
        ExprAux();
    }
    else return;
}

//Expr -> Expr2 ExprAux
AST * Expr(){
    Expr2(); ExprAux();
}

// Else-> else Stmt
// Else-> ''
AST * Else(){
    if(token == else_){
        eat(else_);
        Stmt();
        //arv.add(tabela[Else])
    }
    else return;
}

// StmtList -> Stmt StmtList
// StmtList -> ''
AST * StmtList(){
    if(isStmt()){
        Stmt(); 
        StmtList();
    }
    else return;
}

// FatId1 -> dot Expr
// FatId1 -> arrow Expr
// FatId1 -> = Expr
// FatId1 -> [ Expr ]
void FatId1(){
    switch (token){
        case dot:
            eat(dot);
            Expr();
            break;

        case arrow:
            eat(arrow);
            Expr();
            break;

        case assignment:
            eat(assignment);
            Expr();
            break;

        case lbrackets:
            eat(lbrackets);
            Expr();
            eat(rbrackets);
            break;

    default:
        error();
    }
}

// FatId -> ( ExprList  )
// FatId ->  IdList ; STMT
// FatId -> FatId1
// FatId -> ''
void FatId(){
    switch(token){
        case lparent:
            eat(lparent);
            ExprList();
            eat(rparent);
            break;

        case asterisk:
        case identifier:
            IdList();
            eat(semicolon);
            Stmt();
            break;

        case dot:
        case arrow:
        case assignment:
        case lbrackets:
            FatId1();
            break;
         
        default:
            break;
    }
}

// Stmt-> if ( Expr ) Stmt Else
// Stmt -> return Expr ;
// Stmt -> while ( Expr ) { Stmt }
// Stmt -> switch ( Expr ) { CaseBlock }
// Stmt -> break ;
// Stmt -> { StmtList }
// Stmt -> print ( ExprList ) ;
// Stmt -> readln ( Expr ) ;
// Stmt -> throw;
// Stmt -> try Stmt catch ( Stmt ) Stmt
// Stmt -> id FatId ;
AST * Stmt(){
    switch (token){
        case if_:
            eat(if_);
            eat(lparent);
            Expr();
            eat(rparent);
            Stmt();
            Else();
            break;

        case while_:
            eat(while_);
            eat(lparent);
            Expr();
            eat(rparent);
            eat(lbraces);
            Stmt();
            eat(rbraces);
            break;

        case switch_:
            eat(switch_);
            eat(lparent);
            Expr();
            eat(rparent);
            eat(lbraces);
            CaseBlock();
            eat(rbraces);
            break;

        case break_:
            eat(break_);
            eat(semicolon);
            break;

        case lbraces:
            eat(lbrackets);
            StmtList();
            eat(rbrackets);
            break;
        
        case print_:
            eat(print_);
            eat(lparent);
            ExprList();
            eat(rparent);
            eat(semicolon);
            break;
        
        case readln_:
            eat(print_);
            eat(lparent);
            Expr();
            eat(rparent);
            eat(semicolon);
            break;

        case return_:
            eat(return_);
            Expr();
            eat(semicolon);
            break;
        
        case throw_:
            eat(throw_);
            eat(semicolon);
            break;
        
        case try_:
            eat(try_);
            Stmt();
            eat(catch_);
            eat(lparent);
            Stmt();
            eat(rparent);
            Stmt();
            break;
        
        case identifier:
            eat(identifier);
            FatId();
            eat(semicolon);
            break;

    default:
        error();
    }
}


// Pointer -> asterisk
// Pointer -> ''
AST * Pointer() {
    if(token == asterisk) advance();
    else return;
}

// VarDecl -> Type IdList ; VarDecl
// VarDecl -> ''
AST * VarDecl(){
    if(!isType() || token !=identifier)
        return;
        
    Type();
    IdList();
    eat(semicolon);
    VarDecl();
}

// IdList' -> , IdList
// IdList' -> ''
AST * IdListAux(){
    if(token == comma){
        eat(comma);
        IdList();
    }
    else return;
}

// IdList -> Pointer id Array IdList'
AST * IdList() {
    Pointer();
    eat(identifier);
    Array();
    IdListAux();
}

// FormalRest -> , FormaList
// FormalRest -> ''
AST * FormalRest() {
    if(token == comma){
        eat(comma); 
        FormaList();
    }
    else return;
}

// FormaList -> Type Pointer id Array FormalRest
// FormaList -> ''
AST * FormaList() {
    if(isType()){
        Type();
        Pointer();
        eat(identifier);
        Array();
        FormalRest();
    }
    else return;
}    

// Array -> [ NumInt ] Array
// Array -> ''
AST * Array() {
    if(token == lbrackets){
        eat(lbrackets);
        eat(numInt);
        eat(rbrackets);
        Array();
    }
    else return;
}

// CaseBlock -> case numInt : StmtList CaseBlock
// CaseBlock -> ''
AST * CaseBlock() {
    if(token == case_){
        eat(case_);
        eat(numInt);
        eat(colon);
        StmtList();
        CaseBlock();
    }
    else return;
}

// ExprListTail' -> , ExprListTail
// ExprListTail' -> ''
AST * ExprListTailAux() {
    if(token == comma){
        eat(comma);
        ExprListTail();
    }
    else return;
}

// ExprListTail -> Expr ExprListTail'
// ExprListTail :: ''
AST * ExprListTail() {
    Expr();
    ExprListTailAux();
}

// ExprList -> ExprListTail
// ExprList -> ''
AST * ExprList() {
    ExprListTail();
}

// TypeDecl -> typedef struct { Type IdList ; VarDecl } id ; TypeDecl
AST * TypeDecl(){
    eat(typedef_);
    eat(struct_);
    eat(lbraces);
    Type();
    IdList();
    eat(semicolon);
    VarDecl();
    eat(rbraces);
    eat(identifier);
    eat(semicolon);
    //adiciona na tabela
    TypeDecl();
}

// FunctionalDecl -> Type Pointer id ( FormaList ) { StmtList }
struct AST * FunctionalDecl() {
    Type();
    Pointer();
    eat(identifier);
    eat(lparent);
    FormaList();
    eat(rparent);
    eat(lbraces);
    StmtList();
    eat(rbraces);
}

// Program -> VarDecl Program
// Program -> FunctionalDecl Program
// Program -> TypeDecl Program
// Program -> ''
AST * Program(){
    switch (token) {
        case int_:
        case float_:
        case bool_:
        case char_:
        case double_:
        case long_:
        case identifier:

            FunctionalDecl();
            Program();
            break;
        
        case typedef_:
            TypeDecl();
            Program();
            break; 
    
    default:
        return;
        break;
    }
}

AST * S() {
    AST * r = Program();
    eat(EOF);
    return r;
}

// ---------------------------------------

AST * parser(lexical * l) {
    lex = l;
    token = nextToken(lex);
    return S();
}

