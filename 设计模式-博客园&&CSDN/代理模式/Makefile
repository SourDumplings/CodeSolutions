# 使用命令make all即可全部构建

all:main
.PHONY: all

OBJECTS = RealSubject.o Wangpo.o main.o

CC = g++
CPPFLAGS = -Wall -std=c++11
EXTRAFLAGS =

main: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $@ $^

RealSubject.o: RealSubject.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^

Wangpo.o: Wangpo.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^

main.o: main.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^

.PHONY: clean

clean:
	-del main.exe $(OBJECTS)
