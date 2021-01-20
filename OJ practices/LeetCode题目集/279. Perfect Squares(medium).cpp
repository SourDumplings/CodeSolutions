/*
 * @Author: SourDumplings
 * @Date: 2021-01-20 10:54:36
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/perfect-squares/
 */

class Solution
{
public:
    int numSquares(int n)
    {
        int r[n + 1];
        vector<int> s;
        fill(r, r + n + 1, 99999);
        r[1] = 1;
        r[0] = 0;
        int root = 0;
        while (true)
        {
            s.push_back(root * root);
            if (root * root > n)
            {
                break;
            }
            ++root;
        }
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 0; j < n + 1; ++j)
            {
                if (i < s[j])
                {
                    break;
                }
                r[i] = min(r[i], r[i - s[j]] + 1);
            }
        }
        return r[n];
    }
};