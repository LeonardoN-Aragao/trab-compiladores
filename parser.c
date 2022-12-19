#include <stdio.h>
#include "lexic.h"

// ------------ REMOVER ??? ---------------

lexical * lex;
int token = 0;

// ----------------------------------------

void advance() { token = nextToken(lex); }
void eat(int t) {if (token == t) advance(); else error();}

int isType() {
    if(token == int_ || token == float_ || token == bool_ || token == char_ || token == double_ || token == long_ || token == identifier)
        return 1;
    return 0;
}

int isExpr(){
    if(1)
        return 1;
    return 0;
}

int isStmt(){
    if(1)
        return 1;
    return 0;
}

void Num(){
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
void Type(){
    if(token == int_ || token == float_ || token == bool_ || token == char_ || token == double_ || token == long_)
        advance();
    else
        error();
}

void F(){

}

// Expr9Aux -> plusUnary Expr9
// Expr9Aux -> minusUnary Expr9
// Expr9Aux -> notUnary Expr9
// Expr9Aux -> ''
void Expr9Aux() {
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
void Expr9() {
    F(); Expr9Aux();
}

// Expr8Aux -> * Expr9 Expr8Aux
// Expr8Aux -> / Expr9 Expr8Aux
// Expr8Aux -> % Expr9 Expr8Aux
// Expr8Aux -> ''
void Expr8Aux() {
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
void Expr8() {
    Expr9(); Expr8Aux();
}

// Expr7Aux -> + Expr8 Expr7Aux
// Expr7Aux -> - Expr8 Expr7Aux
// Expr7Aux -> ''
void Expr7Aux() {
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
void Expr7() {
    Expr8(); Expr7Aux();
}

// Expr6Aux -> < Expr7 Expr6Aux
// Expr6Aux -> > Expr7 Expr6Aux
// Expr6Aux -> <= Expr7 Expr6Aux
// Expr6Aux -> >= Expr7 Expr6Aux
// Expr6Aux -> ''
void Expr6Aux() {
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
void Expr6() {
    Expr7(); Expr6Aux();
}

// Expr5Aux -> == Expr6 Expr5Aux
// Expr5Aux -> != Expr6 Expr5Aux
// Expr5Aux -> ''
void Expr5Aux() {
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
void Expr5() {
    Expr6(); Expr5Aux();
}

// Expr4Aux -> & Expr5 Expr4Aux
// Expr4Aux -> ''
void Expr4Aux() {
    if(token == ampersand){
        Expr5(); 
        ExprAux4();
    }
    else return;
}

// Expr4 -> Expr5 Expr4Aux
void Expr4() {
    Expr5(); Expr4Aux();
}


// Expr3Aux -> | Expr4 Expr3Aux
// Expr3Aux -> ''
void Expr3Aux() {
    if(token == verticalPipe){
        Expr4(); 
        Expr3Aux();
    }
    else return;
}

// Expr3 -> Expr4 Expr3Aux
void Expr3() {
    Expr4(); Expr3Aux();
}

// Expr2Aux -> && Expr3 Expr2Aux
// Expr2Aux -> ''
void Expr2Aux() {
    if(token == andSign){
        Expr3(); 
        Expr2Aux();
    }
    else return;
}

// Expr2 -> Expr3 Expr2Aux
void Expr2() {
    Expr3(); Expr2Aux();
}

// ExprAux -> || Expr2 ExprAux
// ExprAux -> ''
void ExprAux(){
    if(token == orSign){
        Expr2(); 
        ExprAux();
    }
    else return;
}

//Expr -> Expr2 ExprAux
void Expr(){
    Expr2(); ExprAux();
}

// Cmd -> Stmt
// Cmd ->{ StmtList }
void Cmd(){
    if(isStmt())
        Stmt();
    else if(token == lbraces){
        eat(lbraces);
        StmtList();
        eat(rbraces);
    }
    else error();
}

// Else-> else Cmd
// Else-> ''
void Else(){
    if(token == else_){
        eat(else_);
        Cmd();
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

void Stmt(){

}

// StmtList -> Stmt StmtList
// StmtList -> ''
void StmtList(){
    if(isStmt()){
        Stmt(); 
        StmtList();
    }
    else return;
}


// Pointer -> asterisk
// Pointer -> ''
void Pointer() {
    if(token == asterisk) advance();
    else return;
}

// VarDecl -> Type IdList ; VarDecl
// VarDecl -> ''
void VarDecl(){
    if(!isType())
        return;
        
    Type();
    IdList();
    eat(semicolon);
    VarDecl();
}

// IdList' -> , IdList
// IdList' -> ''
void IdListAux(){
    if(token == comma){
        eat(comma);
        IdList();
    }
    else return;
}

// IdList -> Pointer id Array IdList'
void IdList() {
    Pointer();
    eat(identifier);
    Array();
    IdListAux();
}

// FormalRest -> , FormaList
// FormalRest -> ''
void FormalRest() {
    if(token == comma){
        eat(comma); 
        FormaList();
    }
    else return;
}

// FormaList -> Type Pointer id Array FormalRest
// FormaList -> ''
void FormaList() {
    if(isType()){
        Type();
        Pointer();
        eat(identifier);
        Array();
        FormalRest();
    }
    else return;
}    

// Array -> [ Num ] Array
// Array -> ''
void Array() {
    if(token == lbrackets){
        eat(lbrackets);
        eat(numInt);
        eat(rbrackets);
        Array();
    }
    else return;
}

// ExprOrCall' -> ( ExprList  )
// ExprOrCall' -> ''
void ExprOrCallAux(){
    if(token == lparent){
        eat(lparent);
        ExprList();
        eat(rparent);
    }
    else return;
}

// ExprOrCall -> Expr ExprOrCall'
void ExprOrCall() {
    Expr();
    ExprOrCallAux();
    eat(semicolon);
}


// CaseBlock -> case num : StmtL CaseBlock
// CaseBlock -> ''
void CaseBlock() {
    if(token == case_){
        eat(case_);
        eat(numInt);
        eat(colon);
        StmtL();
        CaseBlock();
    }
    else return;
}

// ExprListTail' -> , ExprListTail
// ExprListTail' -> ''
void ExprListTailAux() {
    if(token == comma){
        eat(comma);
        ExprListTail();
    }
    else return;
}

// ExprListTail -> Expr ExprListTail'
// ExprListTail :: ''
void ExprListTail() {
    Expr();
    ExprListTailAux();
}

// ExprList -> ExprListTail
// ExprList -> ''
void ExprList() {
    ExprListTail();
}

// TypeDecl -> typedef struct { Type IdList ; VarDecl } id ; TypeDecl
void TypeDecl(){
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
    TypeDecl();
}

// FunctionalDecl -> Type Pointer id ( FormaList ) { StmtL }
void FunctionalDecl() {
    Type();
    Pointer();
    eat(identifier);
    eat(lparent);
    FormaList();
    eat(rparent);
    eat(lbraces);
    StmtL();
    eat(rbraces);
}


// Program -> FunctionalDecl Program
// Program -> TypeDecl Program
// Program -> ''
void Program(){

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

void S() {
    Program();
    eat(EOF);
}

// ---------------------------------------

void parser(lexical * l) {
    lex = l;
    token = getToken();
    S();
}

