'''
@Author: SourDumplings
@Date: 2020-02-22 18:08:18
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode-cn.com/problems/trapping-rain-water/

思路和动态规划类似，但是更高效
分别记录当前指针向左、右的最高的柱子的高度
如果当前位置形成了凹槽则记录
时间复杂度 O(n)，空间复杂度 O(1)
'''


class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0
        left, right = 0, len(height) - 1
        res = 0
        left_max, right_max = height[left], height[right]
        while left < right:
            if height[left] < height[right]:
                if left_max < height[left]:
                    left_max = height[left]
                else:
                    res += left_max - height[left]
                left += 1
            else:
                if right_max < height[right]:
                    right_max = height[right]
                else:
                    res += right_max - height[right]
                right -= 1
        return res
