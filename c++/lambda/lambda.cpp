#include <iostream>
#include <functional>
#include <cstdio>

void test_lambda(std::function<int()> lambda) {
  int i = lambda();
  std::cout << i << std::endl;
}

int main() {
  test_lambda([]() {
        printf("%p\n", __builtin_return_address(0));
        int i = 5;
        return 5;
      });

  return 0;
}
