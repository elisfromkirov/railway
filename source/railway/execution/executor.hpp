#pragma once

#include <railway/execution/job.hpp>

namespace railway {

namespace execution {

class IExecutor {
 public:
  virtual ~IExecutor() noexcept = default;

  virtual void Execute() noexcept = 0;
};

}  // namespace execution

}  // namespace railway