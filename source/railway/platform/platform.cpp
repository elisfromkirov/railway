#include <railway/platform/platform.hpp>

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__)

#include <arpa/inet.h>

#include <sys/epoll.h>
#include <sys/socket.h>

#include <alloca.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

namespace railway {

namespace platform {

int Connect(uint address, ushort port) {
  int handle{};
  int result{};

  struct sockaddr_in peer = {
      .sin_family = AF_INET,
      .sin_port = htons(port),
      .sin_addr = {
          .s_addr = htonl(address)
      }
  };

  handle = socket(AF_INET, SOCK_STREAM, 0);
  if (handle == -1) {
    return -1;  // TODO: Return error "unable to make socket"
  }

  result = connect(handle, (const struct sockaddr*)&peer, sizeof(struct sockaddr_in));
  if (result == -1) {
    close(handle);
    return -1; // TODO: Return error "unable to establish connection"
  }

  result = fcntl(handle, F_GETFL);
  if (result == -1) {
    close(handle);
    return -1; // TODO: Return error "unable to mark socket non-blocking"
  }

  result = fcntl(handle, F_SETFL, result | O_NONBLOCK);
  if (result == -1) {
    close(handle);
    return -1; // TODO: Return error "unable to mark socket non-blocking"
  }

  return handle;
}

int Listen(uint address, ushort port) {
  int handle{};
  int result{};

  struct sockaddr_in peer = {
    .sin_family = AF_INET,
    .sin_port = htons(port),
    .sin_addr = {
      .s_addr = htonl(address)
    }
  };

  handle = socket(AF_INET, SOCK_STREAM, 0);
  if (handle == -1) {
    return -1;  // TODO: Return error "unable to make socket"
  }

  result = bind(handle, (const struct sockaddr*)&peer, sizeof(struct sockaddr_in));
  if (result == -1) {
    close(handle);
    return -1;  // TODO: Return error "unable to bind endpoint to socket"
  }

  result = listen(handle, SOMAXCONN);
  if (result == -1) {
    close(handle);
    return -1; // TODO: Return error "unable to mark socket as listener"
  }

  result = fcntl(handle, F_GETFL);
  if (result == -1) {
    close(handle);
    return -1; // TODO: Return error "unable to mark socket non-blocking"
  }

  result = fcntl(handle, F_SETFL, result | O_NONBLOCK);
  if (result == -1) {
    close(handle);
    return -1; // TODO: Return error "unable to mark socket non-blocking"
  }

  return handle;
}

void Close(int handle) {
  close(handle);
}

ulong Read(int handle, char* buffer, ulong size) {
  return read(handle, buffer, size);
}

ulong Write(int handle, const char* buffer, ulong size) {
  return write(handle, buffer, size);
}

int MakePoll() {
  return epoll_create1(0);
}

ulong Poll(int poll, Event* event, ulong size) {
  epoll_event* events = (epoll_event*)alloca(size * sizeof(events));
  memset(events, 0, size * sizeof(events));

  int result = epoll_wait(poll, events, size, -1);
  if (result == -1) {
    return 0; // TODO: Return "poll error"
  }

  for (int i = 0; i < result; ++i) {
    event[i].reading_available = ((events[i].events & EPOLLIN) == EPOLLIN);
    event[i].writing_available = ((events[i].events & EPOLLOUT) == EPOLLOUT);
    event[i].state = events[i].data.ptr;
  }
}

void EnqueueHandle(int poll, int handle, void* state) {
  epoll_event event{
    .events = EPOLLIN | EPOLLOUT,
    .data = { .ptr = state }
  };
  epoll_ctl(poll, EPOLL_CTL_ADD, handle, &event);
}

void DequeueHandle(int poll, int handle) {
  epoll_event event{};
  epoll_ctl(poll, EPOLL_CTL_DEL, handle, &event);
}

}  // namespace platform

}  // namespace railway

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)

#error Platform not supported

#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

#error Platform not supported

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

#error Platform not supported

#else

#error Platform not supported

#endif