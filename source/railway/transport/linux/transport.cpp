#include <railway/transport/linux/transport.hpp>

#if defined(LINUX_TRANSPORT)

namespace railway {

namespace transport {

Socket Transport::Listen(Address address, Port port) noexcept {
  /// TODO: Handle error using wheels::Result
  /// TODO: Wrap sockfd to Handle
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in sockaddr {
    .sin_family = AF_INET,
    .sin_addr = address.ToNetworkByteOrder(),
    .sin_port = port.ToNetworkByteOrder()
  };

  /// TODO: Handle error using wheels::Result
  bind(sockfd, (const struct sockaddr*)&sockaddr, sizeof(struct sockaddr_in));

  /// TODO: Handle error using wheels::Result
  listen(sockfd, SOMAXCONN);

  /// TODO: Handle error using wheels::Result
  int flags = fcntl(sockfd, F_GETFL);

  /// TODO: Handle error using wheels::Result
  fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

  /// TODO: Handle error using wheels::Result
  ReactorEntry* entry = reactor_.Add(Handle{sockfd});

  /// return Socket{entry};
}

Socket Transport::Connect(Address address, Port port) noexcept {
  /// TODO: Handle error using wheels::Result
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in sockaddr {
    .sin_family = AF_INET,
    .sin_addr = address.ToNetworkByteOrder(),
    .sin_port = port.ToNetworkByteOrder()
  };

  /// TODO:
  connect(sockfd, (const struct sockaddr*)&sockaddr, sizeof(struct sockaddr_in));


}

}  // namespace transport

}  // namespace railway

#endif