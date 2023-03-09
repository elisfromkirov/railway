#include <railway/transport/linux/detail/reactor_state.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

namespace detail {

ReactorState::ReactorState(Handle handle) noexcept
    : Handle{std::move(handle)},
      reading_completion_{},
      writing_completion_{} {
}

int ReactorState::GetHandle() const noexcept {
  return handle_;
}

ICompletion* ReactorState::ResetReadingCompletion(
    ICompletion* reading_completion) noexcept {
  return reading_completion_.exchange(reading_completion);
}

ICompletion* ReactorState::ResetWritingCompletion(
    ICompletion* writing_completion) noexcept {
  return writing_completion_.exchange(writing_completion);
}

}  // namespace detail

}  // namespace transport

}  // namespace railway

#endif