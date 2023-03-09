#pragma once

#include <railway/fault/atomic.hpp>

#include <railway/infra/node.hpp>

#include <railway/platform/platform.hpp>

#include <railway/transport/linux/detail/completion.hpp>
#include <railway/transport/linux/detail/handle.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

namespace detail {

class ReactorState : private Handle,
                     private infra::Node {
 public:
  explicit ReactorState(Handle handle) noexcept;

  int GetHandle() const noexcept;

  ICompletion* ResetReadingCompletion(ICompletion* reading_completion) noexcept;

  ICompletion* ResetWritingCompletion(ICompletion* writing_completion) noexcept;

 private:
  fault::atomic<ICompletion*> reading_completion_;
  fault::atomic<ICompletion*> writing_completion_;
};

}  // namespace detail

}  // namespace transport

}  // namespace railway

#endif