#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-12 20:00:12
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
KO奥数高手

有一天一个江湖传说中的奥数高手冷冷地问我：你知道2000个5（55555...55555）除以84的余数是多少吗？
给你5分钟思考时间。我打开Python IDLE，5秒钟告诉了他答案，
看着屏幕上只有一行代码，他的脸在风中抽搐着。
如果你遇到他，你几秒可以KO他？快来亮出你的KO秘籍吧。
'''


def main():
    num = int('5' * 2000)
    r = num % 84
    print(r)
    return


if __name__ == '__main__':
    main()
    # code
