#include "Visitor.h"

void Program::accept(Visitor *v){ v->visit(this); };
void ProgramL::accept(Visitor *v){ v->visit(this); };
void FunctionOrVarDecl::accept(Visitor *v){ v->visit(this); };
void TypeDecl::accept(Visitor *v){ v->visit(this); };
void VarDecl::accept(Visitor *v){ v->visit(this); };
void Type::accept(Visitor *v){ v->visit(this); };
void Pointer::accept(Visitor *v){ v->visit(this); };
void FormaList::accept(Visitor *v){ v->visit(this); };
void FormalRest::accept(Visitor *v){ v->visit(this); };
void Array::accept(Visitor *v){ v->visit(this); };
void IdList::accept(Visitor *v){ v->visit(this); };
void IdListAux::accept(Visitor *v){ v->visit(this); };
void Stmtl::accept(Visitor *v){ v->visit(this); };
void Stmt::accept(Visitor *v){ v->visit(this); };
void While::accept(Visitor *v){ v->visit(this); };
void Switch::accept(Visitor *v){ v->visit(this); };
void Break::accept(Visitor *v){ v->visit(this); };
void Braces::accept(Visitor *v){ v->visit(this); };
void Print::accept(Visitor *v){ v->visit(this); };
void Readln::accept(Visitor *v){ v->visit(this); };
void Return::accept(Visitor *v){ v->visit(this); };
void Throw::accept(Visitor *v){ v->visit(this); };
void Try::accept(Visitor *v){ v->visit(this); };
void If::accept(Visitor *v){ v->visit(this); };
void StmtFatId::accept(Visitor *v){ v->visit(this); };
void Else::accept(Visitor *v){ v->visit(this); };
void FatId::accept(Visitor *v){ v->visit(this); };
void FatId1::accept(Visitor *v){ v->visit(this); };
// void CallFunction::accept(Visitor *v){ v->visit(this); };
// void FatIdIdList::accept(Visitor *v){ v->visit(this); };
// void FatIdFatId1::accept(Visitor *v){ v->visit(this); };
void DotFatId1::accept(Visitor *v){ v->visit(this); };
void ArrowFatId1::accept(Visitor *v){ v->visit(this); };
void AmpersandFatId1::accept(Visitor *v){ v->visit(this); };
void BracketFatId1::accept(Visitor *v){ v->visit(this); };
void AssingmentFatId1::accept(Visitor *v){ v->visit(this); };
void CaseBlock::accept(Visitor *v){ v->visit(this); };
void ExprList::accept(Visitor *v){ v->visit(this); };
void ExprListTail::accept(Visitor *v){ v->visit(this); };
void Expr::accept(Visitor *v){ v->visit(this); };
void ExprListTailAux::accept(Visitor *v){ v->visit(this); };
void ExprAux::accept(Visitor *v){ v->visit(this); };
void Expr2::accept(Visitor *v){ v->visit(this); };
void Expr2Aux::accept(Visitor *v){ v->visit(this); };
void Expr3Aux::accept(Visitor *v){ v->visit(this); };
void Expr3::accept(Visitor *v){ v->visit(this); };
void Expr4Aux::accept(Visitor *v){ v->visit(this); };
void Expr4::accept(Visitor *v){ v->visit(this); };
void Expr5Aux::accept(Visitor *v){ v->visit(this); };
void Expr5::accept(Visitor *v){ v->visit(this); };
void Expr6Aux::accept(Visitor *v){ v->visit(this); };
void Expr6::accept(Visitor *v){ v->visit(this); };
void Expr7Aux::accept(Visitor *v){ v->visit(this); };
void Expr7::accept(Visitor *v){ v->visit(this); };
void Expr8Aux::accept(Visitor *v){ v->visit(this); };
void Expr8::accept(Visitor *v){ v->visit(this); };
void Expr9Aux::accept(Visitor *v){ v->visit(this); };
void Expr9::accept(Visitor *v){ v->visit(this); };
void F_Expr::accept(Visitor *v){ v->visit(this); };
void True::accept(Visitor *v){ v->visit(this); };
void Num::accept(Visitor *v){ v->visit(this); };
void LongType::accept(Visitor *v){ v->visit(this); };
void IntType::accept(Visitor *v){ v->visit(this); };
void FloatType::accept(Visitor *v){ v->visit(this); };
void BoolType::accept(Visitor *v){ v->visit(this); };
void CharType::accept(Visitor *v){ v->visit(this); };
void DoubleType::accept(Visitor *v){ v->visit(this); };
void Identifier::accept(Visitor *v){ v->visit(this); };
void False::accept(Visitor *v){ v->visit(this); };
void Int::accept(Visitor *v){ v->visit(this); };
void Float::accept(Visitor *v){ v->visit(this); };
void Identifier_F::accept(Visitor *v){ v->visit(this); };
void Literal::accept(Visitor *v){ v->visit(this); };
void F::accept(Visitor *v){ v->visit(this); };

