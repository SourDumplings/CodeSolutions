/*
 * @Author: SourDumplings
 * @Date: 2020-02-17 10:31:11
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/trapping-rain-water/
 * 
 * 以每个点为中心向两侧扩展，每个点只管自己这一个垂直上的雨水
 * 时间复杂度 O(n)，空间复杂度 O(1)
 */

class Solution
{
    public int trap(int[] height)
    {
        int res = 0;
        int l = height.length;
        for (int i = 1; i < l - 1; i++)
        {
            int left = height[i];
            int right = left;
            for (int j = i + 1; j < l; j++)
            {
                right = Math.max(right, height[j]);
            }
            for (int j = i - 1; 0 <= j; j--)
            {
                left = Math.max(left, height[j]);
            }
            res += Math.min(left, right) - height[i];
        }
        return res;
    }
}