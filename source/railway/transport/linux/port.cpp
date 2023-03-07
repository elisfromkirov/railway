#include <railway/transport/linux/port.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

Port::Port(Uint16 port) noexcept
    : port_{port} {
}

Uint16 Port::ToHostByteOrder() const noexcept {
  return port_;
}

Uint16 Port::ToNetworkByteOrder() const noexcept {
  return htons(port_);
}

}  // namespace transport

}  // namespace railway

#endif