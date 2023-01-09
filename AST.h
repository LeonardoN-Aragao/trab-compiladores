#ifndef AST_H
#define AST_H

#include <cstdio>
#include "lexic.h"

class Visitor;
// Nodes
class Program;
class FunctionOrVarDecl;
class ProgramL;
class TypeDecl;
class VarDecl;
class Type;
class Pointer;
class FormaList;
class FormalRest;
class Array;
class IdList;
class IdListAux;
class Stmtl;
class Stmt;
class Else;
class FatId;
class FatId1;
class CaseBlock;
class ExprList;
class ExprListTail;
class ExprListTailAux;
class Expr;
class ExprAux;
class Expr2;
class Expr2Aux;
class Expr3;
class Expr3Aux;
class Expr3;
class Expr3Aux;
class Expr4;
class Expr4Aux;
class Expr5;
class Expr5Aux;
class Expr6;
class Expr6Aux;
class Expr7;
class Expr7Aux;
class Expr8;
class Expr8Aux;
class Expr9;
class Expr9Aux;
class F;
// Subnodes
class Identifier;
class Int;
class Float;

class Node { public: virtual void accept(Visitor *v) = 0; };

class Program: public Node { 
    public: 
		Program(TypeDecl* t,Program * p){ td = t; prog = p;}
		Program(FunctionOrVarDecl * f) { fov = f; }
		TypeDecl* td; FunctionOrVarDecl * fov; Program * prog;
		void accept(Visitor *v);
};

class FunctionOrVarDecl: public Node { 
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
		void accept(Visitor *v);
};

class ProgramL: public Node { 
	public: 
		ProgramL(Array * a, IdListAux * id) { array = a; idL = id; }
		ProgramL(FormaList* f, Stmtl* s) { fl = f; sl = s; }
		Array * array; IdListAux * idL; FormaList* fl; Stmtl* sl;
		void accept(Visitor *v);
};

class TypeDecl: public Node { 
	public:
		TypeDecl( Type * t, IdList * il,  VarDecl * v, Identifier * i) {
			type = t;
			vd = v;
			id = i;
			idL = il; 
		}
		Type * type; Identifier * id; VarDecl * vd; IdList * idL;
		void accept(Visitor *v);
};

class VarDecl: public Node { 
	public: 
		VarDecl(Type * t, IdList * i, VarDecl * v) { type = t; idl = i; vd = v; }
		Type * type; IdList * idl; VarDecl * vd;
		void accept(Visitor *v);
};

class Type: public Node { public: Type(){};void accept(Visitor *v); };

class LongType : public Type { public: LongType(){};void accept(Visitor *v); };

class IntType : public Type { public: IntType(){}; void accept(Visitor *v); };

class FloatType : public Type { public: FloatType(){}; void accept(Visitor *v); };

class BoolType : public Type { public: BoolType(){}; void accept(Visitor *v); };

class CharType : public Type { public: CharType(){}; void accept(Visitor *v); };

class DoubleType : public Type { public: DoubleType(){}; void accept(Visitor *v); };

class Identifier :public Type {
public: 
	char * token_name; void accept(Visitor *v);
	Identifier(char * nome) { token_name = nome; } 
};

class Pointer: public Node { 
	public: 
		Pointer(){};
		int asterisk_token = asterisk;
		void accept(Visitor *v);
};

class FormaList: public Node {
	public:
		FormaList(
			Type * t, Pointer * p, Array * a, FormalRest *f) { 
				type = t; pointer = p; array = a; fr = f;
		}
		Type * type; Pointer * pointer; Array * array; FormalRest *fr; 
		void accept(Visitor *v);
};

class FormalRest: public Node { 
	public: 
		FormalRest(FormaList * f) { fl = f; }
		FormaList * fl;
		void accept(Visitor *v);
};

class Array: public Node { 
	public:
		Array(Int * i, Array * a) { array = a; n = i; }
		Array * array; Int * n;
		void accept(Visitor *v);
};

class IdList: public Node { 
	public:
		IdList(Pointer* p, Identifier * i, Array * a, IdListAux * il) { pointer = p; id = i; array = a; idl = il; }
		Pointer* pointer; Identifier * id; Array * array; IdListAux * idl;
		void accept(Visitor *v);
};

class IdListAux: public Node { 
	public: 
		IdListAux(IdList * i) { il = i;}
		IdList * il; 
		void accept(Visitor *v);
};

class Stmtl : public Node { 
	public:
		Stmtl(Stmt * s, Stmtl * sl) { stmt = s; stmtl = sl; } 
		Stmt * stmt; Stmtl * stmtl; 
		void accept(Visitor *v);
};

class Stmt: public Node { public: Stmt(){};void accept(Visitor *v);};

