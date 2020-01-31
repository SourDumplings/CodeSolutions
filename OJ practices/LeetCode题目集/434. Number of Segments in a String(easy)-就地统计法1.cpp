/*
 * @Author: SourDumplings
 * @Date: 2019-09-25 11:37:19
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-of-segments-in-a-string/
 */

class Solution
{
public:
    int countSegments(string s)
    {
        int res = 0;
        bool firstWord = false;
        for (auto &&c : s)
        {
            if (c == ' ')
            {
                if (firstWord)
                {
                    ++res;
                    firstWord = false;
                }
            }
            else
            {
                firstWord = true;
            }
        }
        if (firstWord && s[s.length() - 1] != ' ')
        {
            ++res;
        }

        return res;
    }
};