void Interpreter::visit(Program *n) {
   print("PROGRAM");
   lvl_next();
   if(n->fov != nullptr) n->fov->accept(this);
   // Dividir em dois casos?
   if(n->td != nullptr) n->td->accept(this);
   if(n->prog != nullptr) n->prog->accept(this);
   lvl_prev();
};

void Interpreter::visit(FunctionOrVarDecl *n) {
   print("FUNCTIONORVARDECL");
   lvl_next();
   if(n->type != nullptr) n->type->accept(this);
   if(n->pointer != nullptr) n->pointer->accept(this);
   if(n->id != nullptr) n->id->accept(this);
   if(n->programl != nullptr) n->programl->accept(this);
   if(n->program != nullptr) n->program->accept(this);
   lvl_prev();
};

void Interpreter::visit(ProgramL *n) {
   print("PROGRAML");
   lvl_next();

   if(n->array != nullptr || n->idL != nullptr) {
      if(n->array != nullptr) n->array->accept(this);
      if(n->idL != nullptr) n->idL->accept(this);
   }
   if(n->fl != nullptr || n->sl != nullptr) {
      print("(");
      if(n->fl != nullptr) n->fl->accept(this);
      print(")");
      print("{");
      if(n->sl != nullptr) n->sl->accept(this);
      print("}");
   }
   lvl_prev();
}

void Interpreter::visit(TypeDecl *n) {
   print("TYPEDECL"); 
   lvl_next();
   // printf("%s", "typedef");
   print("typedef");
   // printf("%s", "struct");
   print("struct");
   // printf("%s", "{");
   print("{");
   if(n->type != nullptr) n->type->accept(this);
   n->idL->accept(this);
   // printf("%s", ";");
   print(";");
   n->vd->accept(this);
   // printf("%s", "}");
   print("}");
   n->id->accept(this);
   // printf("%s", ";");
   print(";");
   //n->typeDecl->accept(this);
   lvl_prev();
};

void Interpreter::visit(VarDecl *n) {
  print("VARDECL");
  lvl_next();
   if(n->type != nullptr) n->type->accept(this);
   if(n->idl != nullptr) n->idl->accept(this);
   // printf("%s", ";");
   print(";");
   if(n->vd != nullptr) n->vd->accept(this);
   lvl_prev();
};

void Interpreter::visit(Type *n) {};
void Interpreter::visit(IntType *n) {
   // printf("%s", "int");
   print("int");
};
void Interpreter::visit(FloatType *n) {
   // printf("%s", "float");
   print("float");
};
void Interpreter::visit(LongType *n) {
   // printf("%s", "long");
   print("long");
};
void Interpreter::visit(BoolType *n) {
   // printf("%s", "bool");
   print("bool");
};
void Interpreter::visit(CharType *n) {
   // printf("%s", "char");
   print("char");
};
void Interpreter::visit(DoubleType *n) {
   // printf("%s", "double");
   print("double");
};

void Interpreter::visit(Pointer *n) {
   // printf("%s", "*");
   print("*");
};

void Interpreter::visit(FormaList *n) {
  print("FORMALIST");
   lvl_next();
   if(n->type != nullptr) n->type->accept(this);
   if(n->pointer != nullptr) n->pointer->accept(this);
   // printf("%s", "id");
   //print("id");
   if(n->i != nullptr) n->i->accept(this);
   if(n->array != nullptr) n->array->accept(this);
   if(n->fr != nullptr) n->fr->accept(this);
   lvl_prev();
};

void Interpreter::visit(FormalRest *n) {
  print("FORMALREST");
   lvl_next();
   // printf("%s", ",");
   print(",");
   if(n->fl != nullptr) n->fl->accept(this);
   lvl_prev();
};

void Interpreter::visit(Array *n) {
  print("ARRAY");
   lvl_next();
   // printf("%s", "[");
   print("[");
   // printf("%s", "num");
   print("num");
   // printf("%s", "]");
   print("]");
   if(n->array != nullptr) n->array->accept(this);
   lvl_prev();
};

