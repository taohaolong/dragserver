/*
 *
 * 系统网络头文件Include
 *
 * Created by tao Jacky on 11/16/16.
 *
 */

#ifndef DRAGONAVS_BASE_SOCK_H
#define DRAGONAVS_BASE_SOCK_H

#include <sys/types.h>

#ifdef WIN32

#include <winsock2.h>
#include <wsipx.h>
#include <wsnwlink.h>
typedef int socklen_t;

#else
// UNIX/LUNIX SOCKET Header Fifle

#include <>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <poll.h>
#include <netinet/tcp.h>

typedef int SOCKET;
#define INVALID_SOCKET        -1
#define SOCKET_ERROR -1


#endif

#endif //DRAGONAVS_BASE_SOCK_H
