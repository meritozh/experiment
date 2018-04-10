#include <iostream>
#include <thread>
#include <chrono>
#include <future>

void foo() {
  // simulate expensive operation
  std::this_thread::sleep_for(std::chrono::seconds(10));
}

void bar() {
  // simulate expensive operation
  std::this_thread::sleep_for(std::chrono::seconds(5));
}

int async_job() {
  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 1;
}

int main() {
  std::cout << "starting first helper...\n";
  std::thread helper1(foo);

  std::cout << "starting second helper...\n";
  std::thread helper2(bar);

  std::cout << "waiting for helpers to finish..." << std::endl;
  helper1.join();
  helper2.join();

  std::cout << "done!\n";

  auto ret = std::async(std::launch::async, async_job);

  std::cout << "run job async: " << std::flush;
  auto duration = 1;
  while (ret.wait_for(std::chrono::seconds(1)) != std::future_status::ready) {
    std::cout << duration++ << " " << std::flush;
  }
  std::cout << "\n";
  std::cout <<  ret.get() << std::endl;

  std::cout << "done!\n";
}
