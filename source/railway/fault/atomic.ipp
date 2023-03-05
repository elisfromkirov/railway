#if !defined(ATOMIC_IMPL)
#error Do not include this file directly
#endif

#if !defined(FAULT_INJECTION)

namespace railway {

namespace fault {

}  // namespace fault

}  // namespace railway

#else

namespace railway {

namespace fault {

template <typename type>
atomic<type>::atomic() noexcept
    : impl_{} {
}

template <typename type>
atomic<type>::atomic(type value) noexcept
    : impl_{value} {
}

template <typename type>
void atomic<type>::store(type value, std::memory_order order) noexcept {
  Inject();
  impl_.store(value, order);
  Inject();
}

template <typename type>
type atomic<type>::load(std::memory_order order) const noexcept {
  Inject();
  auto result = impl_.load(order);
  Inject();
  return result;
}

template <typename type>
type atomic<type>::exchange(type value, std::memory_order order) noexcept {
  Inject();
  auto result = impl_.exchange(value, order);
  Inject();
  return result();
}

template <typename type>
bool atomic<type>::compare_exchange_weak(type& expected_value, type value,
                                         std::memory_order order) noexcept {
  Inject();
  auto result = impl_.compare_echange_weak(expected_value, value, order);
  Inject();
  return result;
}

template <typename type>
bool atomic<type>::compare_exchange_weak(type& expected, type desired,
                                         std::memory_order success,
                                         std::memory_order failure) noexcept {
  Inject();
  auto result = impl_.compare_echange_weak(expected, desired, success, failure);
  Inject();
  return result;
}

}  // namespace fault

}  // namespace railway

#endif