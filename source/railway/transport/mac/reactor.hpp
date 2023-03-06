#pragma once

#include <railway/transport/mac/state.hpp>
#include <railway/transport/mac/state_source.hpp>

namespace railway {

namespace transport {

namespace mac {

class Reactor final : private IStateSource {
 public:
  Reactor();


 private:
  void Release(State* state) noexcept override;

 private:
  int handle_;
};

}  // namespace mac

}  // namespace transport

}  // namespace railway