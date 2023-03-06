#include <railway/transport/mac/async_reader.hpp>

namespace railway {

namespace transport {

namespace mac {

AsyncReader::AsyncReader(State* state) noexcept {
  state->ResetReadingCompletion(this);
}

void AsyncReader::Complete() noexcept {
}

}  // namespace mac

}  // namespace transport

}  // namespace railway