#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "lexic.h"
#include "AST.h"
#include "Visitor.h"
#include "errorManager.h"

// ------------ REMOVER ??? ---------------

lexical *lex;
int token = 0;
Interpreter *x;
errorManager error;

int synchronizationSetType[] = {identifier, asterisk, lbrackets, dot, arrow, ampersand, assignment, lparent};
int synchronizationSetF[] = {rbrackets, semicolon, rparent, comma, orSign, andSign, verticalPipe, ampersand, equality, notEqual, lessSign, great, lessOrEqual, greaterOrEqual, plusSign, minusSign, asterisk, slash, percent, exclamation};
int synchronizationSetFatId1[] = {semicolon};
int synchronizationSetSTMT[] = {rbraces, while_, switch_, break_, lbraces, print_, readln_, return_, throw_, try_, if_, long_, int_, float_, bool_, identifier, char_, double_, rbrackets, catch_, else_, case_};

const char *getTokenName(int value)
{
#define NAME(ERR) \
    case ERR:     \
        return #ERR;
    switch (value)
    {
        NAME(lbrackets)
        NAME(asterisk)
        NAME(lparent)
        NAME(comma)
        NAME(colon)
        NAME(rparent)
        NAME(rbraces)
        NAME(percent)
        NAME(lbraces)
        NAME(plusSign)
        NAME(rbrackets)
        NAME(backslash)
        NAME(arrow)
        NAME(equality)
        NAME(orSign)
        NAME(andSign)
        NAME(greaterOrEqual)
        NAME(notEqual)
        NAME(lessOrEqual)
        NAME(semicolon)
        NAME(exclamation)
        NAME(assignment)
        NAME(ampersand)
        NAME(great)
        NAME(minusSign)
        NAME(verticalPipe)
        NAME(lessSign)
        NAME(slash)
        NAME(dot)
        NAME(EOF)
        NAME(identifier)
        NAME(literal)
        NAME(numInt)
        NAME(numFloat)
        NAME(int_)
        NAME(float_)
        NAME(bool_)
        NAME(char_)
        NAME(double_)
        NAME(long_)
        NAME(if_)
        NAME(else_)
        NAME(while_)
        NAME(switch_)
        NAME(case_)
        NAME(break_)
        NAME(print_)
        NAME(readln_)
        NAME(return_)
        NAME(throw_)
        NAME(try_)
        NAME(catch_)
        NAME(true_)
        NAME(false_)
        NAME(typedef_)
        NAME(struct_)
    }
    return "unknown";
#undef NAME
}

// ----------------------------------------

// Errors ------------------------------------------------

void errorEat(int token, int t)
{
    printf("Error: %s != %s!!!\n", getTokenName(token), getTokenName(t));
}

int inFollow(int token, int *follow)
{
    for (int i = 0; i < sizeof(follow); i++)
    {
        if (follow[i] == token)
            return 0;
    }
    return 1;
}

int inFirst(int token, int *first)
{
    for (int i = 0; i < sizeof(first); i++)
    {
        if (first[i] == token)
            return 0;
    }
    return 1;
}
// Isso para o eat
void erro_eat(int token, int t, int *follow)
{
    if (inFollow(token, follow))
    {
        // Add t at ASA
        // Do not consume token and continue
        printf("If");
    }
    else
    {
        printf("Unexpected Token!!!");
    }
}

void erro(int token)
{
    // STMT -> make the token an id/num and continue
    // FatId -> verify token == +,-,... and continue
    // Type -> add to SymbTable and continue
}
// -------------------------------------------------------

void advance() { token = nextToken(lex); }
void eat(int t)
{
    if (token == t) {
        // printf("%s\n", getTokenName(token));
        advance();
    }
    else
        errorEat(token, t);
}

void synchronizingError(int *follow)
{
    int i = 0;
    while (token != EOF)
    {
        while (follow[i] != NULL)
        {
            if (follow[i] != token) i++;
            else return;
        }
        advance();
        i = 0;
    }
}

int isType()
{
    if (token == int_ || token == float_ || token == bool_ || token == char_ ||
        token == double_ || token == long_ || token == identifier)
        return 1;

    return 0;
}

int isStmt()
{
    if (token == if_ || token == while_ || token == switch_ || token == lbraces ||
        token == print_ || token == readln_ || token == return_ || token == throw_ ||
        token == try_ || token == identifier || token == break_)
        return 1;
    return 0;
}

