#ifndef AST_H
#define AST_H

#include <cstdio>
#include "lexic.h"

class Program;
class Expr;
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
class IdList;
class Stmtl;
class Visitor;
class IdListAux;

class Node { public: virtual void accept(Visitor *v) = 0; };

class Pointer: public Node { 
	public: 
		Pointer(){};
		int asterisk_token = asterisk;
		void accept(Visitor *v);
};

class ProgramL: public Node { 
	public: 
		ProgramL(Array * a, IdListAux * id) { array = a; idL = id; }
		ProgramL(FormaList* f, Stmtl* s) { fl = f; sl = s; }
		Array * array; IdListAux * idL; FormaList* fl; Stmtl* sl;
		void accept(Visitor *v);
};

// IdList ::= Pointer id Array IdList'
class IdList: public Node { 
	public:
		IdList(Pointer* p, Identifier * i, Array * a, IdListAux * il) { pointer = p; id = i; array = a; idl = il; }
		Pointer* pointer; Identifier * id; Array * array; IdListAux * idl;
		void accept(Visitor *v);
};

class Expr: public Node { 
	public: 
		Expr(){};
		Expr(Expr* e1, Expr * e2) { ex1 = e1; ex2 = e2; }
		Expr* ex1; Expr * ex2;
		void accept(Visitor *v);
};

class F : public Expr { public: F(){}; void accept(Visitor *v);};

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

