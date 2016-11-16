cmake_minimum_required(VERSION 3.3)
project(DragonAVS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp server/dragsock.cpp server/dragsock.h common.h.h src/common/common.h src/common/type.h src/network/dragEvent.h src/network/sockbase.h src/network/UDPSock.cpp src/network/UDPSock.h src/network/TCPSock.cpp src/network/TCPSock.h src/network/sockbase.cpp src/network/sockutil.cpp src/network/sockutil.h)
add_executable(DragonAVS ${SOURCE_FILES})