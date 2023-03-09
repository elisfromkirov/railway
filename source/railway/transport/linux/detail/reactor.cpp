#include <railway/transport/linux/detail/reactor.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

namespace detail {

Reactor::Reactor(execution::IExecutor& executor)
    : Handle{0},
      strand_{executor} {
  handle_ = epoll_create1(0);
}

ReactorState* Reactor::Add(Handle handle) noexcept {
  /// TODO: Replace by unique pointer
  auto state = new ReactorState{std::move(handle)};
  execution::Execute(strand_, [=]() {
    /// TODO: Replace it by single function
    epoll_event event{};
    event.data.ptr = state;
    event.events = EPOLLIN | EPOLLOUT;
    epoll_ctl(handle_, EPOLL_CTL_ADD, state->GetHandle(), &event);
  });
  return state;
}

/// TODO: replace it by unique pointer
void Reactor::Remove(ReactorState* state) noexcept {
  execution::Execute(strand_, [=]() {
    /// TODO: Replace it by single function
    epoll_event event{};
    epoll_ctl(handle_, EPOLL_CTL_DEL, state->GetHandle(), &event);
    delete state;
  });
}

/// TODO: This function is lost ...
void Reactor::Run() noexcept {
  epoll_event events[16];
  auto num_events = epoll_wait(handle_, events, 16, -1);
  for (auto i = 0; i < num_events; ++i) {
    auto state = static_cast<ReactorState*>(events[i].data.ptr);
    if ((events[i].events & EPOLLIN) == EPOLLIN) {
      if (auto reading_completion = state->ResetReadingCompletion(nullptr)) {
        reading_completion->Complete();
      }
    }
    if ((events[i].events & EPOLLOUT) == EPOLLOUT) {
      if (auto writing_completion = state->ResetWritingCompletion(nullptr)) {
        writing_completion->Complete();
      }
    }
  }
}

bool Reactor::Done() const noexcept {
  return false;
}

}  // namespace detail

}  // namespace transport

}  // namespace railway

#endif