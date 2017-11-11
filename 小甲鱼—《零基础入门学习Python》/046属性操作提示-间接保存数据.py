#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-06 23:08:44
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class MyDes:

    def __init__(self, value, name=None):
        self.val = value
        self.name = name

    def __get__(self, instance, owner):
        print('正在获取变量：', self.name)
        return self.val

    def __set__(self, instance, value):
        print('正在修改变量：', self.name)
        self.val = value

    def __delete__(self, instance):
        print('正在删除变量：', self.name)
        print('阿欧~该变量删不了！')


class Test:
    x = MyDes(10, 'x')


test = Test()
y = test.x
print(y)
test.x = 8
del test.x
print(test.x)


