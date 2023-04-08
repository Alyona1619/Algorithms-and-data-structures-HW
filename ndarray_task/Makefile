CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
SOURCES = main.cpp
HEADER = ndarray.h

ifeq (${OS},Windows_NT)
	TARGET = main.exe
	RM = del
else
	TARGET = main
	RM = rm
endif

all:
	$(CC) ${CFLAGS} -o ${TARGET} ${SOURCES}

clean:
	echo $(OS)
	${RM} ${TARGET}

run: all
	./${TARGET}
