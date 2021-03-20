'''
Author: SourDumplings
Date: 2021-03-20 11:20:04
Link: https://github.com/SourDumplings/
Email: changzheng300@foxmail.com
Description: https://leetcode-cn.com/problems/ugly-number-ii/
'''


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        uglyNums = [1]
        primes = [2, 3, 5]
        indexes = [0] * 3  # 记录与2，3，5乘的下一个 uglyNum 的索引
        while len(uglyNums) < n:
            nextUglyNum = min(
                [primes[i] * uglyNums[indexes[i]] for i in range(3)])
            uglyNums.append(nextUglyNum)
            for i in range(3):
                if primes[i] * uglyNums[indexes[i]] == nextUglyNum:
                    indexes[i] += 1
        return uglyNums[-1]