/*
 * @Autor: SourDumplings
 * @Date: 2020-01-12 08:17:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/container-with-most-water/
 */

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;
        int n = height.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int area = (j - i) * min(height[i], height[j]);
                if (area > res)
                {
                    res = area;
                }
            }
        }
        return res;
    }
};