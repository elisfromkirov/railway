#include <railway/transport/mac/reactor.hpp>

#include <sys/event.h>

namespace railway {

namespace transport {

namespace mac {

Reactor::Reactor()
    : handle_{kqueue()} {
}

}  // namespace mac

}  // namespace transport

}  // namespace railway