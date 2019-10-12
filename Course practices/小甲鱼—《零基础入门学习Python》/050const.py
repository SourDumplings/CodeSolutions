#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-12 22:30:16
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

# 测试前需要将文件名前面的数字去掉


import sys


class Const:

    def __setattr__(self, name, value):
        if name in self.__dict__:
            raise TypeError('常量无法改变！')
        if not name.isupper():
            raise TypeError('常量名必须大写！')

        self.__dict__[name] = value


sys.modules[__name__] = Const()
