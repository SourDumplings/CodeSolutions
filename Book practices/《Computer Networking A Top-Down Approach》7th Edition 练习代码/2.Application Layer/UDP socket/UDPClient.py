# -*- coding: utf-8 -*-
# @Time    : 2020/11/26 21:57
# @Author  : SourDumplings
# @Email   : changzheng300@foxmail.com
# @Link    : https://github.com/SourDumplings/
# @Site    : 
# @File    : UDPClient.py

from socket import *

from pip._vendor.distlib.compat import raw_input

serverName = 'localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = raw_input('Input lowercase sentence:')
clientSocket.sendto(message.encode(), (serverName, serverPort))
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print(modifiedMessage.decode())
clientSocket.close()
