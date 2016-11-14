#!/bin/sh

 g++  main.cpp  server/dragserver.cpp server/dragserver.h  server/dragserverEvent.cpp server/dragserverEvent.h -o bin/svr -levent -g
