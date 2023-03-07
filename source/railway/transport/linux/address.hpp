#pragma once

#include <railway/core/core.hpp>
#include <railway/core/platform.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

class Address {
 public:
  Address(Uint32 address) noexcept;

  Address(const char* address) noexcept;

  Uint32 ToHostByteOrder() const noexcept;

  Uint32 ToNetworkByteOrder() const noexcept;

 private:
  Uint32 address_;
};

}  // namespace transport

}  // namespace railway

#endif