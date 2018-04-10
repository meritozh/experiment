#include <thread>
#include <chrono>
#include <future>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

auto accumulate_block_worker_ret(int *data, size_t count) {
  this_thread::sleep_for(chrono::seconds(5));
  return accumulate(data, data + count, 0);
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
  auto fut = async(launch::async, accumulate_block_worker_ret, v.data(), v.size());
  while (fut.wait_for(chrono::seconds(2)) != future_status::ready) {
    cout << "... still not ready\n";
  }
  cout << "use_worker_in_std_async computed " << fut.get() << "\n";
  return 0;
}
