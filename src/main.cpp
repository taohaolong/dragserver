/*
 * Copyright: Netease.Inc
 *
 * Author: Jacky Tao
 *
 * Date: 2016-11-11
 *
 * Description: Dragon Audio&Video Transport Server [Main]
 */


#include <iostream>
#include <stdio.h>

#include "server/dragserver.h"
#include "server/dragserverEvent.h"

//#include "common.h"

using namespace std;



int main(int argc, char *argv[]) {


    // server start
    printf("Dragon AVideo Server start.\n ");

    try {

//        DragServer server;
//        server.Start();

        setvbuf(stdout, NULL, _IONBF, 0);
//
        run();
    }
    catch (const std::exception &e) {

    }


    return 0;
}
