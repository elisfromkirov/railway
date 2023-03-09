#pragma once

#include <railway/execution/execute.hpp>
#include <railway/execution/executor.hpp>
#include <railway/execution/job.hpp>

#include <railway/execution/strand/strand.hpp>

#include <railway/platform/platform.hpp>

#include <railway/transport/linux/detail/handle.hpp>
#include <railway/transport/linux/detail/reactor_state.hpp>

#include <utility>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

namespace detail {

class Reactor : private Handle,
                private execution::IJob {
 public:
  explicit Reactor(execution::IExecutor& underlying_executor);

  ReactorState* Add(Handle handle) noexcept;

  void Remove(ReactorState* state) noexcept;

 private:
  void Run() noexcept;

  bool Done() const noexcept;

 private:
  execution::Strand strand_;
  fault::atomic<unsigned int> size_;
};

}  // namespace detail

}  // namespace transport

}  // namespace railway

#endif