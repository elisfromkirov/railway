#include <railway/infra/node.hpp>

namespace railway {

namespace infra {

Node::Node(Node* next) noexcept
    : next_{next} {
}

}  // namespace infra

}  // namespace railway