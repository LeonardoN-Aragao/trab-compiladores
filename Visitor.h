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
	// void visit(PlusExp *n) {
	// 	// Desce na árvore
	// 	n->e1->accept(this);
	// 	printf("%s", "+");
	// 	n->e2->accept(this);
	// 	// Sobe na árvore
	// };
	// void visit(MinusExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "-");
	// 	n->e2->accept(this);
	// };
	// void visit(TimesExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "*");
	// 	n->e2->accept(this);
	// };
	// void visit(DivideExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "/"); 
	// 	n->e2->accept(this);
	// };
	// void visit(EqualsExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "==");
	// 	n->e2->accept(this); 
	// };
	// void visit(DifferentExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "!=");
	// 	n->e2->accept(this);
	// };
	// void visit(LowerExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "<");
	// 	n->e2->accept(this);
	// };
	// void visit(GraterExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", ">");
	// 	n->e2->accept(this);
	// };
	// void visit(LowerEqualExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "<=");
	// 	n->e2->accept(this);
	// };
	// void visit(GraterEqualExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", ">=");
	// 	n->e2->accept(this);
	// };
	// void visit(AndExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "&&");
	// 	n->e2->accept(this);
	// };
	// void visit(OrExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "||");
	// 	n->e2->accept(this);
	// };
	// void visit(RemainderExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "%");
	// 	n->e2->accept(this);
	// };
	// void visit(AndBitABitExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "&");
	// 	n->e2->accept(this);
	// };
	// void visit(OrBitABitExp *n) {
	// 	n->e1->accept(this);
	// 	printf("%s", "|");
	// 	n->e2->accept(this);
	// };
	// void visit(IntergerLiteral *n) {
	// 	printf("%s", n->f0);
	// };
	
	// void visit(ExprListTailAux *n) {
	// 	printf("%s", ",");
	// 	n->elt->accept(this);
	// };
	// void visit(CaseBlock *n) {
	// 	printf("%s", "case");
	// 	printf("%s", "num :");
	// 	n->sl->accept(this);
	// 	n->cb->accept(this);
	// };
	// void visit(DotFatId1 *n) {
	// 	printf("%s", "dot");
	// 	n->expr->accept(this);
	// };
	// void visit(ArrowFatId1 *n) {
	// 	printf("%s", "arrow");
	// 	n->expr->accept(this);
	// };
	// void visit(AmpersandFatId1 *n) {
	// 	printf("%s", "&");
	// 	n->expr->accept(this);
	// };
	// void visit(AssingmentFatId1 *n) {
	// 	printf("%s", "=");
	// 	n->expr->accept(this);
	// };
	// void visit(BracketFatId1 *n) {
	// 	printf("%s", "[");
	// 	n->expr->accept(this);
	// 	printf("%s", "]");
	// 	printf("%s", ";");
	// };
	// void visit(CallFunction *n) {
	// 	printf("%s", "(");
	// 	n->el->accept(this);
	// 	printf("%s", ")");
	// 	printf("%s", ";");
	// };
	// void visit(FatIdIdList *n) {
	// 	n->il->accept(this);
	// 	printf("%s", ";");
	// };
	// void visit(FatIdFatId1 *n) {
	// 	n->fI->accept(this);
	// 	printf("%s", ";");
	// };
	// void visit(Else *n) {
	// 	printf("%s", "else");
	// 	n->stmt->accept(this);
	// };
	// void visit(While *n) {
	// 	printf("%s", "while");
	// 	printf("%s", "(");
	// 	n->expr->accept(this);
	// 	printf("%s", ")");
	// 	n->stmt->accept(this);
	// }
	// void visit(Switch *n) {
	// 	printf("%s", "switch");
	// 	printf("%s", "(");
	// 	n->expr->accept(this);
	// 	printf("%s", ")");
	// 	n->cb->accept(this);
	// };
	// void visit(Break *n) {
	// 	printf("%s", "break");
	// 	printf("%s", ";");
	// };
	// void visit(Braces *n) {
	// 	printf("%s", "{");
	// 	n->stmtl->accept(this);
	// 	printf("%s", "}");
	// 	printf("%s", ";");
	// };
	// void visit(Print *n) {
	// 	printf("%s", "print");
	// 	printf("%s", "(");
	// 	n->el->accept(this);
	// 	printf("%s", ")");
	// 	printf("%s", ";");
	// };
	// void visit(Readln *n) {
	// 	printf("%s", "readln");
	// 	printf("%s", "(");
	// 	n->expr->accept(this);
	// 	printf("%s", ")");
	// };
	// void visit(Return *n) {
	// 	printf("%s", "return");
	// 	printf("%s", "(");
	// 	n->expr->accept(this);
	// 	printf("%s", ")");
	// 	printf("%s", ";");
	// };
	// void visit(Throw *n) {
	// 	printf("%s", "throw");
	// 	printf("%s", ";");
	// };
	// void visit(Try *n) {
	// 	printf("%s", "try");
	// 	n->tryStmt->accept(this);
	// 	printf("%s", "catch");
	// 	printf("%s", "(");
	// 	n->catchStmt->accept(this);
	// 	printf("%s", ")");
	// 	n->catchBlock->accept(this);
	// };
	// void visit(If *n) {
	// 	printf("%s", "if");
	// 	printf("%s", "(");
	// 	n->expr->accept(this);
	// 	printf("%s", ")");
	// 	n->stmt->accept(this);
	// 	n->el->accept(this);
	// };
	// void visit(StmtFatId *n) {
	// 	n->type->accept(this);
	// 	n->fI->accept(this);
	// };
	// void visit(Stmtl *n) {
	// 	n->stmt->accept(this);
	// 	n->stmtl->accept(this);
	// };
	// void visit(Array *n) {
	// 	printf("%s", "[");
	// 	printf("%s", "num");
	// 	printf("%s", "]");
	// 	n->array->accept(this);
	// };
   // void visit(IntType *n) {
   //    printf("%s", "int");
   // };
   // void visit(FloatType *n) {
   //    printf("%s", "float");
   // };
   // void visit(LongType *n) {
   //    printf("%s", "long");
   // };
   // void visit(BoolType *n) {
   //    printf("%s", "bool");
   // };
   // void visit(CharType *n) {
   //    printf("%s", "char");
   // };
   // void visit(DoubleType *n) {
   //    printf("%s", "double");
   // };
   // void visit(Pointer *n) {
   //    printf("%s", "*");
   // };
   // void visit(FormalRest *n) {
   //    printf("%s", ",");
   //    n->fl->accept(this);
   // };
   // void visit(FormaList *n) {
   //    n->type->accept(this);
   //    n->pointer->accept(this);
   //    printf("%s", "id");
   //    n->array->accept(this);
   //    n->fr->accept(this);
   // };
   // void visit(VarDecl *n) {
   //    //n->type->accept(this);
   //    //n->idl->accept(this);
   //    printf("%s", ";");
   //    //n->vd->accept(this);
   // };
   // void visit(TypeDecl *n) {
   //    printf("%s", "typedef");
   //    printf("%s", "struct");
   //    printf("%s", "{");
   //    n->type->accept(this);
   //    n->idL->accept(this);
   //    printf("%s", ";");
   //    n->vd->accept(this);
   //    printf("%s", "}");
   //    n->id->accept(this);
   //    printf("%s", ";");
   //    //n->typeDecl->accept(this);
   // };
   // void visit(FunctionOrVarDecl *n) {
   //    n->type->accept(this);
   //    n->pointer->accept(this);
   //    n->id->accept(this);
   //    n->programl->accept(this);
   //    n->program->accept(this);
   // };
   // void visit(Program *n) {
   //    n->fov->accept(this);
   //    // Dividir em dois casos?
   //    n->td->accept(this);
   //    n->prog->accept(this);
   // };
   // void visit(ProgramL *n) {
   //    n->array->accept(this);
   //    n->idL->accept(this);
   //    // N teria q separar em 2 visit diferentes para cada caso
   //    printf("%s", "(");
   //    n->fl->accept(this);
   //    printf("%s", ")");
   //    printf("%s", "{");
   //    n->sl->accept(this);
   //    printf("%s", "}");
   // }
};

#endif /* BC34D1E5_751D_42A4_B2B3_C7545FE1A533 */
