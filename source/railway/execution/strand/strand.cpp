#include <railway/execution/strand/strand.hpp>

namespace railway {

namespace execution {

Strand::Strand(IExecutor& underlying_executor) noexcept
    : underlying_executor_{underlying_executor} {
}

void Strand::Execute() noexcept {
  /// TODO: Implement it!
}

}  // namespace execution

}  // namespace railway