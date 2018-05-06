# 使用命令make all即可全部构建

all:main
.PHONY: all

OBJECTS = BackDoor.o GivenGreenLight.o BlockEnemy.o Context.o main.o

CC = g++
CPPFLAGS = -Wall -std=c++11
EXTRAFLAGS =

main: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $@ $^

BackDoor.o: BackDoor.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^

GivenGreenLight.o: GivenGreenLight.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^

BlockEnemy.o: BlockEnemy.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^

Context.o: Context.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^

main.o: main.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^

.PHONY: clean

clean:
	-del main.exe $(OBJECTS)
