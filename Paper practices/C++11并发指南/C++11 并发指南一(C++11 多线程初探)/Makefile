# 使用命令make all即可全部构建

all:Thread
.PHONY: all

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

Thread:Thread.o
	$(CC) $(LDFLAGS) -o $@ $^

Thread.o:Thread.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY: clean

clean:
	-del Thread.o Thread.exe
