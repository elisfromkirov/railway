#include <railway/transport/mac/state_reference.hpp>

namespace railway {

namespace transport {

namespace mac {

StateReference::StateReference(State* state, IStateSource* state_source) noexcept
    : state_{state},
      state_source_{state_source} {
}

StateReference::~StateReference() noexcept {
  state_source_->Release(state_);
}

}  // namespace mac

}  // namespace transport

}  // namespace railway