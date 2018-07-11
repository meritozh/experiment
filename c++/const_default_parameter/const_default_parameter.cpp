#include <iostream>
#include <string_view>

void print(const std::string_view str = "foobar") {
  std::cout << str << std::endl;
}

int main() {
  print();
  print("hello, meritozh.");
  return 0;
}
