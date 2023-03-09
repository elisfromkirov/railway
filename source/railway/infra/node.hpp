#pragma once

#include <type_traits>

namespace railway {

namespace infra {

class Node {
 public:
  explicit Node(Node* next = nullptr) noexcept;

  Node*& Next() noexcept {
    return next_;
  }

  template <typename Derived>
  Derived* As() noexcept {
    static_assert(std::is_base_of_v<Node, Derived>,
                  "node can be casted only to derived type");
    return static_cast<Derived*>(this);
  }

 protected:
  ~Node() noexcept = default;

 private:
  Node* next_;
};

}  // namespace infra

}  // namespace railway