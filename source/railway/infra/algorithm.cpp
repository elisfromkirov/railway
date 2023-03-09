#include <railway/infra/algorithm.hpp>

namespace railway {

namespace infra {

Node* Reverse(Node* node) noexcept {
  Node* prev{};
  while (node != nullptr) {
    auto next = node->Next();
    node->Next() = prev;
    prev = node;
    node = next;
  }
  return prev;
}

}  // namespace infra

}  // namespace railway