#include <iostream>
#include <thread>

using namespace std;

int main() {
  cout << "current OS support number of thread: "
       << thread::hardware_concurrency() << endl;
  return 0;
}
