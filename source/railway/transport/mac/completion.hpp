#pragma once

namespace railway {

namespace transport {

namespace mac {

class ICompletion {
 public:
  virtual ~ICompletion() noexcept = default;

  virtual void Complete() noexcept = 0;
};

}  // namespace mac

}  // namespace transport

} // namespace railway