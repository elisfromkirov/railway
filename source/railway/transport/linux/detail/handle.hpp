#pragma once

#include <railway/platform/platform.hpp>

#include <utility>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

namespace detail {

class Handle {
 public:
  explicit Handle(int handle = 0) noexcept;

  Handle(Handle&& other) noexcept;
  Handle& operator=(Handle&& other) noexcept;

  ~Handle() noexcept;

 protected:
  void Swap(Handle& other) noexcept;

 protected:
  int handle_;
};

}  // namespace handle

}  // namespace transport

}  // namespace railway

#endif