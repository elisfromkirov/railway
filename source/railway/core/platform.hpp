#pragma once

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)

#define LINUX_TRANSPORT

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <unistd.h>

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)

#define BSD_TRANSPORT

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

#define WINDOWS_TRANSPORT

#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

#define MAC_TRANSPORT

#else

#error Platform not supported

#endif