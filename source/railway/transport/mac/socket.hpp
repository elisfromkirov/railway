#pragma once

#include <railway/transport/mac/async_acceptor.hpp>
#include <railway/transport/mac/async_reader.hpp>
#include <railway/transport/mac/async_writer.hpp>

#include "state_reference.hpp"

namespace railway {

namespace transport {

namespace mac {

class Socket final : private StateReference {
  friend class Reactor;

 public:
  AsyncAcceptor Accept();

  AsyncReader Read();

  AsyncWriter Write();

 private:
  Socket(State* state, IStateSource* state_source);
};

}  // namespace mac

}  // namespace transport

}  // namespace railway