void Interpreter::visit(IdList*n) {
   print("IDLIST");
   if(n->pointer != nullptr) n->pointer->accept(this);
   if(n->id != nullptr) n->id->accept(this);
   if(n->array != nullptr) n->array->accept(this);
   if(n->idl != nullptr) n->idl->accept(this);
}

void Interpreter::visit(IdListAux *n) {
   print("IDLISTAUX");
   print(",");
   if(n->il != nullptr) n->il->accept(this);
};

void Interpreter::visit(Stmtl *n) {
   print("STMTL");
   lvl_next();
   if(n->stmt != nullptr) n->stmt->accept(this);
   if(n->stmtl != nullptr) n->stmtl->accept(this);
   lvl_prev();
};

void Interpreter::visit(Stmt *n) {}

void Interpreter::visit(While *n) {
   lvl_next();
   // printf("%s", "while");
   print("while");
   // printf("%s", "(");
   print("(");
   if(n->expr != nullptr) n->expr->accept(this);
   // printf("%s", ")");
   print(")");
   if(n->stmt != nullptr) n->stmt->accept(this);
   lvl_prev();
}

void Interpreter::visit(Switch *n) {
   lvl_next();
   // printf("%s", "switch");
   print("switch");
   // printf("%s", "(");
   print("(");
   if(n->expr != nullptr) n->expr->accept(this);
   // printf("%s", ")");
   print(")");
   if(n->cb != nullptr) n->cb->accept(this);
   lvl_prev();
};

void Interpreter::visit(Break *n) {
   lvl_next();
   // printf("%s", "break");
   print("break");
   // printf("%s", ";");
   print(";");
   lvl_prev();
};

void Interpreter::visit(Braces *n) {
   //print("BRACES");
   lvl_next();
   // printf("%s", "{");
   print("{");
   if(n->stmtl != nullptr) n->stmtl->accept(this);
   // printf("%s", "}");
   print("}");
   // printf("%s", ";");
   print(";");
   lvl_prev();
};

void Interpreter::visit(Print *n) {
  //print("PRINT");
   lvl_next();
   // printf("%s", "print");
   print("print");
   // printf("%s", "(");
   print("(");
   if(n->el != nullptr) n->el->accept(this);
   // printf("%s", ")");
   print(")");
   // printf("%s", ";");
   print(";");
   lvl_prev();
};

void Interpreter::visit(Readln *n) {
   print("READLN");
   lvl_next();
   // printf("%s", "readln");
   print("readln");
   // printf("%s", "(");
   print("(");
   if(n->expr != nullptr) n->expr->accept(this);
   // printf("%s", ")");
   print(")");
   lvl_prev();
};

void Interpreter::visit(Return *n) {
  print("RETURN");
   lvl_next();
   // printf("%s", "return");
   print("return");
   // printf("%s", "(");
   print("(");
   if(n->expr != nullptr) n->expr->accept(this);
   // printf("%s", ")");
   print(")");
   // printf("%s", ";");
   print(";");
   lvl_prev();
};

void Interpreter::visit(Throw *n) {
  print("THROW");
   lvl_next();
   // printf("%s", "throw");
   print("throw");
   // printf("%s", ";");
   print(";");
   lvl_prev();
};

void Interpreter::visit(Try *n) {
  print("TRY");
   lvl_next();
   // printf("%s", "try");
   print("try");
   if(n->tryStmt != nullptr) n->tryStmt->accept(this);
   // printf("%s", "catch");
   print("catch");
   // printf("%s", "(");
   print("(");
   if(n->catchStmt != nullptr) n->catchStmt->accept(this);
   // printf("%s", ")");
   print(")");
   if(n->catchBlock != nullptr) n->catchBlock->accept(this);
   lvl_prev();
};

void Interpreter::visit(If *n) {
  print("IF");
   lvl_next();
   // printf("%s", "if");
   print("if");
   // printf("%s", "(");
   print("(");
   if(n->expr != nullptr) n->expr->accept(this);
   // printf("%s", ")");
   print(")");
   if(n->stmt != nullptr) n->stmt->accept(this);
   if(n->el != nullptr) n->el->accept(this);
   lvl_prev();
};

void Interpreter::visit(StmtFatId *n) {
   print("STMTFATID");
   lvl_next();
   if(n->type != nullptr) n->type->accept(this);
   if(n->fI != nullptr) n->fI->accept(this);
   lvl_prev();
};

void Interpreter::visit(Else *n) {
   lvl_next();
   // printf("%s", "else");
   print("else");
   if(n->stmt != nullptr) n->stmt->accept(this);
   lvl_prev();
};

