#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-27 19:51:09
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import random as r

x_range = [0, 10]
y_range = [0, 10]
# 地图范围


class Turtle():

    def __init__(self):
        self.hp = 100
        # 初始HP为100
        self.position = [r.randint(x_range[0], x_range[1]),
                         r.randint(y_range[0], y_range[0])]
        # 初始位置随机

    def move(self):
        # 乌龟移动，返回操作之后的乌龟所处位置
        step = r.randint(1, 2)
        direction = r.randint(1, 4)
        if direction == 1:
            # 向上移动
            self.position[1] += step
            if self.position[1] > y_range[1]:
                self.position[1] = y_range[1] - \
                    (self.position[1] - y_range[1])

        if direction == 2:
            # 向下移动
            self.position[1] -= step
            if self.position[1] < y_range[0]:
                self.position[1] = y_range[0] + \
                    (y_range[0] - self.position[1])

        if direction == 3:
            # 向左移动
            self.position[0] -= step
            if self.position[0] < x_range[0]:
                self.position[0] = x_range[0] + \
                    (x_range[0] - self.position[0])

        if direction == 4:
            # 向右移动
            self.position[0] += step
            if self.position[0] > x_range[1]:
                self.position[0] = x_range[1] - \
                    (self.position[0] - x_range[1])

        self.hp -= 1
        return self.position

    def eat(self):
        self.hp += 20
        if self.hp > 100:
            self.hp = 100
        print('有条鱼被吃了~')


class Fish:

    def __init__(self):
        self.position = [r.randint(x_range[0], x_range[1]),
                         r.randint(y_range[0], y_range[0])]
    # 初始位置随机

    def move(self):
        # 鱼移动，返回操作之后的鱼所处位置
        step = 1
        direction = r.randint(1, 4)

        if direction == 1:
            # 向上移动
            self.position[1] += step
            if self.position[1] > y_range[1]:
                self.position[1] = y_range[1] - \
                    (self.position[1] - y_range[1])

        if direction == 2:
            # 向下移动
            self.position[1] -= step
            if self.position[1] < y_range[0]:
                self.position[1] = y_range[0] + \
                    (y_range[0] - self.position[1])

        if direction == 3:
            # 向左移动
            self.position[0] -= step
            if self.position[0] < x_range[0]:
                self.position[0] = x_range[0] + \
                    (x_range[0] - self.position[0])

        if direction == 4:
            # 向右移动
            self.position[0] += step
            if self.position[0] > x_range[1]:
                self.position[0] = x_range[1] - \
                    (self.position[0] - x_range[1])

        return self.position


turtle = Turtle()
fish = list(range(10))
for i in range(10):
    fish[i] = Fish()
# 生成1只乌龟和10条鱼

fishp = []  # 记录鱼的位置
while True:
    # 游戏程序

    turtlep = turtle.move()
    # 乌龟移动一次

    for each in fish:
        fishp.append(each.move())
        # 每条鱼都移动一次
        if fishp[len(fishp) - 1] == turtlep:
            turtle.eat()
            fish.remove(each)

    if len(fish) == 0:
        print('鱼都被吃完了，游戏结束！')
        break

    if turtle.hp == 0:
        print('乌龟的体力耗尽，游戏结束！')
        break
