#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-08 17:20:12
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1049
思路1：
考虑1位数字0~9包含1个1；
再考虑00~99包含20个1；
再考虑000~999包含300个1；
……
即对于0~999……999（k个9），包含k*pow(10，(k-1))个1
依次类推找出k+1位数字和k位数字所包含1的数量之间关系。
接下来再从高位到低位不断分割，比如输入是1356，先找到000~999包含1个数，
再找1000到1356包含1的个数，它包含1个数是357再加上356包含个数，依次不断向低位靠近。

思路2：
以current记录当前考察位的数字，考察这一位为1时的这一位贡献的1的个数，再把每一位的考察结果累加。
分别以left, right记录这一位左边和右边所构成的数字，x表示当前位的基数，然后分三种情况：
1.current == 0，这说明当前位只有在left从[0, left)的时候会产生1，
比如对于1000，考察十位位即current = 0时, left = 10, 即会出现(个位即right用r代表):
01r, 11r, 21r, 31r, 41r, 51r, 61r, 71r, 81r, 91r, 所以由于这一位是1会贡献left个1，
但是又因为右边会重复从[0, x)出现x次重复，即对于任意一个left，比如left为2时，current带着右边数字会出现：
210, 211, 212, 213, 214, 215, 216, 217, 218, 219一共会贡献x个1
故total += left * x
2.current == 1, 就要比上一步多加一个当current为1的时候右边出现[0, right]个数导致的贡献1的次数,
比如3415，考察到十位数字1的时候，即对于每一种left * x个1（情况1的情况），
即001r, 011r, 021r,..., 321r, 331r，共left * x个
又多了3410, 3411, 3412, 3413, 3414, 3415即right+1个1也是由于current位为1贡献的，故应该再加right+1
3.其他情况的话，类似第一种情况加一种，即左边[0, left]的时候会在位置产生1，所以会产生left+1次，
然后右边产生x次重复，即(left + 1) * x
比如对于1123，考察十位数字2，那么就有001r, 011r, 021r,..., 111r共(left + 1) * x = 120种
'''

d = int(input())
# print("d = %d" % d)
x = 1
total = 0
while d // x != 0:
    # x相当于当前数字所在的位的基数，比如初始时当前数字为个位，基数为1，然后下一轮为十位，基数为10
    right = d % x  # 当前数字右边的数字所组成的数
    left = d // (x * 10)  # 当前数字左边的数字所组成的数
    current = (d // x) % 10  # 当前数字
    # print("x = %d, d = %d, right = %d, left = %d, current = %d" %
          # (x, d, right, left, current))
    if current == 0:
        total += left * x
    elif current == 1:
        total += left * x + right + 1
    else:
        total += (left + 1) * x
    # print("total = %d" % total)
    x = x * 10

print(total)
