#ifndef BC34D1E5_751D_42A4_B2B3_C7545FE1A533
#define BC34D1E5_751D_42A4_B2B3_C7545FE1A533
#include "AST.h"
#include <cstdio>

class Visitor {
public:
   virtual ~Visitor() = default;
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
   virtual void visit(DoubleType *n) = 0;
	virtual void visit(Int *n) = 0;
	virtual void visit(Float *n) = 0;
};

// Accepts definitions -------------------------------------------------------
class Interpreter: public Visitor {
private:
	int height;
	void lvl_next();
	void lvl_prev();
   void print(char *s);
public:
	Interpreter();
   void visit(PlusExp *n) override;
	void visit(MinusExp *n) override;
	void visit(TimesExp *n) override;
	void visit(DivideExp *n) override;
	void visit(EqualsExp *n) override;
	void visit(DifferentExp *n) override;
	void visit(LowerExp *n) override;
	void visit(GraterExp *n) override;
	void visit(LowerEqualExp *n) override;
	void visit(GraterEqualExp *n) override;
	void visit(AndExp *n) override;
	void visit(OrExp *n) override;
	void visit(RemainderExp *n) override;
	void visit(AndBitABitExp *n) override;
	void visit(OrBitABitExp *n) override;
	void visit(IntergerLiteral *n) override;
	void visit(ExprListTailAux *n) override;
	void visit(CaseBlock *n) override;
	void visit(DotFatId1 *n) override;
	void visit(ArrowFatId1 *n) override;
	void visit(AmpersandFatId1 *n) override;
	void visit(AssingmentFatId1 *n) override;
	void visit(BracketFatId1 *n) override;
	void visit(CallFunction *n) override;
	void visit(FatIdIdList *n) override;
	void visit(FatIdFatId1 *n) override;
	void visit(Else *n) override;
	void visit(While *n) override;
	void visit(Switch *n) override;
	void visit(Break *n) override;
	void visit(Braces *n) override;
	void visit(Print *n) override;
	void visit(Readln *n) override;
	void visit(Return *n) override;
	void visit(Throw *n) override;
	void visit(Try *n) override;
	void visit(If *n) override;
	void visit(StmtFatId *n) override;
	void visit(Stmtl *n) override;
	void visit(Array *n) override;
   void visit(IntType *n) override;
   void visit(FloatType *n) override;
   void visit(LongType *n) override;
   void visit(BoolType *n) override;
   void visit(CharType *n) override;
   void visit(DoubleType *n) override;
   void visit(Pointer *n) override;
   void visit(FormalRest *n) override;
   void visit(FormaList *n) override;
   void visit(VarDecl *n) override;
   void visit(TypeDecl *n) override;
   void visit(FunctionOrVarDecl *n) override;
   void visit(Program *n) override;
   void visit(ProgramL *n) override;
   void visit(F *n) override;
   void visit(ExprList *n) override;
   void visit(ExprListTail *n) override;
   void visit(IdListAux *n) override;
   void visit(FatId1 *n) override;
   void visit(Stmt *n) override;
   void visit(Expr *n) override;
   void visit(Identifier *n) override;
   void visit(Num *n) override;
   void visit(Type *n) override;
   void visit(IdList*n) override;
   void visit(FatId *n) override;
	void visit(Int *n) override;
	void visit(Float *n) override;
};

#endif /* BC34D1E5_751D_42A4_B2B3_C7545FE1A533 */
