#include "Visitor.h"

Interpreter::Interpreter() {altura_tree=0;}
void Interpreter::lvlm() {altura_tree++;}
void Interpreter::lvln() {altura_tree--;}


// Exp
PlusExp::PlusExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void PlusExp::accept(Visitor *v) { v->visit(this); };

MinusExp::MinusExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void MinusExp::accept(Visitor *v) { v->visit(this); };

TimesExp::TimesExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void TimesExp::accept(Visitor *v) { v->visit(this); };

DivideExp::DivideExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void DivideExp::accept(Visitor *v) { v->visit(this); };

EqualsExp::EqualsExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void EqualsExp::accept(Visitor *v) { v->visit(this); };

DifferentExp::DifferentExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void DifferentExp::accept(Visitor *v) { v->visit(this); };

LowerExp::LowerExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void LowerExp::accept(Visitor *v) { v->visit(this); };

GraterExp::GraterExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void GraterExp::accept(Visitor *v) { v->visit(this); };

LowerEqualExp::LowerEqualExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void LowerEqualExp::accept(Visitor *v) { v->visit(this); };

GraterEqualExp::GraterEqualExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void GraterEqualExp::accept(Visitor *v) { v->visit(this); };

AndExp::AndExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void AndExp::accept(Visitor *v) { v->visit(this); };

OrExp::OrExp(Expr *a1, Expr *a2) { this->e1 = a1; this-> e2 = a2; };
void OrExp::accept(Visitor *v) { v->visit(this); };

RemainderExp::RemainderExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void RemainderExp::accept(Visitor *v) { v->visit(this); };

AndBitABitExp::AndBitABitExp(Expr *a1, Expr *a2) { this->e1 = a2; this->e2 = a2; };
void AndBitABitExp::accept(Visitor *v) { v->visit(this); };

OrBitABitExp::OrBitABitExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
void OrBitABitExp::accept(Visitor *v) { v->visit(this); };

IntergerLiteral::IntergerLiteral(char *n0) { this->f0=n0; };
void IntergerLiteral::accept(Visitor *v) { v->visit(this); };

void Pointer::accept(Visitor *v){ v->visit(this); };
void ProgramL::accept(Visitor *v){ v->visit(this); };
void Array::accept(Visitor *v){ v->visit(this); };
void IdList::accept(Visitor *v){ v->visit(this); };
void Type::accept(Visitor *v){ v->visit(this); };
void Num::accept(Visitor *v){ v->visit(this); };
void LongType::accept(Visitor *v){ v->visit(this); };
void IntType::accept(Visitor *v){ v->visit(this); };
void FloatType::accept(Visitor *v){ v->visit(this); };
void BoolType::accept(Visitor *v){ v->visit(this); };
void CharType::accept(Visitor *v){ v->visit(this); };
void DoubleType::accept(Visitor *v){ v->visit(this); };
void Identifier::accept(Visitor *v){ v->visit(this); };
void VarDecl::accept(Visitor *v){ v->visit(this); };
void Stmt::accept(Visitor *v){ v->visit(this); };
void Break::accept(Visitor *v){ v->visit(this); };
void Throw::accept(Visitor *v){ v->visit(this); };
void Else::accept(Visitor *v){ v->visit(this); };
void If::accept(Visitor *v){ v->visit(this); };
void While::accept(Visitor *v){ v->visit(this); };
void CaseBlock::accept(Visitor *v){ v->visit(this); };
void Switch::accept(Visitor *v){ v->visit(this); };
void Return::accept(Visitor *v){ v->visit(this); };
void Try::accept(Visitor *v){ v->visit(this); };
void Print::accept(Visitor *v){ v->visit(this); };
void Readln::accept(Visitor *v){ v->visit(this); };
void StmtFatId::accept(Visitor *v){ v->visit(this); };
void Stmtl::accept(Visitor *v){ v->visit(this); };
void FatId::accept(Visitor *v){ v->visit(this); };
void FatId1::accept(Visitor *v){ v->visit(this); };
void CallFunction::accept(Visitor *v){ v->visit(this); };
void FatIdIdList::accept(Visitor *v){ v->visit(this); };
void FatIdFatId1::accept(Visitor *v){ v->visit(this); };
void DotFatId1::accept(Visitor *v){ v->visit(this); };
void ArrowFatId1::accept(Visitor *v){ v->visit(this); };
void AmpersandFatId1::accept(Visitor *v){ v->visit(this); };
void BracketFatId1::accept(Visitor *v){ v->visit(this); };
void FormaList::accept(Visitor *v){ v->visit(this); };
void FormalRest::accept(Visitor *v){ v->visit(this); };
void IdListAux::accept(Visitor *v){ v->visit(this); };
void ExprListTail::accept(Visitor *v){ v->visit(this); };
void ExprList::accept(Visitor *v){ v->visit(this); };
void F::accept(Visitor *v){ v->visit(this); };
void TypeDecl::accept(Visitor *v){ v->visit(this); };
void Program::accept(Visitor *v){ v->visit(this); };
void FunctionOrVarDecl::accept(Visitor *v){ v->visit(this); };
void Braces::accept(Visitor *v){ v->visit(this); };
void Expr::accept(Visitor *v){ v->visit(this); };
void F_Expr::accept(Visitor *v){ v->visit(this); };
void True::accept(Visitor *v){ v->visit(this); };
void False::accept(Visitor *v){ v->visit(this); };
void Int::accept(Visitor *v){ v->visit(this); };
void Float::accept(Visitor *v){ v->visit(this); };
void Identifier_F::accept(Visitor *v){ v->visit(this); };
void AssingmentFatId1::accept(Visitor *v){ v->visit(this); };
void ExprListTailAux::accept(Visitor *v){ v->visit(this); };
void Literal::accept(Visitor *v){ v->visit(this); };

