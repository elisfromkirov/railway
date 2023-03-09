#pragma once

#include <railway/fault/atomic.hpp>

#include <railway/infra/node.hpp>

namespace railway {

namespace infra {

class MPSCQueue {
 public:
  MPSCQueue() noexcept;

  void Push(Node* node) noexcept;

  Node* Grab() noexcept;

 private:
  fault::atomic<Node*> head_;
};

}  // namespace infra

}  // namespace railway