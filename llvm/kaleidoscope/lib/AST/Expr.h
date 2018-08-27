//
// Created by gaoge on 2018/8/20.
//

#pragma once

#include <string>
#include <vector>

/// base class
class Expr {
public:
  virtual ~Expr() {}
};

class NumberExpr : public Expr {
private:
  double Val;

public:
  NumberExpr(const double Val) : Val(Val) {}
};

class VariableExpr : public Expr {
private:
  std::string Name;

public:
  VariableExpr(const std::string &Name) : Name(Name) {}
};

class BinaryExpr : public Expr {
private:
  /// One character operation
  char Op;
  std::unique_ptr<Expr> LHS;
  std::unique_ptr<Expr> RHS;

public:
  BinaryExpr(char Op, std::unique_ptr<Expr> LHS, std::unique_ptr<Expr> RHS)
      : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};

class CallExpr : public Expr {
private:
  std::string Callee;
  std::vector<std::unique_ptr<Expr>> Args;

public:
  CallExpr(const std::string &Callee, std::vector<std::unique_ptr<Expr>> Args)
      : Callee(Callee), Args(std::move(Args)) {}
};

class PrototypeExpr {
private:
  std::string Name;
  std::vector<std::string> Args;

public:
  PrototypeExpr(const std::string &Name, std::vector<std::string> Args)
      : Name(Name), Args(std::move(Args)) {}

  const std::string &getName() const { return Name; }
};

class FunctionBodyExpr {
private:
  std::unique_ptr<PrototypeExpr> Proto;
  std::unique_ptr<Expr> Body;

public:
  FunctionBodyExpr(std::unique_ptr<PrototypeExpr> Proto,
                   std::unique_ptr<Expr> Body)
      : Proto(std::move(Proto)), Body(std::move(Body)) {}
};
