#pragma once

#include <railway/execution/executor.hpp>
#include <railway/execution/job.hpp>

namespace railway {

namespace execution {

class Strand {
 public:
  explicit Strand(IExecutor& underlying_executor) noexcept;

  void Execute() noexcept override;

 private:
  IExecutor& underlying_executor_;
};

}  // namespace execution

}  // namespace railway