//
// Created by tao Jacky on 11/16/16.
//

#ifndef DRAGONAVS_SOCKBASE_H
#define DRAGONAVS_SOCKBASE_H

#include "dragEvent.h"
#include "common/common.h"
#include "common/type.h"

/*-----------------------------Libevent封装-----------------------------------------*/

BEGIN_NAME_SPACE(NetDrag)

class EventLoop;


class EventSockBase {
public:
    EventSockBase();

    ~EventSockBase();


};


END_NAME_SPACE

#endif //DRAGONAVS_SOCKBASE_H
