#include <railway/fault/injection/yield_injector.hpp>

namespace railway {

namespace fault {

namespace injection {

YieldInjector::YieldInjector(NumericType frequency, NumericType seed) noexcept
    : until_inject_{frequency},
      frequency_{frequency},
      twister_{seed} {
}

void YieldInjector::Inject() noexcept {
  until_inject_ -= 1;
  if (until_inject_ == 0) {
    until_inject_ = twister_() % frequency_;
    std::this_thread::yield();
  }
}

}  // namespace injection

}  // namespace fault

}  // namespace railway