#pragma once

#include <railway/fault/atomic.hpp>

#include <railway/transport/mac/handle.hpp>
#include <railway/transport/mac/completion.hpp>

namespace railway {

namespace transport {

namespace mac {

class State : private Handle {
 public:
  explicit State(int handle) noexcept;

  int GetHandle() const noexcept;

  ICompletion* ResetReadingCompletion(ICompletion* reading_completion) noexcept;

  ICompletion* ResetWritingCompletion(ICompletion* writing_completion) noexcept;

 private:
  fault::atomic<ICompletion*> reading_completion_;
  fault::atomic<ICompletion*> writing_completion_;
};

}  // namespace mac

}  // namespace transport

}  // namespace railway