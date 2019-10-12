/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 19:52:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/string-compression/
 */

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int count = 0;
        vector<char> res;
        char lastChar = 0;
        for (char c : chars)
        {
            if (c == lastChar)
            {
                ++count;
            }
            else
            {
                if (count == 1)
                {
                    res.push_back(lastChar);
                }
                else if (count > 1)
                {
                    res.push_back(lastChar);
                    string num = to_string(count);
                    for (auto &&cn : num)
                    {
                        res.push_back(cn);
                    }
                }
                count = 1;
                lastChar = c;
            }
        }
        if (count == 1)
        {
            res.push_back(lastChar);
        }
        else if (count > 1)
        {
            res.push_back(lastChar);
            string num = to_string(count);
            for (auto &&cn : num)
            {
                res.push_back(cn);
            }
        }
        chars = std::move(res);
        return chars.size();
    }
};