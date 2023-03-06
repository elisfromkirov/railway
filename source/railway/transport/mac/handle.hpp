#pragma once

namespace railway {

namespace transport {

namespace mac {

class Handle {
 public:
  explicit Handle(int handle) noexcept;

  Handle(Handle&& other) noexcept;
  Handle& operator=(Handle&& other) noexcept;

 protected:
  ~Handle() noexcept;

  void Swap(Handle& other) noexcept;

 protected:
  int handle_;
};

}  // namespace mac

}  // namespace transport

}  // namespace railway