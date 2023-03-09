#pragma once

#include <railway/execution/executor.hpp>
#include <railway/execution/job.hpp>

#include <railway/platform/platform.hpp>

#include <railway/transport/linux/detail/handle.hpp>
#include <railway/transport/linux/detail/reactor_state.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

namespace detail {

class Reactor : private Handle,
                private execution::IJob {
 public:
  explicit Reactor(execution::IExecutor& executor);

  ReactorState* Add(Handle handle) noexcept;

  void Remove(ReactorState* state) noexcept;

 private:
  void Run() noexcept;

  bool Done() const noexcept;

 private:
  execution::IExecutor& executor_;

  /// TODO: Add MPSCQueue of reactor states to register
  /// TODO: Add MPSCQueue of reactor states to deregister

  /// TODO: Add atomic counter of registered reactor states
};

}  // namespace detail

}  // namespace transport

}  // namespace railway

#endif