'''
@Autor: SourDumplings
@Date: 2020-01-28 21:25:57
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode.com/problems/divide-two-integers/
'''


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        isNeg = dividend * divisor < 0
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        if dividend < 0:
            dividend *= -1
        if divisor < 0:
            divisor *= -1
        res = 0
        while divisor <= dividend:
            t = divisor
            p = 1
            while (t << 1) <= dividend:
                t <<= 1
                p <<= 1
            dividend -= t
            res += p
        return -res if isNeg else res
