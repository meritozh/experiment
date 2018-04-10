int& foo() {
  int i = 5;
  return i;
}

int main() {
  int& foo();
  int pi = foo();
  foo() = 55;
  return foo();
}
