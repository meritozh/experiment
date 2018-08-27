#include "lib/AST/Expr.h"
#include "lib/Lexer/Lexer.h"

#include <vector>
#include <memory>

auto LHS = std::make_unique<VariableExpr>("x");
auto RHS = std::make_unique<VariableExpr>("y");

auto Result = std::make_unique<BinaryExpr>('+', std::move(LHS), std::move(RHS));

static auto ParseNumberExpr() {
  auto R = std::make_unique<NumberExpr>(NumVal);
  getNextToken(); // Consume the number
  return std::move(R);
}

static auto ParseExpression() -> std::unique_ptr<Expr>;

static auto ParseParenExpr() -> std::unique_ptr<Expr> {
  getNextToken();
  auto V = ParseExpression();
  
  if (!V) {
    return nullptr;
  }

  if (CurTok == ')') {
    getNextToken();
    return std::move(V);
  }
}

static auto ParseIdentifierExpr() -> std::unique_ptr<Expr> {
  std::string IdName = IdentifierStr;
  getNextToken();
  if (CurTok != '(') {
    return std::make_unique<VariableExpr>(IdName);
  }

  getNextToken();
  std::vector<std::unique_ptr<Expr>> Args;
  if (CurTok != ')') {
    while (true) {
      if (auto Arg = ParseExpression()) {
        Args.push_back(std::move(Arg));
      } else {
        return nullptr;
      }
    }
  }
}
