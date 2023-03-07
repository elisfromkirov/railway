#pragma once

#include <railway/core/core.hpp>
#include <railway/core/platform.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

class ICompletion {
 public:
  virtual ~ICompletion() noexcept = default;

  virtual void Complete() noexcept = 0;
};

}  // namespace transport

} // namespace railway

#endif