class Array: public Node { 
	public:
		Array(Int * i, Array * a) { array = a; n = i; }
		Array * array; Int * n;
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

class Type: public Node { public: Type(){};void accept(Visitor *v);};

class LongType : public Type { public: LongType(){};void accept(Visitor *v);};

class IntType : public Type { public: IntType(){}; void accept(Visitor *v);};

class FloatType : public Type { public: FloatType(){}; void accept(Visitor *v);};

class BoolType : public Type { public: BoolType(){}; void accept(Visitor *v);};

class CharType : public Type { public: CharType(){}; void accept(Visitor *v);};

class DoubleType : public Type { public: DoubleType(){}; void accept(Visitor *v);};

class Identifier :public Type { 
	public: 
		Identifier(char * nome) { token_name = nome; } 
		char * token_name; 
		void accept(Visitor *v);
};

class VarDecl: public Node { 
	public: 
		VarDecl(Type * t, IdList * i, VarDecl * v) { type = t; idl = i; vd = v; }
		Type * type; IdList * idl; VarDecl * vd;
		void accept(Visitor *v);
};

class Stmt: public Node { public: Stmt(){};void accept(Visitor *v);};

class Break : public Stmt { public: void accept(Visitor *v); };

class Throw : public Stmt { public: void accept(Visitor *v); };

class Else : public Stmt { 
	public: 
		Else(Stmt * s) { stmt = s; }
		Stmt * stmt;
		void accept(Visitor *v);
};

class If : public Stmt { 
	public: 
		If(Expr * ex, Stmt * s, Else * e) { expr = ex; stmt = s; el = e; }
		Expr * expr; Stmt * stmt; Else * el;
		void accept(Visitor *v);
};

class While : public Stmt { 
	public: 
		While (Expr * ex, Stmt * s) { stmt = s; expr = ex; }
		Expr * expr; Stmt * stmt;
		void accept(Visitor *v);
}; 

class CaseBlock: public Node { 
	public: 
		CaseBlock(Int * i, Stmtl * s, CaseBlock * c) { cl = i; sl = s; cb = c; }
		Int * cl; Stmtl * sl; CaseBlock * cb; 
		void accept(Visitor *v);
};

class Switch : public Stmt { 
	public: 
		Switch(Expr * ex, CaseBlock * c) { expr = ex; cb = c; }
		Expr * expr; CaseBlock * cb;
		void accept(Visitor *v);
};

class Return : public Stmt { 
	public: 
		Return(Expr * ex) { expr = ex; }
		Expr * expr;
		void accept(Visitor *v);
};

class Try : public Stmt { 
	public: 
		Try(Stmt * tS, Stmt * cS, Stmt * cB) { tryStmt = tS; catchStmt = cS; catchBlock = cB; }
		Stmt * tryStmt; Stmt * catchStmt; Stmt * catchBlock;
		void accept(Visitor *v);
};

class Braces : Stmt {
	public:
		Braces() {};
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

class StmtFatId : public Stmt { 
	public: 
		StmtFatId(Type * t, FatId * f) { type = t; fI = f;}
		Type * type; FatId * fI; 
		void accept(Visitor *v);
};

class Stmtl : public Stmt { 
	public:
		Stmtl(Stmt * s, Stmtl * sl) { stmt = s; stmtl = sl; } 
		Stmt * stmt; Stmtl * stmtl; 
		void accept(Visitor *v);
};

class FatId: public Node {public: void accept(Visitor *v);};

class FatId1: public Node {public: void accept(Visitor *v);};

class CallFunction: public FatId { 
	public: 
		CallFunction(ExprList * e) { el = e; }
		ExprList * el; 
		void accept(Visitor *v);
};

class FatIdIdList : public FatId { 
	public: 
		FatIdIdList(IdList * i){ il = i;}
		IdList * il; 
		void accept(Visitor *v);
};

class FatIdFatId1 : public FatId { 
	public:
		FatIdFatId1(FatId1 * f){ fI = f; }
		FatId1 * fI; 
		void accept(Visitor *v);
};

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

class IdListAux: public Node { 
	public: 
		IdListAux(IdList * i) { il = i;}
		IdList * il; 
		void accept(Visitor *v);
};

class ExprListTailAux : Expr { 
	public:
		ExprListTailAux(ExprListTail * e) { elt = e; } 
		ExprListTail * elt; 
		void accept(Visitor *v);
};

class ExprListTail : Expr { 
	public: 
		ExprListTail(Expr * e, ExprListTailAux * el) { expr = e; elt = el; }
		Expr * expr; ExprListTailAux * elt; 
		void accept(Visitor *v);
};

class ExprList : Expr { 
	public: 
		ExprList(ExprListTail * e) { elt = e; }
		ExprListTail * elt;
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

// x + y
class PlusExp: public Expr {
public:
  Expr *e1, *e2;
  PlusExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x - y
class MinusExp: public Expr {
public:
  Expr *e1, *e2;
  MinusExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x * y
class TimesExp: public Expr {
public:
  Expr *e1, *e2;
  TimesExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x / y
class DivideExp: public Expr {
public:
  Expr *e1, *e2;
  DivideExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x == y
class EqualsExp: public Expr {
public:
  Expr *e1, *e2;
  EqualsExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x != y
class DifferentExp: public Expr {
public:
  Expr *e1, *e2;
  DifferentExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x < y
class LowerExp: public Expr {
public:
  Expr *e1, *e2;
  LowerExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x > y
class GraterExp: public Expr {
public:
  Expr *e1, *e2;
  GraterExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x <= y
class LowerEqualExp: public Expr {
public:
  Expr *e1, *e2;
  LowerEqualExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x >= y
class GraterEqualExp: public Expr {
public:
  Expr *e1, *e2;
  GraterEqualExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x && y
class AndExp: public Expr {
public:
  Expr *e1, *e2;
  AndExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x || y
class OrExp: public Expr {
public:
  Expr *e1, *e2;
  OrExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x % y
class RemainderExp: public Expr {
public:
  Expr *e1, *e2;
  RemainderExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x & y
class AndBitABitExp: public Expr {
public:
  Expr *e1, *e2;
  AndBitABitExp(Expr *a1, Expr *a2);
  void accept(Visitor *v);
};
// x | y
class OrBitABitExp: public Expr {
public:
  	Expr *e1, *e2;
  	OrBitABitExp(Expr *a1, Expr *a2);
  	void accept(Visitor *v);
};
// (int)x
class IntergerLiteral: public Expr {
public:
	char *f0;
	IntergerLiteral(char *n0);
	void accept(Visitor *v);
};

class Visitor {
public:
  virtual void visit(PlusExp *n) = 0;
  virtual void visit(MinusExp *n) = 0;
  virtual void visit(TimesExp *n) = 0;
  virtual void visit(DivideExp *n) = 0;
  virtual void visit(EqualsExp *n) = 0;
  virtual void visit(DifferentExp *n) = 0;
  virtual void visit(LowerExp *n) = 0;
  virtual void visit(GraterExp *n) = 0;
  virtual void visit(LowerEqualExp *n) = 0;
  virtual void visit(GraterEqualExp *n) = 0;
  virtual void visit(AndExp *n) = 0;
  virtual void visit(OrExp *n) = 0;
  virtual void visit(RemainderExp *n) = 0;
  virtual void visit(AndBitABitExp *n) = 0;
  virtual void visit(OrBitABitExp *n) = 0;
  virtual void visit(IntergerLiteral *n) = 0;
  virtual void visit(Program *n) = 0;
  virtual void visit(ProgramL *n) = 0;
  virtual void visit(Pointer *n) = 0;
  virtual void visit(Array *n) = 0;
  virtual void visit(IdList *n) = 0;
  virtual void visit(Type *n) = 0;
  virtual void visit(Num *n) = 0;
  virtual void visit(LongType *n) = 0;
  virtual void visit(IntType *n) = 0;
  virtual void visit(FloatType *n) = 0;
  virtual void visit(BoolType *n) = 0;
  virtual void visit(CharType *n) = 0;
  virtual void visit(Identifier *n) = 0;
  virtual void visit(VarDecl *n) = 0;
  virtual void visit(Expr *n) = 0;
  virtual void visit(Stmt *n) = 0;
  virtual void visit(Break *n) = 0;
  virtual void visit(Throw *n) = 0;
  virtual void visit(Else *n) = 0;
  virtual void visit(If *n) = 0;
  virtual void visit(While *n) = 0;
  virtual void visit(CaseBlock *n) = 0;
  virtual void visit(Switch *n) = 0;
  virtual void visit(Return *n) = 0;
  virtual void visit(Try *n) = 0;
  virtual void visit(Print *n) = 0;
  virtual void visit(Readln *n) = 0;
  virtual void visit(Braces *n) = 0;
  virtual void visit(StmtFatId *n) = 0;
  virtual void visit(Stmtl *n) = 0;
  virtual void visit(FatId *n) = 0;
  virtual void visit(FatId1 *n) = 0;
  virtual void visit(CallFunction *n) = 0;
  virtual void visit(FatIdIdList *n) = 0;
  virtual void visit(FatIdFatId1 *n) = 0;
  virtual void visit(DotFatId1 *n) = 0;
  virtual void visit(ArrowFatId1 *n) = 0;
  virtual void visit(AmpersandFatId1 *n) = 0;
  virtual void visit(AssingmentFatId1 *n) = 0;
  virtual void visit(BracketFatId1 *n) = 0;
  virtual void visit(FormalRest *n) = 0;
  virtual void visit(IdListAux *n) = 0; 
  virtual void visit(ExprListTailAux *n) = 0;
  virtual void visit(ExprListTail *n) = 0;
  virtual void visit(ExprList *n) = 0;
  virtual void visit(F *n) = 0;
  virtual void visit(TypeDecl *n) = 0;
  virtual void visit(FunctionOrVarDecl *n) = 0;
  virtual void visit(FormaList *n) = 0;
};

// Accepts definitions -------------------------------------------------------
class Interpreter: public Visitor {
public:
	Interpreter() {};
	void visit(PlusExp *n) {
		// Desce na árvore
		n->e1->accept(this);
		printf("%s", "+");
		n->e2->accept(this);
		// Sobe na árvore
	};
	void visit(MinusExp *n) {
		n->e1->accept(this);
		printf("%s", "-");
		n->e2->accept(this);
	};
	void visit(TimesExp *n) {
		n->e1->accept(this);
		printf("%s", "*");
		n->e2->accept(this);
	};
	void visit(DivideExp *n) {
		n->e1->accept(this);
		printf("%s", "/"); 
		n->e2->accept(this);
	};
	void visit(EqualsExp *n) {
		n->e1->accept(this);
		printf("%s", "==");
		n->e2->accept(this); 
	};
	void visit(DifferentExp *n) {
		n->e1->accept(this);
		printf("%s", "!=");
		n->e2->accept(this);
	};
	void visit(LowerExp *n) {
		n->e1->accept(this);
		printf("%s", "<");
		n->e2->accept(this);
	};
	void visit(GraterExp *n) {
		n->e1->accept(this);
		printf("%s", ">");
		n->e2->accept(this);
	};
	void visit(LowerEqualExp *n) {
		n->e1->accept(this);
		printf("%s", "<=");
		n->e2->accept(this);
	};
	void visit(GraterEqualExp *n) {
		n->e1->accept(this);
		printf("%s", ">=");
		n->e2->accept(this);
	};
	void visit(AndExp *n) {
		n->e1->accept(this);
		printf("%s", "&&");
		n->e2->accept(this);
	};
	void visit(OrExp *n) {
		n->e1->accept(this);
		printf("%s", "||");
		n->e2->accept(this);
	};
	void visit(RemainderExp *n) {
		n->e1->accept(this);
		printf("%s", "%");
		n->e2->accept(this);
	};
	void visit(AndBitABitExp *n) {
		n->e1->accept(this);
		printf("%s", "&");
		n->e2->accept(this);
	};
	void visit(OrBitABitExp *n) {
		n->e1->accept(this);
		printf("%s", "|");
		n->e2->accept(this);
	};
	void visit(IntergerLiteral *n) {
		printf("%s", n->f0);
	};
	
