#pragma once

#include <railway/platform/platform.hpp>

#include <railway/execution/executor.hpp>

#include <railway/transport/linux/address.hpp>
#include <railway/transport/linux/port.hpp>
#include <railway/transport/linux/socket.hpp>

#include <railway/transport/linux/detail/reactor.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

class Transport {
 public:
  Transport(execution::IExecutor& executor);

  Socket Listen(Address address, Port port) noexcept;

  Socket Connect(Address address, Port port) noexcept;

 private:
  detail::Reactor reactor_;
};

}  // namespace transport

}  // namespace railway

#endif