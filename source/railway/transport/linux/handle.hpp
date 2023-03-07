#pragma once

#include <railway/core/core.hpp>
#include <railway/core/platform.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

class Handle {
 public:
  explicit Handle(int handle) noexcept;

  Handle(Handle&& other) noexcept;
  Handle& operator=(Handle&& other) noexcept;

  ~Handle() noexcept;

 protected:
  void Swap(Handle& other) noexcept;

 protected:
  int handle_;
};

}  // namespace transport

}  // namespace railway

#endif