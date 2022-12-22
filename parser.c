#include <stdio.h>
#include "parser.h"
#include "lexic.h"
#include "AST.h"
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

Identifier * Parser_identifier(){
    // adiciona na tabela
    char * token_name = searchAndGetString(lex, token, getLexeme(lex));
    Identifier * i = new Identifier(token_name);
    eat(identifier);
    return  i;
}

//Num -> numInt
//Num -> numFloat
Num * Parser_Num(){
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
Type* Parser_Type(){
    if(token == int_ || token == float_ || token == bool_ || token == char_ || token == double_ || token == long_)
        advance();
    else if(1) //verificar tabela de simbolos
        return;
    else
        error();
}

Expr* Parser_F(){

}

// Expr9Aux -> plusUnary Expr9
// Expr9Aux -> minusUnary Expr9
// Expr9Aux -> notUnary Expr9
// Expr9Aux -> ''
Expr* Expr9Aux() {
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
Expr* Expr9() {
    Parser_F(); Expr9Aux();
}

// Expr8Aux -> * Expr9 Expr8Aux
// Expr8Aux -> / Expr9 Expr8Aux
// Expr8Aux -> % Expr9 Expr8Aux
// Expr8Aux -> ''
Expr* Expr8Aux() {
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
Expr* Expr8() {
    Expr9(); Expr8Aux();
}

// Expr7Aux -> + Expr8 Expr7Aux
// Expr7Aux -> - Expr8 Expr7Aux
// Expr7Aux -> ''
Expr* Expr7Aux() {
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
Expr* Expr7() {
    Expr8(); Expr7Aux();
}

// Expr6Aux -> < Expr7 Expr6Aux
// Expr6Aux -> > Expr7 Expr6Aux
// Expr6Aux -> <= Expr7 Expr6Aux
// Expr6Aux -> >= Expr7 Expr6Aux
// Expr6Aux -> ''
Expr* Expr6Aux() {
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
Expr* Expr6() {
    Expr7(); Expr6Aux();
}

// Expr5Aux -> == Expr6 Expr5Aux
// Expr5Aux -> != Expr6 Expr5Aux
// Expr5Aux -> ''
Expr* Expr5Aux() {
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
Expr* Expr5() {
    Expr6(); Expr5Aux();
}

// Expr4Aux -> & Expr5 Expr4Aux
// Expr4Aux -> ''
Expr* Expr4Aux() {
    if(token == ampersand){
        Expr5(); 
        Expr4Aux();
    }
    else return;
}

// Expr4 -> Expr5 Expr4Aux
Expr* Expr4() {
    Expr5(); Expr4Aux();
}

// Expr3Aux -> | Expr4 Expr3Aux
// Expr3Aux -> ''
Expr* Expr3Aux() {
    if(token == verticalPipe){
        Expr4(); 
        Expr3Aux();
    }
    else return;
}

// Expr3 -> Expr4 Expr3Aux
Expr* Expr3() {
    Expr4(); Expr3Aux();
}

// Expr2Aux -> && Expr3 Expr2Aux
// Expr2Aux -> ''
Expr* Expr2Aux() {
    if(token == andSign){
        Expr3(); 
        Expr2Aux();
    }
    else return;
}

// Expr2 -> Expr3 Expr2Aux
Expr* Expr2() {
    Expr3(); Expr2Aux();
}

// ExprAux -> || Expr2 ExprAux
// ExprAux -> ''
Expr* ExprAux(){
    if(token == orSign){
        Expr2(); 
        ExprAux();
    }
    else return;
}

//Expr -> Expr2 ExprAux
Expr* Parser_Expr(){
    Expr2(); ExprAux();
}

// Else-> else Stmt
// Else-> ''
Else* Parser_Else(){
    if(token == else_){
        eat(else_);
        Parser_Stmt();
        //arv.add(tabela[Else])
    }
    else return;
}

// StmtList -> Stmt StmtList
// StmtList -> ''
Stmtl* Parser_StmtList(){
    if(isStmt()){
        Parser_Stmt(); 
        Parser_StmtList();
    }
    else return;
}

// FatId1 -> dot Expr
// FatId1 -> arrow Expr
// FatId1 -> = Expr
// FatId1 -> [ Expr ]
FatId1* Parser_FatId1(){
    switch (token){
        case dot:
            eat(dot);
            Parser_Expr();
            break;

        case arrow:
            eat(arrow);
            Parser_Expr();
            break;

        case assignment:
            eat(assignment);
            Parser_Expr();
            break;

        case lbrackets:
            eat(lbrackets);
            Parser_Expr();
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
FatId * Parser_FatId(){
    switch(token){
        case lparent:
            eat(lparent);
            Parser_ExprList();
            eat(rparent);
            break;

        case asterisk:
        case identifier:
            Parser_IdList();
            eat(semicolon);
            Parser_Stmt();
            break;

        case dot:
        case arrow:
        case assignment:
        case lbrackets:
            Parser_FatId1();
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
Stmt* Parser_Stmt(){
    switch (token){
        case if_:
            eat(if_);
            eat(lparent);
            Parser_Expr();
            eat(rparent);
            Parser_Stmt();
            Parser_Else();
            break;

        case while_:
            eat(while_);
            eat(lparent);
            Parser_Expr();
            eat(rparent);
            eat(lbraces);
            Parser_Stmt();
            eat(rbraces);
            break;

        case switch_:
            eat(switch_);
            eat(lparent);
            Parser_Expr();
            eat(rparent);
            eat(lbraces);
            Parser_CaseBlock();
            eat(rbraces);
            break;

        case break_:
            eat(break_);
            eat(semicolon);
            break;

        case lbraces:
            eat(lbrackets);
            Parser_StmtList();
            eat(rbrackets);
            break;
        
        case print_:
            eat(print_);
            eat(lparent);
            Parser_ExprList();
            eat(rparent);
            eat(semicolon);
            break;
        
        case readln_:
            eat(print_);
            eat(lparent);
            Parser_Expr();
            eat(rparent);
            eat(semicolon);
            break;

        case return_:
            eat(return_);
            Parser_Expr();
            eat(semicolon);
            break;
        
        case throw_:
            eat(throw_);
            eat(semicolon);
            break;
        
        case try_:
            eat(try_);
            Parser_Stmt();
            eat(catch_);
            eat(lparent);
            Parser_Stmt();
            eat(rparent);
            Parser_Stmt();
            break;
        
        case identifier:
            eat(identifier);
            Parser_FatId();
            eat(semicolon);
            break;

    default:
        error();
    }
}


// Pointer -> asterisk
// Pointer -> ''
Pointer* Parser_Pointer() {
    if(token == asterisk) advance();
    else return;
}

// VarDecl -> Type IdList ; VarDecl
// VarDecl -> ''
VarDecl* Parser_VarDecl(){
    if(!isType() || token !=identifier)
        return;
        
    Parser_Type();
    Parser_IdList();
    eat(semicolon);
    Parser_VarDecl();
}

// IdList' -> , IdList
// IdList' -> ''
IdListAux* Parser_IdListAux(){
    if(token == comma){
        eat(comma);
        Parser_IdList();
    }
    else return;
}

// IdList -> Pointer id Array IdList'
IdList* Parser_IdList() {
    Parser_Pointer();
    eat(identifier);
    Parser_Array();
    Parser_IdListAux();
}

// FormalRest -> , FormaList
// FormalRest -> ''
FormalRest* Parser_FormalRest() {
    if(token == comma){
        eat(comma); 
        Parser_FormaList();
    }
    else return;
}

// FormaList -> Type Pointer id Array FormalRest
// FormaList -> ''
FormaList* Parse_FormaList() {
    if(isType()){
        Parser_Type();
        Parser_Pointer();
        eat(identifier);
        Parser_Array();
        Parser_FormalRest();
    }
    else return;
}    

// Array -> [ NumInt ] Array
// Array -> ''
Array * Parser_Array() {
    if(token == lbrackets){
        eat(lbrackets);
        eat(numInt);
        eat(rbrackets);
        Parser_Array();
    }
    else return;
}

// CaseBlock -> case numInt : StmtList CaseBlock
// CaseBlock -> ''
CaseBlock * Parser_CaseBlock() {
    if(token == case_){
        eat(case_);
        eat(numInt);
        eat(colon);
        Parser_StmtList();
        Parser_CaseBlock();
    }
    else return NULL;
}

// ExprListTail' -> , ExprListTail
// ExprListTail' -> ''
ExprListTailAux* Parser_ExprListTailAux() {
    if(token == comma){
        eat(comma);
        return new ExprListTailAux(Parser_ExprListTail());
    }
    else return NULL;
}

// ExprListTail -> Expr ExprListTail'
// ExprListTail :: ''
ExprListTail * Parser_ExprListTail() {
    return new ExprListTail (
        Parser_Expr(),
        Parser_ExprListTailAux()
    );
}

// ExprList -> ExprListTail
// ExprList -> ''
ExprList * Parser_ExprList() {
    return new ExprList(Parser_ExprListTail());
}

// TypeDecl -> typedef struct { Type IdList ; VarDecl } id ; TypeDecl
TypeDecl* Parser_TypeDecl(){
    eat(typedef_);
    eat(struct_);
    eat(lbraces);
    Type * t = Parser_Type();
    IdList * il = Parser_IdList();
    eat(semicolon);
    VarDecl * v = Parser_VarDecl();
    eat(rbraces);
    Identifier * i = Parser_identifier();
    eat(semicolon);
    Parser_TypeDecl();

    return new TypeDecl(
        t,il,v,i
    );
}


// ProgramL ::= Array IdList'
// ProgramL ::= ( FormaList ) { STMTL }
ProgramL * Parser_ProgramL(){
    if(token == lparent){
        eat(lparent);
        FormaList * f = Parser_FormaList();
        eat(rparent);
        eat(lbraces);
        Stmtl * s = Parser_Stmtl();
        eat(rbraces);

        return new ProgramL(f,s);
    }
    else{
        return new ProgramL(Parser_Array(),Parser_IdListAux());
    }
}

// FunctionOrVarDecl ::= Type Pointer id ProgramL Program
FunctionOrVarDecl * Parser_FunctionOrVarDecl() {

    Type * t = Parser_Type();
    Pointer * p = Parser_Pointer();
    Identifier * i = Parser_identifier();
    ProgramL * pl = Parser_ProgramL();
    Program * prog = Parser_Program();

    return new FunctionOrVarDecl(
        t,p,i,pl,prog
    );
}

// Program -> VarDecl Program
// Program -> FunctionalDecl Program
// Program -> TypeDecl Program
// Program -> ''
Program * Parser_Program(){
    switch (token) {
        case int_:
        case float_:
        case bool_:
        case char_:
        case double_:
        case long_:
        case identifier:
            return new Program(Parser_FunctionOrVarDecl());
        
        case typedef_:
            return new Program(Parser_TypeDecl(),Parser_Program());
    
    default:
        error();
        return NULL;
    }
}

Program * S() {
    Program * p = Parser_Program();
    eat(EOF);
    return p;
}

// ---------------------------------------

Program * parser(lexical * l) {
    lex = l;
    token = nextToken(lex);
    return S();
}

