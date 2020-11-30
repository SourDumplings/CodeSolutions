# -*- coding: utf-8 -*-
# @Time    : 2020/11/26 23:37
# @Author  : SourDumplings
# @Email   : changzheng300@foxmail.com
# @Link    : https://github.com/SourDumplings/
# @Site    : 
# @File    : TCPClient.py

from socket import *

from pip._vendor.distlib.compat import raw_input

serverName = 'localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
sentence = raw_input('Input lowercase sentence:')
clientSocket.send(sentence.encode())
modifiedSentence = clientSocket.recv(1024)
print('From Server: ', modifiedSentence.decode())
clientSocket.close()
