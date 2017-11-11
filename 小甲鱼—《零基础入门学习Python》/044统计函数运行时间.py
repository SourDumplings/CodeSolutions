#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-01 15:27:10
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import time as t


class MyTimer:

    def __init__(self, func, n=1000000):
        self.begin = 0
        self.end = 0
        self.count = t.perf_counter
        self.prompt = '并未开始计时。'
        self.func = func
        self.n = n

    def __str__(self):
        return self.prompt

    __repr__ = __str__

    def __add__(self, other):
        prompt = '总共运行了 %f 秒' % (self.result + other.result)
        return prompt

    def set_time(self, count=t.perf_counter):
        if (count == t.process_time) or (count == t.perf_counter):
            self.count = count
        else:
            print('设置错误！')

    def timming(self):
        self.begin = self.count()
        self.func()
        self.end = self.count()
        self.result = (self.end - self.begin) * self.n
        self.prompt = '总共运行了 %f 秒' % self.result
        self.begin = self.end = 0


def test():
    text = 'I love FishC.com!'
    char = 'o'
    if char in text:
        pass


t1 = MyTimer(test)
t1.timming()
print(t1)
t2 = MyTimer(test, 100000000)
t2.timming()
print(t2)
print(t1 + t2)
