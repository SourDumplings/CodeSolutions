#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-19 13:29:31
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import random

secret = random.randint(1, 10)
print('------------------我爱鱼C工作室------------------')

try:
    temp = input("不妨猜一下小甲鱼现在心里想的是哪个数字：")
    guess = int(temp)
    while guess != secret:
        temp = input("哎呀，猜错了，请重新输入吧：")
        guess = int(temp)
        if guess == secret:
            print("我草，你是小甲鱼心里的蛔虫吗？！")
            print("哼，猜中了也没有奖励！")
        else:
            if guess > secret:
                print("哥，大了大了~~~")
            else:
                print("嘿，小了，小了~~~")
    print("游戏结束，不玩啦^_^")
except ValueError:
    print('输入的不是整数吧~~')
except KeyboardInterrupt:
    print('输入中断！')
except EOFError as reason:
    print('产生异常了哦！原因是：', str(reason))
