#include <railway/transport/linux/reactor_entry.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

ReactorEntry::ReactorEntry(Handle handle) noexcept
    : Handle{std::move(handle)},
      reading_completion_{},
      writing_completion_{} {
}

int ReactorEntry::GetHandle() const noexcept {
  return handle_;
}

ICompletion* ReactorEntry::ResetReadingCompletion(
    ICompletion* reading_completion) noexcept {
  return reading_completion_.exchange(reading_completion);
}

ICompletion* ReactorEntry::ResetWritingCompletion(
    ICompletion* writing_completion) noexcept {
  return writing_completion_.exchange(writing_completion);
}

}  // namespace transport

}  // namespace railway

#endif