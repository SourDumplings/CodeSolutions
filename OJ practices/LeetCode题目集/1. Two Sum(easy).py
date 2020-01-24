'''
@Autor: SourDumplings
@Date: 2020-01-24 09:23:24
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: 
'''
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = len(nums)
        d = dict()
        for i, n in enumerate(nums):
            d[n] = i
        for i in range(l):
            r = target - nums[i]
            j = d.get(r)
            if j is not None and i != j:
                return [i, d[r]]
