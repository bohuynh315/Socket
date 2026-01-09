#ifndef CORE_SOCKET_DEFINES_H
#define CORE_SOCKET_DEFINES_H

#include <netinet/in.h>
#include <functional>

typedef int SocketHandle_t;
typedef struct sockaddr_in SocketAddress_t;

#define MIN_PORT_NUMBER 1024
#define MAX_PORT_NUMBER 65535

#define MAX_CONNECTIONS 10

typedef struct {
    const char* ip;
    int port;
} endpoint_t;

typedef std::function<void(const char* message, const size_t length)> message_handler_t;

#endif // CORE_SOCKET_DEFINES_H
