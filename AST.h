#ifndef AST_H
#define AST_H

#include "lexic.h"

class Program;
class FunctionOrVarDecl;
class ExprListTailAux;
class ExprListTail;
class FormaList;
class FormalRest;
class ExprList;
class FatId;
class FatId1;
class Array;
class Identifier;
class Expr;
class IdList;
class Stmtl;
class IdListAux;

class Pointer { 
	public: 
		Pointer(){};
		int asterisk_token = asterisk;
};

class ProgramL { 
	public: 
		ProgramL(Array * a, IdListAux * id) { array = a; idL = id; }
		ProgramL(FormaList* f, Stmtl* s) { fl = f; sl = s; }
		Array * array; IdListAux * idL; FormaList* fl; Stmtl* sl;
};

// IdList ::= Pointer id Array IdList'
class IdList { 
	public:
		IdList(Pointer* p, Identifier * i, Array * a, IdListAux * il) { pointer = p; id = i; array = a; idl = il; }
		Pointer* pointer; Identifier * id; Array * array; IdListAux * idl;
};

class Expr { 
	public: 
		Expr(){};
		Expr(Expr* e1, Expr * e2) { ex1 = e1; ex2 = e2; }
		Expr* ex1; Expr * ex2;
};

class F : public Expr { public: F(){}; };

class F_Expr : public F {
	public: 
		F_Expr(Expr * ex) { expr = ex; }
		Expr * expr; 
};

class Num : public F { public: Num(){}; };

class True : public F { public: True(){}; };

class False : public F { public: False(){}; };

class Literal : public F { 
	public:
		Literal(char* v) { value = v; }
		char* value;
};

class Int : public Num { 
	public:
		Int(int v) { value = v; }
		int value;
};

class Array { 
	public:
		Array(Int * i, Array * a) { array = a; n = i; }
		Array * array; Int * n;
};

class Float : public Num { 
	public:
		Float(float v) { value = v; }
		float value;
};

class Char : public F {
	public:
		Char(char v) { value = v; }
		char value;
};

class Bool : public F { 
	public:
		Bool(float v) { value = v; }
		float value;
};

class Long : public F { 
	public:
		Long(long v) { value = v; }
		long value;
};

class Double : public F { 
	public:
		Double(double v) { value = v; }
		double value;
};

class Identifier_F :public F { 
	public: 
		Identifier_F(char * nome) { token_name = nome; } 
		char * token_name; 
};

class Type { public: Type(){};};

class LongType : public Type { public: LongType(){};};

class IntType : public Type { public: IntType(){}; };

class FloatType : public Type { public: FloatType(){}; };

class BoolType : public Type { public: BoolType(){}; };

class CharType : public Type { public: CharType(){}; };

class DoubleType : public Type { public: DoubleType(){}; };

class Identifier :public Type { 
	public: 
		Identifier(char * nome) { token_name = nome; } 
		char * token_name; 
};

class VarDecl { 
	public: 
		VarDecl(Type * t, IdList * i, VarDecl * v) { type = t; idl = i; vd = v; }
		Type * type; IdList * idl; VarDecl * vd;
};

class Stmt { public: Stmt(){};};

class Break : public Stmt {  };

class Throw : public Stmt {  };

class Else : public Stmt { 
	public: 
		Else(Stmt * s) { stmt = s; }
		Stmt * stmt;
};

class If : public Stmt { 
	public: 
		If(Expr * ex, Stmt * s, Else * e) { expr = ex; stmt = s; el = e; }
		Expr * expr; Stmt * stmt; Else * el;
};

class While : public Stmt { 
	public: 
		While (Expr * ex, Stmt * s) { stmt = s; expr = ex; }
		Expr * expr; Stmt * stmt;
}; 

class CaseBlock { 
	public: 
		CaseBlock(Int * i, Stmtl * s, CaseBlock * c) { cl = i; sl = s; cb = c; }
		Int * cl; Stmtl * sl; CaseBlock * cb; 
};

class Switch : public Stmt { 
	public: 
		Switch(Expr * ex, CaseBlock * c) { expr = ex; cb = c; }
		Expr * expr; CaseBlock * cb;
};

