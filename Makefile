CXX=g++

COMPILE=3
FLAGS=-Werror -O${COMPILE}

all:
	${CXX} ${FLAGS} main.cpp -o main
