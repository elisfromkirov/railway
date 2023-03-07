#include <railway/transport/linux/address.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

Address::Address(Uint32 address) noexcept
    : address_{address} {
}

Address::Address(const char* address) noexcept
    : address_{inet_addr(address)} {
}

Uint32 Address::ToHostByteOrder() const noexcept {
  return address_;
}

Uint32 Address::ToNetworkByteOrder() const noexcept {
  return htonl(address_);
}

}  // namespace transport

}  // namespace railway

#endif