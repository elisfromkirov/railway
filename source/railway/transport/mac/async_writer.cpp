#include <railway/transport/mac/async_writer.hpp>

namespace railway {

namespace transport {

namespace mac {

AsyncWriter::AsyncWriter(State* state) noexcept {
  state->ResetReadingCompletion(this);
}

void AsyncWriter::Complete() noexcept {
}

}  // namespace mac

}  // namespace transport

}  // namespace railway