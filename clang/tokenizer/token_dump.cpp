
template <typename T>
class Stack {
private:
  T elements[];

public:
  void push(T e) {
    this->elements[0] = e;
  }
};

int main() {
  auto s = Stack<int>();
  s.push(5);
}
