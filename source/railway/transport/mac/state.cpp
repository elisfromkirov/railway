#include <railway/transport/mac/state.hpp>

namespace railway {

namespace transport {

namespace mac {

namespace detail {

State::State(int handle) noexcept
    : Handle{handle},
      reading_completion_{},
      writing_completion_{} {
}

int State::GetHandle() const noexcept {
  return handle_;
}

ICompletion* State::ResetReadingCompletion(ICompletion* reading_completion) noexcept {
  return reading_completion_.exchange(reading_completion);
}

ICompletion* State::ResetWritingCompletion(ICompletion* writing_completion) noexcept {
  return writing_completion_.exchange(writing_completion);
}

}  // namespace detail

}  // namespace mac

}  // namespace transport

}  // namespace railway