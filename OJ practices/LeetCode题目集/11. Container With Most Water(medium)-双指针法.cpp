/**
 * @file 11. Container With Most Water(medium)-双指针法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 双指针法，复杂度：时间 O(n)，空间 O(1)
 * https://leetcode.cn/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r)
        {
            int lH = height[l];
            int rH = height[r];
            int area = min(lH, rH) * (r - l);
            if (res < area)
            {
                res = area;
            }
            if (lH <= rH)
            {
                while (l < r && height[l] <= lH)
                    ++l;
            }
            else
            {
                while (l < r && height[r] <= rH)
                    --r;
            }
        }
        return res;
    }
};