#include <railway/transport/linux/reactor.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

ReactorEntry* Reactor::Add(Handle handle) noexcept {
  /// TODO: Implement
}

void Reactor::Remove(ReactorEntry* entry) noexcept {
  /// TODO: Implement
}

}  // namespace transport

}  // namespace railway

#endif