	void visit(ExprListTailAux *n) {
		printf("%s", ",");
		n->elt->accept(this);
	};
	void visit(CaseBlock *n) {
		printf("%s", "case");
		printf("%s", "num :");
		n->sl->accept(this);
		n->cb->accept(this);
	};
	void visit(DotFatId1 *n) {
		printf("%s", "dot");
		n->expr->accept(this);
	};
	void visit(ArrowFatId1 *n) {
		printf("%s", "arrow");
		n->expr->accept(this);
	};
	void visit(AmpersandFatId1 *n) {
		printf("%s", "&");
		n->expr->accept(this);
	};
	void visit(AssingmentFatId1 *n) {
		printf("%s", "=");
		n->expr->accept(this);
	};
	void visit(BracketFatId1 *n) {
		printf("%s", "[");
		n->expr->accept(this);
		printf("%s", "]");
		printf("%s", ";");
	};
	void visit(CallFunction *n) {
		printf("%s", "(");
		n->el->accept(this);
		printf("%s", ")");
		printf("%s", ";");
	};
	void visit(FatIdIdList *n) {
		n->il->accept(this);
		printf("%s", ";");
	};
	void visit(FatIdFatId1 *n) {
		n->fI->accept(this);
		printf("%s", ";");
	};
	void visit(Else *n) {
		printf("%s", "else");
		n->stmt->accept(this);
	};
	void visit(While *n) {
		printf("%s", "while");
		printf("%s", "(");
		n->expr->accept(this);
		printf("%s", ")");
		n->stmt->accept(this);
	}
	void visit(Switch *n) {
		printf("%s", "switch");
		printf("%s", "(");
		n->expr->accept(this);
		printf("%s", ")");
		n->cb->accept(this);
	};
	void visit(Break *n) {
		printf("%s", "break");
		printf("%s", ";");
	};
	void visit(Braces *n) {
		printf("%s", "{");
		n->stmtl->accept(this);
		printf("%s", "}");
		printf("%s", ";");
	};
	void visit(Print *n) {
		printf("%s", "print");
		printf("%s", "(");
		n->el->accept(this);
		printf("%s", ")");
		printf("%s", ";");
	};
	void visit(Readln *n) {
		printf("%s", "readln");
		printf("%s", "(");
		n->expr->accept(this);
		printf("%s", ")");
	};
	void visit(Return *n) {
		printf("%s", "return");
		printf("%s", "(");
		n->expr->accept(this);
		printf("%s", ")");
		printf("%s", ";");
	};
	void visit(Throw *n) {
		printf("%s", "throw");
		printf("%s", ";");
	};
	void visit(Try *n) {
		printf("%s", "try");
		n->tryStmt->accept(this);
		printf("%s", "catch");
		printf("%s", "(");
		n->catchStmt->accept(this);
		printf("%s", ")");
		n->catchBlock->accept(this);
	};
	void visit(If *n) {
		printf("%s", "if");
		printf("%s", "(");
		n->expr->accept(this);
		printf("%s", ")");
		n->stmt->accept(this);
		n->el->accept(this);
	};
	void visit(StmtFatId *n) {
		n->type->accept(this);
		n->fI->accept(this);
	};
	void visit(Stmtl *n) {
		n->stmt->accept(this);
		n->stmtl->accept(this);
	};
	void visit(Array *n) {
		printf("%s", "[");
		printf("%s", "num");
		printf("%s", "]");
		n->array->accept(this);
	};
  void visit(IntType *n) {
    printf("%s", "int");
  };
  void visit(FloatType *n) {
    printf("%s", "float");
  };
  void visit(LongType *n) {
    printf("%s", "long");
  };
  void visit(BoolType *n) {
    printf("%s", "bool");
  };
  void visit(CharType *n) {
    printf("%s", "char");
  };
  void visit(DoubleType *n) {
    printf("%s", "double");
  };
  void visit(Pointer *n) {
    printf("%s", "*");
  };
  void visit(FormalRest *n) {
    printf("%s", ",");
    n->fl->accept(this);
  };
  void visit(FormaList *n) {
    n->type->accept(this);
    n->pointer->accept(this);
    printf("%s", "id");
    n->array->accept(this);
    n->fr->accept(this);
  };
  void visit(VarDecl *n) {
    //n->type->accept(this);
    //n->idl->accept(this);
    printf("%s", ";");
    //n->vd->accept(this);
  };
  void visit(TypeDecl *n) {
    printf("%s", "typedef");
    printf("%s", "struct");
    printf("%s", "{");
    n->type->accept(this);
    n->idL->accept(this);
    printf("%s", ";");
    n->vd->accept(this);
    printf("%s", "}");
    n->id->accept(this);
    printf("%s", ";");
    //n->typeDecl->accept(this);
  };
  void visit(FunctionOrVarDecl *n) {
    n->type->accept(this);
    n->pointer->accept(this);
    n->id->accept(this);
    n->programl->accept(this);
    n->program->accept(this);
  };
  void visit(Program *n) {
    n->fov->accept(this);
    // Dividir em dois casos?
    n->td->accept(this);
    n->prog->accept(this);
  };
  void visit(ProgramL *n) {
    n->array->accept(this);
    n->idL->accept(this);
    // N teria q separar em 2 visit diferentes para cada caso
    printf("%s", "(");
    n->fl->accept(this);
    printf("%s", ")");
    printf("%s", "{");
    n->sl->accept(this);
    printf("%s", "}");
  }
};

#endif // AST_H
