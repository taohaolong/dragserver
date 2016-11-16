//
// Created by tao Jacky on 11/16/16.
//

#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "sockutil.h"
#include "base/base_sock.h"

#include <stdio.h>

BEGIN_NAME_SPACE(NetDrag)

evutil_socket_t Socket::create_tcp() {

#ifndef NETPRINT
    printf("evutil_socket_t Socket::create_tcp() \n");
#endif


    return ::socket(AF_INET, SOCK_STREAM, 0);
}



evutil_socket_t Socket::create_udp() {

    return ::socket(AF_INET, SOCK_DGRAM, 0);
}

END_NAME_SPACE