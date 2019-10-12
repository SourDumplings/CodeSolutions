/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 21:27:16
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-of-boomerangs/
 */

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int res = 0;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> m;
            for (int j = 0; j < n; j++)
            {
                int d = (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]) +
                        (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
                ++m[d];
            }
            for (auto &&p : m)
            {
                int num = p.second;
                if (p.first != 0 && num >= 2)
                {
                    res += num * (num - 1); // A(2, num)
                }
            }
        }
        return res;
    }
};