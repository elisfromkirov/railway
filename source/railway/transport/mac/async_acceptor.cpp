#include <railway/transport/mac/async_acceptor.hpp>

namespace railway {

namespace transport {

namespace mac {

AsyncAcceptor::AsyncAcceptor(State* state) noexcept {
  state_.ResetWritingCompletion(this);
}

void AsyncAcceptor::Complete() noexcept {
}

}  // namespace mac

}  // namespace transport

}  // namespace railway