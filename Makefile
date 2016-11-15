LIB=-levent
INC=-I.
CFLAG=-g -Wall
CXX=g++
CUR_PATH = ./obj/
#$(foreach dir,$(CUR_PATH),$(wildcard $(dir)*.cpp))
SOURCE=$(wildcard *.cpp ./server/*.cpp ./log/*.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SOURCE))
OBJ=$(filter-out main.o,$(OBJS))
.cpp.o:$(SOURCE)
	$(CXX) $(CFLAG) -c $< -o $@

build:$(OBJ)
	$(CXX) $(CFLAG) $(OBJ) main.cpp -o bin/dragServer $(LIB)
clean:
	rm -rf log/*.o
	rm -rf server/*.o
	rm -f  bin/dragServer