/*
 * @Author: SourDumplings
 * @Date: 2019-09-26 10:27:42
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/assign-cookies/
 */

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int res = 0;
        int i = 0;
        int n = g.size();
        for (auto &&c : s)
        {
            while (i < n && c < g[i])
            {
                ++i;
            }
            if (i == n)
            {
                break;
            }
            ++res;
            ++i;
        }

        return res;
    }
};