#include <railway/fault/injection/inject.hpp>
#include <railway/fault/injection/yield_injector.hpp>

namespace railway {

namespace fault {

namespace injection {

void Inject() noexcept {
  static thread_local YieldInjector yield_injector{};
  yield_injector.Inject();
}

}  // namespace injection

}  // namespace fault

}  // namespace railway