void Interpreter::visit(PlusExp *n) {
   // Desce na árvore
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "+");
   if(n->e2 != nullptr) n->e2->accept(this);
   // Sobe na árvore
};
void Interpreter::visit(MinusExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "-");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(TimesExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "*");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(DivideExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "/"); 
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(EqualsExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "==");
   if(n->e2 != nullptr) n->e2->accept(this); 
};
void Interpreter::visit(DifferentExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "!=");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(LowerExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "<");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(GraterExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", ">");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(LowerEqualExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "<=");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(GraterEqualExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", ">=");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(AndExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "&&");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(OrExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "||");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(RemainderExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "%");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(AndBitABitExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "&");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(OrBitABitExp *n) {
   if(n->e1 != nullptr) n->e1->accept(this);
   printf("%s", "|");
   if(n->e2 != nullptr) n->e2->accept(this);
};
void Interpreter::visit(IntergerLiteral *n) {
   printf("%s", n->f0);
};

void Interpreter::visit(ExprListTailAux *n) {
   printf("%s", ",");
   if(n->elt != nullptr) n->elt->accept(this);
};
void Interpreter::visit(CaseBlock *n) {
   printf("%s", "case");
   printf("%s", "num :");
   if(n->sl != nullptr) n->sl->accept(this);
   if(n->cb != nullptr) n->cb->accept(this);
};
void Interpreter::visit(DotFatId1 *n) {
   printf("%s", "dot");
   if(n->expr != nullptr) n->expr->accept(this);
};
void Interpreter::visit(ArrowFatId1 *n) {
   printf("%s", "arrow");
   if(n->expr != nullptr) n->expr->accept(this);
};
void Interpreter::visit(AmpersandFatId1 *n) {
   printf("%s", "&");
   if(n->expr != nullptr) n->expr->accept(this);
};
void Interpreter::visit(AssingmentFatId1 *n) {
   printf("%s", "=");
   if(n->expr != nullptr) n->expr->accept(this);
};
void Interpreter::visit(BracketFatId1 *n) {
   printf("%s", "[");
   if(n->expr != nullptr) n->expr->accept(this);
   printf("%s", "]");
   printf("%s", ";");
};
void Interpreter::visit(CallFunction *n) {
   printf("%s", "(");
   if(n->el != nullptr) n->el->accept(this);
   printf("%s", ")");
   printf("%s", ";");
};
void Interpreter::visit(FatIdIdList *n) {
   if(n->il != nullptr) n->il->accept(this);
   printf("%s", ";");
};
void Interpreter::visit(FatIdFatId1 *n) {
   if(n->fI != nullptr) n->fI->accept(this);
   printf("%s", ";");
};
void Interpreter::visit(Else *n) {
   printf("%s", "else");
   if(n->stmt != nullptr) n->stmt->accept(this);
};
void Interpreter::visit(While *n) {
   printf("%s", "while");
   printf("%s", "(");
   if(n->expr != nullptr) n->expr->accept(this);
   printf("%s", ")");
   if(n->stmt != nullptr) n->stmt->accept(this);
}
void Interpreter::visit(Switch *n) {
   printf("%s", "switch");
   printf("%s", "(");
   if(n->expr != nullptr) n->expr->accept(this);
   printf("%s", ")");
   if(n->cb != nullptr) n->cb->accept(this);
};
void Interpreter::visit(Break *n) {
   printf("%s", "break");
   printf("%s", ";");
};
void Interpreter::visit(Braces *n) {
   printf("%s", "{");
   if(n->stmtl != nullptr) n->stmtl->accept(this);
   printf("%s", "}");
   printf("%s", ";");
};
void Interpreter::visit(Print *n) {
   printf("%s", "print");
   printf("%s", "(");
   if(n->el != nullptr) n->el->accept(this);
   printf("%s", ")");
   printf("%s", ";");
};
void Interpreter::visit(Readln *n) {
   printf("%s", "readln");
   printf("%s", "(");
   if(n->expr != nullptr) n->expr->accept(this);
   printf("%s", ")");
};
void Interpreter::visit(Return *n) {
   printf("%s", "return");
   printf("%s", "(");
   if(n->expr != nullptr) n->expr->accept(this);
   printf("%s", ")");
   printf("%s", ";");
};
void Interpreter::visit(Throw *n) {
   printf("%s", "throw");
   printf("%s", ";");
};
void Interpreter::visit(Try *n) {
   printf("%s", "try");
   if(n->tryStmt != nullptr) n->tryStmt->accept(this);
   printf("%s", "catch");
   printf("%s", "(");
   if(n->catchStmt != nullptr) n->catchStmt->accept(this);
   printf("%s", ")");
   if(n->catchBlock != nullptr) n->catchBlock->accept(this);
};
void Interpreter::visit(If *n) {
   printf("%s", "if");
   printf("%s", "(");
   if(n->expr != nullptr) n->expr->accept(this);
   printf("%s", ")");
   if(n->stmt != nullptr) n->stmt->accept(this);
   if(n->el != nullptr) n->el->accept(this);
};
void Interpreter::visit(StmtFatId *n) {
   if(n->type != nullptr) n->type->accept(this);
   if(n->fI != nullptr) n->fI->accept(this);
};
void Interpreter::visit(Stmtl *n) {
   if(n->stmt != nullptr) n->stmt->accept(this);
   if(n->stmtl != nullptr) n->stmtl->accept(this);
};
void Interpreter::visit(Array *n) {
   printf("%s", "[");
   printf("%s", "num");
   printf("%s", "]");
   if(n->array != nullptr) n->array->accept(this);
};
void Interpreter::visit(IntType *n) {
   printf("%s", "int");
};
void Interpreter::visit(FloatType *n) {
   printf("%s", "float");
};
void Interpreter::visit(LongType *n) {
   printf("%s", "long");
};
void Interpreter::visit(BoolType *n) {
   printf("%s", "bool");
};
void Interpreter::visit(CharType *n) {
   printf("%s", "char");
};
void Interpreter::visit(DoubleType *n) {
   printf("%s", "double");
};
void Interpreter::visit(Pointer *n) {
   printf("%s", "*");
};
void Interpreter::visit(FormalRest *n) {
   printf("%s", ",");
   if(n->fl != nullptr) n->fl->accept(this);
};
void Interpreter::visit(FormaList *n) {
   if(n->type != nullptr) n->type->accept(this);
   if(n->pointer != nullptr) n->pointer->accept(this);
   printf("%s", "id");
   if(n->array != nullptr) n->array->accept(this);
   if(n->fr != nullptr) n->fr->accept(this);
};
void Interpreter::visit(VarDecl *n) {
   if(n->type != nullptr) n->type->accept(this);
   if(n->idl != nullptr) n->idl->accept(this);
   printf("%s", ";");
   if(n->vd != nullptr) n->vd->accept(this);
};
void Interpreter::visit(TypeDecl *n) {
   printf("%s", "typedef");
   printf("%s", "struct");
   printf("%s", "{");
   if(n->type != nullptr) n->type->accept(this);
   n->idL->accept(this);
   printf("%s", ";");
   n->vd->accept(this);
   printf("%s", "}");
   n->id->accept(this);
   printf("%s", ";");
   //n->typeDecl->accept(this);
};
void Interpreter::visit(FunctionOrVarDecl *n) {
   if(n->type != nullptr) n->type->accept(this);
   if(n->pointer != nullptr) n->pointer->accept(this);
   if(n->id != nullptr) n->id->accept(this);
   if(n->programl != nullptr) n->programl->accept(this);
   if(n->program != nullptr) n->program->accept(this);
};
void Interpreter::visit(Program *n) {
   if(n->fov != nullptr) n->fov->accept(this);
   // Dividir em dois casos?
   if(n->td != nullptr) n->td->accept(this);
   if(n->prog != nullptr) n->prog->accept(this);
};
void Interpreter::visit(ProgramL *n) {
   if(n->array != nullptr) n->array->accept(this);
   if(n->idL != nullptr) n->idL->accept(this);
   // N teria q separar em 2 visit diferentes para cada caso
   printf("%s", "(");
   if(n->fl != nullptr)n->fl->accept(this);
   printf("%s", ")");
   printf("%s", "{");
   if(n->sl != nullptr)  n->sl->accept(this);
   printf("%s", "}");
}

   void Interpreter::visit(F *n) {}
   void Interpreter::visit(ExprList *n) {}
   void Interpreter::visit(ExprListTail *n) {}
   void Interpreter::visit(IdListAux *n) {}
   void Interpreter::visit(FatId1 *n) {}
   void Interpreter::visit(Stmt *n) {}
   void Interpreter::visit(Expr *n) {}
   void Interpreter::visit(Identifier *n) {
      // if(n->token_name != nullptr)  n->accept(this);
      printf("%s", n->token_name);
   }
   void Interpreter::visit(Num *n) {}
   void Interpreter::visit(Type *n) {}
   void Interpreter::visit(IdList*n) {}
   void Interpreter::visit(FatId *n) {}