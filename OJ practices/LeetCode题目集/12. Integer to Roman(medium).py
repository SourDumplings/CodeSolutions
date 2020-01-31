'''
@Author: SourDumplings
@Date: 2020-01-31 09:11:25
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode.com/problems/integer-to-roman/
'''


class Solution:
    def intToRoman(self, num: int) -> str:
        d = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M'}
        base = 1000
        res = ""
        while base > 0:
            quotient, num = divmod(num, base)
            if quotient < 4:
                res += quotient * d[base]
            elif quotient == 4:
                res += d[base] + d[base * 5]
            elif quotient < 9:
                res += d[base * 5] + (quotient - 5) * d[base]
            elif quotient == 9:
                res += d[base] + d[base * 10]
            base //= 10
        return res

