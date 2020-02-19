/*
 * @Author: SourDumplings
 * @Date: 2020-02-19 19:07:08
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/trapping-rain-water/
 * 
 * 对于蛮力算法每个点都要向左、右扫描来找最高的柱子
 * 可以完全将次记录下来：
 * left[i] 记录从 i 到最左端最高的柱子的高度
 * right[i] 记录从 i 到最右端最高的柱子的高度
 * 
 * 时间复杂度 O(n)，空间复杂度 O(n)
 */

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
        {
            return 0;
        }
        
        int left[n];
        int right[n];
        left[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (left[i - 1] < height[i - 1])
            {
                left[i] = height[i - 1];
            }
            else
            {
                left[i] = left[i - 1];
            }
        }
        right[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (right[i + 1] < height[i + 1])
            {
                right[i] = height[i + 1];
            }
            else
            {
                right[i] = right[i + 1];
            }
        }
        int res = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int h = min(left[i], right[i]);
            if (height[i] < h)
            {
                res += h - height[i];
            }
        }
        return res;
    }
};
