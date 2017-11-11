#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-30 22:04:52
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class C:

    def __init__(self, *arg):
        # print(arg)
        self.n = len(arg)
        if self.n != 0:
            self.result = ''
            for i in range(self.n):
                self.result += (str(arg[i]) + ' ')
            self.result = self.result[:-1]
            print('传入了 %d 个参数，分别是：%s' % (self.n, self.result))
        else:
            print('并没有传入参数')


c = C()
a = C(1, 2, 3)
