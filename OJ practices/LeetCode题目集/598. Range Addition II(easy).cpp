/*
 * @Author: SourDumplings
 * @Date: 2019-10-09 13:19:13
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/range-addition-ii/
 * 
 * 数字最大的必然是左上角的，那么只要找出每次操作的a, b中最小值即可
 */

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int minA = m;
        int minB = n;
        for (auto &&p : ops)
        {
            int a = p[0];
            int b = p[1];
            if (a < minA)
            {
                minA = a;
            }
            if (b < minB)
            {
                minB = b;
            }
        }
        return minA * minB;
    }
};