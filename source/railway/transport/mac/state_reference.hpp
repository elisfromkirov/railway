#pragma once

#include <railway/transport/mac/state.hpp>
#include <railway/transport/mac/state_source.hpp>

namespace railway {

namespace transport {

namespace mac {

class StateReference {
 public:
  explicit StateReference(State* state, IStateSource* state_source) noexcept;

  StateReference(StateReference&& other) noexcept = delete;
  StateReference& operator=(StateReference&& other) noexcept = delete;

 protected:
  ~StateReference() noexcept;

 protected:
  State* state_;

 private:
  IStateSource* state_source_;
};

}  // namespace mac

}  // namespace transport

}  // namespace railway