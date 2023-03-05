#pragma once

#include <random>
#include <thread>

namespace railway {

namespace fault {

namespace injection {

class YieldInjector {
 public:
  using NumericType = std::mt19937::result_type;
  using Twister = std::mt19937;

 public:
  static constexpr const NumericType kDefaultFrequency{13};
  static constexpr const NumericType kDefaultSeed{42};

 public:
  explicit YieldInjector(NumericType frequency = kDefaultFrequency,
                         NumericType seed = kDefaultSeed) noexcept;

  void Inject() noexcept;

 private:
  NumericType until_inject_;
  NumericType frequency_;
  Twister twister_;
};

}  // namespace injection

}  // namespace fault

}  // namespace railway