void Interpreter::visit(FatId *n) {
   if(n->el != nullptr) {
      print("(");
      n->el->accept(this);
      print(")");
      print(";");
   }
   if(n->idl != nullptr) {
      n->idl->accept(this);
      print(";");
   };
   if(n->fi1 != nullptr) {
      n->fi1->accept(this);
      print(";");
   };
}

void Interpreter::visit(FatId1 *n) {}

void Interpreter::visit(DotFatId1 *n) {
   lvl_next();
   // printf("%s", "dot");
   print("dot");
   if(n->expr != nullptr) n->expr->accept(this);
   lvl_prev();
};

void Interpreter::visit(ArrowFatId1 *n) {
   lvl_next();
   // printf("%s", "arrow");
   print("arrow");
   if(n->expr != nullptr) n->expr->accept(this);
   lvl_prev();
};

void Interpreter::visit(AmpersandFatId1 *n) {
   lvl_next();
   // printf("%s", "&");
   print("&");
   if(n->expr != nullptr) n->expr->accept(this);
   lvl_prev();
};

void Interpreter::visit(AssingmentFatId1 *n) {
   lvl_next();
   // printf("%s", "=");
   print("=");
   if(n->expr != nullptr) n->expr->accept(this);
   lvl_prev();
};

void Interpreter::visit(BracketFatId1 *n) {
   lvl_next();
   // printf("%s", "[");
   print("[");
   if(n->expr != nullptr) n->expr->accept(this);
   // printf("%s", "]");
   print("]");
   // printf("%s", ";");
   print(";");
   lvl_prev();
};

void Interpreter::visit(CaseBlock *n) {
   lvl_next();
   // printf("%s", "case");
   print("case");
   // printf("%s", "num :");
   print("num :");
   if(n->sl != nullptr) n->sl->accept(this);
   if(n->cb != nullptr) n->cb->accept(this);
   lvl_prev();
};

void Interpreter::visit(ExprList *n) {
   if(n->elt != nullptr) n->elt->accept(this);
};

void Interpreter::visit(ExprListTail *n) {
   if(n->expr != nullptr) n->expr->accept(this);
   if(n->elt != nullptr) n->elt->accept(this);
};

void Interpreter::visit(ExprListTailAux *n) {
   lvl_next();
   // printf("%s", ",");
   print(",");
   if(n->elt != nullptr) n->elt->accept(this);
   lvl_prev();
};

void Interpreter::visit(Expr *n) {
   print("Expr");
   if(n->ex1 != nullptr) n->ex1->accept(this);
   // print("if1 expr");
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(ExprAux *n) {
   print("||");
   // print("expr2");
   if(n->ex1 != nullptr) n->ex1->accept(this);
   // print("expraux");
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr2 *n) {
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr2Aux *n) {
   print("&&");
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr3 *n) {
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr3Aux *n) {
   print("|");
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr4 *n) {
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr4Aux *n) {
   print("&");
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr5 *n) {
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr5Aux *n) {
   if(n->op != nullptr) print(n->op);
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr6 *n) {
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr6Aux *n) {
   if(n->op != nullptr) print(n->op);
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr7 *n) {
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr7Aux *n) {
   if(n->op != nullptr) print(n->op);
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr8 *n) {
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr8Aux *n) {
   if(n->op != nullptr) print(n->op);
   if(n->ex1 != nullptr) n->ex1->accept(this);
   if(n->ex2 != nullptr) n->ex2->accept(this);
};
void Interpreter::visit(Expr9 *n) {
   if(n->f != nullptr) n->f->accept(this);
   if(n->e != nullptr) n->e->accept(this);
};
void Interpreter::visit(Expr9Aux *n) {
   if(n->op != nullptr) print(n->op);
   if(n->ex1 != nullptr) n->ex1->accept(this);
};

void Interpreter::visit(F *n) {
   // n->->accept(this);
};

void Interpreter::visit(Identifier *n) {
   // if(n->token_name != nullptr)  n->accept(this);
   // printf("%s", n->token_name);
   print(n->token_name);
};

void Interpreter::visit(Identifier_F *n) {
   // if(n->token_name != nullptr)  n->accept(this);
   // printf("%s", n->token_name);
   print(n->token_name);
};

void Interpreter::visit(Num *n) {
   print("num");
};

void Interpreter::visit(Int *n) {
   print(n->value);
   // printf("%d\n", n->value);
};

void Interpreter::visit(Float *n) {
   // print(n->value);
   // printf("%f\n", n->value);
};

void Interpreter::visit(F_Expr *n) {
   print("(");
   if(n->expr != nullptr) n->expr->accept(this);
   print(")");
}
