#include "Visitor.h"
 
PlusExp::PlusExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int PlusExp::accept(Visitor *v) { return v->visit(this); };

MinusExp::MinusExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int MinusExp::accept(Visitor *v) { return v->visit(this); };

TimesExp::TimesExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int TimesExp::accept(Visitor *v) { return v->visit(this); };

DivideExp::DivideExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int DivideExp::accept(Visitor *v) { return v->visit(this); };

EqualsExp::EqualsExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int EqualsExp::accept(Visitor *v) { return v->visit(this); };

DifferentExp::DifferentExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int DifferentExp::accept(Visitor *v) { return v->visit(this); };

LowerExp::LowerExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int LowerExp::accept(Visitor *v) { return v->visit(this); };

GraterExp::GraterExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int GraterExp::accept(Visitor *v) { return v->visit(this); };

LowerEqualExp::LowerEqualExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int LowerEqualExp::accept(Visitor *v) { return v->visit(this); };

GraterEqualExp::GraterEqualExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int GraterEqualExp::accept(Visitor *v) { return v->visit(this); };

AndExp::AndExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int AndExp::accept(Visitor *v) { return v->visit(this); };

OrExp::OrExp(Exp *a1, Exp *a2) { this->e1 = a1; this-> e2 = a2; };
int OrExp::accept(Visitor *v) { return v->visit(this); };

RemainderExp::RemainderExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int RemainderExp::accept(Visitor *v) { return v->visit(this); };

AndBitABitExp::AndBitABitExp(Exp *a1, Exp *a2) { this->e1 = a2; this->e2 = a2; };
int AndBitABitExp::accept(Visitor *v) { return v->visit(this); };

OrBitABitExp::OrBitABitExp(Exp *a1, Exp *a2) { this->e1 = a1; this->e2 = a2; };
int OrBitABitExp::accept(Visitor *v) { return v->visit(this); };

IntergerLiteral::IntergerLiteral(char *n0) { this->f0 = n0; };
int IntergerLiteral::accept(Visitor *v) { return v->visit(this); };
