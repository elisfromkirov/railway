#pragma once

#include <railway/transport/mac/state.hpp>

namespace railway {

namespace transport {

namespace mac {

class IStateSource {
 public:
  virtual ~IStateSource() noexcept = 0;

  virtual void Release(State* state) noexcept = 0;
};

}  // namespace mac

}  // namespace transport

}  // namespace railway