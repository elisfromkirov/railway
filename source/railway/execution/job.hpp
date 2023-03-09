#pragma once

#include <railway/infra/node.hpp>

namespace railway {

namespace execution {

class IJob : public infra::Node {
 public:
  virtual ~IJob() noexcept = default;

  /// TODO: Can method IJob::Run throw an exception? Why?
  virtual void Run() noexcept = 0;

  virtual bool Done() const noexcept = 0;
};

}  // namespace execution

}  // namespace railway