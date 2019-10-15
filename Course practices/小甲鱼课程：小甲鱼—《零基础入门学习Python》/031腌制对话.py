#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-18 10:25:20
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import pickle


record = open('record.txt')
boy = {}
girl = {}
count = 1
boy[1] = []
girl[1] = []


for eachline in record:
    if eachline[:6] != '======':
        (role, says) = eachline.split(':', 1)
        if role == '小客服':
            girl[count].append(says)
        else:
            boy[count].append(says)
    else:
        count += 1
        boy[count] = []
        girl[count] = []
record.close()


for recordnum in boy:
    boy_file = open('boy_%d.txt' % recordnum, 'wb')
    pickle.dump(boy[recordnum], boy_file)
    boy_file.close()

for recordnum in girl:
    girl_file = open('girl_%d.txt' % recordnum, 'wb')
    pickle.dump(girl[recordnum], girl_file)
    girl_file.close()
