#include <iostream>

// void foo(int i) {
//   std::cout << "#1: " << i << std::endl;
// }

void foo(int& i) {
  std::cout << "#2: " << i << std::endl;
}

void foo(int&& i) {
  std::cout << "#3: " << i << std::endl;
}

int main() {
  int&& r = 42;
  foo(std::move(r));
  return 0;
}
