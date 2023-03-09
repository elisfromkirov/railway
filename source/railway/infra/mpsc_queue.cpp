#include <railway/infra/algorithm.hpp>
#include <railway/infra/mpsc_queue.hpp>

namespace railway {

namespace infra {

MPSCQueue::MPSCQueue() noexcept
    : head_{nullptr} {
}

void MPSCQueue::Push(Node* node) noexcept {
  auto curr_head = head_.load();
  do {
    node->Next() = curr_head;
  } while (!head_.compare_exchange_weak(curr_head, node));
}

Node* MPSCQueue::Grab() noexcept {
  return Reverse(head_.exchange(nullptr));
}

}  // namespace infra

}  // namespace railway