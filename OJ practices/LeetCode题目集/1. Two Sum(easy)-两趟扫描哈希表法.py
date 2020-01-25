'''
@Autor: SourDumplings
@Date: 2020-01-24 09:23:24
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode.com/problems/two-sum/
'''
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = dict()
        for i, n in enumerate(nums):
            d[n] = i
        for i, n in enumerate(nums):
            r = target - n
            j = d.get(r)
            if j is not None and i != j:
                return [i, j]
