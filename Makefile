CXX=g++

COMPILE=3
FLAGS=-Werror -O${COMPILE}

TARGET=wtime_control

all:
	${CXX} ${FLAGS} main.cpp -o ${TARGET}
