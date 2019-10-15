#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-07 22:51:11
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import pickle as p
import os


class MyDes:
    saved = []

    def __init__(self, name):
        self.name = name

    def __get__(self, instance, owner):
        if self.name not in MyDes.saved:
            raise AttributeError('%s 属性还没有赋值！' % self.name)
        with open('%s.pkl' % self.name, 'rb') as self.pickle_file:
            return p.load(self.pickle_file)

    def __set__(self, instance, value):
        self.val = value
        with open('%s.pkl' % self.name, 'wb') as self.pickle_file:
            p.dump(self.val, self.pickle_file)
            MyDes.saved.append(self.name)

    def __delete__(self, instance):
        os.remove('%s.pkl' % self.name)
        MyDes.saved.remove(self.name)
