#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-21 19:29:31
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import random
import easygui as g

secret = random.randint(1, 10)
g.msgbox('欢迎进入酸饺子的猜数游戏', '猜数游戏', ok_button='开始游戏')

try:
    temp = g.enterbox("不妨猜一下小甲鱼现在心里想的是哪个数字：", '猜数游戏')
    if (temp is False) or (temp is None):
        g.msgbox('这么怂啊哥~', '猜数游戏', ok_button='滚')
    else:
        guess = int(temp)
        while guess != secret:
            temp = g.enterbox("哎呀，猜错了，请重新输入吧：", '猜数游戏')
            if (temp is False) or (temp is None):
                break
            guess = int(temp)
            if guess == secret:
                g.msgbox("我草，你是小甲鱼心里的蛔虫吗？！", '猜数游戏')
                g.msgbox("哼，猜中了也没有奖励！", '猜数游戏')
            else:
                if guess > secret:
                    g.msgbox("哥，大了大了~~~", '猜数游戏')
                else:
                    g.msgbox("嘿，小了，小了~~~", '猜数游戏')
        g.msgbox("游戏结束，不玩啦^_^", '猜数游戏')
except ValueError:
    g.msgbox('输入的不是整数吧~~', '猜数游戏')
except KeyboardInterrupt:
    g.msgbox('输入中断！', '猜数游戏')
except EOFError as reason:
    g.msgbox('产生异常了哦！原因是：%s' % reason, '猜数游戏')
