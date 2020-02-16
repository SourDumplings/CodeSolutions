'''
@Author: SourDumplings
@Date: 2020-02-16 19:37:18
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode-cn.com/problems/merge-sorted-array/

双指针法，从后往前填
'''

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p = m + n - 1
        p1 = m - 1
        p2 = n - 1
        while 0 <= p1 and 0 <= p2:
            num1 = nums1[p1]
            num2 = nums2[p2]
            if num1 < num2:
                nums1[p] = nums2[p2]
                p2 -= 1
            else:
                nums1[p] = nums1[p1]
                p1 -= 1
            p -= 1

        while 0 <= p and p1 == -1:
            nums1[p] = nums2[p2]
            p -= 1
            p2 -= 1
        while 0 <= p and p2 == -1:
            nums1[p] = nums1[p1]
            p -= 1
            p1 -= 1
            
