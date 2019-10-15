#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-13 22:20:16
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


data = {}

print('''|--- 新建用户: N/n ---|
|--- 登录账号: E/e ---|
|--- 退出程序: Q/q ---|''')


def CreatAccount():
    username = input('请输入用户名：')
    while username in data:
        username = input('该用户名已经存在，请重新输入：')
    data[username] = input('请输入密码：')
    print('账号创建成功！')


def Login():
    username = input('请输入用户名：')
    password = input('请输入密码：')
    if (username not in data) or (data[username] != password):
        print('该用户不存在或密码错误！')
    else:
        print('登陆成功！欢迎进入酸饺子编写的莫名其妙的系统！')


while 1:
    order = input('请输入指令代码：')
    if (order == 'N') or (order == 'n'):
        CreatAccount()
    elif (order == 'E') or (order == 'e'):
        Login()
    elif (order == 'Q') or (order == 'q'):
        print('您已经退出程序，谢谢使用！')
        break
    else:
        print('输入错误！')
