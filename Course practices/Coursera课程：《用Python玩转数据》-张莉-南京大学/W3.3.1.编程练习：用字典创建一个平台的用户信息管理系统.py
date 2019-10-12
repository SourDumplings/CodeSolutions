#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-20 09:38:17
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
3.1.编程练习：用字典创建一个平台的用户信息（包含用户名和密码）管理系统，新用户可以用与现有系统帐号不冲突的用户名创建帐号，已存在的老用户则可以用用户名和密码登陆重返系统。
'''


def newusers(data):
    print("enter a name: ", end='')
    name = input()
    while data.get(name):
        print("this name exists, enter again: ", end='')
        name = input()
    print("set the password: ", end='')
    pw = input()
    data[name] = pw
    print("new user added!")
    return


def oldusers(data):
    print("Enter the  username and password(name password): ", end='')
    temp = input().split(' ')
    name = temp[0]
    pw = temp[1]
    if data.get(name) == pw:
        print(name, 'welcome back!')
    else:
        print('login incorrect!')
    return


def login():
    option = '''
             (N)ew User Login
             (O)ld User Login
             (E)xit
                    '''
    data = {}
    while (True):
        print("Enter the option: ", end='')
        print(option)
        o = input()
        if o == "E" or o == "e":
            break
        elif o == "N" or o == "n":
            newusers(data)
        elif o == "O" or o == "o":
            oldusers(data)
        else:
            print("Wrong order!")


if __name__ == '__main__':
    login()
