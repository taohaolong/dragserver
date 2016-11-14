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

#include "server/event.h"


using namespace std;


int main(int argc, char *argv[]) {

    // server start
    printf("Dragon AVideo Server start.\n ");

    try {
        int m = 0;
        Dawnevent server;
        server.Start();
    }
    catch (const std::exception &e) {

    }


    return 0;
}