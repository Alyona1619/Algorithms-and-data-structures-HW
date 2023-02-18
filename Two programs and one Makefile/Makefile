CC = g++
CFLAGS = -std=c++11 -Wall -pedantic

PROGA1 = main1.cpp
PROGA2 = main2.cpp

ifeq ($(OS), Windows_NT)
	RM = del
	BIN1 = main1.exe 
	BIN2 = main2.exe
else
	RM = rm
	BIN1 = main1
	BIN2 = main2
endif

all: generator processor

generator:
	$(CC) $(CFLAGS) -o $(BIN1) $(PROGA1)

processor:
	$(CC) $(CFLAGS) -o $(BIN2) $(PROGA2)

clean:
	echo $(OS)
	$(RM) $(BIN1)
	$(RM) $(BIN2)
	$(RM) *.txt

run: all
	$(BIN1) 
	$(BIN2)