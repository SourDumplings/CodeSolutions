#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-01 14:51:07
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import time as t


class MyTimer:

    def __init__(self):
        self.begin = 0
        self.end = 0
        self.count = t.perf_counter
        self.prompt = '并未开始计时。'

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

    def _cal(self):
        if self.end:
            self.result = self.end - self.begin
            self.prompt = '共用时：%f 秒' % self.result
        self.begin = 0
        self.end = 0

    def start(self):
        self.prompt = '提示：请先调用 stop() 停止计时！'
        self.begin = self.count()
        print('计时开始！')

    def stop(self):
        if self.begin:
            self.end = self.count()
            self._cal()
            print('计时结束！')
        else:
            print('提示：请先调用 start() 开始计时！')
