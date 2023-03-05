#pragma once

#if !defined(FAULT_INJECTION)

#include <atomic>

namespace railway {

namespace fault {

template <typename type>
using atomic = std::atomic<type>;

}  // namespace fault

}  // namespace railway

#else

#include <railway/fault/injection/inject.hpp>

#include <atomic>

namespace railway {

namespace fault {

template <typename type>
class atomic {
 public:
  atomic() noexcept;

  atomic(type value) noexcept;

  void store(type value, std::memory_order order = std::memory_order_seq_cst) noexcept;

  type load(std::memory_order order = std::memory_order_seq_cst) const noexcept;

  type exchange(type value, std::memory_order order = std::memory_order_seq_cst) noexcept;

  bool compare_exchange_weak(type& expected_value,
                             type value,
                             std::memory_order order = std::memory_order_seq_cst) noexcept;

  bool compare_exchange_weak(type& expected_value,
                             type value,
                             std::memory_order success,
                             std::memory_order failure) noexcept;

 private:
  std::atomic<type> impl_;
};

}  // namespace fault

}  // namespace railway

#endif

#define ATOMIC_IMPL
#include <railway/fault/atomic.ipp>
#undef ATOMIC_IMPL