// Start Parser ----------------------------------------------------------------


// ---------------------------------------

Program *parser(lexical *l)
{
    lex = l;
    token = nextToken(lex);
    return S();
}

Program *S()
{
    Program *p = Parser_Program();
    eat(EOF);
    x = new Interpreter();
    printf("VISITOR\n");
    x->visit(p);
    printf("\n");
    return p;
}

// Program -> VarDecl Program
// Program -> FunctionalDecl Program
// Program -> TypeDecl Program
// Program -> ''
Program *Parser_Program()
{
    switch (token)
    {
    case int_:
    case float_:
    case bool_:
    case char_:
    case double_:
    case long_:
    case identifier:
        return new Program(Parser_FunctionOrVarDecl());

    case typedef_:
        return new Program(Parser_TypeDecl(), Parser_Program());

    default:
        return NULL;
    }
}

// ProgramL ::= Array IdList'
// ProgramL ::= ( FormaList ) { STMTL }
ProgramL *Parser_ProgramL()
{
    if (token == lparent)
    {
        eat(lparent);
        FormaList *f = Parser_FormaList();
        eat(rparent);
        eat(lbraces);
        Stmtl *s = Parser_StmtList();
        eat(rbraces);

        return new ProgramL(f, s);
    }
    else
    {
        return new ProgramL(Parser_Array(), Parser_IdListAux());
    }
}

// FunctionOrVarDecl ::= Type Pointer id ProgramL Program
FunctionOrVarDecl *Parser_FunctionOrVarDecl()
{

    Type *t = Parser_Type();
    Pointer *p = Parser_Pointer();
    Identifier *i = Parser_identifier();
    ProgramL *pl = Parser_ProgramL();
    Program *prog = Parser_Program();

    return new FunctionOrVarDecl(
        t, p, i, pl, prog);
}

// TypeDecl -> typedef struct { Type IdList ; VarDecl } id ; TypeDecl
TypeDecl *Parser_TypeDecl()
{
    eat(typedef_);
    eat(struct_);
    eat(lbraces);
    Type *t = Parser_Type();
    IdList *il = Parser_IdList();
    eat(semicolon);
    VarDecl *v = Parser_VarDecl();
    eat(rbraces);
    Identifier *i = Parser_identifier();
    eat(semicolon);
    Parser_TypeDecl();

    return new TypeDecl(t, il, v, i);
}

// VarDecl -> Type IdList ; VarDecl
// VarDecl -> ''
VarDecl *Parser_VarDecl()
{
    if (!isType() || token != identifier)
    {
        return NULL;
    }

    Type *t = Parser_Type();
    IdList *id = Parser_IdList();
    eat(semicolon);
    return new VarDecl(t, id, Parser_VarDecl());
}

// Type -> long
// Type -> int
// Type -> float
// Type -> bool
// Type -> ID
// Type -> char
// Type -> double
Type *Parser_Type() {
    switch (token)
    {
    case int_:
    {
        IntType *i = new IntType();
        eat(int_);
        return i;
    }
    case float_:
    {
        FloatType *f = new FloatType();
        eat(float_);
        return f;
    }
    case bool_:
    {
        BoolType *b = new BoolType();
        eat(bool_);
        return b;
    }
    case char_:
    {
        CharType *c = new CharType();
        eat(char_);
        return c;
    }
    case double_:
    {
        DoubleType *d = new DoubleType();
        eat(double_);
        return d;
    }
    case long_:
    {
        LongType *l = new LongType();
        eat(long_);
        return l;
    }
    case identifier:
        return Parser_identifier();

    default:
        char *str = (char *)malloc(100);
        snprintf(str, 100, "Erro sintático: Tipo %s inválido", getTokenName(token));
        error = createError(9, str);
        printError(error);
        synchronizingError(synchronizationSetType);
        free(str);
        return NULL;
    }
}

// Pointer -> asterisk
// Pointer -> ''
Pointer *Parser_Pointer()
{
    if (token == asterisk)
    {
        eat(asterisk);
        return new Pointer();
    }
    else
        return NULL;
}

// FormaList -> Type Pointer id Array FormalRest
// FormaList -> ''
FormaList *Parser_FormaList()
{
    if (isType())
    {
        Type *t = Parser_Type();
        Pointer *p = Parser_Pointer();
        Identifier *i = Parser_identifier();
        // eat(identifier);
        Array *a = Parser_Array();
        FormalRest *fr = Parser_FormalRest();
        return new FormaList(t, p, a, fr, i);
    }
    else
        return NULL;
}

