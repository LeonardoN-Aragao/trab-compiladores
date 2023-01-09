#ifndef BC34D1E5_751D_42A4_B2B3_C7545FE1A533
#define BC34D1E5_751D_42A4_B2B3_C7545FE1A533
#include "AST.h"
#include <cstdio>

class Visitor {
public:
   virtual ~Visitor() = default;
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
   virtual void visit(Identifier_F *n) = 0;
   virtual void visit(VarDecl *n) = 0;
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
   // virtual void visit(CallFunction *n) = 0;
   // virtual void visit(FatIdIdList *n) = 0;
   // virtual void visit(FatIdFatId1 *n) = 0;
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
   virtual void visit(F_Expr *n) = 0;
   virtual void visit(TypeDecl *n) = 0;
   virtual void visit(FunctionOrVarDecl *n) = 0;
   virtual void visit(FormaList *n) = 0;
   virtual void visit(DoubleType *n) = 0;
	virtual void visit(Int *n) = 0;
	virtual void visit(Float *n) = 0;
	virtual void visit(Expr *n) = 0;
	virtual void visit(ExprAux *n) = 0;
   virtual void visit(Expr2 *n) = 0;
	virtual void visit(Expr2Aux *n) = 0;
	virtual void visit(Expr3 *n) = 0;
	virtual void visit(Expr3Aux *n) = 0;
	virtual void visit(Expr4 *n) = 0;
	virtual void visit(Expr4Aux *n) = 0;
	virtual void visit(Expr5 *n) = 0;
	virtual void visit(Expr5Aux *n) = 0;
	virtual void visit(Expr6 *n) = 0;
	virtual void visit(Expr6Aux *n) = 0;
	virtual void visit(Expr7 *n) = 0;
	virtual void visit(Expr7Aux *n) = 0;
	virtual void visit(Expr8 *n) = 0;
	virtual void visit(Expr8Aux *n) = 0;
	virtual void visit(Expr9 *n) = 0;
	virtual void visit(Expr9Aux *n) = 0;	
};

// Accepts definitions -------------------------------------------------------
class Interpreter: public Visitor {
private:
	int height;
	void lvl_next() {this->height++;};
	void lvl_prev() {this->height--;};
   void print(char *s) {
      for(int i=0; i<this->height; i++) {
         printf(" ");
      }
      printf("%s\n", s);
   };
   void print(int s) {
      for(int i=0; i<this->height; i++) {
         printf(" ");
      }
      printf("%d\n", s);
   };
   void print(float s) {
      for(int i=0; i<this->height; i++) {
         printf(" ");
      }
      printf("%f\n", s);
   };
public:
	Interpreter() { this->height=0; };
	void visit(ExprListTailAux *n) override;
	void visit(CaseBlock *n) override;
	void visit(DotFatId1 *n) override;
	void visit(ArrowFatId1 *n) override;
	void visit(AmpersandFatId1 *n) override;
	void visit(AssingmentFatId1 *n) override;
	void visit(BracketFatId1 *n) override;
	// void visit(CallFunction *n) override;
	// void visit(FatIdIdList *n) override;
	// void visit(FatIdFatId1 *n) override;
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
   void visit(F_Expr *n) override;
   void visit(ExprList *n) override;
   void visit(ExprListTail *n) override;
   void visit(IdListAux *n) override;
   void visit(FatId1 *n) override;
   void visit(Stmt *n) override;
   void visit(Identifier *n) override;
   void visit(Identifier_F *n) override;
   void visit(Num *n) override;
   void visit(Type *n) override;
   void visit(IdList*n) override;
   void visit(FatId *n) override;
	void visit(Int *n) override;
	void visit(Float *n) override;
	void visit(Expr *n) override;
	void visit(ExprAux *n) override;
	void visit(Expr2 *n) override;
	void visit(Expr2Aux *n) override;
	void visit(Expr3 *n) override;
	void visit(Expr3Aux *n) override;
	void visit(Expr4 *n) override;
	void visit(Expr4Aux *n) override;
	void visit(Expr5 *n) override;
	void visit(Expr5Aux *n) override;
	void visit(Expr6 *n) override;
	void visit(Expr6Aux *n) override;
	void visit(Expr7 *n) override;
	void visit(Expr7Aux *n) override;
	void visit(Expr8 *n) override;
	void visit(Expr8Aux *n) override;
	void visit(Expr9 *n) override;
	void visit(Expr9Aux *n) override;
};

#endif /* BC34D1E5_751D_42A4_B2B3_C7545FE1A533 */
