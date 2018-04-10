[[nodiscard]] async_mutex_lock await_resume() const noexcept {
  return async_mutex_lock{m_mutex, std::adopt_lock};
}
}
;

// == cppcoro/lib/async_mutex.cpp
// =====================================================================================

inline async_mutex::~async_mutex() {
  [[maybe_unused]] auto state = m_state.load(std::memory_order_relaxed);
  assert(state == not_locked || state == locked_no_waiters);
  assert(m_waiters == nullptr);
}

inline bool async_mutex::try_lock() noexcept {
  auto oldState = not_locked;
  return m_state.compare_exchange_strong(oldState, locked_no_waiters,
                                         std::memory_order_acquire,
                                         std::memory_order_relaxed);
}

inline async_mutex_lock_operation async_mutex::lock_async() noexcept {
  return async_mutex_lock_operation{*this};
}

inline async_mutex_scoped_lock_operation
async_mutex::scoped_lock_async() noexcept {
  return async_mutex_scoped_lock_operation{*this};
}

inline void async_mutex::unlock() {
  assert(m_state.load(std::memory_order_relaxed) != not_locked);
