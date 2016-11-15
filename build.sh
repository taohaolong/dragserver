#!/bin/sh



 g++  main.cpp log/filelock.cpp log/filelock.h log/KmMutex.h log/logger.h  log/logger.cpp  \
    common.h \
    server/dragserver.h server/dragserver.cpp server/dragserverEvent.h server/dragserverEvent.cpp \
     -o bin/svr -levent -g
