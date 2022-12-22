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

class Pointer { 
	public: 
		Pointer(){};
		int asterisk_token = asterisk;
};

class ProgramL { 
	public: 
		ProgramL(Array * a, IdList * id) { array = a; idL = id; }
		ProgramL(FormaList* f, Stmtl* s) { fl = f; sl = s; }
		Array * array; IdList * idL; FormaList* fl; Stmtl* sl;
};

class Array { 
	public:
		Array(Array * a, unsigned int s) { array = a; size =s; }
		unsigned int size; Array * array;
};

class IdList { 
	public:
		IdList(Identifier ** l, unsigned int s) { list = l; size =s; }
		Identifier ** list; unsigned int size;
};

class Type { public: Type(){};};


class Num : Type { public: Num(){};};

class LongType : Type { 
	public: 
		LongType(long v){ value = v; } 
		long value; 
};

class IntType : Num { 
	public:
		IntType(int v){ value = v; } 
		int value; 
};

class FloatType : Num { 
	public:
		FloatType(float v){ value = v; }
		float value; 
};

class BoolType : Type { 
	public:
		BoolType(bool v){ value = v; }
		bool value; 
};

class CharType : Type { 
	public:
		CharType(char v){ value = v; }
		char value; 
};

class DoubleType : Type { 
	public:
		DoubleType(double v){ value = v; }
		double value; 
};

class Identifier { 
	public:
		Identifier(char * nome) { token_name = nome; } 
		char * token_name; 
};

class VarDecl { 
	public:
		VarDecl(Type * t, Identifier * i) { type = t; id = i; }
		Type * type; Identifier * id;
};

class Expr {};

class Stmt {};

class Break : Stmt {  };

class Throw : Stmt {  };

class Else : Stmt { 
	public: 
		Else(Stmt * s) { stmt = s; }
		Stmt * stmt;
};

class If : Stmt { 
	public: 
		If(Expr * ex, Stmt * s, Else * e) { expr = ex; stmt = s; el = e; }
		Expr * expr; Stmt * stmt; Else * el;
};

class While : Stmt { 
	public: 
		While (Expr * ex, Stmt * s) { stmt = s; expr = ex; }
		Expr * expr; Stmt * stmt;
}; 

class CaseBlock { 
	public: 
		CaseBlock(IntType ** i, unsigned int s) { cl = i; size = s; }
		IntType ** cl; unsigned int size; 
};

class Switch : Stmt { 
	public: 
		Switch(Expr * ex, CaseBlock * c) { expr = ex; cb = c; }
		Expr * expr; CaseBlock * cb;
};

class Return : Stmt { 
	public: 
		Return(Expr * ex) { expr = ex; }
		Expr * expr;
};

class Try : Stmt { 
	public: 
		Try(Stmt * tS, Stmt * cS, Stmt * cB) { tryStmt = tS; catchStmt = cS; catchBlock = cB; }
		Stmt * tryStmt; Stmt * catchStmt; Stmt * catchBlock;
};

class Print : Stmt {
	public: 
		Print(ExprList * e) { el = e; } 
		ExprList * el; 
};

class Readln : Stmt { 
	public:
		Readln(Expr * ex) { expr = ex; } 
		Expr *expr;
};

class StmtFatId : Stmt { 
	public: 
		StmtFatId(Type * t, FatId * f) { type = t; fI = f;}
		Type * type; FatId * fI; 
};

class Stmtl : Stmt { 
	public:
		Stmtl(Stmt * s, Stmtl * sl) { stmt = s; stmtl = sl; } 
		Stmt * stmt; Stmtl * stmtl; 
};

class FatId {};

class FatId1 {};

class CallFunction: FatId { 
	public: 
		CallFunction(ExprList * e) { el = e; }
		ExprList * el; 
};

class FatIdIdList : FatId { 
	public: 
		FatIdIdList(IdList * i){ il = i;}
		IdList * il; 
};

class FatIdFatId1 : FatId { 
	public:
		FatIdFatId1(FatId1 * f){ fI = f; }
		FatId1 * fI; 
};

class DotFatId1 : FatId1 { 
	public: 
		DotFatId1(Expr * ex) { expr = ex; }
		Expr * expr; 
};

class ArrowFatId1 : FatId1 { 
	public: 
		ArrowFatId1(Expr * ex) { expr = ex; } 
		Expr * expr; 
};

class AmpersandFatId1 : FatId1 { 
	public:
	 	AmpersandFatId1(Expr * ex){ expr = ex; }
		Expr * expr; 
};

class AssingmentFatId1 : FatId1 { 
	public: 
		AssingmentFatId1(Expr * ex){ expr = ex; }
		Expr * expr; 
};

class BracketFatId1 : FatId1 { 
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

class F : Expr {
	public: 
		F(Expr * ex) { expr = ex; }
		Expr * expr; 
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
