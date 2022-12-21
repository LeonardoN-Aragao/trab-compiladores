#ifndef VISITOR_H_INCLUDE
#define VISITOR_H_INCLUDE
#include <string>
class Visitor;
// Abstract Class for Expressions
class Exp {
public:
  virtual int accept(Visitor *v) = 0;
};
// Classes for each expression
// x + y
class PlusExp: public Exp {
public:
  Exp *e1, *e2;
  PlusExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x - y
class MinusExp: public Exp {
public:
  Exp *e1, *e2;
  MinusExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x * y
class TimesExp: public Exp {
public:
  Exp *e1, *e2;
  TimesExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x / y
class DivideExp: public Exp {
public:
  Exp *e1, *e2;
  DivideExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x == y
class EqualsExp: public Exp {
public:
  Exp *e1, *e2;
  EqualsExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x != y
class DifferentExp: public Exp {
public:
  Exp *e1, *e2;
  DifferentExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x < y
class LowerExp: public Exp {
public:
  Exp *e1, *e2;
  LowerExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x > y
class GraterExp: public Exp {
public:
  Exp *e1, *e2;
  GraterExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x <= y
class LowerEqualExp: public Exp {
public:
  Exp *e1, *e2;
  LowerEqualExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x >= y
class GraterEqualExp: public Exp {
public:
  Exp *e1, *e2;
  GraterEqualExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x && y
class AndExp: public Exp {
public:
  Exp *e1, *e2;
  AndExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x || y
class OrExp: public Exp {
public:
  Exp *e1, *e2;
  OrExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x % y
class RemainderExp: public Exp {
public:
  Exp *e1, *e2;
  RemainderExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x & y
class AndBitABitExp: public Exp {
public:
  Exp *e1, *e2;
  AndBitABitExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// x | y
class OrBitABitExp: public Exp {
public:
  Exp *e1, *e2;
  OrBitABitExp(Exp *a1, Exp *a2);
  int accept(Visitor *v);
};
// (int)x
class IntergerLiteral: public Exp {
public:
  char *f0;
  IntergerLiteral(char *n0);
  int accept(Visitor *v);
};

class Visitor {
public:
  virtual int visit(PlusExp *n) = 0;
  virtual int visit(MinusExp *n) = 0;
  virtual int visit(TimesExp *n) = 0;
  virtual int visit(DivideExp *n) = 0;
  virtual int visit(EqualsExp *n) = 0;
  virtual int visit(DifferentExp *n) = 0;
  virtual int visit(LowerExp *n) = 0;
  virtual int visit(GraterExp *n) = 0;
  virtual int visit(LowerEqualExp *n) = 0;
  virtual int visit(GraterEqualExp *n) = 0;
  virtual int visit(AndExp *n) = 0;
  virtual int visit(OrExp *n) = 0;
  virtual int visit(RemainderExp *n) = 0;
  virtual int visit(AndBitABitExp *n) = 0;
  virtual int visit(OrBitABitExp *n) = 0;
  virtual int visit(IntergerLiteral *n) = 0;
  // virtual float visit(FloatLiteral *n) = 0;
};

// class FloatLiteral: public Exp {
// public:
//   char *f0;
//   FloatLiteral(char *n0) { this->f0 = n0; };
//   int accept(Visitor *v) { return v->visit(this); };
// };

class Interpreter: public Visitor {
public:
  int visit(PlusExp *n) { return n->e1->accept(this) + n->e2->accept(this); };
  int visit(MinusExp *n) { return n->e1->accept(this) - n->e2->accept(this); };
  int visit(TimesExp *n) { return n->e1->accept(this) * n->e2->accept(this); };
  int visit(DivideExp *n) { return n->e1->accept(this) / n->e2->accept(this); };
  int visit(EqualsExp *n) { return n->e1->accept(this) == n->e2->accept(this) ? 1 : 0; };
  int visit(DifferentExp *n) { return n->e1->accept(this) != n->e2->accept(this) ? 1 : 0; };
  int visit(LowerExp *n) { return n->e1->accept(this) < n->e2->accept(this) ? 1 : 0; };
  int visit(GraterExp *n) { return n->e1->accept(this) > n->e2->accept(this) ? 1 : 0; };
  int visit(LowerEqualExp *n) { return n->e1->accept(this) <= n->e2->accept(this) ? 1 : 0; };
  int visit(GraterEqualExp *n) { return n->e1->accept(this) >= n->e2->accept(this) ? 1 : 0; };
  int visit(AndExp *n) { return n->e1->accept(this) && n->e2->accept(this) ? 1 : 0; };
  int visit(OrExp *n) { return n->e1->accept(this) || n->e2->accept(this) ? 1 : 0; };
  int visit(RemainderExp *n) { return n->e1->accept(this) % n->e2->accept(this); };
  int visit(AndBitABitExp *n) { return n->e1->accept(this) & n->e2->accept(this); };
  int visit(OrBitABitExp *n) { return n->e1->accept(this) | n->e2->accept(this); };
  int visit(IntergerLiteral *n) { return atoi(n->f0); };
  //float visit(FloatLiteral *n) { return (float)n->f0->accept(this); };
};

#endif // VISITOR_H_INCLUDE
