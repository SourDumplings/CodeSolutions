/*
 * @Author: SourDumplings
 * @Date: 2020-01-12 09:00:09
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/container-with-most-water/
 * 
 * 我们用两个指针指到两边，然后像内移动矮的一方即可。
 * 水槽的容积是由矮的柱子的高度和两柱子间距决定的，
 * 所以向内移动高的是肯定会缩小容积的，这就是算法的原理。
 */

class Solution
{
    public int maxArea(int[] height)
    {
        int l = 0, r = height.length - 1;
        int res = 0;
        while (l < r)
        {
            int area = 0;
            if (height[l] < height[r])
            {
                area = (r - l) * height[l];
                ++l;
            }
            else
            {
                area = (r - l) * height[r];
                --r;
            }
            if (area > res)
            {
                res = area;
            }
        }
        return res;
    }
}