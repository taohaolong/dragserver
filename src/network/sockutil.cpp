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


void signal_handle(int sig) {
    printf("program exit for signal = %d\n", sig);
    exit(0);
}

#ifndef WIN32

void check_linux_release() {
    int stat = 0;
    char result[1024];
    char cmd[1024];
    memset(result, '\0', 1024);
    memset(cmd, '\0', 1024);
    FILE *ptr;
    strcpy(cmd, "uname -r");
    if ((ptr = popen(cmd, "r")) != NULL) {
        while (fgets(result, 1024, ptr) != NULL) {
            if (strlen(result) > 1024) {
                break;
            }
            else if (strlen(result) > 0) {
                stat = 1;
                *(strchr(result, '\n')) = '\0';
            }
            else {
                break;
            }

        }
        pclose(ptr);
        ptr = NULL;
    }
    else {
        printf("popen %s error\n", cmd);
    }
    if (stat) {
        string res(result);
        if (res > "2.6.26") {
            return;
        }
        else {
            printf("program exit for linux release [%s] is too low, must>(2.6.26)!\n", result);
            exit(0);
        }

    }
    else {
        printf("program exit for get linux release error\n");
        exit(0);
    }
}

#endif


void Socket::Init() {
#ifdef        WIN32
    WSADATA wsa_data;
        int	 r = WSAStartup(MAKEWORD(2,2), &wsa_data);
#else
    signal(SIGPIPE, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    signal(SIGINT, signal_handle);
    signal(SIGTERM, signal_handle);
#ifndef __MACH__
    check_linux_release();
#endif //__MACH__
#endif //WIN32
}


/*
 * @brief create TCP Socket
 * @param[in,out] none
 * @return TCP socket id to event_socket
 */
evutil_socket_t Socket::create_tcp() {


#ifndef NOTNETPRINT
    // test log info on console.
    printf("[DEBUG]evutil_socket_t Socket::create_tcp() \n");
#endif
    return ::socket(AF_INET, SOCK_STREAM, 0);
}


/*
 * @brief create TCP Socket
 * @param[in,out] none
 * @return UDP socket id to event_socket
 */
evutil_socket_t Socket::create_udp() {

#ifndef NOTNETPRINT
    // test log info on console.
    printf("[DEBUG]evutil_socket_t Socket::create_udp() \n");
#endif

    return ::socket(AF_INET, SOCK_DGRAM, 0);
}


int Socket::bind(evutil_socket_t fd, const InetAddress &addr) {
    return ::bind(fd, (const sockaddr *) &addr, sizeof(sockaddr));
}

int Socket::connect(evutil_socket_t fd, const InetAddress &addr) {
    return ::connect(fd, (const sockaddr *) &addr, sizeof(addr));
}

int        Socket::listen(evutil_socket_t fd, int backlog) {
    return ::listen(fd, backlog);
}

evutil_socket_t        Socket::accept(evutil_socket_t fd, InetAddress &addr) {
    int len = sizeof(sockaddr);
    return ::accept(fd, (sockaddr * ) & addr.get_sock_addr(), (socklen_t * ) & len);
}

int        Socket::send(evutil_socket_t fd, const char *data, size_t len, int flag) {
    return ::send(fd, data, len, flag);
}

int        Socket::recv(evutil_socket_t fd, char *data, size_t len, int flag) {
    return ::recv(fd, data, len, flag);

}

sockaddr_in Socket::get_local_addr(evutil_socket_t fd) {
    sockaddr_in local_addr;
    memset(&local_addr, 0, sizeof(local_addr));
    socklen_t addr_len = sizeof(local_addr);
    ::getsockname(fd, (struct sockaddr *) (&local_addr), &addr_len);
    return local_addr;
}

sockaddr_in Socket::get_peer_addr(evutil_socket_t fd) {
    sockaddr_in peer_addr;
    memset(&peer_addr, 0, sizeof(peer_addr));
    socklen_t addr_len = sizeof(peer_addr);
    ::getpeername(fd, (struct sockaddr *) (&peer_addr), &addr_len);
    return peer_addr;
}

int Socket::error() {
#ifdef        WIN32
    return ::WSAGetLastError() ;
#else
    return errno;
#endif
}

int        Socket::socket_error(evutil_socket_t fd) {
    int error_id = 0;
    ev_socklen_t error_length = sizeof(error_id);

    getsockopt(fd, SOL_SOCKET, SO_ERROR, (char *) &error_id, &error_length);
    return error_id;
}

int Socket::nonblocking(evutil_socket_t fd) {
    return evutil_make_socket_nonblocking(fd);
}

int        Socket::reuseable(evutil_socket_t fd) {
    return evutil_make_listen_socket_reuseable(fd);
}

int        Socket::closeonexec(evutil_socket_t fd) {
    return evutil_make_socket_closeonexec(fd);
}

int        Socket::shutdown_write(evutil_socket_t fd) {
    //SHUT_RD = 0; SHUT_WR = 1; SHUT_RDWR = 2
    return ::shutdown(fd, 1);
}

void Socket::close(evutil_socket_t &fd) {
    if (fd != INVALID_SOCKET) {
        evutil_closesocket(fd);
        fd = INVALID_SOCKET;
    }
}

bool Socket::would_block() {
    register int err = Socket::error();
#ifdef        WIN32
    if (err==WSAEWOULDBLOCK || err==WSAEINPROGRESS )
        {
                return true;
        }
        else
        {
                return false ;
        }
#else
    if (err == EWOULDBLOCK || err == EINPROGRESS || err == EAGAIN) {
        return true;
    }
    else {
        return false;
    }
#endif
}

bool Socket::emfile() {
    register int err = Socket::error();
#ifdef        WIN32
    if (err == WSAEMFILE)
        {
                return true;
        }
        else
        {
                return false ;
        }
#else
    if (err == EMFILE) {
        return true;
    }
    else {
        return false;
    }
#endif
}

void        Socket::gettimeofday(struct timeval *tv, struct timezone *tz) {
#ifdef        WIN32
    uint64_t ft;
        GetSystemTimeAsFileTime((FILETIME *)&ft);
        tv->tv_sec = (long)( ft / 10000000 );
        tv->tv_usec = (long)( (ft % 10000000) / 10 );
#else
    ::gettimeofday(tv, 0);
#endif
}

int Socket::get_socket_sendbuf(evutil_socket_t fd) {
    int size = 0;
    int length = sizeof(int);

    ::getsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char *) &size, (socklen_t * ) & length);
    return size;
}

void Socket::set_socket_sendbuf(evutil_socket_t fd, int size) {
    int result = ::setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char *) &size, sizeof(int));
}


int Socket::get_socket_recvbuf(evutil_socket_t fd) {
    int size = 0;
    int length = sizeof(int);

    ::getsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char *) &size, (socklen_t * ) & length);
    return size;
}

void Socket::set_socket_recvbuf(evutil_socket_t fd, int size) {
    int result = ::setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char *) &size, sizeof(int));
}

int Socket::set_socket_tos(evutil_socket_t fd, int dscp) {
/*
*https://www.ietf.org/rfc/rfc2474.txt
*/
    if (fd < 0)
        return -1;
#ifdef WIN32
    return -1;
#else
    if (dscp < 0 || dscp > 63)
        return -1;
    int tos = dscp << 2;
    if (0 != ::setsockopt(fd, IPPROTO_IP, IP_TOS, (char *) &tos, 4)) {
        return -1;
    }
    return 0;
#endif
}

END_NAME_SPACE