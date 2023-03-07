#pragma once

#include <railway/core/core.hpp>
#include <railway/core/platform.hpp>

#include <railway/fault/atomic.hpp>

#include <railway/transport/linux/handle.hpp>
#include <railway/transport/linux/completion.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

class ReactorEntry : private Handle {
 public:
  explicit ReactorEntry(Handle handle) noexcept;

  int GetHandle() const noexcept;

  ICompletion* ResetReadingCompletion(ICompletion* reading_completion) noexcept;

  ICompletion* ResetWritingCompletion(ICompletion* writing_completion) noexcept;

 private:
  fault::atomic<ICompletion*> reading_completion_;
  fault::atomic<ICompletion*> writing_completion_;
};

}  // namespace transport

}  // namespace railway

#endif