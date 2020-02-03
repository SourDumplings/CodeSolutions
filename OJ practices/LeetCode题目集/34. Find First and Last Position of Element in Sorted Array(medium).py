'''
@Author: SourDumplings
@Date: 2020-02-03 11:12:20
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
'''
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        b = self.binarySearch(nums, target)
        res = [-1, -1]
        if b == -1:
            return res
        l = len(nums)
        e = b
        while e < l and nums[e] == target:
            e += 1
        while 0 <= b and nums[b] == target:
            b -= 1
        res = [b + 1, e - 1]
        return res

    def binarySearch(self, nums: List[int], target: int) -> int:
        l = len(nums)
        if l == 0:
            return -1
        lo = 0
        hi = l - 1
        while lo < hi:
            mi = int((lo + hi) / 2)
            if nums[mi] == target:
                return mi
            elif nums[mi] < target:
                lo = mi + 1
            else:
                hi = mi
        return lo if nums[lo] == target else -1
