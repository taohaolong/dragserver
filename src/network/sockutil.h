//
// Created by tao Jacky on 11/16/16.
//

#ifndef DRAGONAVS_SOCKUTIL_H
#define DRAGONAVS_SOCKUTIL_H

#include "dragEvent.h"
#include "inet_address.h"

BEGIN_NAME_SPACE(NetDrag)

class Socket {

public:
    static void Init();

    static evutil_socket_t create_udp();

    static evutil_socket_t create_tcp();

    static int bind(evutil_socket_t, const InetAddress &);

    static int connect(evutil_socket_t, const InetAddress &);

    static int listen(evutil_socket_t, int backlog = 100);

    static evutil_socket_t accept(evutil_socket_t, InetAddress &);

    static int send(evutil_socket_t, const char *, size_t, int);

    static int recv(evutil_socket_t, char *, size_t, int);

    static sockaddr_in get_local_addr(evutil_socket_t);

    static sockaddr_in get_peer_addr(evutil_socket_t);

    static int error();

    static int socket_error(evutil_socket_t);

    static int nonblocking(evutil_socket_t);

    static int reuseable(evutil_socket_t);

    static int closeonexec(evutil_socket_t);

    static int shutdown_write(evutil_socket_t);

    static void close(evutil_socket_t &);

    static bool would_block();

    static bool emfile();

    static void gettimeofday(struct timeval *, struct timezone *);

    static int get_socket_sendbuf(evutil_socket_t);

    static void set_socket_sendbuf(evutil_socket_t, int);

    static int get_socket_recvbuf(evutil_socket_t);

    static void set_socket_recvbuf(evutil_socket_t, int);

    static int set_socket_tos(evutil_socket_t fd, int dscp);

};

END_NAME_SPACE


#endif //DRAGONAVS_SOCKUTIL_H
