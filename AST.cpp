#include "AST.h"
// // Exp
// PlusExp::PlusExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void PlusExp::accept(Visitor *v) { v->visit(this); };

// MinusExp::MinusExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void MinusExp::accept(Visitor *v) { v->visit(this); };

// TimesExp::TimesExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void TimesExp::accept(Visitor *v) { v->visit(this); };

// DivideExp::DivideExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void DivideExp::accept(Visitor *v) { v->visit(this); };

// EqualsExp::EqualsExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void EqualsExp::accept(Visitor *v) { v->visit(this); };

// DifferentExp::DifferentExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void DifferentExp::accept(Visitor *v) { v->visit(this); };

// LowerExp::LowerExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void LowerExp::accept(Visitor *v) { v->visit(this); };

// GraterExp::GraterExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void GraterExp::accept(Visitor *v) { v->visit(this); };

// LowerEqualExp::LowerEqualExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void LowerEqualExp::accept(Visitor *v) { v->visit(this); };

// GraterEqualExp::GraterEqualExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void GraterEqualExp::accept(Visitor *v) { v->visit(this); };

// AndExp::AndExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void AndExp::accept(Visitor *v) { v->visit(this); };

// OrExp::OrExp(Expr *a1, Expr *a2) { this->e1 = a1; this-> e2 = a2; };
// void OrExp::accept(Visitor *v) { v->visit(this); };

// RemainderExp::RemainderExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void RemainderExp::accept(Visitor *v) { v->visit(this); };

// AndBitABitExp::AndBitABitExp(Expr *a1, Expr *a2) { this->e1 = a2; this->e2 = a2; };
// void AndBitABitExp::accept(Visitor *v) { v->visit(this); };

// OrBitABitExp::OrBitABitExp(Expr *a1, Expr *a2) { this->e1 = a1; this->e2 = a2; };
// void OrBitABitExp::accept(Visitor *v) { v->visit(this); };

// IntergerLiteral::IntergerLiteral(char *n0) { this->f0=n0; };
// void IntergerLiteral::accept(Visitor *v) { v->visit(this); };

// void Pointer::accept(Visitor *v){ v->visit(this); };

// void ProgramL::accept(Visitor *v){ v->visit(this); };
// void Array::accept(Visitor *v){ v->visit(this); };
// void IdList::accept(Visitor *v){ v->visit(this); };
// void Type::accept(Visitor *v){ v->visit(this); };
// void Num::accept(Visitor *v){ v->visit(this); };
// void LongType::accept(Visitor *v){ v->visit(this); };
// void IntType::accept(Visitor *v){ v->visit(this); };
// void FloatType::accept(Visitor *v){ v->visit(this); };
// void BoolType::accept(Visitor *v){ v->visit(this); };
// void CharType::accept(Visitor *v){ v->visit(this); };
// void DoubleType::accept(Visitor *v){ v->visit(this); };
// void Identifier::accept(Visitor *v){ v->visit(this); };
// void VarDecl::accept(Visitor *v){ v->visit(this); };
// void Stmt::accept(Visitor *v){ v->visit(this); };
// void Break::accept(Visitor *v){ v->visit(this); };
// void Throw::accept(Visitor *v){ v->visit(this); };
// void Else::accept(Visitor *v){ v->visit(this); };
// void If::accept(Visitor *v){ v->visit(this); };
// void While::accept(Visitor *v){ v->visit(this); };
// void CaseBlock::accept(Visitor *v){ v->visit(this); };
// void Switch::accept(Visitor *v){ v->visit(this); };
// void Return::accept(Visitor *v){ v->visit(this); };
// void Try::accept(Visitor *v){ v->visit(this); };
// void Print::accept(Visitor *v){ v->visit(this); };
// void Readln::accept(Visitor *v){ v->visit(this); };
// void StmtFatId::accept(Visitor *v){ v->visit(this); };
// void Stmtl::accept(Visitor *v){ v->visit(this); };
// void FatId::accept(Visitor *v){ v->visit(this); };
// void FatId1::accept(Visitor *v){ v->visit(this); };
// void CallFunction::accept(Visitor *v){ v->visit(this); };
// void FatIdIdList::accept(Visitor *v){ v->visit(this); };
// void FatIdFatId1::accept(Visitor *v){ v->visit(this); };
// void DotFatId1::accept(Visitor *v){ v->visit(this); };
// void ArrowFatId1::accept(Visitor *v){ v->visit(this); };
// void AmpersandFatId1::accept(Visitor *v){ v->visit(this); };
// void BracketFatId1::accept(Visitor *v){ v->visit(this); };
// void FormaList::accept(Visitor *v){ v->visit(this); };
// void FormalRest::accept(Visitor *v){ v->visit(this); };
// void IdListAux::accept(Visitor *v){ v->visit(this); };
// void ExprListTail::accept(Visitor *v){ v->visit(this); };
// void ExprList::accept(Visitor *v){ v->visit(this); };
// void F::accept(Visitor *v){ v->visit(this); };
// void TypeDecl::accept(Visitor *v){ v->visit(this); };
// void Program::accept(Visitor *v){ v->visit(this); };
// void FunctionOrVarDecl::accept(Visitor *v){ v->visit(this); };
// void Braces::accept(Visitor *v){ v->visit(this); };
// void Expr::accept(Visitor *v){ v->visit(this); };
// void F_Expr::accept(Visitor *v){ v->visit(this); };
// void True::accept(Visitor *v){ v->visit(this); };
// void False::accept(Visitor *v){ v->visit(this); };
// void Int::accept(Visitor *v){ v->visit(this); };
// void Float::accept(Visitor *v){ v->visit(this); };
// void Identifier_F::accept(Visitor *v){ v->visit(this); };
// void AssingmentFatId1::accept(Visitor *v){ v->visit(this); };
// void ExprListTailAux::accept(Visitor *v){ v->visit(this); };
// void Literal::accept(Visitor *v){ v->visit(this); };


// Interpreter::Interpreter() {altura_tree=0;}
// void Interpreter::lvlm() {altura_tree++;}
// void Interpreter::lvln() {altura_tree--;}