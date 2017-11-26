#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-19 13:04:01
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://pintia.cn/problem-sets/434/problems/6259
'''

import sys


def main():
    d = {}

    text_list = []  # 定义一个空列表
    for line in sys.stdin:
        # py.3中input（）只能输入一行  sys.stdin按下换行键然后ctrl+d程序结束
        text_list.append(line)  # 每一行组成的列表合并

    # print(text_list)

    word = ""
    flag = 0
    for each_line in text_list:
        for i in each_line:
            # print(i)
            if i == '#':
                flag = 1
                break
            elif (len(word) <= 80) and (i.isalnum() or i == '_'):
                word += i
            else:
                if not word:
                    continue
                elif len(word) > 15:
                    word = word[:15]
                word = word.lower()
                # print(word)
                if d.get(word):
                    d[word] += 1
                else:
                    d[word] = 1
                word = ""
        if flag:
            break

    # 排序
    sum_num = len(d)
    result1 = sorted(d.items(), key=lambda d: d[1], reverse=True)
    result2 = []
    for i in range(sum_num):
        temp = {}
        temp[result1[i][0]] = result1[i][1]
        for j in range(i, sum_num - 1):
            if result1[j][1] == result1[j + 1][1]:
                temp[result1[j][0]] = result1[j][1]
            else:
                break
        temp = sorted(temp.items(), key=lambda d: d[0], reverse=False)
        result2.extend(temp)

    # 输出
    print(sum_num)
    show_num = int(0.1 * sum_num)
    for i in range(show_num):
        print("%d:%s" % (result2[i][1], result2[i][0]))


if __name__ == '__main__':
    main()