class While : public Stmt { 
	public: 
		While (Expr * ex, Stmt * s) { stmt = s; expr = ex; }
		Expr * expr; Stmt * stmt;
		void accept(Visitor *v);
}; 

class Switch : public Stmt { 
	public: 
		Switch(Expr * ex, CaseBlock * c) { expr = ex; cb = c; }
		Expr * expr; CaseBlock * cb;
		void accept(Visitor *v);
};

class Break : public Stmt { public: void accept(Visitor *v); };

class Braces: public Stmt {
	public:
		Braces(Stmtl *sl) { stmtl = sl; };
		Stmtl *stmtl;
		void accept(Visitor *v);
};

class Print : public Stmt {
	public: 
		Print(ExprList * e) { el = e; } 
		ExprList * el; 
		void accept(Visitor *v);
};

class Readln : public Stmt { 
	public:
		Readln(Expr * ex) { expr = ex; } 
		Expr *expr;
		void accept(Visitor *v);
};

class Return : public Stmt { 
	public: 
		Return(Expr * ex) { expr = ex; }
		Expr * expr;
		void accept(Visitor *v);
};

class Throw : public Stmt { public: void accept(Visitor *v); };

class Try : public Stmt { 
	public: 
		Try(Stmt * tS, Stmt * cS, Stmt * cB) { tryStmt = tS; catchStmt = cS; catchBlock = cB; }
		Stmt * tryStmt; Stmt * catchStmt; Stmt * catchBlock;
		void accept(Visitor *v);
};

class If : public Stmt { 
	public: 
		If(Expr * ex, Stmt * s, Else * e) { expr = ex; stmt = s; el = e; }
		Expr * expr; Stmt * stmt; Else * el;
		void accept(Visitor *v);
};

class StmtFatId : public Stmt { 
	public: 
		StmtFatId(Type * t, FatId * f) { type = t; fI = f;}
		Type * type; FatId * fI; 
		void accept(Visitor *v);
};

class Else : public Node { 
	public: 
		Else(Stmt * s) { stmt = s; }
		Stmt * stmt;
		void accept(Visitor *v);
};

class FatId: public Node {
public:
	ExprList *el; IdList *idl; FatId1 *fi1;
	FatId(ExprList *el) { this->el = el; };
	FatId(IdList *idl) { this->idl = idl; };
	FatId(FatId1 *fi1) { this->fi1 = fi1; };
	void accept(Visitor *v);
};

// class CallFunction: public FatId { 
// 	public: 
// 		CallFunction(ExprList * e) { el = e; }
// 		ExprList * el; 
// 		void accept(Visitor *v);
// };

// class FatIdIdList : public FatId { 
// 	public: 
// 		FatIdIdList(IdList * i){ il = i;}
// 		IdList * il; 
// 		void accept(Visitor *v);
// };

// class FatIdFatId1 : public FatId { 
// 	public:
// 		FatIdFatId1(FatId1 * f){ fI = f; }
// 		FatId1 * fI; 
// 		void accept(Visitor *v);
// };

class FatId1: public Node {public:  void accept(Visitor *v); };

class DotFatId1 : public FatId1 { 
	public: 
		DotFatId1(Expr * ex) { expr = ex; }
		Expr * expr;
		void accept(Visitor *v);
};

class ArrowFatId1 : public FatId1 { 
	public: 
		ArrowFatId1(Expr * ex) { expr = ex; } 
		Expr * expr; 
		void accept(Visitor *v);
};

class AmpersandFatId1 : public FatId1 { 
	public:
	 	AmpersandFatId1(Expr * ex){ expr = ex; }
		Expr * expr; 
		void accept(Visitor *v);
};

class AssingmentFatId1 : public FatId1 { 
	public: 
		AssingmentFatId1(Expr * ex){ expr = ex; }
		Expr * expr; 
		void accept(Visitor *v);
};

class BracketFatId1 : public FatId1 { 
	public: 
		BracketFatId1(Expr * ex){ expr = ex; }
		Expr * expr; 
		void accept(Visitor *v);
};


class CaseBlock: public Node { 
	public: 
		CaseBlock(Int * i, Stmtl * s, CaseBlock * c) { cl = i; sl = s; cb = c; }
		Int * cl; Stmtl * sl; CaseBlock * cb; 
		void accept(Visitor *v);
};

class ExprList: public Node { 
	public: 
		ExprList(ExprListTail * e) { elt = e; }
		ExprListTail * elt;
		void accept(Visitor *v);
};

class ExprListTail: public Node { 
	public: 
		ExprListTail(Expr * e, ExprListTailAux * el) { expr = e; elt = el; }
		Expr * expr; ExprListTailAux * elt; 
		void accept(Visitor *v);
};

