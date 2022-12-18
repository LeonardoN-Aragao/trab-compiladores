#include <stdio.h>
#include "lexic.h"

// ------------ REMOVER ??? ---------------

lexical * lex;
int token = 0;

// ----------------------------------------

void advance() { token = nextToken(); }
void eat(int t) {if (token == t) advance(); else error();}

int isType() {
    if(token == int_ || token == float_ || token == bool_ || token == char_ || token == double_ || token == long_)
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

// Type -> long;
// Type -> int;
// Type -> float;
// Type -> bool;
// Type -> ID;
// Type -> char;
// Type -> double;
void Type(){
    if(token == int_ || token == float_ || token == bool_ || token == char_ || token == double_ || token == long_)
        advance();
    else
        error();
}

void Expr(){

}

void STMT(){

}

// STMTList ::= STMT STMTList
// STMTList ::= ''
void STMTList(){
    if(isSTMT()){
        STMT(); 
        STMTList();
    }
    else return;
}


// Pointer -> asterisk;
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

// IdList ::= Pointer id Array IdList'
void IdList() {
    Pointer();
    eat(identifier);
    Array();
    IdListAux();
}

// IdList' ::= , IdList
// IdList' ::= ''
void IdListAux(){
    if(token == comma){
        eat(comma);
        IdList();
    }
    else return;
}

// FormalRest ::= , FormaList
// FormalRest ::= ''
void FormalRest() {
    if(token == comma){
        eat(comma); 
        FormaList();
    }
    else return;
}

// FormaList ::= Type Pointer id Array FormalRest
// FormaList ::= ''
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

// Array ::= [ Num ] Array
// Array ::= ''
void Array() {
    if(token == lbrackets){
        eat(lbrackets);
        eat(numInt);
        eat(rbrackets);
        Array();
    }
    else return;
}

// ExprOrCall' ::= ( ExprList  ) ;
// ExprOrCall' ::= ''
void ExprOrCallAux(){
    if(token == lparent){
        eat(lparent);
        ExprList();
        eat(rparent);
    }
    else return;
}

// ExprOrCall ::= A ExprOrCall' ;
void ExprOrCall() {

}


// CaseBlock ::= case num : STMTL CaseBlock
// CaseBlock ::= ''
void CaseBlock() {
    if(token == case_){
        eat(case_);
        eat(numInt);
        eat(colon);
        STMTL();
        CaseBlock();
    }
    else return;
}

// ExprListTail' ::= , ExprListTail
// ExprListTail' ::= ''
void ExprListTailAux() {
    if(token == comma){
        eat(comma);
        ExprListTail();
    }
    else return;
}

// ExprListTail ::= Expr ExprListTail'
// ExprListTail :: ''
void ExprListTail() {
    
}

// ExprList ::= ExprLT
// ExprList ::= ''
void ExprList() {

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

// FunctionalDecl -> Type Pointer id ( FormaList ) { STMTL }
void FunctionalDecl() {
    Type();
    Pointer();
    eat(identifier);
    eat(lparent);
    FormaList();
    eat(rparent);
    eat(lbraces);
    STMTL();
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
            FunctionalDecl();
            Program();
            break;
        
        case typedef_:
            TypeDecl();
            Program();
            break; 
    
    default:
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

