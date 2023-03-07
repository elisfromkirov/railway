#pragma once

#include <railway/core/core.hpp>
#include <railway/core/platform.hpp>

#include <railway/transport/linux/handle.hpp>
#include <railway/transport/linux/reactor_entry.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

/// TODO: Reactor has a Job
class Reactor : private Handle {
 public:
  /// TODO: Add reactor constructor from reference to executor

  ReactorEntry* Add(Handle handle) noexcept;

  void Remove(ReactorEntry* entry) noexcept;

 private:
  /// TODO: Add Run() method where reactor polls i/o events

 private:
  /// TODO: Add strand where all reactor tasks will be executed
};

}  // namespace transport

}  // namespace railway

#endif