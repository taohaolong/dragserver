//
// Created by tao Jacky on 11/16/16.
//

#ifndef DRAGONAVS_SOCKUTIL_H
#define DRAGONAVS_SOCKUTIL_H

#include "dragEvent.h"
#include "common/common.h"
#include "common/type.h"


BEGIN_NAME_SPACE(NetDrag)

class Socket {

public:
    static void Init();
    static evutil_socket_t create_udp();
    static evutil_socket_t create_tcp();

};

END_NAME_SPACE


#endif //DRAGONAVS_SOCKUTIL_H