class ExprListTailAux: public Node { 
	public:
		ExprListTailAux(ExprListTail * e) { elt = e; } 
		ExprListTail * elt; 
		void accept(Visitor *v);
};

class Expr: public Node { 
public: 
	Expr2* ex1;	ExprAux * ex2;
	Expr(Expr2* e1, ExprAux * e2) {
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class ExprAux: public Node { 
public: 
	Expr2* ex1;	ExprAux * ex2;
	ExprAux(Expr2* e1, ExprAux * e2) {
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr2: public Node { 
public: 
	Expr3* ex1; Expr2Aux * ex2;
	Expr2(Expr3* e1, Expr2Aux * e2) {
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr2Aux: public Node { 
public: 
	Expr3* ex1;	Expr2Aux * ex2;
	Expr2Aux(Expr3* e1, Expr2Aux * e2) {
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr3: public Node { 
public: 
	Expr4* ex1; Expr3Aux * ex2;
	Expr3(Expr4* e1, Expr3Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr3Aux: public Node { 
public: 
	Expr4* ex1; Expr3Aux * ex2;
	Expr3Aux(Expr4* e1, Expr3Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr4: public Node { 
public: 
	Expr5* ex1; Expr4Aux * ex2;
	Expr4(Expr5* e1, Expr4Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr4Aux: public Node { 
public: 
	Expr5* ex1; Expr4Aux * ex2;
	Expr4Aux(Expr5* e1, Expr4Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr5: public Node { 
public: 
	Expr6* ex1; Expr5Aux * ex2;
	Expr5(Expr6* e1, Expr5Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr5Aux: public Node { 
public: 
	Expr6* ex1; Expr5Aux * ex2;
	Expr5Aux(Expr6* e1, Expr5Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr6: public Node { 
public: 
	Expr7* ex1; Expr6Aux * ex2;
	Expr6(Expr7* e1, Expr6Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr6Aux: public Node { 
public: 
	Expr7* ex1; Expr6Aux * ex2;
	Expr6Aux(Expr7* e1, Expr6Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr7: public Node { 
public: 
	Expr8* ex1; Expr7Aux * ex2;
	Expr7(Expr8* e1, Expr7Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr7Aux: public Node { 
public: 
	Expr8* ex1; Expr7Aux * ex2;
	Expr7Aux(Expr8* e1, Expr7Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr8: public Node { 
public: 
	Expr9* ex1; Expr8Aux * ex2;
	Expr8(Expr9* e1, Expr8Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr8Aux: public Node { 
public: 
	Expr9* ex1; Expr8Aux * ex2;
	Expr8Aux(Expr9* e1, Expr8Aux * e2) { 
		this->ex1 = e1;
		this->ex2 = e2;
	};
	void accept(Visitor *v);
};

class Expr9: public Node { 
public: 
	F* f; Expr9Aux * e;
	Expr9(F* f, Expr9Aux * e) {
		this->f = f; this->e = e;
	};
	void accept(Visitor *v);
};

class Expr9Aux: public Node { 
public:
	Expr9* ex1; const char *v;
	Expr9Aux() {};
	Expr9Aux(Expr9* e, const char *v) {
		this->ex1 = e;
		this->v = v;
	};
	void accept(Visitor *v);
};

class F : public Node { public: F(){}; void accept(Visitor *v);};

class F_Expr : public F {
	public: 
		F_Expr(Expr * ex) { expr = ex; }
		Expr * expr; 
		void accept(Visitor *v);
};

class Num : public F { public: Num(){}; void accept(Visitor *v);};

class True : public F { public: True(){}; void accept(Visitor *v);};

class False : public F { public: False(){}; void accept(Visitor *v);};

class Literal : public F { 
	public:
		Literal(char* v) { value = v; }
		char* value;
		void accept(Visitor *v);
};

class Int : public Num { 
	public:
		Int(int v) { value = v; }
		int value;
		void accept(Visitor *v);
};

class Float : public Num { 
	public:
		Float(float v) { value = v; }
		float value;
		void accept(Visitor *v);
};

class Char : public F {
	public:
		Char(char v) { value = v; }
		char value;
		void accept(Visitor *v);
};

class Bool : public F { 
	public:
		Bool(float v) { value = v; }
		float value;
		void accept(Visitor *v);
};

class Long : public F { 
	public:
		Long(long v) { value = v; }
		long value;
		void accept(Visitor *v);
};

class Double : public F { 
	public:
		Double(double v) { value = v; }
		double value;
		void accept(Visitor *v);
};

class Identifier_F :public F { 
	public: 
		Identifier_F(char * nome) { token_name = nome; } 
		char * token_name; 
		void accept(Visitor *v);
};

#endif // AST_H