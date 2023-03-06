#include <railway/transport/mac/socket.hpp>

namespace railway {

namespace transport {

namespace mac {

AsyncAcceptor Socket::Accept() {
  return AsyncAcceptor{this->state_};
}

AsyncReader Socket::Read() {
  return AsyncReader{this->state_};
}

AsyncWriter Socket::Write() {
  return AsyncWriter{this->state_};
}

Socket::Socket(State* state, IStateSource* state_source)
    : StateReference{state, state_source} {
}

}  // namespace mac

}  // namespace transport

}  // namespace railway