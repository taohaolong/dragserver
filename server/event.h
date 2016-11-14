//
// Created by tao Jacky on 11/13/16.
//

#ifndef DRAGONAVS_EVENT_H
#define DRAGONAVS_EVENT_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <event2/event.h>
#include <event2/bufferevent.h>

#define LISTEN_PORT 8760
#define LISTEN_BACKLOG 32
#define MAX_LINE    256

class Dawnevent {
public:
    int Init();
    int Start();
//
//   // void do_accept_cb(evutil_socket_t listener, short event, void *arg);
//    void read_cb(struct bufferevent *bev, void *arg);
//    void error_cb(struct bufferevent *bev, short event, void *arg);
//    void write_cb(struct bufferevent *bev, void *arg);

};


#endif //DRAGONAVS_EVENT_H
