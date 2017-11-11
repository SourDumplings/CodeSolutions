#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-07 21:47:20
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import time as t


class Record:

    def __init__(self, value, name):
        self.name = name
        self.val = value

    def __get__(self, instance, owner):
        self.date = t.strftime('%c')
        with open('record.txt', 'a') as f:
            f.writelines('%s 变量于北京时间 %s 被读取，%s = %s\n' %
                         (self.name, self.date, self.name, self.val))
        return self.val

    def __set__(self, instance, value):
        self.date = t.strftime('%c')
        self.val = value
        with open('record.txt', 'a') as f:
            f.writelines('%s 变量于北京时间 %s 被修改，%s = %s\n' %
                         (self.name, self.date, self.name, self.val))
        
