#include <experimental/coroutine>
#include <future>
#include <iostream>

template <typename R, typename... Args>
struct std::experimental::coroutine_traits<std::future<R>, Args...> {
  struct promise_type {
    std::promise<R> p;

    suspend_never initial_suspend() { return {}; }
    suspend_never final_suspend() { return {}; }

    auto get_return_object() { return p.get_future(); }
    void unhandled_exception() { p.set_exception(std::current_exception()); }

    void return_value(R v) { p.set_value(v); }
  };
};

using promise_type =
    std::experimental::coroutine_traits<std::future<int>>::promise_type;

std::future<int> f() {
  std::puts("Hello");
  co_return 42;
}

/// f() will be tranfered like this by compiler with -fcoroutines-ts flag.
/// source from: CppCon 2017 - Toby Allsopp "Coroutines: what can't they do?"
// std::future<int> f_transfered() {
//   promise_type p;
//   auto r = p.get_return_object();
//   co_await p.initial_suspend();
//   try {
//     std::puts("hello");
//     p.return_value(42);
//   } catch() {
//     p.unhandled_exception();
//   }
// final_suspend:
//   co_await p.final_suspend();
// destroy:
// }

int main() {
  std::cout << f().get() << std::endl;
  return 0;
}
