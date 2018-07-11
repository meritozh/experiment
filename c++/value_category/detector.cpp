#include <iostream>

namespace detector {
  template <typename T>
  struct value_category {
    static constexpr const char* value = "prvalue";
  };

  template <typename T>
  struct value_category<T&> {
    static constexpr const char* value = "lvalue";
  };

  template <typename T>
  struct value_category<T&&> {
    static constexpr const char* value = "xvalue";
  };
}

#define PRINT_VALUE_CATEGORY(expr) \
  std::cout << #expr << " is a " \
            << ::detector::value_category<decltype((expr))>::value \
            << "\n";

int main() {
  struct S {
    int i;
  };

  S s{1};

  PRINT_VALUE_CATEGORY(4);
  PRINT_VALUE_CATEGORY(s);
  PRINT_VALUE_CATEGORY(S{3});
  PRINT_VALUE_CATEGORY(std::move(S{4}));
  PRINT_VALUE_CATEGORY(S{2}.i);

  return 0;
}
