'''
@Author: SourDumplings
@Date: 2020-02-15 23:06:48
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode-cn.com/problems/climbing-stairs/
'''


class Solution:
    def climbStairs(self, n: int) -> int:
        first = 1
        res = second = 2
        if n < 3:
            return n
        count = 2
        while True:
            res = first + second
            count += 1
            if count == n:
                break
            first = second
            second = res
        return res