class Return : public Stmt { 
	public: 
		Return(Expr * ex) { expr = ex; }
		Expr * expr;
};

class Try : public Stmt { 
	public: 
		Try(Stmt * tS, Stmt * cS, Stmt * cB) { tryStmt = tS; catchStmt = cS; catchBlock = cB; }
		Stmt * tryStmt; Stmt * catchStmt; Stmt * catchBlock;
};

class Print : public Stmt {
	public: 
		Print(ExprList * e) { el = e; } 
		ExprList * el; 
};

class Readln : public Stmt { 
	public:
		Readln(Expr * ex) { expr = ex; } 
		Expr *expr;
};

class StmtFatId : public Stmt { 
	public: 
		StmtFatId(Type * t, FatId * f) { type = t; fI = f;}
		Type * type; FatId * fI; 
};

class Stmtl : public Stmt { 
	public:
		Stmtl(Stmt * s, Stmtl * sl) { stmt = s; stmtl = sl; } 
		Stmt * stmt; Stmtl * stmtl; 
};

class FatId {};

class FatId1 {};

class CallFunction: public FatId { 
	public: 
		CallFunction(ExprList * e) { el = e; }
		ExprList * el; 
};

class FatIdIdList : public FatId { 
	public: 
		FatIdIdList(IdList * i){ il = i;}
		IdList * il; 
};

class FatIdFatId1 : public FatId { 
	public:
		FatIdFatId1(FatId1 * f){ fI = f; }
		FatId1 * fI; 
};

class DotFatId1 : public FatId1 { 
	public: 
		DotFatId1(Expr * ex) { expr = ex; }
		Expr * expr; 
};

class ArrowFatId1 : public FatId1 { 
	public: 
		ArrowFatId1(Expr * ex) { expr = ex; } 
		Expr * expr; 
};

class AmpersandFatId1 : public FatId1 { 
	public:
	 	AmpersandFatId1(Expr * ex){ expr = ex; }
		Expr * expr; 
};

class AssingmentFatId1 : public FatId1 { 
	public: 
		AssingmentFatId1(Expr * ex){ expr = ex; }
		Expr * expr; 
};

class BracketFatId1 : public FatId1 { 
	public: 
		BracketFatId1(Expr * ex){ expr = ex; }
		Expr * expr; 
};

class FormaList {
	public:
		FormaList(
			Type * t, Pointer * p, Array * a, FormalRest *f) { 
				type = t; pointer = p; array = a; fr = f;
		}
		Type * type; Pointer * pointer; Array * array; FormalRest *fr; 
};

class FormalRest { 
	public: 
		FormalRest(FormaList * f) { fl = f; }
		FormaList * fl;
};

class IdListAux { 
	public: 
		IdListAux(IdList * i) { il = i;}
		IdList * il; 
};

class ExprListTailAux : Expr { 
	public:
		ExprListTailAux(ExprListTail * e) { elt = e; } 
		ExprListTail * elt; 
};

class ExprListTail : Expr { 
	public: 
		ExprListTail(Expr * e, ExprListTailAux * el) { expr = e; elt = el; }
		Expr * expr; ExprListTailAux * elt; 
};

class ExprList : Expr { 
	public: 
		ExprList(ExprListTail * e) { elt = e; }
		ExprListTail * elt; 
};


class TypeDecl { 
	public:
		TypeDecl( Type * t, IdList * il,  VarDecl * v, Identifier * i) {
			type = t;
			vd = v;
			id = i;
			idL = il; 
		}
		Type * type; Identifier * id; VarDecl * vd; IdList * idL;
};

class Program { 
    public: 
		Program(TypeDecl* t,Program * p){ td = t; prog = p;}
		Program(FunctionOrVarDecl * f) { fov = f; }
		TypeDecl* td; FunctionOrVarDecl * fov; Program * prog;
};

class FunctionOrVarDecl { 
	public: 
		FunctionOrVarDecl(
    		Type* t, Pointer * p, Identifier* i, ProgramL* pl, Program * prog){
			type = t;
			pointer = p;
			id = i;
			programl= pl;
			program= prog;
		}
		Type* type; Pointer* pointer; Identifier* id; ProgramL* programl; Program * program;
};

#endif // AST_H
