#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-01 09:17:10
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import time as t


class MyTimer():

    def __init__(self):
        self.unit = ['年', '月', '天', '小时', '分钟', '秒']
        self.num = [0, 12, 31, 24, 60, 60]
        self.prompt = '未开始计时'
        self.lasted = []
        self.begin = 0
        self.end = 0

    def __str__(self):
        return self.prompt

    __repr__ = __str__

    def __add__(self, other):
        prompt = '总共运行了'
        result = []
        for index in range(6):
            result.append(self.lasted[index] + other.lasted[index])
            if result[index]:
                prompt += (str(result[index]) + self.unit[index])
        return prompt

    # 内部方法，计算运行时间
    def _calc(self):
        self.lasted = []
        self.prompt = '总共运行了'
        for index in range(6):
            self.lasted.append(self.end[index] - self.begin[index])
            if self.lasted[index] < 0:
                self._switch(index)
        for index in range(6):
            if self.lasted[index]:
                self.prompt += (str(self.lasted[index]) + self.unit[index])

        # 为下一轮计时初始化变量
        self.begin = 0
        self.end = 0

    # 负数转换
    def _switch(self, index):

        # 借位函数
        def _borrow(self, index):
            # print(index)
            if self.lasted[index]:
                self.lasted[index] -= 1
                # print('借位了')
            else:
                self.lasted[index] = self.num[index] - 1
                _borrow(self, (index - 1))

        self.lasted[index] += self.num[index]
        # print(index)
        _borrow(self, (index - 1))

    # 开始计时
    def start(self):
        self.begin = t.localtime()
        self.prompt = '提示：请先调用 stop() 停止计时！'
        print('计时开始。。。')
        print('当前时间:', self.begin)

    # 停止计时
    def stop(self):
        if not self.begin:
            print('提示：请先调用 start() 开始计时！')
        else:
            self.end = t.localtime()
            print('当前时间:', self.end)
            self._calc()
            print('计时结束！')
