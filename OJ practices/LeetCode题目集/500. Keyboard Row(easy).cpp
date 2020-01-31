/*
 * @Author: SourDumplings
 * @Date: 2019-09-27 16:50:00
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/keyboard-row/
 */

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        int info[3][10] =
            {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
             {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
             {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};
        int h[26];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 1 && j == 9 || i == 2 && j == 7)
                {
                    break;
                }
                h[info[i][j] - 'a'] = i;
            }
        }
        vector<string> res;
        for (auto &&s : words)
        {
            int r = h[tolower(s[0]) - 'a'];
            bool flag = true;
            for (auto &&c : s)
            {
                if (h[tolower(c) - 'a'] != r)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res.push_back(s);
            }
        }
        return res;
    }
};