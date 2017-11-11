#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-04 12:28:38
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Demo:

    def __getattr__(self, name):
        super().__setattr__(name, 'FishC')


demo = Demo()
demo.x
print(demo.x)
demo.x = 'X-man'
print(demo.x)
