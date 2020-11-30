# -*- coding: utf-8 -*-
# @Time    : 2020/11/26 22:32
# @Author  : SourDumplings
# @Email   : changzheng300@foxmail.com
# @Link    : https://github.com/SourDumplings/
# @Site    : 
# @File    : UDPServer.py

from socket import *

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print("The server is ready to receive")
while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    modifiedMessage = message.decode().upper()
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)
