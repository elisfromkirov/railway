#pragma once

#include <railway/transport/mac/completion.hpp>
#include <railway/transport/mac/state.hpp>

namespace railway {

namespace transport {

namespace mac {

class AsyncWriter : private ICompletion {
  friend class Socket;

 private:
  AsyncWriter(State* state) noexcept;

 private:
  void Complete() noexcept override;
};

}  // namespace mac

}  // namespace transport

}  // namespace railway