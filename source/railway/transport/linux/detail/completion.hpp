#pragma once

#include <railway/platform/platform.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

namespace detail {

class ICompletion {
 public:
  virtual ~ICompletion() noexcept = default;

  virtual void Complete() noexcept = 0;
};

}  // namespace detail

}  // namespace transport

} // namespace railway

#endif