#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-12 14:16:17
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


# import math


# def is_prime(number):
#     if number > 1:
#         if number == 2:
#             return True
#         if number % 2 == 0:
#             return False
#         for current in range(3, int(math.sqrt(number) + 1), 2):
#             if number % current == 0:
#                 return False
#         return True
#     return False

def is_prime(number):
    if number == 1:
        return 0
    elif number == 2:
        return 1
    else:
        temp = number // 2 + 2
        for each in range(2, temp):
            if number % each == 0:
                return 0
        else:
            return 1


stop = 10000
result = 0


def get_primes(stop):
    for each in range(2, stop):
        if is_prime(each):
            yield each


for number in get_primes(stop):
    result += number
print(result)
