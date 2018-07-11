#include <string>
#include <string_view>
#include <memory>
#include <iostream>

class PerfectString {
public:
  PerfectString(const std::string_view D) {
    this->Length = D.length();
    this->Data = std::make_shared<char*>(new char[this->Length]);
    std::memcpy(this->Data.get(), D.data(), this->Length);
  }
  
  operator std::string_view() {
    return std::string_view(*(this->Data.get()), this->Length);
  }

  std::shared_ptr<char*> Data;
  uint64_t Length;
};

void print(std::string_view sv) {
  std::cout << sv << std::endl;
}

int main() {
  std::string str = "foobar";
  auto S = PerfectString(str);

  print(S);

  return 0;
}
