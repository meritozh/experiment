#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/ArgumentsAdjusters.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/CommandLine.h>

#include <iostream>

static llvm::cl::OptionCategory ASTParserCategory("AST Parser Sample");

class ParseASTVisitor : public clang::RecursiveASTVisitor<ParseASTVisitor> {
public:
  explicit ParseASTVisitor(clang::ASTContext *Ctx) : Context(Ctx) {}

  bool VisitCallExpr(clang::CallExpr *E) {
    auto FullLoc = Context->getFullLoc(E->getExprLoc());
    if (FullLoc.isValid() && FullLoc.isInSystemHeader())
      return true;
    if (E->getNumArgs()) {
      auto Arg = E->getArg(0);
      auto T = Arg->getType();
      std::cout << "param's type: " << T.getAsString() << std::endl;
    }
    return true;
  }

private:
  clang::ASTContext *Context;
};

class ParseASTConsumer : public clang::ASTConsumer {
public:
  explicit ParseASTConsumer(clang::ASTContext *Ctx) : Visitor(Ctx) {}

  void HandleTranslationUnit(clang::ASTContext &Ctx) override {
    Visitor.TraverseDecl(Ctx.getTranslationUnitDecl());
  }

private:
  ParseASTVisitor Visitor;
};

class ParseASTAction : public clang::ASTFrontendAction {
protected:
  std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(clang::CompilerInstance &CI,
                    llvm::StringRef InFile) override {
    return std::make_unique<ParseASTConsumer>(&CI.getASTContext());
  }
};

int main(int argc, const char *argv[]) {
  clang::tooling::CommonOptionsParser Op(argc, argv, ASTParserCategory);
  clang::tooling::ClangTool Tool(Op.getCompilations(), Op.getSourcePathList());

  clang::tooling::ArgumentsAdjuster Ardj1 =
      clang::tooling::getInsertArgumentAdjuster("-I/usr/local/include/c++/v1");
  clang::tooling::ArgumentsAdjuster Ardj2 =
      clang::tooling::getInsertArgumentAdjuster("-I/usr/local/lib/clang/7.0.0/include");
  Tool.appendArgumentsAdjuster(Ardj1);
  Tool.appendArgumentsAdjuster(Ardj2);

  return Tool.run(
      clang::tooling::newFrontendActionFactory<ParseASTAction>().get());
}
