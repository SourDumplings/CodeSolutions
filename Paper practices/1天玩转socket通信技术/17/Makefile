# 使用命令make all即可全部构建

all: server client
.PHONY: all

CC = g++
CPPFLAGS = -Wall -std=c++11
EXTRAFLAGS = -lws2_32

server:server.cpp
	$(CC) $(CPPFLAGS) -o $@ $^ $(EXTRAFLAGS)

client: client.cpp
	$(CC) $(CPPFLAGS) -o $@ $^ $(EXTRAFLAGS)


.PHONY: clean

clean:
	-del server.exe client.exe