// FormalRest -> , FormaList
// FormalRest -> ''
FormalRest *Parser_FormalRest()
{
    if (token == comma)
    {
        eat(comma);
        return new FormalRest(Parser_FormaList());
    }
    else
        return NULL;
}

// Array -> [ NumInt ] Array
// Array -> ''
Array *Parser_Array()
{
    if (token == lbrackets)
    {
        eat(lbrackets);
        Int *i = (Int *)Parser_Num();
        eat(rbrackets);
        return new Array(i, Parser_Array());
    }
    else
        return NULL;
}

// IdList -> Pointer id Array IdList'
IdList *Parser_IdList()
{
    Pointer *p = Parser_Pointer();
    Identifier *id = Parser_identifier();
    return new IdList(p, id, Parser_Array(), Parser_IdListAux());
}

// IdList' -> , IdList
// IdList' -> ''
IdListAux *Parser_IdListAux()
{
    if (token == comma)
    {
        eat(comma);
        return new IdListAux(Parser_IdList());
    }
    else
        return NULL;
}

// StmtList -> Stmt StmtList
// StmtList -> ''
Stmtl *Parser_StmtList()
{
    if (isStmt() || isType())
    {
        Stmt *s = Parser_Stmt();
        Stmtl *sl = Parser_StmtList();
        return new Stmtl(s, sl);
    }
    else
    {
        return NULL;
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
// Stmt -> Type FatId ;
Stmt *Parser_Stmt()
{
    switch (token)
    {
    case if_:
    {
        eat(if_);
        eat(lparent);
        Expr *expr = Parser_Expr();
        eat(rparent);
        return new If(expr, Parser_Stmt(), Parser_Else());
    }
    case while_:
    {
        eat(while_);
        eat(lparent);
        Expr *e = Parser_Expr();
        eat(rparent);
        // eat(lbraces);
        Stmt *s = Parser_Stmt();
        // eat(rbraces);
        return new While(e, s);
    }
    case switch_:
    {
        eat(switch_);
        eat(lparent);
        Expr *e = Parser_Expr();
        eat(rparent);
        eat(lbraces);
        CaseBlock *cb = Parser_CaseBlock();
        eat(rbraces);
        return new Switch(e, cb);
    }
    case break_:
        eat(break_);
        eat(semicolon);
        return new Break();

    case lbraces:
    {
        eat(lbraces);
        Stmtl *sl = Parser_StmtList();
        eat(rbraces);
        return new Braces(sl);
    }
    case print_:
    {
        eat(print_);
        eat(lparent);
        ExprList *el = Parser_ExprList();
        eat(rparent);
        eat(semicolon);
        return new Print(el);
    }
    case readln_:
    {
        eat(print_);
        eat(lparent);
        Expr *e = Parser_Expr();
        eat(rparent);
        eat(semicolon);
        return new Readln(e);
    }
    case return_:
    {
        eat(return_);
        Expr *e = Parser_Expr();
        eat(semicolon);
        return new Return(e);
    }
    case throw_:
        eat(throw_);
        eat(semicolon);
        return new Throw();

    case try_:
    {
        eat(try_);
        Stmt *s1 = Parser_Stmt();
        eat(catch_);
        eat(lparent);
        Stmt *s2 = Parser_Stmt();
        eat(rparent);

        return new Try(s1, s2, Parser_Stmt());
    }
    default:
        if (isType())
        {
            Type *t = Parser_Type();
            FatId *f = Parser_FatId();
            eat(semicolon);
            return new StmtFatId(t, f);
        }
        else
        {
            char *str = (char *)malloc(100);
            snprintf(str, 100, "Erro sintático: Expressão %s inválido", getTokenName(token));
            error = createError(10, str);
            printError(error);
            synchronizingError(synchronizationSetSTMT);
            free(str);
            return NULL;
        }
    }
}

// Else-> else Stmt
// Else-> ''
Else *Parser_Else()
{
    if (token == else_)
    {
        eat(else_);
        return new Else(Parser_Stmt());
    }
    else
        return NULL;
}


// FatId ::= ( ExprList ) ;
// FatId ::=  IdList ;
// FatId ::= FatId1 ;
FatId *Parser_FatId()
{
    switch (token)
    {
    case lparent:
    {
        eat(lparent);
        FatId *c = new FatId(Parser_ExprList());
        // CallFunction *c = new CallFunction(Parser_ExprList());
        eat(rparent);
        return c;
    }
    case asterisk:
    case identifier:
    {
        FatId *f = new FatId(Parser_IdList());
        eat(semicolon);
        return f;
    }
    case dot:
    case arrow:
    case assignment:
    case lbrackets:
        return new FatId(Parser_FatId1());

    default:
        return NULL;
    }
}

// FatId1 -> dot Expr
// FatId1 -> arrow Expr
// FatId1 -> = Expr
// FatId1 -> [ Expr ]
FatId1 *Parser_FatId1()
{
    switch (token)
    {
    case dot:
        eat(dot);
        return new DotFatId1(Parser_Expr());

    case arrow:
        eat(arrow);
        return new ArrowFatId1(Parser_Expr());

    case assignment:
        eat(assignment);
        return new AssingmentFatId1(Parser_Expr());

    case lbrackets:
    {
        eat(lbrackets);
        BracketFatId1 *b = new BracketFatId1(Parser_Expr());
        eat(rbrackets);
        return b;
    }
    default:
        char *str = (char *)malloc(100);
        snprintf(str, 100, "Erro sintático: Caracter %s inválido", getTokenName(token));
        error = createError(11, str);
        printError(error);
        synchronizingError(synchronizationSetFatId1);
        free(str);
        return NULL;
    }
}

// CaseBlock -> case numInt : StmtList CaseBlock
// CaseBlock -> ''
CaseBlock *Parser_CaseBlock()
{
    if (token == case_)
    {
        eat(case_);
        char *token_value = searchAndGetString(lex, token, getLexeme(lex));
        Int *i = new Int(atoi(token_value));
        eat(numInt);
        eat(colon);
        return new CaseBlock(i, Parser_StmtList(), Parser_CaseBlock());
    }
    else
        return NULL;
}


// ExprList -> ExprListTail
// ExprList -> ''
ExprList *Parser_ExprList()
{
    return new ExprList(Parser_ExprListTail());
}

// ExprListTail -> Expr ExprListTail'
// ExprListTail :: ''
ExprListTail *Parser_ExprListTail()
{
    return new ExprListTail(
        Parser_Expr(),
        Parser_ExprListTailAux());
}

// ExprListTail' -> , ExprListTail
// ExprListTail' -> ''
ExprListTailAux *Parser_ExprListTailAux()
{
    if (token == comma)
    {
        eat(comma);
        return new ExprListTailAux(Parser_ExprListTail());
    }
    else
        return NULL;
}

// Expr -> Expr2 ExprAux
Expr *Parser_Expr() {
	Expr2 *a = Parser_Expr2();
	ExprAux *b = Parser_ExprAux();
	return new Expr(a, b);
}

// ExprAux -> || Expr2 ExprAux
// ExprAux -> ''
ExprAux *Parser_ExprAux() {
	if (token == orSign) {
		Expr2 *e1 = Parser_Expr2();
		ExprAux *e2 = Parser_ExprAux();
		return new ExprAux(e1, e2);
	} else return NULL;
}

// Expr2 -> Expr3 Expr2Aux
Expr2 *Parser_Expr2() {
	Expr3 *e1 = Parser_Expr3();
	Expr2Aux *e2 = Parser_Expr2Aux();
	return new Expr2(e1, e2);
}

// Expr2Aux -> && Expr3 Expr2Aux
// Expr2Aux -> ''
Expr2Aux *Parser_Expr2Aux() {
	if (token == andSign) {
		Expr3 *e1 = Parser_Expr3();
		Expr2Aux *e2 = Parser_Expr2Aux();
		return new Expr2Aux(e1, e2);
	} else return NULL;
}

// Expr3 -> Expr4 Expr3Aux
Expr3 *Parser_Expr3() {
	Expr4 *e1 = Parser_Expr4();
	Expr3Aux *e2 = Parser_Expr3Aux();
	return new Expr3(e1, e2);
}

// Expr3Aux -> | Expr4 Expr3Aux
// Expr3Aux -> ''
Expr3Aux *Parser_Expr3Aux() {
	if (token == verticalPipe) {
		Expr4 *e1 = Parser_Expr4();
		Expr3Aux *e2 = Parser_Expr3Aux();
		return new Expr3Aux(e1, e2);
	} else return NULL;
}

// Expr4 -> Expr5 Expr4Aux
Expr4 *Parser_Expr4() {
	Expr5 *e1 = Parser_Expr5();
	Expr4Aux *e2 = Parser_Expr4Aux();
	return new Expr4(e1, e2);
}

// Expr4Aux -> & Expr5 Expr4Aux
// Expr4Aux -> ''
Expr4Aux *Parser_Expr4Aux() {
	if (token == ampersand) {
		Expr5 *e1 = Parser_Expr5();
		Expr4Aux *e2 = Parser_Expr4Aux();
		return new Expr4Aux(e1, e2);
	} else return NULL;
}

// Expr5 -> Expr6 Expr5Aux
Expr5 *Parser_Expr5() {
	Expr6 *e1 = Parser_Expr6();
	Expr5Aux *e2 = Parser_Expr5Aux();
	return new Expr5(e1, e2);
}

// Expr5Aux -> == Expr6 Expr5Aux
// Expr5Aux -> != Expr6 Expr5Aux
// Expr5Aux -> ''
Expr5Aux *Parser_Expr5Aux() {
	switch (token) {
	case equality: {
		eat(equality);
		Expr6 *e1 = Parser_Expr6();
		Expr5Aux *e2 = Parser_Expr5Aux();
		return new Expr5Aux(e1, e2, getTokenName(equality));
	}
	case notEqual: {
		eat(notEqual);
		Expr6 *e1 = Parser_Expr6();
		Expr5Aux *e2 = Parser_Expr5Aux();
		return new Expr5Aux(e1, e2, getTokenName(notEqual));
	}
	default:
		return NULL;
	}
}

// Expr6 -> Expr7 Expr6Aux
Expr6 *Parser_Expr6() {
	Expr7 *e1 = Parser_Expr7();
	Expr6Aux *e2 = Parser_Expr6Aux();
	return new Expr6(e1, e2);
}

// Expr6Aux -> < Expr7 Expr6Aux
// Expr6Aux -> > Expr7 Expr6Aux
// Expr6Aux -> <= Expr7 Expr6Aux
// Expr6Aux -> ''
Expr6Aux *Parser_Expr6Aux() {
	switch (token) {
	case lessSign: {
		eat(lessSign);
		Expr7 *e1 = Parser_Expr7();
		Expr6Aux *e2 = Parser_Expr6Aux();
		return new Expr6Aux(e1, e2, getTokenName(lessSign));
	}
	case great: {
		eat(great);
		Expr7 *e1 = Parser_Expr7();
		Expr6Aux *e2 = Parser_Expr6Aux();
		return new Expr6Aux(e1, e2, getTokenName(great));
	}
	case lessOrEqual: {
		eat(lessOrEqual);
		Expr7 *e1 = Parser_Expr7();
		Expr6Aux *e2 = Parser_Expr6Aux();
		return new Expr6Aux(e1, e2, getTokenName(lessOrEqual));
	}
	case greaterOrEqual: {
		eat(greaterOrEqual);
		Expr7 *e1 = Parser_Expr7();
		Expr6Aux *e2 = Parser_Expr6Aux();
		return new Expr6Aux(e1, e2, getTokenName(greaterOrEqual));
	}
	default:
		return NULL;
	}
}

// Expr7 -> Expr8 Expr7Aux
Expr7 *Parser_Expr7() {
	Expr8 *e1 = Parser_Expr8();
	Expr7Aux *e2 = Parser_Expr7Aux();
	return new Expr7(e1, e2);
}

// Expr7Aux -> + Expr8 Expr7Aux
// Expr7Aux -> - Expr8 Expr7Aux
// Expr7Aux -> ''
Expr7Aux *Parser_Expr7Aux() {
	switch (token) {
	case plusSign: {
		eat(plusSign);
		Expr8 *e1 = Parser_Expr8();
		Expr7Aux *e2 = Parser_Expr7Aux();
		return new Expr7Aux(e1, e2, getTokenName(plusSign));
		break;
	}
	case minusSign: {
		eat(minusSign);
		Expr8 *e1 = Parser_Expr8();
		Expr7Aux *e2 = Parser_Expr7Aux();
		return new Expr7Aux(e1, e2, getTokenName(minusSign));
		break;
	}
	default:
		return NULL;
	}
}

// Expr8 -> Expr9 Expr8Aux
Expr8 *Parser_Expr8() {
	Expr9 *e1 = Parser_Expr9();
	Expr8Aux *e2 = Parser_Expr8Aux();
	return new Expr8(e1, e2);
}

// Expr8Aux -> * Expr9 Expr8Aux
// Expr8Aux -> / Expr9 Expr8Aux
// Expr8Aux -> % Expr9 Expr8Aux
// Expr8Aux -> ''
Expr8Aux *Parser_Expr8Aux() {
	switch (token) {
	case asterisk: {
		eat(asterisk);
		Expr9 *e1 = Parser_Expr9();
		Expr8Aux *e2 = Parser_Expr8Aux();
		return new Expr8Aux(e1, e2, getTokenName(asterisk));
		break;
	}
	case slash: {
		eat(slash);
		Expr9 *e1 = Parser_Expr9();
		Expr8Aux *e2 = Parser_Expr8Aux();
		return new Expr8Aux(e1, e2, getTokenName(slash));
		break;
	}
	case percent: {
		eat(percent);
		Expr9 *e1 = Parser_Expr9();
		Expr8Aux *e2 = Parser_Expr8Aux();
		return new Expr8Aux(e1, e2, getTokenName(percent));
		break;
	}
	default:
		return NULL;
	}
}

// Expr9 -> F Expr9Aux
Expr9 *Parser_Expr9() {
	F *f = Parser_F();
	Expr9Aux *ex = Parser_Expr9Aux();
	return new Expr9(f, ex);
}

// Expr9Aux -> plusUnary Expr9
// Expr9Aux -> minusUnary Expr9
// Expr9Aux -> notUnary Expr9
// Expr9Aux -> ''
Expr9Aux *Parser_Expr9Aux() {
	switch (token) {
	case plusSign: {
		eat(plusSign);
		Expr9* ex = Parser_Expr9();
		return new Expr9Aux(ex, getTokenName(plusSign));
	}
	case minusSign: {
		eat(minusSign);
		Expr9* ex = Parser_Expr9();
		return new Expr9Aux(ex, getTokenName(minusSign));
	}
	case exclamation: {
		eat(exclamation);
		Expr9* ex = Parser_Expr9();
		return new Expr9Aux(ex, getTokenName(exclamation));
	}
	default:
		return NULL;
	}
}

Identifier *Parser_identifier()
{
    // adiciona na tabela
    char *token_name = searchAndGetString(lex, token, getLexeme(lex));
    Identifier *i = new Identifier(token_name);
    eat(identifier);
    return i;
}

// F ::= ( Expr )
// F ::= id
// F ::= num
// F ::= literal
// F ::= true
// F ::= false
F *Parser_F()
{
    switch (token)
    {
    case numInt:
    {  
        char *token_value = searchAndGetString(lex, token, getLexeme(lex));
        Int *i = new Int(atoi(token_value));
        eat(numInt);
        return i;
    }
    case numFloat:
    {
        char *token_value = searchAndGetString(lex, token, getLexeme(lex));
        Float *f = new Float(atof(token_value));
        eat(numFloat);
        return f;
    }
    case literal:
    {
        char *token_value = searchAndGetString(lex, token, getLexeme(lex));
        Literal *l = new Literal(token_value);
        eat(literal);
        return l;
    }
    case true_:
        eat(true_);
        return new True();

    case false_:
        eat(false_);
        return new False();

    case identifier:
    {
        char *token_value = searchAndGetString(lex, token, getLexeme(lex));
        Identifier_F *i = new Identifier_F(token_value);
        eat(identifier);
        return i;
    }

    case lparent:
    {
        eat(lparent);
        F_Expr *f = new F_Expr(Parser_Expr());
        eat(rparent);
        return f;
    }
    default:
        char *str = (char *)malloc(100);
        snprintf(str, 100, "Erro sintático: Identificador %s inválido", getTokenName(token));
        error = createError(8, str);
        printError(error);
        synchronizingError(synchronizationSetF);
        free(str);
        return NULL;
    }
}

// Num -> numInt
// Num -> numFloat
Num *Parser_Num()
{
    switch (token)
    {
    case numInt:
    {
        char *token_value = searchAndGetString(lex, token, getLexeme(lex));
        Int *i = new Int(atoi(token_value));
        eat(numInt);
        return i;
    }
    case numFloat:
    {
        char *token_value = searchAndGetString(lex, token, getLexeme(lex));
        Float *f = new Float(atof(token_value));
        eat(numFloat);
        return f;
    }
    default:
        return NULL;
    }
}
