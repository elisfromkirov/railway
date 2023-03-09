#pragma once

#include <railway/core/core.hpp>
#include "platform/platform.hpp"

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

class Port {
 public:
  Port(Uint16 port) noexcept;

  Uint16 ToHostByteOrder() const noexcept;

  Uint16 ToNetworkByteOrder() const noexcept;

 private:
  Uint16 port_;
};

}  // namespace transport

}  // namespace railway

#endif