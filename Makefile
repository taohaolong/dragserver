# BUILD PROJECT 1.0
# by Jacky.Tao @2016.11.16

LIB=-levent
INC=-I. -I ./src/ -I./src/common/
CFLAG=-g -Wall
CXX=g++
SRC_PATH = ./src/

#$(foreach dir,$(SRC_PATH),$(wildcard $(dir)*.cpp))

SOURCE=$(wildcard $(SRC_PATH)*.cpp $(SRC_PATH)server/*.cpp $(SRC_PATH)log/*.cpp \
         $(SRC_PATH)network/*.cpp )

OBJS=$(patsubst %.cpp,%.o,$(SOURCE))

OBJ=$(filter-out $(SRC_PATH)main.o,$(OBJS))

.cpp.o:$(SOURCE)
	$(CXX) $(INC)  $(CFLAG) -c $< -o $@ -static-libgcc -static-libstdc++

build:$(OBJ)
	$(CXX) $(SRC_PATH)main.cpp $(INC) $(CFLAG) $(OBJ)  -o bin/dragServer $(LIB)
clean:
	rm -rf $(SRC_PATH)log/*.o
	rm -rf $(SRC_PATH)server/*.o
	rm -rf $(SRC_PATH)network/*.o
	rm -f  bin/dragServer
	rm -f  src/*.o