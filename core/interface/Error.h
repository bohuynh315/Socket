#ifndef ERROR_H
#define ERROR_H

typedef enum {
    E_OK = 0,
    E_FAILED_TO_CREATE_SOCKET = -1,
    E_FAILED_TO_BIND_SOCKET = -2,
    E_FAILED_TO_LISTEN_SOCKET = -3,
    E_INVALID_PARAMETER = -4,
    E_UNKNOWN = -99
} error_t;

#endif // ERROR_H