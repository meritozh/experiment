#include <vector>
#include <iostream>

struct A {
  int a[100];
  A() {}
  A(const A& other) noexcept {
    std::cout << "copy" << std::endl;
  }
  A(A&& other) noexcept {
    std::cout << "move" << std::endl;
  }
};

void foo(const A& a) {
  std::vector<A> vA;
  vA.push_back(std::move(a));
}

void bar(A&& a) {
  std::vector<A> vA;
  vA.push_back(std::move(a));
}

int main () {
  A a;
  foo(a);            // "copy"
  bar(std::move(a)); // "move"
}
