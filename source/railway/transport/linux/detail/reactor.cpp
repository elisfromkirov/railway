#include <railway/transport/linux/detail/reactor.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

namespace detail {

Reactor::Reactor(execution::IExecutor& executor)
    : Handle{epoll_create1(0)},
      executor_{executor} {
}

ReactorState* Reactor::Add(Handle handle) noexcept {
  // Allocate state
  // Push to queue
  // Return state
}

void Reactor::Remove(ReactorState* state) noexcept {
  // Push to queue
}

void Reactor::Run() noexcept {
  /// TODO: Implement it
}

bool Reactor::Done() const noexcept {
  return false;
}

}  // namespace detail

}  // namespace transport

}  // namespace railway

#endif