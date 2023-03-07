#pragma once

#include <railway/core/core.hpp>
#include <railway/core/platform.hpp>

#include <railway/transport/linux/address.hpp>
#include <railway/transport/linux/port.hpp>
#include <railway/transport/linux/socket.hpp>
#include <railway/transport/linux/reactor.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

class Transport {
 public:
  /// TODO: Add transport constructor from reference to executor

  Socket Listen(Address address, Port port) noexcept;

  Socket Connect(Address address, Port port) noexcept;

 private:
  Reactor reactor_;
};

}  // namespace transport

}  // namespace railway

#endif